#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	string str;
	int a1 = 0, a2 = 0, a3 = 0;	

	cin >> n;
	getline(cin,str);
	while (n > 0)
	{
			
		getline (cin, str);
		if ( str == "Emperor Penguin")
			a1++;	
		else if (str == "Macaroni Penguin")
			a2++;
		else if (str == "Little Penguin")
			a3++;
		/*
			cout << "n:" << n << " str:" << str << endl;
		
		cout << "a1,a2,a3: " << a1 << '\t' << a2
			 << '\t' << a3 << endl;
		*/
		n--;	
	}
	
	if (a1 > a2)
	{
		if (a1 > a3)
			cout << "Emperor Penguin" << endl;
		else
			cout << "Little Penguin" << endl;
	}
	else
	{
		if (a2 > a3)
			cout << "Macaroni Penguin" << endl;
		else
			cout << "Little Penguin" << endl;
	}

	return 0;
}
