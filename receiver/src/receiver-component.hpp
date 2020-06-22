#ifndef OROCOS_RECEIVER_COMPONENT_HPP
#define OROCOS_RECEIVER_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Receiver : public RTT::TaskContext
{
  public:
    Receiver(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();

  private:
    Orocos::InputPort<double> mInputPort;

    Orocos::InputPort<double> mEventPort;
};
#endif
