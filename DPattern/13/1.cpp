#include<iostream>

using namespace std;

class Subject
{
  public:
    virtual void Request(int a) = 0;
};

class RealSubject : public Subject
{
  public:
    void Request(int a)
    {
      cout << "do real operation..." << a <<  endl;
    }
};

class Proxy : public Subject
{
  public:
    void Request(int a)
    {
      cout << "proxy do something.." << endl;
      RealSubject* realSubject = new RealSubject();
      realSubject -> Request(a);
      cout << " proxy do something else.." << endl;
    }
};


int main()
{
  int value = 10;
  cout << "no proxy:" << endl;
  Subject* subject0 = new RealSubject();
  subject0 -> Request(value);
  cout << "with proxy:" << endl;
  Subject* subject1 = new Proxy();
  subject1 -> Request(value);
  return 0;
}
