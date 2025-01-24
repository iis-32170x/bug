#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_object.hpp"

class VertexAgentDegree : public ScAgentAction
{
    SC_CLASS()
    SC_GENERATED_BODY()

public:

    SC_PROPERTY(Keynode("action_find_vertices_by_degree"), ForceCreate)
    static ScAddr action_find_vertices_by_degree;
};