#include<iostream>
using namespace std;

class Abase //基类，普通类和装饰器类的共同基类
{
  public:
  virtual void method() = 0; //纯虚函数
  virtual ~Abase() {}; 
};

class Decorator : public Abase  //装饰器类，继承基类
{
private:
  Abase* pA;  // 特殊点，成员变量指向基类的指针
public:
  Decorator(Abase* my_pA):pA(my_pA) {}  // 构造函数用基类来初始化

  virtual void method()  // 将本类的方法重载成本类的成员变量的方法
  {
    pA -> method();
  }
};
class tuDecorator : public Decorator    //装饰器子类，继承装饰器
{
private:
  void decorate()  //装饰器特有的装饰动作
  {
    cout << "decorate ddd" << endl;
  }
public:
  tuDecorator(Abase* my_pA):Decorator(my_pA) {}  //构造函数用装饰器类来初始化
  
  virtual void method()  //重载基类函数
  {
    decorate();  //执行装饰功能
    Decorator::method();  //调用实际功能
    decorate(); //执行装饰功能
  }
};

class B : public Abase  // 主体类，装饰器的作用就是将主体的方法进行装饰
{
  public:
  virtual void method()  //待装饰的方法
  {
    cout << "B ..." << endl; 
  }
};

int main()
{
  Abase* pA = new B();
  pA -> method();
  Abase* pB = new tuDecorator(new B());
  pB -> method();
}
