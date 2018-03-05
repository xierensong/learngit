#include <iostream>

using namespace std;

int main()
{
	int A = 0, B = 0;
	cin >> A >> B;
	if (A % 2 == 1)
		A = A - 1;
	if (B % 2 == 1)
		B = B + 1;
	cout << (B - A) / 2 << endl;
	return 0;
}
