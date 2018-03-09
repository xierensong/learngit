#include <iostream>
#include <string>

using namespace std;

int Seats[66][11] = {0};
int main()
{
	int i = 0;
	char inputChar;
	int a = 0, b = 0;
	int seatType;
	/*premium class.*/
	for (i = 1; i <= 2; i++)
	{
		Seats[i][1] = 2;
		Seats[i][2] = 1;
		Seats[i][3] = 1;
		Seats[i][4] = 2;
	}
	/*business class.*/
	for (i = 3; i <= 20; i++)
	{
		Seats[i][1] = 2;
		Seats[i][2] = 1;
		Seats[i][3] = 1;
		Seats[i][4] = 1;
		Seats[i][5] = 1;
		Seats[i][6] = 2;
	}
	/*economy class.*/
	for (i = 21; i <= 65; i++)
	{
		Seats[i][1] = 2;
        Seats[i][2] = 0;
        Seats[i][3] = 1;
        Seats[i][4] = 1;
        Seats[i][5] = 0;
        Seats[i][6] = 0;
		Seats[i][7] = 1;
		Seats[i][8] = 1;
		Seats[i][9] = 0;
		Seats[i][10] = 0;
		Seats[i][11] = 2;
	}
	
		cin >> a ;
		/*a = inputChar - 47; */
		if (a > 65 || a < 1)
		{
			cout << "neither";
			return 0;
		}	
		cin >> inputChar;
		if (inputChar >= 'A' && inputChar <= 'K')
			b = inputChar - 'A' + 1;	
		else
		{
			cout << "neither";
			return 0;
		}
		//cout << "a, b:" << a << ' ' << b << endl;
		seatType = Seats[a][b];
		//cout << "seattype:" << seatType << endl;
		switch (seatType)
		{
		case 1:
			cout << "aisle";
			break;
		case 2:
			cout << "window" ;
			break;
		default:	
			cout << "neither";
		}

	return 0;
}
