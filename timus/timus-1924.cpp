// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	
	while (cin >> n)
	{
		if ((n+1)/2 & 1)
			cout << "grimy" << endl;
		else
			cout << "black" << endl;
	}

    return 0;
}

