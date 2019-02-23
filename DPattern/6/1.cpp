#include<iostream>

using namespace std;

class Product  //工厂方法创建的对象接口
{
  private:
    int value; //对象的属性
  public:
    Product(int myValue) : value(myValue){};
    int getValue()
    {
      return this -> value;
    }
};

class ConcreteProduct: public Product //对象的具体类
{
  public:
  ConcreteProduct(int value):Product(value){};
};

class Creator  //工厂方法的类
{
  public:
    virtual Product* FactoryMethod()
    {
        return new Product(0);
    }

    void AnOperation()
    {
      cout << "An operation... " << endl;
      Product* product = FactoryMethod();
      cout << product -> getValue() << endl;
    }
};

class ConcreteCreator:public Creator
{
  public:
    virtual Product* FactoryMethod()
    {
        return new ConcreteProduct(10);
    } 
};

int main()
{
  Creator* creator = new Creator();
  creator -> AnOperation();
  ConcreteCreator* concreteCreator = new ConcreteCreator();
  concreteCreator -> AnOperation();
  return 0;
}
