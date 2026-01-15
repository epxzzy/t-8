subsystem:  
all hardware stuff, emitting events. draw on screen.
`emit()`

systemcontroller:
listens events and triggers toolrunners.

`handleevent()`
`emit()`

toolrunners:
pick a tool and tick it. basically safety tool wrapper.

`enter()`
`tick()`
`exit()`

tool:
do something functional, listen for subsystem events, emit draw intents

`enter()`
`tick()`
`exit()`
`emit()`
`handleevent()`
