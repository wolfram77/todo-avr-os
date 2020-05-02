nitros
======

A simple, easy to use OS for AVR microcontrollers.



### Design requirements

1.  Minimal simple, and yet a relatively strong OS concept

2.  Try to minimize RAM overhead (Flash overhead is a non-issue)

3.  Try proper event handling, and fast execution.

4.  Support driver installation and removal.

5.  Yet to explore.

Non-preemptive task switching is probably a simple concept, and has relatively
low overhead. It helps removes some randomness is execution, which might be a
necessary evil in certain types of embedded systems.



### Events

1.  Could be Simple

2.  Easy to implement.

3.  Similar to interrupt.



### Tasks

1.  Foreground tasks.

2.  Non-preemtive.

3.  Require Synchronization



### Named Object

1.  Reduce module to module dependency

2.  Uses a hashing technique.






