# easyFSM

It is a simply library to help you set a FSM. It is programed by C++.

## Instruction

You can directly include easyFSM.h in your project.

```c++
#include "easyFSM.h"
```

The easyFSM is designed as a simple FSM library. Before you instantiated `easyFSM` ，you should creat two enums, one is for state and another is for event.

```c++
// List all the states and events of your FSM 
enum State
{
    state1 = 0,
    ....,
};
enum Event
{
	event1 = 0,
    ...,
};
```

Then you can use `State` and `Event` to create the `easyFSM` , and remember to init `easyFSM` with the start state.

```c++
// you can create a FSM with easyFSM easily
// State and Event are enums, the State1 is the statr state of FSM
easyFSM<State, Event> FSM(State1)
```

So far, you have instantiate a `easyFSM`, then we are going to bind actions with FSM. In easyFSM, you need to define your action functions by yourself. After you defined action functions, you can use `bind()` to bind your function with states and events.

```c++
// declaration
void bind(S curState, S nextState, E events, void(*action)());
// for example
void action(){...}
enum State{...};
enum Event{...};
...
FSM.bind(curState, nextState, event, action);
```

After you bound state, event and function,  you can use `handleEBent()` to send events to change the state of FSM.

```c++
FSM.handleEvent(event);
```

By the way, you can use member function `CurState()` to check the current state.

```c++
FSM.CurState();
```

## Test

You can git clone my code and run on your computer.

```shell
# git clone
git clone https://github.com/ChrisZ-NJU/easyFSM.git
# cd easyFSM
cd easyFSM
# use makefile to help you test
make | ./easyFSM
# or
make test
# you can also use makefile to clean
make clean
```

