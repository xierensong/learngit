#include <iostream>

using namespace std;

int a[10005];

int main()
{
	int N;
	int i, j;
	int QN,Q1,Q2;
	int tmp;

	cin >> N;
	a[0] = 0;
	for (i = 1; i <= N; i++)
	{
		cin >> tmp;
		a[i] = a[i-1] + tmp;
		
	}
	cin >> QN;
	for (i = 0; i < QN; i++)
	{
		cin >> Q1 >> Q2;
		cout << a[Q2] - a[Q1-1] << endl;	
	}
	return 0;
}
