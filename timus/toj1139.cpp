#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N,M;
	int blockNum = 0;

	cin >> N >> M;
	if (N == M)
		cout << N - 1 << endl;
	else
		cout << N + M - 2 - __gcd (N - 1, M - 1) << endl;
	
	return 0;
}
