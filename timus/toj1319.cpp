#include <iostream>
using namespace std;

int a[105][105];
int main()
{
	int n = 0;
	int i,j,k;
	int offsetY, offsetX;/*offsetY: Y axis; offsetX: X axis*/	
	int preSum;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			preSum = 0;
			offsetX = 0;
			if (i <= j)
			{
				offsetY = i - 1;
				offsetX = n - j + offsetY;
				/*cout << "offsetX:" << offsetX << '\t' <<
						"offsetY:" << offsetY << endl;
				*/
				k = offsetX;
				while (k > 0)	
				{
					preSum += k;
					k--;
				}
				cout << preSum + 1 + offsetY << ' ';
			}
			else
			{
				offsetY = n - i;
				offsetX = j + offsetY - 1;
				for (k = 1; k <= offsetX; k++)
				while (offsetX > 0)
				{
					preSum += offsetX;
					offsetX--;
				}
				cout << n * n - preSum - offsetY << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
