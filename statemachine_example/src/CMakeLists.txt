
#
# Components, types and plugins.
#
# The CMake 'target' names are identical to the first argument of the
# macros below, except for orocos_typegen_headers, where the target is fully
# controlled by generated code of 'typegen'.
#

# Creates a component library libstatemachine_example-<target>.so
# and installs in the directory lib/orocos/statemachine_example/
#
orocos_component(statemachine_example statemachine_example-component.hpp statemachine_example-component.cpp) # ...you may add multiple source files
#
# You may add multiple orocos_component statements.

target_link_libraries(statemachine_example ${OROCOS-RTT_RTT-SCRIPTING_LIBRARY})

#
# Additional headers:
#
# Installs in the include/orocos/statemachine_example/ directory
#
orocos_install_headers(statemachine_example-component.hpp) # ...you may add multiple header files
#
# You may add multiple orocos_install_headers statements.

