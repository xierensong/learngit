#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n;
	map<string, int> houseMap; 
	vector<string>::iterator iter;
	vector<string> names[4];
	int i;
	string name, house;

	houseMap.insert(pair<string,int>("Slytherin",0));
	houseMap.insert(pair<string,int>("Hufflepuff",1));
	houseMap.insert(pair<string,int>("Gryffindor",2));
	houseMap.insert(pair<string,int>("Ravenclaw",3));
	cin >> n;	
	getline(cin,name);
	for (i = 0; i < n; i ++)
	{
		getline(cin,name);
		getline(cin,house);
		names[houseMap[house]].push_back(name);		
	}
	
	cout << "Slytherin:" << endl;
		
	for (iter = names[0].begin(); iter != names[0].end(); iter++)
		cout << *iter << endl;
	cout << endl;

	cout << "Hufflepuff:" << endl;
	
	for (iter = names[1].begin(); iter != names[1].end(); iter++)
        cout << *iter << endl;
	cout << endl;

	cout << "Gryffindor:" << endl;

	for (iter = names[2].begin(); iter != names[2].end(); iter++)
        cout << *iter << endl;
    cout << endl;			

	cout << "Ravenclaw:" << endl;

	for (iter = names[3].begin(); iter != names[3].end(); iter++)
        cout << *iter << endl;
    cout << endl;
	return 0;
}
