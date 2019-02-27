#include<iostream>

using namespace std;

class Worker
{
  private:
    string name;
  public:
    Worker(string myName):name(myName){};
};
class Product
{
  private:
    int value;
  public:
    Product():value(0){};
    Product(int myValue):value(myValue){};
    void setProduct(int myValue)
    {
      this -> value = myValue;
    }
    int getProduct()
    {
      return value;
    }
};
class Work
{
  public:
    void working(Worker& myWorker, Product& myProduct)
    {
        myProduct.setProduct(10);
    }
};

class Sell
{
  public:
    void selling(Product& myProduct, int& day)
    {
      cout << "selling for " << day << endl;
    }
};

class Compiler
{
  public:
   void compile(Worker& myWorker, int& day)
   {
     Product* myProduct = new Product();
     cout << "the initial value:" << myProduct -> getProduct() << endl;
     Work* work = new Work();
     work -> working(myWorker, *myProduct);
     cout << "ther current value:" << myProduct -> getProduct()  << endl;
     Sell* sell = new Sell();
     day = 100;
     sell -> selling(*myProduct,day);
   }
};
int main()
{
  string myName = "XXX";
  Worker* myWorker = new Worker(myName);
  int day;
  Compiler* compiler = new Compiler();
  compiler -> compile(*myWorker, day);
  return 0;
}
