#include <iostream>

using namespace std;

int main ()
{
	int N[55];
	char digital;	
	int i = 1;	
	int remaining = 0;

	while (cin >> digital)
	{
		if (digital != '\n')
		{
			N[i] = digital - 48;
			i++;
		}
		else
			break;
	}
	N[0] = i - 1;
	/*
	for (i = 1; i <= N[0]; i++)
	{
		cout << N[i] << endl;
	}
	*/
	
	remaining = N[1] % 7;
	for (i = 2; i <= N[0]; i++)
	{
		remaining = (remaining * 10 + N[i]) % 7;
	}

	cout << remaining << endl;
	return 0;
}
