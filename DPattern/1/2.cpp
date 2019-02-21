#include<iostream>
#include"1.cpp"

using namespace std;

class B:public A  //B is a A
{
  protected:  //重载函数设置为只有子类可以访问
    virtual void step2()  //重载父类的同名函数
    {
      cout << "(B)step2..." << endl;
    }    

    virtual void step1()   //重载父类的同名函数
    {
      cout << "(B)step1..." << endl;
    }
};
int main()
{
    A* a= new B(); //子类的对象赋给父类的实例
    a -> run();  //父类的实例指向父类的模板函数,模板函数调用子类的重载方法。
    delete a;  //调用父类的析构函数
    return 0;
}
