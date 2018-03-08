#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string words[10005];

int main()
{
	int h,w,n;
	string currentWord;
	int i;
	int lineNum = 0;
	int currentLineLength = 0;
	
	cin >> h >> w >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> words[i];
	}	

	i = 1;
	while (i <= n)
	{
		currentLineLength = 0;
		while (currentLineLength + words[i].length() <= w)	
		{	
			/*cout << "word: " << words[i] <<endl; */
			currentLineLength += words[i].length() + 1;
			i++;		
		}
		lineNum++;
		/*cout << "lineNum: " << lineNum << endl; */
	}
	/*cout << "h: " << h << endl;		*/
	cout << ceil (lineNum * 1.0 / h) << endl;	
	return 0;
}
