#include <iostream>

using namespace std;

int obstacles[105];

int main()
{
	int n;
	int exit = 0;
	int i = 0;
	int flag = 0; //indicate the special status
	int left = 0xc0c0c0c0;
	int right = 0x3f3f3f3f;
	
	cin >> n >> exit;

	if (n == 0 && exit != 0)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> obstacles[i];	
	}

	if (exit == 0)
	{
		cout << "0 0" << endl;
	}	
	else if (exit < 0)
	{
		for (i = 1; i <= n; i++)
		{
			if (obstacles[i] == 0)
			{
				flag = 1;
				break;
			}
			if (obstacles[i] > exit && obstacles[i] < 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			cout << "Impossible" << endl;
		else
		{
			//get min right value near 0
			for (i = 1; i <= n; i++)	
			{
				if (obstacles[i] < right && obstacles[i] > 0)
					right = obstacles[i];
			}
			//cout << "right:" << right << endl;
			cout << (-1) * exit  + 2 * right << ' ' << (-1) * exit << endl;
		}
	}
	else
	{
		for (i = 1; i <= n; i++)
        {
			if (obstacles[i] == 0)
            {   
                flag = 1;
                break;
            }
            if (obstacles[i] < exit && obstacles[i] > 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "Impossible" << endl;
        else
        {
            //get max left value
            for (i = 1; i <= n; i++)
            {
                if (obstacles[i] > left && obstacles[i] < 0)
                    left = obstacles[i];
            }
            cout << exit << ' ' << (-1) * left * 2 + exit << endl;
        }		
	}
	return 0;
}
