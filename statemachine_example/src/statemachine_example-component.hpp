#ifndef OROCOS_STATEMACHINE_EXAMPLE_COMPONENT_HPP
#define OROCOS_STATEMACHINE_EXAMPLE_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/TaskContext.hpp>
#include <rtt/scripting/ScriptingService.hpp>
#include <rtt/scripting/StateMachine.hpp>

class Statemachine_example : public RTT::TaskContext
{
  public:
    Statemachine_example(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();

  private:
    Orocos::Attribute<int> mCounter;
};
#endif
