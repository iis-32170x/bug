#include "vertex_module.hpp"
#include "agents/vertex_degree_agent.hpp"

SC_IMPLEMENT_MODULE(vertexModule)

sc_result vertexModule::InitializeImpl()
{
    if (!sc_memory_is_initialized())
        return SC_RESULT_ERROR;

    SC_AGENT_REGISTER(VertexDegreeAgent)    
}

sc_result vertexModule::ShutdownImpl()
{
    SC_AGENT_UNREGISTER(VertexDegreeAgent) 
    return SC_RESULT_OK;
}