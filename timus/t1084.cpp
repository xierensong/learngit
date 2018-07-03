
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.1415926535897

int main()
{
	double side = 0, r, diagonal;
	double cord = 0;
	double area = 0;
	double sector, triangle, angle;

	cin >> side >> cord;
	r = side / 2.0;
	diagonal = sqrt(2) * r;
	//cout << diagonal << endl;
	if (cord <= r)
		area = PI * cord * cord;
	else if (cord >= diagonal)
		area = side * side;
	else
	{
	    triangle = r * sqrt(cord * cord - r * r);
		//cout << "r: " << r << "cord: " << cord << endl;
		angle = acos(r / cord);
		//cout << "angle: " << angle * 180 / PI << endl;
		sector = angle * cord * cord;
		area = PI * cord * cord - 4 * (sector - triangle);
		//cout <<"sector: " << sector << endl;
		//cout <<"triangle: " << triangle << endl;
	}
	cout << setiosflags(ios::fixed) << setprecision(3) << area << endl;



	system("pause");

	return 0;
}

