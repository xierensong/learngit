#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int n = 0;
    vector<string> strVec;
    string str="";
    cin >> n;
    while(n--)
    {
        cin >> str;
        strVec.push_back(str);
    }
    for(auto it = strVec.begin(); it != strVec.end(); it++)
        cout << *it << endl;
    return 0;
}
