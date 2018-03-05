#include <iostream>

using namespace std;

typedef struct team
{
	int ID;
	int M;
}TeamType;

TeamType contestResult[150005];

int main()
{
	int N = 0;
	int i,j; 

	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> contestResult[i].ID >> contestResult[i].M;
	}

	for (j = 100;  j >= 0; j--)
	{
		for (i = 1; i <= N; i++)
			if (contestResult[i].M == j)
				cout << contestResult[i].ID << ' ' <<
						contestResult[i].M  << endl;
	}	
/*	
	cout << endl;
	for (i = 1; i <= N; i++)
	{
		cout << contestResult[i].ID << '\t' << contestResult[i].M;
		cout << endl;
	}
*/
	return 0;
}
