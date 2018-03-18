// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	long n;
	long i,j;
	long lastPos = 0, currentPos = 0;
	long currentValue = 0,tmp = 0;
	long group[105];
	long minSupporters = 0;
	long minminSupporters = 0;
	long totalVoters = 0;

	cin >> n;
	//lastPos = (n % 2) ? (n + 1) / 2 : n / 2;
	lastPos =  (n + 1) / 2;
	//cout << "last position: " << lastPos << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> group[i];
		totalVoters += group[i];
	}

	
	for (i = 1; i <= n - 1; i++)
	{	
		currentPos = i;
		for (j = i + 1; j <= n; j++)		
			if (group[j] < group[currentPos])
			{
				currentPos = j;				
			}
		//cout << "i current Position: " << i << ' ' << currentPos << endl;
		if (currentPos != i)
		{
			tmp = group[i];
			group[i] = group[currentPos];
			group[currentPos] = tmp;
		}
		
		//minSupporters += (group[i] % 2) ? (group[i] + 1) / 2 : group[i] / 2;
		//minSupporters += (group[i] + 1) / 2 ;
		//cout << "minimal supporters: " << minSupporters << endl;
	}
	for (i = 1; i <= (n / 2 + 1); i++)
	{
		minSupporters += (group[i] + 1) / 2;
		//cout << "minimal supporters: " << minSupporters << endl;
	}
	/*
	sort(group + 1, group + n + 1);
	for (i = 1; i <= (n / 2 + 1); i++) 
		minSupporters += (group[i] + 1) / 2;
	*/
	//minminSupporters = totalVoters % 2 ? (totalVoters + 1) / 2 : totalVoters / 2;
	minSupporters = minSupporters < (totalVoters + 1) / 2 ? minSupporters : (totalVoters + 1) / 2;
	cout << minSupporters << endl;

    return 0;
}

