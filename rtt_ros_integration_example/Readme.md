### RTT ros integration

This example is a straight up copy of the example found [here](https://github.com/jhu-lcsr/rtt_ros_examples). 

Install `rtt_ros_integration` using the instructions [here](https://github.com/orocos/rtt_ros_integration) and install it to `/opt/ros/melodic` or extend the workspace to your workspace.

Build using `catkin_make` and run using `roslaunch rtt_ros_integration_example example.launch` you might wonder that nothing is happening. But if you open another terminal and run `rostopic list` then you will find that the same topics `float_in` `float_out` and `string_in` and `string_out` are displayed in the list. You can also publish on the topic  `float_in` and get an output on `float_out` topic.

> Note : Don't forget to start roscore before launching the example.

