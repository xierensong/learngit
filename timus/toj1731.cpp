#include <iostream>

using namespace std;

int main()
{
	int n,m;
	int i;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
	for (i = 1; i <= m; i++)
	{
		cout << i * n + 1 << ' ' ;
	}
	cout << endl;
	return 0;
}
