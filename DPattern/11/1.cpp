#include<iostream>
#include<vector>

using namespace std;

class Flyweight
{
  public:
    virtual void Operation(int extrinsicState) = 0;
};

class ConcreteFlyweight: public Flyweight
{
  private:
    int intrinsicState;
  public:
    ConcreteFlyweight(int myInstrinsicState):intrinsicState(myInstrinsicState) {}
    int getIntrinsicState()
    {
      return this -> intrinsicState;
    }
    virtual void Operation(int extrinsicState)
    {
      cout << "ConcreteFlyweight:" << extrinsicState << endl;
    }    
};

class UnsharedConcreteFlyweight:public Flyweight
{
  private:
    int allState;
  public:
    UnsharedConcreteFlyweight(int myAllState):allState(myAllState){}
    virtual void Operation(int extrinsicState)
    {
      cout << "UnsharedConcreteFlyweight:" << allState << endl;
    }
};

class FlyweightFactory
{
  private:
    vector<ConcreteFlyweight*> flyweights; 
  public:
    FlyweightFactory()
    {
      flyweights.clear();
    }
    ConcreteFlyweight* GetConcreteFlyweight(int intrinsicState)
    {
        for(auto it = flyweights.begin(); it != flyweights.end(); it ++)
        {
        if ((*it) -> getIntrinsicState() == intrinsicState)
            return *it;  
        }
        ConcreteFlyweight* concreteFlyweight = new ConcreteFlyweight(intrinsicState);
        flyweights.push_back(concreteFlyweight);
        
        return concreteFlyweight;
    }
    int GetFlyweightCount()
    {
      return flyweights.size();
    }
};
int main()
{
  int extrinsicState = 0;
  int intrinsicState = 10;
  FlyweightFactory* fc = new FlyweightFactory();

  Flyweight* fly = fc -> GetConcreteFlyweight(intrinsicState);
  Flyweight* fly1 = fc -> GetConcreteFlyweight(intrinsicState);

  fly-> Operation(extrinsicState);
  int count = fc -> GetFlyweightCount();
  cout << "flyweight number: " << count << endl;
  return 0;
}
