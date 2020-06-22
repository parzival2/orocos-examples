#include "receiver-component.hpp"
#include <iostream>
#include <rtt/Component.hpp>

Receiver::Receiver(std::string const& name)
    : TaskContext(name)
    , mInputPort("receiverIn")
    , mEventPort()
{
    this->ports()
        ->addPort(mInputPort)
        .doc("The inputport of receiver that receives the double from sender.");
    this->ports()->addEventPort("receiverEv", mEventPort).doc("Input port that raises an event.");
}

bool Receiver::configureHook()
{
    Orocos::log(Orocos::Info) << "[Receiver::configureHook] Configurehook has been called"
                              << Orocos::endlog();
    return true;
}

bool Receiver::startHook()
{
    Orocos::log(Orocos::Info) << "[Receiver::startHook] startHook has been called"
                              << Orocos::endlog();
    return true;
}

void Receiver::updateHook()
{
    Orocos::log(Orocos::Info) << "[Receiver::updateHook] updateHook has been called"
                              << Orocos::endlog();
    double inputValue = 0.;
    if(mInputPort.read(inputValue))
    {
        Orocos::log(Orocos::Info) << "[Receiver::updateHook] Received new data on the inputport"
                                  << Orocos::endlog();
        Orocos::log(Orocos::Info) << "[Receiver::updateHook] Received value : " << inputValue
                                  << Orocos::endlog();
    }
}

void Receiver::stopHook()
{
    Orocos::log(Orocos::Info) << "[Receiver::stopHook] stopHook has been called"
                              << Orocos::endlog();
}

void Receiver::cleanupHook()
{
    Orocos::log(Orocos::Info) << "[Receiver::cleanupHook] cleanupHook has been called"
                              << Orocos::endlog();
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Receiver)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Receiver)
