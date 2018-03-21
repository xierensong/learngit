#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string cipherText;
	string originText;
	int length;
	char cipherLetter;
	char stackLetter;
	int i,j;
	int flag = 0;

	cin >> cipherText;
	length = cipherText.size();

	i = 0;
	j = 0;
	while ( i < length)
	{
		cipherLetter = cipherText[i];
		if (originText.empty() == false)
			stackLetter = originText[originText.size() - 1];
		else
			stackLetter = ' ';
		
		if (cipherLetter == stackLetter)
		{
			originText.pop_back();
		}
		else
		{
			originText.push_back(cipherLetter);
		}
		i++;
	}
	
		cout << originText << endl;;
	return 0;
}
