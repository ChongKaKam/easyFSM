#include <iostream>
#include "easyFSM.h"

using std::cout;
using std::endl;
using std::cin; 

// define state and event
enum State
{
    state1 = 1,
    state2,
    state3,
};
enum Event
{
    E1to1 = 1,
    E1to2,
    E1to3,
    E2to1,
    E2to2,
    E2to3,
    E3to1,
    E3to2,
    E3to3
};

// function to test state transfer
void Func_1(){cout << "Current state is 1" << endl;}
void Func_2(){cout << "Current state is 2" << endl;}
void Func_3(){cout << "Current state is 3" << endl;}

// main 
int main()
{
    // create new FSM and init state
    easyFSM<State,Event> FSM(state1);
    // bind function to FSM
    FSM.bind(state1, state1, E1to1, Func_1);
    FSM.bind(state1, state2, E1to2, Func_2);
    FSM.bind(state1, state3, E1to3, Func_3);
    FSM.bind(state2, state1, E2to1, Func_1);
    FSM.bind(state2, state2, E2to2, Func_2);
    FSM.bind(state2, state3, E2to3, Func_3);
    FSM.bind(state3, state1, E3to1, Func_1);
    FSM.bind(state3, state2, E3to2, Func_2);
    FSM.bind(state3, state3, E3to3, Func_3);
    // start test
    cout << "start testing..." << endl; 
    // print current state
    cout << "Current state is " << FSM.CurState() << endl;
    // 1-->3-->1-->2-->3-->2-->1
    cout << "1-->3" << endl;
    FSM.handleEvent(E1to3);
    cout << "3-->1" << endl;
    FSM.handleEvent(E3to1);
    cout << "1-->2" << endl;
    FSM.handleEvent(E1to2);
    cout << "2-->3" << endl;
    FSM.handleEvent(E2to3);
    cout << "3-->2" << endl;
    FSM.handleEvent(E3to2);
    cout << "2-->1" << endl;
    FSM.handleEvent(E2to1);
    // end test
    cout << "end test" << endl;
    return 0;
}
