#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int eatNum = 0;
	string statusString; 
	int i;	
	int maxHungry = 0;
	int maxSatisfied = 10;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> eatNum >> statusString;
		if (statusString == "hungry")
		{
			if (eatNum > maxHungry)
				maxHungry = eatNum;
		}
		else if (statusString == "satisfied")
		{
			if (eatNum < maxSatisfied)
				maxSatisfied = eatNum;
		}	
	}
	
	if (maxHungry < maxSatisfied && maxSatisfied > 2)
		cout << maxSatisfied << endl;
	else
		cout << "Inconsistent" << endl;
	return 0;
}
