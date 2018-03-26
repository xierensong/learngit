#include <iostream>
#include <iomanip>

using namespace std;
double a[1001];
int main()
{
	int n;
	int i;
	double sum = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];	
		sum += a[i];
	}
	cout << setiosflags(ios::fixed) << setprecision(6) <<  sum / n << endl;
	return 0;
}
