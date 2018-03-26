#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,k = 0;
	string markStr;
	int size = 0;
	int i;
	long long factorial = 1;

	cin >> n;
	cin >> markStr;
	size = markStr.size();
	for (i = 0; i < size; i++)
	{
		if (markStr[i] == '!')
			k++;	
	}
	//cout << "k:" << k << endl;	

	i = 0;
	while (i < n / k)
	{
		factorial = factorial * (n - i * k);
		i++;
	}
	if ( n % k != 0)
		factorial  = factorial * (n % k);
	cout << factorial << endl;
	return 0;
}
