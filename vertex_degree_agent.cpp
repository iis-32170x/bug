#include <vertex_degree_agent.hpp>
#include "keynodes/vertex_keynodes.hpp"

namespace std
{
    template <>
    struct hash<ScAddr>
    {
        std::size_t operator()(const ScAddr &addr) const noexcept
        {
            return std::hash<uint64_t>()(addr.Hash());
        }
    };
}

ScAddr VertexDegreeAgent::GetActionClass() const
{
    return SearchKeynodes::action_find_vertices_by_degree;
}

ScResult VertexDegreeAgent::DoProgram(ScAction &action)
{
    auto const &[graph, targetDegree] = action.GetArguments<2>();
    if (!m_context.IsElement(graph) || !m_context.IsElement(targetDegree))
    {
        SC_AGENT_LOG_ERROR("Action does not have valid arguments.");
        return action.FinishWithError();
    }

    int targetDegreeValue;
    if (!m_context.GetIntegerValue(targetDegree, targetDegreeValue))
    {
        SC_AGENT_LOG_ERROR("Target degree is not a valid integer.");
        return action.FinishWithError();
    }

    ScIterator3Ptr nodeIterator = m_context.CreateIterator3(
        graph, ScType::EdgeAccessConstPosPerm, ScType::NodeConst);
    if (!nodeIterator->Next())
    {
        SC_AGENT_LOG_ERROR("The graph is empty.");
        return action.FinishWithError();
    }
    ScStructure resultStructure = m_context.GenerateStructure();
    std::unordered_map<ScAddr, int> nodeDegrees;

   
    do
    {
        ScAddr node = nodeIterator->Get(2);
        int degree = 0;

        ScIterator3Ptr edgeIterator = m_context.CreateIterator3(
            node, ScType::EdgeUCommonConst, ScType::NodeConst);
        while (edgeIterator->Next())
        {
            degree++;
        }
        edgeIterator = m_context.CreateIterator3(
            ScType::NodeConst, ScType::EdgeUCommonConst, node);
        while (edgeIterator->Next())
        {
            degree++;
        }

        nodeDegrees[node] = degree;
    } while (nodeIterator->Next());

    for (const auto &[node, degree] : nodeDegrees)
    {
        if (degree == targetDegreeValue)
        {
            resultStructure << node;
        }
    }

    if (resultStructure.Size() == 0)
    {
        SC_AGENT_LOG_WARNING("No vertices found with the specified degree.");
    }
}
