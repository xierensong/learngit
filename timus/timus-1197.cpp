// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>

using namespace std;

int main()
{
	int i = 0, n = 0;
	char x1,y1;
	int x = 0, y = 0;
	int sum = 0;
	while (cin >> n)
	{
		if (n > 0)
		{
			for (i = 0; i < n; i++)
			{
				
				while (cin >> x1 >> y1)
				{
					sum = 0;
					x = x1 - 97;
					y = y1 - 49;
					if (x - 2 >= 0 && y - 1 >= 0) //left top
						sum++;
					if (x - 2 >= 0 && y + 1 <= 7) //left down
						sum++;
					if (x + 2 <= 7 && y - 1 >= 0)  //right top
						sum++;
					if (x + 2 <= 7 && y + 1 <= 7)  //right down
						sum++;
					if (x - 1 >= 0 && y - 2 >= 0) //up left
						sum++;
					if (x + 1 <= 7 && y - 2 >= 0) //up right
						sum++;
					if (x - 1 >= 0 && y + 2 <= 7) //down left
						sum++;
					if (x + 1 <= 7 && y + 2 <= 7) //down right
						sum++;
					cout << sum << endl;
				}
			}
		}
	}

    return 0;
}

