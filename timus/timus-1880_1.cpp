// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <algorithm>

using namespace std;

int a1[4001], a2[4001], a3[4001];
int main()
{
	int n = 0;
	int i = 0, j = 0, k = 0;
	int minValue = 0;
	int count = 0;

	cin >> n;
	a1[0] = n;
	for (i = 1; i <= n; i++)
	{
		cin >> a1[i];
	}
	cin >> n;
	a2[0] = n;
	for (i = 1; i <= n; i++)
	{
		cin >> a2[i];
	}
	cin >> n;
	a3[0] = n;
	for (i = 1; i <= n; i++)
	{
		cin >> a3[i];
	}
	/*
	cout << "a1[0]" << a1[0] << endl;
	cout << "a2[0]" << a2[0] << endl;
	cout << "a3[0]" << a3[0] << endl;
	*/
	for (i = 1, j = 1, k = 1; i <= a1[0] && j <= a2[0] && k <= a3[0];)
	{
		minValue = min(a1[i], min(a2[j], a3[k]));
		//cout << "minValue" << minValue << endl;
		if (minValue == a1[i] && minValue == a2[j] && minValue == a3[k])
		{
			i++; j++; k++;
			count++;
		}
		else if (minValue == a1[i]) i++;
		else if (minValue == a2[j]) j++;
		else  k++;
	}

	cout << count << endl;
	


    return 0;
}

