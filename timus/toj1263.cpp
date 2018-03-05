#include <iostream>
#include <iomanip>
using namespace std;

int candidates[10005] = {0};

int main()
{
	int N = 0;
	int M = 0;
	int i = 0;
	int voteNumber = 0;

	cin >> N >> M;
	for (i = 1; i <= M; i++)
	{
		cin >> voteNumber;
		candidates[voteNumber]++;
	}
	for (i = 1; i <= N; i++)
		cout << setiosflags(ios::fixed) << setprecision(2) << candidates[i] / (M * 1.0) * 100 << '%' << endl;

	return 0;
}
