#include <iostream>

using namespace std;

int a[10005] = {0};
int main()
{
	int n = 0;
	int k = 0;
	int i = 0;
	int unusedBooms = 0;
	int survivedDroids = 0;
		
	cin >> n >> k;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (i = 1; i <= n; i++)
	{
		unusedBooms += a[i] > k ? a[i] - k : 0;
	}
	
	for (i = 1; i <= n; i++)
	{
		survivedDroids += k > a[i] ? k - a[i] : 0;
	}
	cout << unusedBooms << ' ' << survivedDroids << endl;
	
	return 0;
}
