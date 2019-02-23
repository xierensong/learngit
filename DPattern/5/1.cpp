#include<iostream>

using namespace std;

class Implementor   //桥的一端 实现基类
{
public:
  virtual void OperationImp() = 0;  //虚基类 实现方法
};

class Abstraction   //桥的另一端 抽象基类
{
  protected:
    Implementor* imp;   //抽象类 通过实现类指针指向实现基类
  public:
    Abstraction(Implementor* myImp):imp(myImp) {}   //构造函数
    void Operation()  //将实现具体类方法封装进抽象类的方法中
    {
      imp -> OperationImp();
    }
};

class ConcreteImplementorA: public Implementor  //实现具体类
{
public:
  void OperationImp()
  {
    cout << "Concrete Implementor A Operation Implemention..." << endl;
  }
};

class ConcreteImplementorB: public Implementor  //实现具体类
{
public:
  void OperationImp() 
  {
    cout << "Concrete Implementor B Operation Implemention..." << endl;
  }
};

class RefinedAbstraction: public Abstraction   //抽象具体类
{
  public:
    RefinedAbstraction(Implementor* myImp):Abstraction(myImp){}  //抽象具体类构造函数，利用抽象基类构造具体类
    void method()
    {
      Abstraction::Operation();   //调用实现类的方法
      cout << "Refined Abstraction method..." << endl;  //进行本身的操作
    }
};

int main()
{
    Implementor* implementorA = new ConcreteImplementorA();  //构造具体实现类指针
    Implementor* implementorB = new ConcreteImplementorB();
    //利用具体实现类指针构造具体抽象类对象指针（注：不指向抽象基类，因为基类没有具体抽象类的方法）
    RefinedAbstraction* refinedAbstraction1 = new RefinedAbstraction(implementorA);
    //具体实现类调用方法
    refinedAbstraction1 -> method();
    RefinedAbstraction* refinedAbstraction2 = new RefinedAbstraction(implementorB);
    refinedAbstraction2 -> method(); 
    return 0;
}


