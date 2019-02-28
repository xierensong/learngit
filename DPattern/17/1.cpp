#include<iostream>

using namespace std;

class Memento
{
  private:
   int state;
  public:
   Memento(int myState):state(myState){}
   int GetState()
   {
     return this -> state;
   }
   void SetState(int myState)
   {
     this -> state = myState;
   }
};

class Originator
{
  private:
    int state;
  public:
    Memento* CreateMemento()
    {
      cout << "save state..." << endl;
      Memento* memento = new Memento(state);
     return memento; 
    }
    void SetMemento(Memento* m)
    {
      cout << "restore state..." << endl;
      this -> state = m -> GetState();  
    }
    int GetState()
    {
      return this -> state;
    }
    void SetState(int myState)
    {
      this -> state = myState;
    }
};
int main()
{
  Originator* originator = new Originator();
  cout << "current state:" << originator -> GetState() << endl;
  Memento* memento = originator -> CreateMemento();
  int state = 100;
  originator -> SetState(100);
  cout << "current state:" << originator -> GetState() << endl;
  originator -> SetMemento(memento);
  cout << "current state:" << originator -> GetState() << endl;
  return 0;
}
