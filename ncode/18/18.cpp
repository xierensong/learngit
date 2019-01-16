#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void calc_LIS(vector<int> array, vector<int> &num)
{
  //cout << "enter function" << endl;
    for(int i = 1; i < array.size(); i++)
    {
      for(int j = i - 1; j >= 0; j--)
      {
        /*
        cout << array[i] << '\t' << array[j] << '\t'
          << num[i] << '\t' << num[j] << endl;
          */
        if (array[i] > array[j] && num[i] < num[j] + 1)
          num[i] = num[j] + 1;
      }
    }
}

int main()
{
  int n = 0;
  vector<int> array;
  vector<int> num;
  vector<int> reverse_num;

  while(cin >> n)
  {
    array.clear();
    num.clear();
    reverse_num.clear();
    num.insert(num.begin(), n, 1);
    reverse_num.insert(reverse_num.begin(), n, 1);
    for(int i = 0; i < n; i ++)
    {
      int item = 0;
      cin >> item;
      array.push_back(item);    
    }
    if (array.size() == 0)
      return 0;

    if (array.size() == 1)
    {
      cout << '0' << endl;
      return 0;
    }
    calc_LIS(array, num);
    reverse(array.begin(), array.end());
    calc_LIS(array, reverse_num);
    /*
    for (auto it = num.begin(); it != num.end(); it++)
      cout << *it << '\t';
    cout << endl;
    for (auto it = reverse_num.rbegin(); it != reverse_num.rend(); it++)
      cout << *it << '\t';
    cout << endl;
    */
    int max = 0;
    auto it1 = num.begin();
    auto it2 = reverse_num.rbegin();
    for (;
        it1 != num.end(), it2 != reverse_num.rend(); it1++, it2++)
    {
      int curr = *it1 + *it2 - 1;
      if (curr > max)
      {
        max = curr;
      } 
    }
    cout << array.size() - max << endl;
  }
  return 0;
}
