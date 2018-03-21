#include <iostream>
#include <algorithm>
using namespace std;

int a[101];
int main()
{
	int n;
	int i = 0;
	int limit = 6;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
//	cout << endl;	
	while (next_permutation(a, a + n) && limit > 1)
	{
//		for (i = 0; i < n; i++)
//			cout << a[i] << '\t';
//		cout << endl;
		limit --;
	}
	if (limit == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
