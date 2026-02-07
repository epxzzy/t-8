## directive
there is a directive class that just a glorified data encapsulator,
contains some arbitrary data:

```
DirectiveType Type;
DirectiveScope Scope;
std::string targetName;
const void* data = nullptr;
```

handled by having the supposed reciever class look at the data and figure out which one of its methods to call and what parameters and their order.


