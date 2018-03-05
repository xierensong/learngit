#include <iostream>
using namespace std;

int a[1005];
int main()
{
	int n = 0;
	int i,j,k;
	int currValue = 0;	
	int count = 0;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}	
	
	i = 1;
	count = 1;
	/*judge the next one.*/
	while (i <= n)
	{
		if (count == 0)
			count++;
		else
		{
			if (a[i + 1] == a[i] && i + 1 <= n)
				count++;
			else
			{
				cout << count << ' ' << a[i] << ' ';
				count = 0;
			}
			i++;	
		}
	}

	return 0;
}
