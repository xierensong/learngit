#include <iostream>
#include <string>

using namespace std;


string printA(int n)
{
	int i = 0;
	//char charI;
	string stringA = "";
	if ( n == 1)
	{
		stringA = "sin(1)";
		return stringA;
	}
	for (i = 1; i <= n; i++)
	{
		string s3 = i % 2 ? "+" : "-";
		string s0 = (i == 1)? "" : s3;
		string s1 = "sin(";
    	string s2 = to_string(i);
    	stringA += s0 + s1 + s2;
	}
	string s6(n, ')');
	stringA += s6;
	//cout << "printA:" <<  stringA << endl;
	return stringA;
}

string printS(int n)
{
	string stringS(n - 1, '(');
	int i = 0;
	for (i = 1; i <= n; i ++)
	{
		string s0 = (i == 1) ? "" : ")";
		string s1 = printA(i);
		string s2 = "+";
		string s3 = to_string(n + 1 - i);
		stringS += s0 + s1 + s2 + s3;
		//cout << stringS << endl;
	}
	return stringS;
}

int main()
{
	int n;
	string stringS = "";
	cin >> n;
	
	if (n == 0) 
	{
		cout << "+1" << endl;
		return 0;
	}
	stringS = printS(n);	
	cout << stringS << endl;
	return 0;
}
