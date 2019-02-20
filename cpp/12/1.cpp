#include<iostream>
#include<string>

using namespace std;

class Rectangle
{
  private:
    int a;
    int b;
    public:
  Rectangle(int a1, int b1)
  {
    a = a1;
    b = b1;
  } 
  int calcarea()
  {
    return this -> a * this -> b;
  }
  void printarea()
  {
    cout << "The area of rectangle is " << 
            calcarea() << endl;
  }
  bool operator==(Rectangle& R2)
  {
    int area1 = this -> calcarea();
    int area2 = R2. calcarea();
    if (area1 == area2)
      return true;
    else
      return false;
  }
  bool operator>(Rectangle& R2)
  {
    int area1 = this -> calcarea();
    int area2 = R2.calcarea();
    if (area1 > area2)
      return true;
    else
      return false;
  }
  bool operator<(Rectangle& R2)
  {
    int area1 = this -> calcarea();
    int area2 = R2.calcarea();
    if (area1 < area2)
      return true;
    else
      return false;
  }
};

int main()
{
  Rectangle r1(3,4), r2(2,6), r3(4,5);
  r1.printarea();
  r2.printarea();
  r3.printarea();
  cout << boolalpha << "\n\nThe results of comparing these rectangles are:"
    << "\n r1==r2 yields " << (r1==r2)
    << "\n r2>r3 yields " << (r2>r2)
    << "\n r1<r3 yields " << (r1<r3)
    << endl;
}
