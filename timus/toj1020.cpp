#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

typedef struct Tnail
{
	double x;
	double y;
}Tnail;

Tnail nails[105];

int main()
{
	int N;
	double R;
	int i;
	double ropeLen = 0, tmp = 0;

	cin >> N >> R;
	for (i = 0; i < N; i++)
	{
		cin >> nails[i].x >> nails[i].y;
		if (i >= 1)
		{
			tmp = (nails[i].x - nails[i-1].x) * (nails[i].x - nails[i-1].x)
			+ (nails[i].y - nails[i-1].y) * (nails[i].y - nails[i-1].y);
			tmp = sqrt(tmp);
			//cout << tmp << endl;
			ropeLen += tmp;
		}
	}
	//add the cycle line
	tmp = (nails[N-1].x - nails[0].x) * (nails[N-1].x - nails[0].x)
		+ (nails[N-1].y - nails[0].y) * (nails[N-1].y - nails[0].y);
	tmp = sqrt(tmp);
	ropeLen += tmp;
	tmp = 2 * 3.1415 * R;
	ropeLen += tmp;
	cout << fixed << setprecision(2) << ropeLen << endl;
	return 0;
}
