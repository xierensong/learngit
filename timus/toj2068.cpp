#include <iostream>

using namespace std;

int main()
{
	int n;
	int i;
	int a;
	int sum = 0;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a;
		sum += a / 2;
	}
	if (sum % 2 == 0)
		cout << "Stannis" << endl;
	else
		cout << "Daenerys" << endl;		
	return 0;
}
