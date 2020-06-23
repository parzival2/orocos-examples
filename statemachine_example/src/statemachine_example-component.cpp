#include "statemachine_example-component.hpp"
#include <rtt/Component.hpp>
#include <rtt/scripting/Scripting.hpp>

Statemachine_example::Statemachine_example(std::string const& name)
    : TaskContext(name)
    , mCounter("Counter", 0)
{
    this->attributes()->addAttribute(mCounter);
}

bool Statemachine_example::configureHook()
{
    RTT::scripting::ScriptingService::shared_ptr mScriptingSerive =
        boost::dynamic_pointer_cast<Orocos::scripting::ScriptingService>(
            this->provides()->getService("scripting"));
    if(!mScriptingSerive)
    {
        Orocos::log(Orocos::Error)
            << "[Statemachine_example::configureHook] Statemachine service not found : "
            << Orocos::endlog();
    }
    else
    {
        Orocos::scripting::StateMachinePtr mStateMachinePtr =
            mScriptingSerive->getStateMachine("ExampleStateMachine");
        if(!mStateMachinePtr)
        {
            Orocos::log(Orocos::Error) << "[Statemachine_example::configureHook] StateMachine "
                                          "ExampleStateMachine not found"
                                       << Orocos::endlog();
        }
        else
        {
            Orocos::log(Orocos::Info)
                << "[Statemachine_example::configureHook] The name of the state machine found is : "
                << mStateMachinePtr->getName() << Orocos::endlog();
            // Also log the state of the StateMachine
            Orocos::log(Orocos::Info)
                << "[Statemachine_example::configureHook] The state of the Statemachine is : "
                << mStateMachinePtr->getCurrentStateName() << Orocos::endlog();
        }
    }
    return true;
}

bool Statemachine_example::startHook()
{
    return true;
}

void Statemachine_example::updateHook()
{
    Orocos::log(Orocos::Info)
        << "[Statemachine_example::updateHook] The present Counter value is : " << mCounter.get()
        << Orocos::endlog();
}

void Statemachine_example::stopHook() {}

void Statemachine_example::cleanupHook() {}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Statemachine_example)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Statemachine_example)
