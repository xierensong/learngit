#include <iostream>
#include <string>

using namespace std;

int main()
{
	string letter;
	int tmpValue = 0;
	int step3Value = 0;
	int step1Value = 0;
	char step0Value;
	int i;

	cin >> letter;
	for (i = 0; i < letter.size(); i++)
	{
		if (i == 0)
		{
			//cout << "step4 value: " << letter[i] << endl;
			step3Value = letter[i] - 'a';
			//cout << "step3 Value: " << step3Value << endl;
			step1Value = step3Value - 5 >= 0 ? step3Value - 5: 26 + step3Value - 5;
			//cout << "step1 value: " << step1Value << endl;	
			step0Value = step1Value + 'a';
			cout << step0Value;
			tmpValue = step3Value;
		}
		else
		{
			//cout << "step4 value: " << letter[i] << endl;
			step3Value = letter[i] - 'a';
			//cout << "step3 Value: " << step3Value << endl;
			step1Value = step3Value - tmpValue >= 0 ? step3Value - tmpValue : 26 + step3Value - tmpValue;
			//cout << "step1 value: " << step1Value << endl;
			step0Value = step1Value + 'a';
			cout << step0Value;
			tmpValue = step3Value;
		}	
	}	
	cout << endl;	
	return 0;
}
