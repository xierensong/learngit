#include<iostream>

using namespace std;

class Strategy   //策略基类
{
public:
    virtual void method() = 0;  //待子类实现的虚策略
    virtual ~Strategy(){}; //基类加虚析构函数
};

class A : public Strategy   //策略1
{
public:
  virtual void method ()  //重载基类策略
  {
    cout << "A..." << endl;
  }
};

class B : public Strategy 
{
public:
  virtual void method ()  //重载基类策略
  {
    cout << "B..." << endl;
  }
};

class M  //使用策略的类
{
private:
    Strategy* strategy;  // 需要指定策略基类变量
public:
    M(Strategy* strategy)   // 使用类初始化策略基类变量,选择不同的基线策略初始化就选择了不同的策略
    {
      this -> strategy = strategy;
    }
    ~M()   // 析构函数
    {
      delete this -> strategy;  // 析构函数释放策略基类变量指针
    }
    void run()
    {
        cout << "M..." << endl;
        strategy -> method();   // 调用基类虚函数，实现多态，多策略调度
    }
};

int main()
{
   Strategy * pa = new B();   //定义策略基类指针，用策略基类的子类初始化基类指针，不同的子类决定了不同的策略
   M* pm = new M(pa);  // 基类指针初始化使用类对象
   pm -> run();  // 调用使用函数，实现不同策略切换
  return 0;
}
