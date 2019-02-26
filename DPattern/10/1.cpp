#include<iostream>

using namespace std;

class Singleton
{
  private:
    static Singleton* uniqueInstance;
    int singletonData;
  protected:
    Singleton(int mySingletonData):singletonData(mySingletonData){};
  public:
    static Singleton* Instance(int mySingleData)
    {
      if (uniqueInstance == nullptr)
      {
        uniqueInstance = new Singleton(mySingleData);
      } 
      return uniqueInstance;
    }
    void SingletonOperation()
    {
      cout << "exec singleton operation..." << endl;
    }

    int GetSingletonData()
    {
      return this -> singletonData;
    }
};

Singleton* Singleton::uniqueInstance = nullptr;

int main()
{
    int i = 10;
    Singleton* singleton = Singleton::Instance(i);  
    singleton -> SingletonOperation();
    cout << singleton -> GetSingletonData() << endl;
    i = 12;
    Singleton* singleton1 = Singleton::Instance(i);
    singleton1 -> SingletonOperation();
    cout << singleton1 -> GetSingletonData() << endl;
    return 0;
}
