#pragma once
#include <sc-memory/sc_module.hpp>
#include <keynodes/vertex_keynodes.hpp>

class VertexDegreeAgent : public ScAgentAction
{
public:
    SC_CLASS(Agent, Event(vertex_keynodes::action_find_vertices_by_degree, ScEvent::Type::AddOutputEdge))
    SC_GENERATED_BODY()

protected:
    ScResult DoProgram(ScAction &action) override;
};