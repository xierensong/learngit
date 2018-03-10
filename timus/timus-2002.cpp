// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <string>


using namespace std;

string username[105];
string password[105];
string onlineUsername[105];

void printOnline(string *onlineList, int length)
{
	int i;
	cout << "online user name:" << endl;
	for (i = 0; i <= length; i++)
	{
		cout << onlineList[i] << endl;
	}
}

int main()
{
	int n;
	string lineStr;
	string commandList[3];
	int i,k,nn = 0;
	int pos1, pos2, lineLength;

	cin >> n;
	getline(cin, lineStr);

	for (i = 1; i <= n; i++)
	{
		//cout << "n::" << i << endl;
		getline(cin, lineStr);
		lineLength = lineStr.size();

		//parse the command line
		pos1 = lineStr.find(' ');
		if (pos1 != string::npos)
			commandList[0] = string(lineStr, 0, pos1);
		else
			commandList[0] = string(lineStr, 0, lineLength - 1);

		//cout << "=" << commandList[0] << "=" << endl;
		pos2 = lineStr.find(' ',pos1 + 1);
		if (pos2 != string::npos)
			commandList[1] = string(lineStr, pos1 + 1, pos2 - pos1 - 1);
		else
			commandList[1] = string(lineStr, pos1 + 1, lineLength - pos1 - 1);
		//cout << "=" << commandList[1] << "=" << endl;

		commandList[2] = string(lineStr, pos2 + 1, lineLength - pos2 - 1);
		//cout << "=" << commandList[2] << "=" << endl;

		//route
		if (commandList[0] == "register")
		{
			//search user name
			int j = 0;
			int flag = 0; //indicate if exists;
			while (username[j] != "")
			{
				if (username[j] == commandList[1])
				{					
					flag = 1;
					break;
				}
				j++;
			}
			//insert the new user
			if (flag == 0)
			{
				username[j] = commandList[1];
				password[j] = commandList[2];
				cout << "success: new user added" << endl;
			}
			else
			{
				cout << "fail: user already exists" << endl;
			}
		}
		else if (commandList[0] == "login")
		{
			//search user name
			int j = 0;
			int fflag = 0; //indicate if exists;1:exist;0:no exist
			while (username[j] != "")
			{
				//find user name
				if (username[j] == commandList[1])
				{					
					fflag = 1;
					break;
				}
				j++;
			}
			//no find,
			//insert the new user
			if (fflag == 0)
			{				
				cout << "fail: no such user" << endl;
			}
			else
			{
				if (password[j] == commandList[2])
				{
					//search online user
					k = 0;
					int ffflag = 0; //indicat if exists;1:exist;0:no exist
					while (onlineUsername[k] != "")
					{
						if (onlineUsername[k] == commandList[1])
						{							
							ffflag = 1;
							break;
						}
						k++;

					}
					if (ffflag == 0)
					{
						cout << "success: user logged in" << endl;

						onlineUsername[k] = commandList[1]; //insert the new login
					}
					else
					{
						cout << "fail: already logged in" << endl;
					}

				}
				else
				{
					cout << "fail: incorrect password" << endl;
				}
			}
			//printOnline(onlineUsername, k);
			//cout << "-===-" << endl;
		}
		else if (commandList[0] == "logout")
		{
			//search user name
			int l = 0;
			int fffflag = 0; //indicate if exists;
			while (username[l] != "")
			{
				if (username[l] == commandList[1])
				{
					fffflag = 1;
					break;
				}
				l++;
			}
			//no find	
			if (fffflag == 0)
			{
				cout << "fail: no such user" << endl;
			}
			//find
			else
			{
				//search online user
				int m = 0;
				int ffffflag = 0; //indicat if exists;1:exist;0:no exist
				while (onlineUsername[m] != "")
				{
					if (onlineUsername[m] == commandList[1])
					{
						ffffflag = 1;
						break;
					}
					m++;

				}
				if (ffffflag == 0)
				{
					cout << "fail: already logged out" << endl;
				}
				else
				{
					cout << "success: user logged out" << endl;
					nn = m + 1;
					//cout << "onlineUsername[m]: " << onlineUsername[m] << endl;
					//fix empty string
					while (onlineUsername[nn] != "")
					{
						onlineUsername[nn - 1] = onlineUsername[nn];
						//cout << "onlineUsername[nn]" << onlineUsername[nn] << endl;
						nn++;
					}
					onlineUsername[nn - 1] = "";
				}
				//printOnline(onlineUsername, nn - 2);
				//cout << "-===-" << endl;
			}
		}
	}

    return 0;
}

