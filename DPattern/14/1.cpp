#include<iostream>

using namespace std;

class Target
{
  public:
    virtual void Request() = 0;  //新的没有参数
};

class Adaptee
{
  public:
    void SpecificRequest(int a)  // 旧的有参数
    {
      cout << "old request processing..." << endl;
    }
};

class Adapter:public Target
{
  private:
    Adaptee* adaptee;
  public:
    Adapter(Adaptee* myAdaptee):adaptee(myAdaptee){}
    virtual void Request()  //适配器重载，将有参加一个默认参数适配成无参
    {
      cout << "adapt..." << endl;
      int a = 0;
      adaptee -> SpecificRequest(a);
      cout << "add some description... " << endl;
    }
};
int main()
{
    Adaptee* adaptee = new Adaptee();
    Adapter* adapter = new Adapter(adaptee);
    adapter -> Request(); 
    return 0;
}
