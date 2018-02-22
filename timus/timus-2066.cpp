// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>

using namespace std;


int main()
{
	int a = 0, b = 0, c = 0;

	int minValue = 0,currValue = 0;
	
	cin >> a >> b >> c;

	currValue = a * b + c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a * b - c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a * b * c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a + b - c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a + b * c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a + b + c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a - b + c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a - b * c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	currValue = a - b - c;
	//cout << currValue << endl;
	if (currValue < minValue)
		minValue = currValue;

	cout << minValue << endl;
    return 0;
}


