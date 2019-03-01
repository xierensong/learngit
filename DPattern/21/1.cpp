#include<iostream>

using namespace std;

class Receiver
{
    public:
      Receiver() {}
      void Action()
      {
        cout << "exec action in Receiver..." << endl;
      }
};

class Command
{
  public:
    virtual void Execute() = 0;
};

class ConcreteCommand:public Command
{
  private:
    Receiver receiver;
  public:
    ConcreteCommand(Receiver myReceiver):
      receiver(myReceiver) {}
    virtual void Execute()
    {
        cout << "exec command in ConcreteCommand" << endl;
        receiver.Action();
    }
};
int main()
{
  Receiver* receiver = new Receiver();
  Command* command = new ConcreteCommand(*receiver);
  command -> Execute();
  return 0;
}
