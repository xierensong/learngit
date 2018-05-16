#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> reagents;
	int i, K;
	string tmpColor;
	int number = 1;	
	cin >> reagents["Blue"]
		>> reagents["Red"]
		>> reagents["Yellow"];

	cin >> K;	
	for (i = 0; i < K; i++)
	{
		cin >> tmpColor;
		number = number * reagents[tmpColor];
	}
	cout << number << endl;
	return 0;
}

