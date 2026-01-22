submodules:  
small&single purpose hardware workers (GPIO scan, encoder read, display flush, network RX, etc.).

`init()`
`start()`
`tick()`
`stop()`
`emit(event)`

submodule manager:  
owns and schedules submodules. centralizes lifecycle and ticking.

`register(submodule)`
`init_all()`
`start(id)` / `stop(id)`
`tick_all()`
`emit(event)`
`handleEvent(event)`

subsystem:  
aggregates submodules, emits raw events upward, executes draw/output intents downward.

`init()`
`tick()`
`emit(event)`
`handleEvent(event)`

systemcontroller:  
policy + routing layer. interprets events, decides active toolrunner, performs transitions.

`handleEvent(event)`
`emit(event)`
`transition(toolrunner)`

toolrunner:  
execution context/sandbox. owns lifecycle of the tool and mediates interaction with the system. pretty much a condom.

`enter()`
`tick()`
`exit()`
`emit(event)`
`handleEvent(event)`

tool:  
apps, freedom of logic and state.

`enter()`
`tick()`
`exit()`
`handleEvent(event)`
`emit(drawintent OR event)`

![alt text](./floworsum.png)