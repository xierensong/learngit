#include <iostream>
#include <string>

using namespace std;

string referBook[1005];
string prompts[27] = {""};

int main()
{
	int n;
	int i,j;
	char typed;
	
	cin >> n;	
	for (i = 1; i <= n; i++)
	{
		cin >> referBook[i];
	}

	cin >> typed;
	for (i = 1; i <= n; i++)
	{
		if (referBook[i][0] == typed)
		{
			//cout << referBook[i] << endl;
			prompts[referBook[i][1] - 'a' + 1] = referBook[i];
		}
	}
	for (i = 1; i <= 27; i++)
	{
	 	if (prompts[i] != "")
			cout << prompts[i] << endl;	
	}
	return 0;
}
