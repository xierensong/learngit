#include <iostream>

using namespace std;

int main()
{
	int PetrInitial, PetrRaise, taxiDriverInitial, taxiDriverRaise;
	int PetrFinal,taxiDriverFinal;	
	
	PetrFinal = PetrInitial;
	taxiDriverFinal = taxiDriverInitial;

	cin >> PetrInitial >> PetrRaise >>
		taxiDriverInitial >> taxiDriverRaise;

	PetrFinal = PetrInitial;
	taxiDriverFinal = taxiDriverInitial;
	if ( taxiDriverFinal < PetrFinal)
	{
		cout << PetrFinal << endl;
	}
	else
	{
	while (1)
	{

	if (PetrFinal + PetrRaise <= taxiDriverFinal)
    {   
        PetrFinal += PetrRaise;
        /*cout << "Petr: " << PetrFinal << endl;
		*/

    }
    else
    {
        cout << taxiDriverFinal << endl;
        break;
    }
	
	if (taxiDriverFinal - taxiDriverRaise >= PetrFinal)
    {   
        taxiDriverFinal -= taxiDriverRaise; 
        /*cout << "taxiDriver: " << taxiDriverFinal << endl;
       */ 
    }
    else
    {
        cout << PetrFinal << endl;
        break;
    }

	}
	}
	return 0;
}
