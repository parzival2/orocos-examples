#ifndef OROCOS_SENDER_COMPONENT_HPP
#define OROCOS_SENDER_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Sender : public RTT::TaskContext
{
  public:
    Sender(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();

  private:
    Orocos::OutputPort<double> mOutPort;
    double mStartNumber;
};
#endif
