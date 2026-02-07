## directive
there is a directive class that just a glorified data encapsulator,
contains some arbitrary data:

```
DirectiveType Type;
DirectiveScope Scope;
std::string targetName;
DataPacket data;
```

handled by having the supposed reciever class look at the data and figure
out which one of its methods to call and what parameters and their order.

datapacket itself will be a class later down the line holding a bunch of optional fields

IDirectiveNode is just a helper class/dispatch table/interface for 
directives, it allows for automated method calling pipelines by using
directives. when a directive is recieved by this class (via handle
(Directive&)) it first check if the class can even handle this directive,
if not then it just sinks it down(which has to be defined in the usage 
class) but if it can it just figures out which method to call (with the
right parameters, which is defined by registerHandler(DirectiveType, 
lambda function))