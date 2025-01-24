#pragma once

#include <sc-memory/sc_module.hpp>

class vertexModule : public ScModule
{
    SC_CLASS(LoadOrder(1))
    SC_GENERATED_BODY()

protected:

    virtual sc_result InitializeImpl() override;

 
    virtual sc_result ShutdownImpl() override;
};