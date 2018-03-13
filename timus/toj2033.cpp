#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct FRIEND {
	string name;
	string device;
	long long price;
}; 

int main()
{	
	struct FRIEND friends[7];
	int i = 0;
	map<string,int> deviceCount;
	map<string,long long> deviceLowPrice;
	map<string,int>::iterator it;
	int maxCount = 0;
	string maxDevice; 
	vector<string> maxDevices;
	string desiredDevice;

	for (i = 1; i <= 6; i++)
	{
		cin >> friends[i].name;
		cin >> friends[i].device;
		cin >> friends[i].price;
		
		deviceCount[friends[i].device] ++;
		
		if (deviceLowPrice[friends[i].device] == 0)
			deviceLowPrice[friends[i].device] = friends[i].price;
		else if (deviceLowPrice[friends[i].device] > friends[i].price)
			deviceLowPrice[friends[i].device] = friends[i].price;
	}
		
	for (it = deviceCount.begin(); it != deviceCount.end(); it++)
	{
		if (it->second > maxCount)
		{	
			maxCount  = it->second;
			maxDevice = it->first;
		}
	}
	for (it = deviceCount.begin(); it != deviceCount.end(); it++)
	{
		if (it->second == maxCount)
		{
			maxDevices.push_back(it->first);
			//cout << it->first << endl;
		}
	}
	
	if (maxDevices.size() == 1)
		cout << (*maxDevices.begin()) << endl;
	else
	{
		long long cLowPrice = 0x3f3f3f3f; 
		for (i = 0; i < maxDevices.size(); i++)
		{
			if (deviceLowPrice[maxDevices[i]] <= cLowPrice)
			{
				cLowPrice = deviceLowPrice[maxDevices[i]];
				desiredDevice = maxDevices[i];
			}
			//cout << "device:" << maxDevices[i] << " low Price:" << cLowPrice << endl;
		}	
		cout << desiredDevice << endl;
	}
	return 0;
}
