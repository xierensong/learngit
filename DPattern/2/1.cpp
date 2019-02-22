#include<iostream>

using namespace std;
enum Week
{
  Mon,
  Tue,
  Wes
};

class A
{
private:
  Week week;
public:
  A(Week myWeek)
  {
    this -> week = myWeek;
  }

  void print()
  {
    if (week == Mon)
      cout << "Monday" << endl;
    else if (week == Tue)
      cout << "Tuesday" << endl;
    else 
      cout << "Wesday" << endl;
  }
};

int main()
{
  Week week = Tue;
  A* a = new A(week);
  a -> print();
}
