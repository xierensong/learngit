#include<iostream>

using namespace std;

class A
{
public:
  void run() //模板方法的函数
  {
    step1();  //父类不实现，由子类实现,运行时绑定
    step2();  //父类不实现，由子类实现，运行时绑定
    step3();  //调用父类的方法
  }
  virtual ~A(){}
protected:
  virtual void step1() = 0; //纯虚函数
  virtual void step2() = 0; //纯虚函数
  void step3() //稳定方法
  {
    cout << "(A)step3..." << endl;
  }
};
