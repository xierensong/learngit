#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> section;
	int n = 0;
	int i = 0;
	int totalStep = 0, prevStep = 0, currStep = 0;
	string name;
	
	section["Alice"] = 1;
	section["Ariel"] = 1;
	section["Aurora"] = 1;
	section["Phil"] = 1;
	section["Peter"] = 1;
	section["Olaf"] = 1;
	section["Phoebus"] = 1;
	section["Ralph"] = 1;
	section["Robin"] = 1;
	section["Bambi"] = 2;
	section["Belle"] = 2;
	section["Bolt"] = 2;
	section["Mulan"] = 2;
	section["Mowgli"] = 2;
	section["Mickey"] = 2;
	section["Silver"] = 2;
	section["Simba"] = 2;
	section["Stitch"] = 2;
	section["Dumbo"] = 3;
	section["Genie"] = 3;
	section["Jiminy"] = 3;
	section["Kuzko"] = 3;
	section["Kida"] = 3;
	section["Kenai"] = 3;
	section["Tarzan"] = 3;
	section["Tiana"] = 3;
	section["Winnie"] = 3;

	while (cin >> n)
	{
		prevStep = 1;
		totalStep = 0;
		for (i = 0; i < n; i++)
		{
			cin >> name;
			currStep = section[name];

			if (currStep == 0) 
			{
				section.erase(name);
				break;
			}
			else
			{
				totalStep += abs(currStep - prevStep);
				prevStep = currStep;
			}
			//cout << "totalStep:" << totalStep << endl;
		}
		cout << totalStep << endl;
	}


    return 0;
}


