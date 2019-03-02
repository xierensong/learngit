#include<iostream>
#include<cstring>
#include<map>

using namespace std;
class Context;
class VariableExp;

class BooleanExp
{
  public:
    BooleanExp() {}  //只加分号是声明
    virtual ~BooleanExp() {}
    virtual bool Evaluate(Context&) = 0; //纯虚函数需要重载
    virtual BooleanExp* Replace(char*, BooleanExp&) = 0;
    virtual BooleanExp* Copy() const  = 0;
};

class Context
{
  private:
    map<char*, bool> _context;
  public:
    bool Lookup(char* myVal) ;
    void Assign(char* myVal, bool myBool);
    void show();
};

class VariableExp : public BooleanExp 
{
  private:
    char* _name;
  public:
    VariableExp(char* name)
    {
      _name = name;
    }
    virtual ~VariableExp(){}

    virtual bool Evaluate(Context& aContext)
    {
      cout << "variable evaluate..." << endl;
      return aContext.Lookup(_name);
    }
    virtual BooleanExp* Replace(char* name, BooleanExp& exp)
    {
      if (strcmp(name, _name) == 0)
      {
        return exp.Copy();
      }
      else
      {
        return new VariableExp(_name);
      }
    }
    virtual BooleanExp* Copy() const
    {
      return new VariableExp(_name);
    }
};
bool Context::Lookup(char* myVal) 
{
  cout << "look up:" << myVal << endl;
  return _context[myVal];
}
void Context::Assign(char* myVal, bool myBool)
{
  _context[myVal] = myBool;
}
void Context::show()
{
  for (auto element:_context)
    cout << boolalpha <<  element.first << '\t' << element.second << endl;
}

class AndExp : public BooleanExp
{
  private:
    BooleanExp* _operand1;
    BooleanExp* _operand2;
  public:
    AndExp(BooleanExp* op1, BooleanExp* op2)
    {
      _operand1 = op1;
      _operand2 = op2;
    }
    virtual ~AndExp() {};

    virtual bool Evaluate(Context& aContext)
    {
      cout << boolalpha << _operand1 -> Evaluate(aContext) << endl;
      cout << boolalpha << _operand2 -> Evaluate(aContext) << endl;
      return 
        _operand1 -> Evaluate(aContext) &&
        _operand2 -> Evaluate(aContext);
    }
    virtual BooleanExp* Replace(char* name, BooleanExp& exp)
    {
      return
        new AndExp(
            _operand1 -> Replace(name, exp),
            _operand2 -> Replace(name, exp)
            );
    }
    virtual BooleanExp* Copy() const
    {
      return 
        new AndExp(_operand1->Copy(), _operand2->Copy());
    }
};

int main()
{
  BooleanExp* expression;
  Context context;
  char* t1 = (char*)"X";
  char* t2 = (char*)"Y"; //常量转换成非常量
  VariableExp* x = new VariableExp(t1);
  VariableExp* y = new VariableExp(t2);
  /*
  expression = new AndExp(
      new AndExp(y,x),
      new AndExp(y,x)
      );
  */
  expression = new AndExp(y,y);

  context.Assign(t1, false);
  context.Assign(t2, false);
  context.show();
  bool result = expression-> Evaluate(context);

  cout << boolalpha << "the result:" << result << endl;
  return 0;
}
