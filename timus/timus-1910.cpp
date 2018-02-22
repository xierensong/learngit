#include <iostream>

using namespace std;

int a[1001] = { 0 };
int main()
{
	int n = 0;
	int i = 0;
	int max = 0, currValue = 0, mid = 0;
	while (cin >> n)
	{
		for (i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		max = a[1] + a[2] + a[3];
		mid = 2;
		for (i = 1; i <= n - 2; i++)
		{
			currValue = a[i] + a[i + 1] + a[i + 2];
			if (currValue > max)
			{
				max = currValue;
				mid = i + 1;
			}
		}
		cout << max << ' ' << mid << endl;
	}

    return 0;
}

