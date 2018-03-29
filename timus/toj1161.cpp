#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>

using namespace std;

double weight[101];
int main()
{
	int n;
	int i;
	double totalWeight = 0;
	
	cin >> n;	
	for (i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	if ( n == 1)
		cout << fixed << setprecision(2) << weight[0] << endl;
	else
	{
		sort(weight, weight + n);
		for (i = n - 2; i >= 0; i --)
		{
			weight[i] = 2 * (sqrt (1.0 * weight[i] * weight[i+1]));
			//cout << "weight" << i << ": " << weight[i] << endl;
		}
		cout << fixed << setprecision(2) << weight[i + 1] << endl;
	}	
			
	return 0;
}
