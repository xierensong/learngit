#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int i,j;
	vector<string> storeList;	
	string currentStore;
	vector<string>::iterator it;
	int noVisits = 0;

	cin >> n;
	getline(cin, currentStore);
	i = 0;
	while (i < n)
	{
		getline(cin, currentStore);
		//cout << currentStore << endl;
		for (it = storeList.begin(); it != storeList.end(); it++)
		{
			//cout << "storeList: " << *it << endl;
			if ((*it) == currentStore)
			{
				noVisits ++;	
				break;
			}
			
		}
		if (it == storeList.end())
		{
			storeList.push_back(currentStore);
		}
		i++;	
	}
	cout << noVisits << endl;
	return 0;
}
