#include <iostream>
#include <iomanip>
using namespace std;

int boat[101];
int main()
{
	int n;
	int t;
	int s;
	int i;
	int tmp;

	cin >> n >> t >> s;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		boat[i] = tmp - s + t;	
		
		//cout << boat[i] << endl;
	}
	for (i = 0; i < n; i++)
	{
		cout <<fixed << setprecision(6) << (1.0 * boat[i]) / 2 + s << endl;
	}
	return 0;
}
