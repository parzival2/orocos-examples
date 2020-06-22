#include "sender-component.hpp"
#include <rtt/Component.hpp>

Sender::Sender(std::string const& name)
    : TaskContext(name)
    , mOutPort("senderOut", 0.0)
    , mStartNumber(0.)
{
    // Directly set the period.
    this->setPeriod(0.1);
    // Add the ports that we have added
    this->ports()->addPort(mOutPort).doc("Sender ouputport that sends the double out.");
}

bool Sender::configureHook()
{
    Orocos::log(Orocos::Info) << "[Sender::configureHook] Configurehook has been called"
                              << Orocos::endlog();
    return true;
}

bool Sender::startHook()
{
    Orocos::log(Orocos::Info) << "[Sender::startHook] startHook has been called"
                              << Orocos::endlog();
    return true;
}

void Sender::updateHook()
{
    Orocos::log(Orocos::Info) << "[Sender::updateHook] updateHook has been called, increasing the "
                                 "start number and writing to output port."
                              << Orocos::endlog();
    mStartNumber += 0.1;
    mOutPort.write(mStartNumber);
}

void Sender::stopHook()
{
    Orocos::log(Orocos::Info) << "[Sender::stopHook] stopHook has been called" << Orocos::endlog();
}

void Sender::cleanupHook()
{
    Orocos::log(Orocos::Info) << "[Sender::cleanUpHook] cleanUpHook has been called"
                              << Orocos::endlog();
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Sender)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Sender)
