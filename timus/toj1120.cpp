#include <iostream>

using namespace std;

int main()
{
	int N;
	int i = 0;
	int P = 0;
	int A = 0;
	double tmp = 0;
	double tmp2 = 0;

	cin >> N;
	for(i = 1; i * (i - 1) < 2 * N; i++)
	{
		tmp = i * (i - 1);
		//cout << "tmp: " << tmp << endl;
		tmp2 = (2 * N - tmp) / (2 * i);
		//cout << "tmp2: " << tmp2 << ' ' << int(tmp2) <<  endl;
		
		if (tmp2 == int (tmp2))
		{
			if ( i > P)
			{
				P = i;
				A = int (tmp2);
			}
		}
		//cout << A << ' ' << P << endl;
		//cout << endl;
	}
	if (P != 0)
		cout << A << ' ' << P << endl;
	return 0;
}
