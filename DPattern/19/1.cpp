#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Iterator
{
  public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual T CurrentItem() const = 0;
};

template<typename T>
class Aggregate
{
  public:
    virtual Iterator<T>* CreateIterator() const = 0;
	virtual long Count() const = 0;
    virtual T Get(long index) const = 0;
};

template<typename T>
class ConcreteAggregate: public Aggregate<T>
{
  private:
	vector<T> data;	
  public:
    ConcreteAggregate(vector<T> myData):data(myData) {}
    virtual Iterator<T>* CreateIterator() const;
    virtual long Count() const
	{
		return data.size();
	}
    virtual T Get(long index) const
    {
      return data[index];
    }    
};

template<typename T>
class ConcreteIterator: public Iterator<T>
{
  private:
	const Aggregate<T>* aggregate;
	long current;
  public:
    ConcreteIterator(const Aggregate<T>* myAggregate): //const必须有
      aggregate(myAggregate),current(0) {}
    virtual void First()
	{
		current = 0;
	}
    virtual void Next()
	{
		current ++;
	}
    virtual bool IsDone()
	{
		return current >= aggregate -> Count();
	}
    virtual T CurrentItem() const
    {
        return aggregate -> Get(current);
    }
};

template<typename T>
Iterator<T>* ConcreteAggregate<T>::CreateIterator() const
{
	Iterator<T>* iterator = new ConcreteIterator<T>(this);
    return iterator;
}

int main()
{
    vector<int> myData = {1,2,3,4,5};
    Aggregate<int>* myAggregate = new ConcreteAggregate<int>(myData);
    Iterator<int>* myIterator = myAggregate -> CreateIterator();
     // new ConcreteIterator<int>(myAggregate);
    for (myIterator -> First(); !myIterator -> IsDone(); myIterator -> Next())
    {
      cout << "the current value is " << myIterator -> CurrentItem() << endl;
    }
    return 0;
}
