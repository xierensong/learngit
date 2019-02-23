#include<iostream>

using namespace std;

class Product  //工厂方法创建的对象接口,
{
  public:
   virtual void createProduct()
   {
     cout << "base product..." << endl;
   }
};

class ConcreteProduct: public Product //实现Product接口
{
  public:
    virtual void createProduct()
    {
      cout << "concrete product... " << endl;
    }
};

class Creator  //工厂方法的类
{
  public:
    virtual Product* FactoryMethod()  //工厂方法名，返回Product类的对象
    {
        return new Product();  //定义缺省实现
    }

    void AnOperation()  //可以调用工厂方法创建一个Product对象
    {
      cout << "An operation... " << endl;
      Product* product = FactoryMethod();  //调用工厂方法
      product -> createProduct(); //验证创建的是那个类
    }
};

class ConcreteCreator:public Creator  //工厂方法的具体类
{
  public:
    virtual Product* FactoryMethod()  //重定义工厂方法
    {
        return new ConcreteProduct();  //返回一个ConcreteProduct实例
    } 
};

int main()
{
  Creator* creator = new Creator(); //创建一个工厂方法类
  creator -> AnOperation(); //调用缺省的工厂方法完成操作
  ConcreteCreator* concreteCreator = new ConcreteCreator(); //创建一个具体的工厂方法类
  concreteCreator -> AnOperation(); //调用具体的工厂方法完成操作,和缺省的工厂方法调用的方法是一个
  return 0;
}
