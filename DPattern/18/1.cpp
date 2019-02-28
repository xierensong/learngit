#include<iostream>
#include<list>

using namespace std;

class Component
{
  public:

    virtual void Operation() = 0;
    virtual void Add(Component*) = 0;
    virtual void Remove(Component*) = 0;
};

class Leaf : public Component
{
  private:
    string name;
  public:
    Leaf(string myName):name(myName){}
    virtual void Operation()
    {
      cout << "operate on " << name << endl;
    }
    virtual void Add(Component* myComponent) {}
    virtual void Remove(Component* mycomponent) {}
};

class Composite : public Component
{
  private:
    string name;
    list<Component*> children;
  public:
    Composite(string myName):name(myName){}

    virtual void Operation()
    {
      cout << "operate on " << name << endl;
      for(auto element: children)
      {
        element -> Operation();
      }
        
    }
    virtual void Add(Component* myComponent)
    {
      children.push_back(myComponent);
    }
    virtual void Remove(Component* myComponent)
    {
      children.remove(myComponent);
    }
};

int main()
{
  Component* root = new Composite("root");
  Leaf* leafNode = new Leaf("leaf1");
  Composite* branchNode = new Composite("branch");
  Composite* branchNode1 = new Composite("branch1");

  root -> Add(branchNode);
  root -> Add(branchNode1);

  branchNode -> Add(leafNode);

  root -> Operation();

  return 0;
}
