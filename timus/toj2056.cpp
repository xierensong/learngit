#include <iostream>

using namespace std;

int marks[11] = {0};
int main()
{
	int n;
	int i = 0;
	int hasSatisfactoryMarks = 0;
	float averageMarks = 0.0;
	float totalMarks = 0.0;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> marks[i];
		totalMarks += marks[i];		
	}
	
	averageMarks = totalMarks / n;

	for (i = 1; i <= n; i++)
	{
		if (marks[i] == 3)
		{
			hasSatisfactoryMarks = 1;
			break;
		}	
	}

	if (hasSatisfactoryMarks == 1)
		cout << "None" << endl;
	else if (averageMarks == 5.0)
		cout << "Named" << endl;
	else if (averageMarks >= 4.5)
		cout << "High" << endl;
	else 
		cout << "Common" << endl;
		
	return 0;
}
