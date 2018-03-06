#include <iostream>
#include <algorithm>

using namespace std;

void bigInt2digitalArray(int tmpTicketNo, int ticket[])
{
	
        ticket[1] = tmpTicketNo / 100000;

        tmpTicketNo = tmpTicketNo % 100000;
        ticket[2] = tmpTicketNo / 10000;

        tmpTicketNo = tmpTicketNo % 10000;
        ticket[3] = tmpTicketNo / 1000;

        tmpTicketNo = tmpTicketNo % 1000;
        ticket[4] = tmpTicketNo / 100;

        tmpTicketNo = tmpTicketNo % 100;
        ticket[5] = tmpTicketNo / 10; 

        ticket[6] = tmpTicketNo % 10; 
/*		cout << "tickets" << '\t' << ticket[1]
						  << '\t' << ticket[2]
						  << '\t' << ticket[3]
						  << '\t' << ticket[4]
						  << '\t' << ticket[5]
						  << '\t' << ticket[6]
						  <<endl ;
*/
}

int main()
{
	int length = 6;
	int i = 0;
	int ticketNo;
	int ticket[7];
	int tmpTicketNo;

	int currFirstHalf, currEndHalf;
	int newFirstHalf, newEndHalf;	
		
	while (cin >> ticketNo)
	{
		tmpTicketNo = ticketNo + 1;
		
		bigInt2digitalArray(tmpTicketNo, ticket);

		currFirstHalf = ticket[1] +	ticket[2] + ticket[3];
		currEndHalf = ticket[4] + ticket[5] + ticket[6];
		/*
			cout << "First Half:" << currFirstHalf << ' ' <<
			  "End Half:" << currEndHalf << endl;
		*/
		if (currFirstHalf == currEndHalf)
			cout << "Yes" << endl;
		else
		{
			tmpTicketNo = ticketNo - 1;
			bigInt2digitalArray(tmpTicketNo, ticket);		
			currFirstHalf = ticket[1] + ticket[2] + ticket[3];
			currEndHalf = ticket[4] + ticket[5] + ticket[6];
			if (currFirstHalf == currEndHalf)
				cout << "Yes" << endl;		
			else
				cout << "No" << endl;
		}

	}

	return 0;
}
