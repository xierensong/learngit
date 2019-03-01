#include<iostream>
#include<typeinfo>
#include<string>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
  public:
    virtual void VisitConcreteElementA(ConcreteElementA*){} ;
    virtual void VisitConcreteElementB(ConcreteElementB*){};
};

class ConcreteVistor1 : public Visitor
{
  private:
    string visitResult;
  public:
    void Vistor1Format(ConcreteElementA*,ConcreteElementB*);
    virtual void VisitConcreteElementA(ConcreteElementA*);
    virtual void VisitConcreteElementB(ConcreteElementB*);
    void GetVisitor1Result()
    {
      cout << visitResult << endl;
    }
};
class ConcreteVistor2 : public Visitor
{
  private:
    string visitResult;
  public:
    void Vistor2Format(ConcreteElementA*,ConcreteElementB*);
    virtual void VisitConcreteElementA(ConcreteElementA*);
    virtual void VisitConcreteElementB(ConcreteElementB*);
    void GetVisitor2Result()
    {
      cout << visitResult << endl;
    }
};
class Element
{
  public:
    virtual void Accept(Visitor&){};
};
class ConcreteElementA : public Element
{
  public:
    virtual void Accept(Visitor& v); 
    void OperationA()
    {
      cout << "concrete element a is processing..." << endl;
    }
};

class ConcreteElementB : public Element
{
  public:
    virtual void Accept(Visitor& v);
    void OperationB()
    {
      cout << "concrete element b is processing..." << endl;
    }
};

void ConcreteElementA::Accept(Visitor& v)
{
  v.VisitConcreteElementA(this);
}
void ConcreteElementB::Accept(Visitor& v)
{
  v.VisitConcreteElementB(this);
}
void ConcreteVistor1::Vistor1Format(
    ConcreteElementA* concreteA, ConcreteElementB* concreteB)
{
   VisitConcreteElementA(concreteA); 
   cout << "visitor1 format result." << endl;
   VisitConcreteElementB(concreteB);
}
void ConcreteVistor1::VisitConcreteElementA(ConcreteElementA* concreteA)
{
  concreteA ->  OperationA();
  cout << "visitor1 adding: wwe we we" << endl;
  visitResult = visitResult + typeid(concreteA).name();
}
void ConcreteVistor1::VisitConcreteElementB(ConcreteElementB* concreteB)
{
  concreteB -> OperationB();
  cout << "visitor1 adding: mmo mo mo" << endl;
  visitResult = visitResult + typeid(concreteB).name();
}
void ConcreteVistor2::Vistor2Format(
    ConcreteElementA* concreteA, ConcreteElementB* concreteB)
{
  VisitConcreteElementA(concreteA);
  cout << "visitor2 format result." << endl;
  VisitConcreteElementB(concreteB);
}
void ConcreteVistor2::VisitConcreteElementA(ConcreteElementA* concreteA)
{
  concreteA ->  OperationA();
  cout << "visitor2 adding: wwewewe" << endl;
}
void ConcreteVistor2::VisitConcreteElementB(ConcreteElementB* concreteB)
{
   concreteB -> OperationB();
   cout << "visitor2 adding: mmomomo" << endl;
}

int main()
{
  ConcreteElementA* concreteElementA = new ConcreteElementA();
  concreteElementA -> OperationA();  //没有访问器的原始结果
  cout << "=====" << endl;
  ConcreteElementB* concreteElementB1 = new ConcreteElementB();
  concreteElementB1 -> OperationB();  //没有访问器的原始结果 
  cout << "=====" << endl;
  Element* elementA = concreteElementA;
  Element* elementB1 = concreteElementB1;

  ConcreteVistor1 visitorA;
  elementB1 -> Accept(visitorA);  //访问器变更的结果
  cout << "=====" << endl;
  elementA -> Accept(visitorA);
  cout << "=====" << endl;
  visitorA.GetVisitor1Result(); //访问器的组合结果
   cout << "=====" << endl;

  ConcreteElementB* concreteElementB = new ConcreteElementB();
  concreteElementB -> OperationB();  //没有访问器的原始结果
  cout << "=====" << endl;
  Element* elementB = concreteElementB;

  ConcreteVistor2 visitorB;
  elementB -> Accept(visitorB);  //访问器变更的结果
  cout << "=====" << endl;
  visitorB.GetVisitor2Result(); //访问器的组合结果
   cout << "=====" << endl;
  return 0;
}
