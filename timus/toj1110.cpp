#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N,M,Y;
	int X;
	int flag = 0;
	int i = 0;
	int tmp = 0;

	cin >> N >> M >> Y;
	for (X = 0; X <= M - 1; X++)
	{
		for (i = 0; i <= N; i++)
		{
			if (i == 0) tmp = 1;
			else
				tmp = (tmp * X) % M;		
		}
		/*
			cout << "tmp :" << tmp << endl;
		*/
		if (tmp == Y)
		{
			cout << X << ' ';
			flag = 1;
		}	

	}
	if (flag == 0)
			cout << -1 << endl;
	else
			cout << endl;
	return 0;
}
