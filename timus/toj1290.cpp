#include <iostream>
#include <algorithm>
using namespace std;

int num[25001];
int main()
{
	int n = 0;
	int i = 0;

	cin >> n;
	if (n == 0)
		return 0;
	for (i = 1; i <= n; i++)
	{
		cin >> num[i];
	}

	sort(num + 1, num + n + 1);
	
	for (i = n; i >= 1; i--)
		cout << num[i] << endl;
	return 0;
}
