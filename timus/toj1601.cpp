#include <iostream>
#include <string>

using namespace std;

int main()
{
	string message;
	int msgLength = 0;
	int flag = 1;	//1: stay same; 0: change cap.
	int i = 0;	


	while (getline(cin, message))
	{
	msgLength = message.size();
	for (i = 0; i < msgLength; i++)
	{
		if (message[i] >= 'A' && message[i] <= 'Z')
		{
			if (flag == 0)
			{
				message[i] = message[i] + 32;
			}
			else
			{
				flag = 0;
			}
		}
		else if (message[i] >= 'a' && message[i] <= 'z')
		{
			if (flag == 1)
			{
				message[i] = message[i] - 32;
				flag = 0;
			}
		}
		else if (message[i] == '!' || message[i] == '?' || message[i] == '.')
		{
			flag = 1;

		}
		cout << message[i];
	}	
	cout << endl;
	}
	return 0;
}
