#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	map<int, int> wheels;
	int diameter;
	int i;
	map<int, int>::iterator it;
	int cars = 0;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> diameter;
		wheels[diameter]++;
	}
	
	for (it = wheels.begin(); it != wheels.end(); it++)
	{
		cars += it -> second / 4;
	}
	
	cout << cars << endl;		
	return 0;
}
