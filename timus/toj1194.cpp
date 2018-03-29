#include <iostream>

using namespace std;

int main()
{
	int M,K;

	cin >> M >> K;
	cout << M * (M - 1) / 2 - K << endl;
	return 0;
}
