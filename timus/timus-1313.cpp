// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <algorithm>

using namespace std;

int a[105][105];
int main()
{
	int n = 0;
	int i = 0, j = 0;

	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> a[i][j];

	
	for (i = 2; i <= 2 * n; i++)
		for (j = i - 1; j >= 1; j--)
		{
			if (j <= n && i - j <= n)
			//cout << j << '\t' << i - j << ':' <<'\t' << a[j][i - j] << endl;
				cout << a[j][i - j] << ' ';
		}


	


    return 0;
}


}