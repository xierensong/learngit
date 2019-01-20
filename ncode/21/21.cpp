#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

bool cmp(string a, string b)
{
  return atoi(a.c_str()) < atoi(b.c_str());
}

int main()
{
    vector<string> I,R,Res;
    int n_I, n_R;
    while(cin >> n_I)
    {
      I.clear();
      R.clear();
      Res.clear();
    for(int i = 0; i < n_I; i++)
    {
        string cur;
        cin >> cur;
        I.push_back(cur);
    }
    cin >> n_R;
    for(int i = 0; i < n_R; i++)
    {
        string cur;
        cin >> cur;
        R.push_back(cur);
    }
    sort(R.begin(),R.end(), cmp);
    //剔重
    auto unique_R = unique(R.begin(), R.end());
    /*
    for(auto it = R.begin(); it != unique_R; it++)
    {
      cout << *it << endl;
    }
    */
    int len = unique_R - R.begin();
    for(int i = 0; i < len; i++)
    {
        string str_R = R[i];
		vector<string> current_R;
        for(int j = 0; j < I.size(); j++)
        {
            string str_I = I[j];
            //找到
            if (str_I.find(str_R) != -1)
            {
                current_R.push_back(to_string(j));
                current_R.push_back(str_I);
            }
        }
        if (current_R.size())
        {
            //列表头插入大小
		    current_R.insert(current_R.begin(), to_string(current_R.size() / 2));
            //列表头插入规则
            current_R.insert(current_R.begin(), str_R);
		    Res.insert(Res.end(), current_R.begin(), current_R.end());
		    current_R.clear();
        }
    }
	Res.insert(Res.begin(), to_string(Res.size()));
	for(auto it = Res.begin(); it != Res.end(); it++)
	{
		cout << *it << ' ';
	}
    cout << endl;
    }
    return 0;
}
