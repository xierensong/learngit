#include <iostream>
#include <string>

using namespace std;

int main()
{
	string numString;
	int numLength = 0;
	int digitValue = 0, numValue = 0;
	int maxDigitValue = 0;
	int flag = 0;
	int base = 0;
	int i = 0, j = 0;

	cin >> numString;
	numLength = numString.size();
	//fetch the max digit
	for (i = 0; i < numLength; i++)
	{
		if (numString[i] >= '0' && numString[i] <= '9')
			digitValue = numString[i] - '0';
		else if (numString[i] >= 'A' && numString[i] <= 'Z')
			digitValue = numString[i] - 'A' + 10;
		
		if (digitValue > maxDigitValue)
			maxDigitValue = digitValue;
	}
	//cout << "max digit value:" << maxDigitValue << endl;
	if (maxDigitValue < 1)
		base = 2;
	else
		base = maxDigitValue + 1;

	for (i = base; i <= 36; i++)
	{
		//cout << "base " << i << endl;
		numValue = 0;
		for (j = 0; j < numLength; j++)
    	{   
        	if (numString[j] >= '0' && numString[j] <= '9')
            	digitValue = numString[j] - '0';
        	else if (numString[j] >= 'A' && numString[i] <= 'Z')
            	digitValue = numString[j] - 'A' + 10;
			//cout << "digit value：" << digitValue << endl;            
            numValue = numValue * i + digitValue;
			//cout << "number value: " << numValue << endl;
			numValue = numValue % (i - 1);
			//cout << "number value %: " << numValue << endl;
    	}
		if (numValue == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		cout << i << endl;
	else
		cout << "No solution." << endl;
	return 0;
}
