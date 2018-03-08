#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	int i;
	map<string, int> nameCount;
	string name;	
	map<string, int>::const_iterator map_it;	

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> name;
		nameCount[name]++;
	}
	//cout << endl;
	for (map_it = nameCount.begin(); map_it != nameCount.end(); map_it++)
	{
		if (map_it -> second >= 2)
			cout << map_it -> first << endl;	
	}
	
	return 0;
}
