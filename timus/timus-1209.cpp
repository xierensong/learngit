#include <iostream>
#include <algorithm>


using namespace std;


int main()
{
	int n = 0;
	int i = 0;
	long long int pos = 0;
	long long int value;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> pos;
		value = (sqrt((8 * pos - 7)*1.0) - 1) / 2;

		if (value * value + value + 2 == 2 * pos)
			cout << '1';
		else
			cout << '0';
		cout << ' ';
	}


	


    return 0;
}

