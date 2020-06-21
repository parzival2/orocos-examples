#include "HelloWorld-component.hpp"
#include <rtt/Component.hpp>

/**
 * @brief HelloWorld::HelloWorld This function will be called when
 * loadComponent("hello", "HelloWorld")
 * is caleld in the ops file.
 * @param name
 */
HelloWorld::HelloWorld(std::string const& name)
    : TaskContext(name)
{
    Orocos::log(Orocos::Info) << "Initialization of HelloWorld" << Orocos::endlog();
}

bool HelloWorld::configureHook()
{
    Orocos::log(Orocos::Info) << "HelloWorld Configure hook called" << Orocos::endlog();
    return true;
}

bool HelloWorld::startHook()
{
    Orocos::log(Orocos::Info) << "HelloWorld started !" << Orocos::endlog();
    return true;
}

/**
 * @brief HelloWorld::updateHook The updateHook will be called depending on the period that we have
 * decided on the ops or xml file.
 * If the period is zero or not set in the ops, then the task will be considered as a non-periodic
 * task.
 */
void HelloWorld::updateHook()
{
    Orocos::log(Orocos::Info) << "HelloWorld executes updateHook !" << Orocos::endlog();
}

void HelloWorld::stopHook()
{
    Orocos::log(Orocos::Info) << "HelloWorld executes stopping !" << Orocos::endlog();
}

void HelloWorld::cleanupHook()
{
    Orocos::log(Orocos::Info) << "HelloWorld cleaning up !" << Orocos::endlog();
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(HelloWorld)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(HelloWorld)
