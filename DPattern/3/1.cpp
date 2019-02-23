#include<iostream>
#include<list>

using namespace std;

class Observer  // 观察者基类
{
  public:
    virtual void update() = 0;  // 只包含对观察者中被观察对象的状态的更新操作
};

class Subject  // 主体基类，被观察的对象,包含对观察者类的绑定，解绑定，通知操作
{
  private:
    list<Observer*> Observers;  //拥有所有观察者的指针列表
  protected:
    Subject(){};  //默认构造函数
  public:
    virtual ~Subject(){};  //默认析构函数，必须有
    virtual void Attach(Observer* observer)  //绑定一个观察者类
    {
      Observers.push_back(observer);
    }

    virtual void Detach(Observer* observer)  //解绑定一个观察者类
    {
      Observers.remove(observer);
    }
    virtual void notify()  // 通知所有的观察者更新状态值。
    {
      for( list<Observer*>::iterator it = Observers.begin(); it != Observers.end(); it ++)
        (*it) -> update();
    }
};


class ConcreteSubject:public Subject  // 具体主体类，继承主体基类
{
  private:
    int subjectState;  //具体主题类的状态
  public:
    ConcreteSubject(int mySubState):subjectState(mySubState) {}  //构造函数
    int GetState()  //查看状态
    {
      return this -> subjectState;
    }
    void SetState(int newState) //设置状态
    {
       this -> subjectState = newState; 
       Subject::notify();  //调用基线通知方法通知所有观察者,屏蔽了所有观察者操作。
    }
};

class ConcreteObserver:public Observer // 具体观察者类，继承观察者基类
{
  private:
    int observerState;  //观察者当前状态
    ConcreteSubject* concreteSubject; //被观察对象
  public:
    ConcreteObserver(ConcreteSubject* mySubject)  //构造函数，每个观察者必须有一个被观察的主体
    {
      concreteSubject = mySubject;
      concreteSubject -> Attach(this); //构造时，为被观察的主题绑定自己。重点圈圈
    }
    ~ConcreteObserver()  //析构函数，解绑定自己。
    {
      concreteSubject -> Detach(this);//析构时，为被观察的主题解绑定自己
    }
    virtual void update()  // 观察者更新自己，一般通过具体主体类的notify方法类调用，将主体类的状态更新到观察者自己身上来
    {
      observerState = concreteSubject -> GetState();
      cout << "ConcreteObserver's state is " << observerState << endl;
      cout << "updated!" << endl; 
    }
};

int main()
{
  ConcreteSubject* concreteSubject = new ConcreteSubject(0); //生成一个具体主题类
  Observer* myObserver = new ConcreteObserver(concreteSubject);//用具体主体类初始化一个具体观察者。
  concreteSubject -> SetState(5); //对具体主体设置状态，将自动通知到观察者类。
  return 0;
}
