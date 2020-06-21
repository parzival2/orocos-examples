### HelloWorld

A simple example that demonstrates how orocos rtt subsystem functions. This example does nothing and will only print some logs in the orocos logging system.

Build using `catkin_make` in your workspace directory and deploy the component using 

`deployer src/HelloWorld/HelloWorld_start.ops`

and start exploring the deployment system in orocos. More information can be found [here](https://orocos-toolchain.github.io/ocl/toolchain-2.9/xml/orocos-deployment.html)

`cd` into the component using `cd hello` in the deployer. 

`ls` will give the list of functions, properties, inputs and outputs that we can access.

Start the component using the `start` command.

If we set the period using `setPeriod(0.1)` in deployer, then we can see that the `updateHook` will be called at 10 times a second. The log will be printed to `orocos.log` file created in the workspace directory.

Stop the component using the `stop` command.

Clean up the component using the `cleanup` command.

