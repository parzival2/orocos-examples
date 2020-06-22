### Receiver

As the name itself suggests, it receives a value sent by sender. The receiver will have an input port and input event defined which will be call `updateHook` method when ever a message comes on input port. Take a look at [receiver_sender_start.ops](../receiver_sender_start.ops) file for further information on how to connect ports and events.

The receiver will have an event port that will wake the thread when ever a value is received on it. 

> Note: `0.360 [ Warning][Thread] Lowering scheduler type to SCHED_OTHER for non-privileged users..
> 0.360 [ Warning][Thread] Forcing priority (50) of thread with SCHED_OTHER policy to 0.
> 0.361 [ Warning][Thread] Lowering scheduler type to SCHED_OTHER for non-privileged users..Lowering scheduler type to SCHED_OTHER for non-privileged users..`
>
> If you get messages like defined above, then the real-time priority for the specific user has not been set and has to be set in `/etc/security/limits.conf` in linux
>
> Add the line as described in the examples of that file `user    hard    rtprio   99` and reboot.
>
> If after rebooting, if you still have the same messages, then the real-time priority can be set by `uname -r 99` and the current priority can be checked using `uname -r`.