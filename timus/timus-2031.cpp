// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>


using namespace std;


int main()
{
	int n;
	cin >> n;

	if (n == 1)
		cout << "01" << endl;
	else if (n == 2)
		cout << "11 01" << endl;
	else if (n == 3)
		cout << "06 68 88" << endl;
	else if (n == 4)
		cout << "16 06 68 88" << endl;
	else
		cout << "Glupenky Pierre" << endl;

    return 0;
}

