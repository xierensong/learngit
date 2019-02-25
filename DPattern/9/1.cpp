#include<iostream>

using namespace std;

class Prototype
{
  public:
    virtual Prototype* Clone() = 0;
    virtual void print() = 0;
};

class ConcretePrototype1:public Prototype
{
  private:
    int value;
  public:
    ConcretePrototype1(int myValue):value(myValue){}
    ConcretePrototype1(const ConcretePrototype1& other)
    {
      value = other.value;
    }
    virtual Prototype* Clone()
    {
      return new ConcretePrototype1(*this);
    }
    virtual void print()
    {
      cout << "value:" << value << endl;
    }
};

class ConcretePrototype2:public Prototype
{
  private:
    int number;
  public:
    ConcretePrototype2(int myNumber):number(myNumber){}
    ConcretePrototype2(const ConcretePrototype2& other)
    {
      number = other.number;
    }
    virtual Prototype* Clone()
    {
      return new ConcretePrototype2(*this);
    }
    virtual void print()
    {
      cout << "number:" << number << endl;
    }
};

class Client
{
  private:
    Prototype* prototype;
  public:
    Client(Prototype* myPrototype): prototype(myPrototype) {}    
    void Operation()
    {
      prototype = prototype->Clone();
      prototype -> print();
    }
};

int main()
{
  int value = 100;
  ConcretePrototype1* concretePrototype1 = new ConcretePrototype1(value);
  Client* client = new Client(concretePrototype1);
  client -> Operation();
  int number = 1000;
  ConcretePrototype2* concretePrototype2 = new ConcretePrototype2(number);
  Client* client1 = new Client(concretePrototype2);
  client1 -> Operation();
  return 0;
}
