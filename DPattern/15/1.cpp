#include<iostream>

using namespace std;
class Colleague;  //前向声明 但它不完整
class Mediator
{ 
  public:
    virtual void changed(Colleague* colleague) = 0;
  protected:
    virtual void CreateColleagues() = 0;
};
class Colleague
{
  private:
    Mediator* mediator;
  public:
    Colleague(Mediator* myMediator):mediator(myMediator){};
    virtual void notify() 
    {   
      mediator -> changed(this);
    }   
};

class ConcreteColleague1:public Colleague
{
  public:
    ConcreteColleague1(Mediator* myMediator):Colleague(myMediator){} //子类初始化时，带上父类的初始化方法
    void operation()
    {
      cout << "concrete colleague 1 is working..." << endl;
      notify(); 
    }
    void method1()
    {
      cout << "colleage 1 special action..triggered by colleage 3" << endl;
    }
};

class ConcreteColleague2:public Colleague
{
  public:
    ConcreteColleague2(Mediator* myMediator):Colleague(myMediator){}
    void operation()
    {
      cout << "concrete colleague 2 is working..." << endl;
      notify();
    }
    void method2()
    {
      cout << "colleague 2 special action.. triggerd by colleague 1" << endl;
    }

};
class ConcreteColleague3:public Colleague
{
  public:
    ConcreteColleague3(Mediator* myMediator):Colleague(myMediator){}
    void operation()
    {
      cout << "concrete colleague 3 is working..." << endl;
      notify();
    }
    void method3()
    {
      cout << "colleague 3 special action.. triggerd by colleague 2" << endl;
    }
};

class ConcreteMediator: public Mediator
{ 
  private:
    ConcreteColleague1* myColleague1;
    ConcreteColleague2* myColleague2;
    ConcreteColleague3* myColleague3;
  public:
    virtual void changed(Colleague* colleague)
    {   
        if (colleague == myColleague1)
            myColleague2 -> method2();
        else if (colleague == myColleague2)
            myColleague3 -> method3();
        else if (colleague == myColleague3)
            myColleague1 -> method1();
    }
	ConcreteColleague1* getColleague1()
	{
		return this -> myColleague1;
	}

    ConcreteColleague2* getColleague2()
    {   
        return this -> myColleague2;
    }

    ConcreteColleague3* getColleague3()
    {   
        return this -> myColleague3;
    }
	
    virtual void CreateColleagues()
    {   
        myColleague1 = new ConcreteColleague1(this);
        myColleague2 = new ConcreteColleague2(this);
        myColleague3 = new ConcreteColleague3(this);
    }
};

int main()
{
    ConcreteMediator * mediator = new ConcreteMediator();
    ConcreteColleague1* concreteColleague1;
    ConcreteColleague2* concreteColleague2;
    ConcreteColleague3* concreteColleague3;
    mediator -> CreateColleagues();
	concreteColleague1 = mediator -> getColleague1(); //由中介来创建具体同事类
    concreteColleague2 = mediator -> getColleague2(); //由中介来创建具体同事类
	concreteColleague3 = mediator -> getColleague3(); //由中介来创建具体同事类

    concreteColleague1 -> operation();
    concreteColleague2 -> operation();
    concreteColleague3 -> operation();
    return 0; 
}
