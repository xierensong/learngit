#include <iostream>

using namespace std;

int main()
{
	int a,b;
	
	cin >> a >> b;
	
	cout << max (2 * b + 40, 39 * 2 + 40 + (a - 40) * 2 + 1) << endl;

	return 0;
}
