#include <iostream>

using namespace std;

int main()
{
	long long N, M;
	long long K;
	long long i;
	long long value, count;
	
	cin >> N;

	cin >> K;
	value = K;
	count = 1;

	for (i = 2; i <= N; i++)
	{
		cin >> K;
		if (K == value)
		{
			count ++;
			//cout << "value:" << value << "count: " << count << endl;
		}
		else
		{
			if (count == 0)
			{
				value = K;
				count ++;
				//cout << "value:" << value << " count: " << count << endl;
			}
			else
			{
				count --;
				//cout << "value:" << value << "count:" << count << endl;
			}
		}
	}
	cout << value << endl;
	return 0;
}
