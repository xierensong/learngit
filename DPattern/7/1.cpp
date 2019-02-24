#include<iostream>

using namespace std;

class AbstractProductA
{
  public:
   virtual void print() = 0; 
};

class ProductA1: public AbstractProductA
{
  public:
    virtual void print()
    {
      cout << "Product A1..." << endl;
    }
};

class ProductA2: public AbstractProductA
{
  public:
    virtual void print()
    {
      cout << "Product A2..." << endl;
    }
};

class AbstractProductB
{
  public:
    virtual void show() = 0;
};

class ProductB1: public AbstractProductB
{
  public:
    virtual void show()
    {
        cout << "Proudct B1..." << endl;
    }
};

class ProductB2: public AbstractProductB
{
  public:
    virtual void show()
    {
      cout << "Product B2..." << endl;
    }
};

class AbstractFactory
{
  public:
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1: public AbstractFactory
{
  public:
    virtual AbstractProductA* CreateProductA()
    {
      return new ProductA1();
    }
    virtual AbstractProductB* CreateProductB()
    {
      return new ProductB1();
    }
};

class ConcreteFactory2: public AbstractFactory
{
  public:
    virtual AbstractProductA* CreateProductA()
    {
      return new ProductA2();
    }
    virtual AbstractProductB* CreateProductB()
    {
      return new ProductB2();
    }

};

class Client
{
  private:
    AbstractFactory* abstractFactory;
  public:
    Client(AbstractFactory* myAbstractFactory):abstractFactory(myAbstractFactory){}
    void exec() 
    {
        AbstractProductA* abstractProductA = abstractFactory -> CreateProductA();
        abstractProductA -> print();
        AbstractProductB* abstractProductB = abstractFactory -> CreateProductB();
        abstractProductB -> show();
    }
};

int main()
{
  ConcreteFactory1* concreteFactory1 = new ConcreteFactory1();
  Client* client = new Client(concreteFactory1);
  client -> exec();
  ConcreteFactory2* concreteFactory2 = new ConcreteFactory2();
  Client* client1 = new Client(concreteFactory2);
  client1 -> exec();
}
