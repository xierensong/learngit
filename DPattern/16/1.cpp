#include<iostream>

using namespace std;
class State;
class Context
{ 
  private: 
	friend class State;
    State* state;
  private: 
    void ChangeState(State* myState);
  public:
    Context();
    void stateAOpen();
    void stateBClose();
};
class State
{ 
  protected:
    void ChangeState(Context* myContext, State* myState);
  public:
    virtual void stateAOpen(Context* myContext){}
    virtual void stateBClose(Context* myContext){}
};

class ConcreteStateB : public State
{
  public:
    static State* Instance();

    virtual void stateAOpen(Context* myContext);
};

void Context::ChangeState(State* myState)
{
  state = myState;
}
Context::Context()
{
   state = ConcreteStateB::Instance();
   cout << "Initial state is state B..." << endl;
}
void Context::stateAOpen()
{
  state -> stateAOpen(this);
  cout << "state change to state A..." << endl;
}
void Context::stateBClose()
{
    state -> stateBClose(this);
    cout << "state change to state B..." << endl;
}

void State::ChangeState(Context* myContext, State* myState)
{
  myContext -> ChangeState(myState);
}

class ConcreteStateA : public State
{
  public:
    static State* Instance()
    {
      return new ConcreteStateA();
    }
    virtual void stateBClose(Context* myContext)
    {
      ChangeState(myContext, ConcreteStateB::Instance());
      cout << "next state is state B." << endl;
    }
};

State* ConcreteStateB::Instance()
{
  return new ConcreteStateB();
}
void ConcreteStateB::stateAOpen(Context* myContext)
{
  ChangeState(myContext, ConcreteStateA::Instance());
  cout << "next state is state A." << endl;
}


int main()
{
  State* stateA = ConcreteStateA::Instance();
  State* stateB = ConcreteStateB::Instance();
  Context* context = new Context();
  context -> stateAOpen();
  context -> stateBClose();
  return 0;
}
