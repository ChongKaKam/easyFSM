//
//  easyFSM.h
//
//  Created by 庄嘉鑫 on 2022/2/25.
//

#ifndef easyFSM_h
#define easyFSM_h

#include <vector>
#include <iostream>

template<typename S, typename E>
class easyFSM
{
public:
    // constructor
    // easyFSM(){}
    easyFSM(S defState):_curState(defState){}
    // deconstructor
    ~easyFSM(){}
    S CurState(){return _curState;}
    // bind
    void bind(S curState, S nextState, E event, void (*action)())
    {
        _itemList.push_back(*new item(curState, nextState, event, action));
    }
    void handleEvent(E event)
    {
        ACTION_PTR *action = nullptr;
        S nextState;
        bool flag = false;
        for(int i=0; i<_itemList.size(); ++i)
        {
            if(_curState==_itemList[i]._curState && event == _itemList[i]._event)
            {
                flag = true;
                action = _itemList[i]._action;
                nextState = _itemList[i]._nextState;
                break;
            }
        }
        if(flag)
        {
            if(action){action();}
            _curState = nextState;
        }
    }
private:
    typedef void ACTION_PTR(void);
    // item class
    class item
    {
    public:
        item(S curState, S nextState, E event, ACTION_PTR *action):
        _curState(curState),_nextState(nextState),_event(event),_action(action)
        {};
    public:
        S _curState;
        E _event;
        S _nextState;
        ACTION_PTR *_action;
    };
private:
    // private atribution
    typedef std::vector<item> VECITEM;
    S _curState;
    VECITEM _itemList;
    
};

#endif /* easyFSM_h */
