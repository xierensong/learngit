#include <iostream>

using namespace std;

int main()
{
	long long N,M;

	cin >> N >> M;
	if (N > M)
	{
		cout << M * 2 - 1 << endl;
	}
	else
	{
		cout << (N - 1) * 2 << endl;
	}
	return 0;
}
