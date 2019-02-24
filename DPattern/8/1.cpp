#include<iostream>

using namespace std;

class Product
{
  private:
    int value;
  public:
    Product(int myVal):value(myVal){}
    void show()
    {
      cout << "value: " << value << endl;
    }    
};

class Builder
{
  public:
    virtual void BuildPart() = 0;
};

class ConcreteBuilder: public Builder
{
  private:
    Product* product;
  public:
    void BuildPart()
    {
      product = new Product(10); 
    }
    Product* GetResult()
    {
      return this -> product;
    }
    void show()
    {
        this -> product -> show();
    } 
};

class Director
{
  private:
    Builder* builder;
  public:
    Director(Builder* myBuilder):builder(myBuilder){}
    void Construct()
    {
        builder -> BuildPart();
    }
};

int main()
{
  ConcreteBuilder* concreteBuilder = new ConcreteBuilder();
  Director* director = new Director(concreteBuilder);
  director -> Construct();
  Product* product = concreteBuilder -> GetResult();
  product -> show();
  return 0;
}
