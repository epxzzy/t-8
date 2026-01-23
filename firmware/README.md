![alt text](./floworsum.png)

### submodules:  
small&single purpose hardware workers (GPIO scan, encoder read, display flush, network RX, etc.).

`init()`
`start()`
`tick()`
`stop()`
`emit(event)`

## submanager:  
owns and schedules submodules. centralizes lifecycle and ticking.

`register(submodule)`
`init_all()`
`start(id)` / `stop(id)`
`tick_all()`
`handleModEvent(event)`
`emit(event)`

# subsystem:  
aggregates submodules, emits raw events upward, executes draw/output intents downward.

`init()`
`tick()`
`handleInternalEvent(event)`
`handleExternalEvent(event)`


## systemcontroller:  
policy + routing layer. interprets events, decides active toolrunner, performs transitions.

`handleRunnerEvent(event)`
`emit(event)`
`transition(toolrunner)`

### toolrunner:  
execution context/sandbox. owns lifecycle of the tool and mediates interaction with the system. pretty much a condom.

`enter()`
`tick()`
`exit()`
`handleToolEvent(event)`
`emit(event)`

### tool:  
apps, freedom of logic and state.

`enter()`
`tick()`
`exit()`
`handleEvent(event)`
`emit(drawintent OR event)`



### Notes: 
events float up, policies sink down. events are stimuli while policies are responses.   
any layer can emit events and any layer above that can inforce policies, only exception being `tool/submodule` and `subsystem`.  

subsystem ticks everything. it can be considered the heart.

i am NOT writing a GOD DAMNED KERNEL.





