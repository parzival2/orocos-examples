### Statemachine Example

An example that explains how to work with state machines in Orocos rtt. 

In this example, the state machine transitions to two states based on the counter value. The state machine changes state after counting to 10 and starts counting from initial value after reaching a value of 30. It can be clearly seen in the [statemachine_.osd](statemachine_.osd) how the transitions in between the states are performed.

The state machine can be accessed in the `TaskContext` by using 

```c++
RTT::scripting::ScriptingService::shared_ptr mScriptingSerive =
        boost::dynamic_pointer_cast<Orocos::scripting::ScriptingService>(
            this->provides()->getService("scripting"));
```

casting the pointer to `ScriptingService`. The state machine can be accessed using 

```c++
Orocos::scripting::StateMachinePtr mStateMachinePtr =
            mScriptingSerive->getStateMachine("ExampleStateMachine");
```

In-order to compile the component, a line has to be added in `CMakeLists.txt` 

`target_link_libraries(statemachine_example ${OROCOS-RTT_RTT-SCRIPTING_LIBRARY})`

In `deployer` the state machine can be accessed using name and all of its functions using the `.` operator.

`e.g. ExampleStateMachine.getCurrentStateName()`.