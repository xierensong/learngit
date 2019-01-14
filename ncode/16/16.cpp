#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
  string numStr1, numStr2, sumStr, tmpStr1, tmpStr2;
  while(cin >> tmpStr1 >> tmpStr2)
  {
    numStr1.clear();
    numStr2.clear();
    sumStr.clear();
    for(int i = tmpStr1.size() - 1; i >= 0; i --)
      numStr1.push_back(tmpStr1[i]);
    for(int i = tmpStr2.size() - 1; i >= 0; i --)
      numStr2.push_back(tmpStr2[i]);
    int minLen = min(numStr1.size(), numStr2.size());
    int maxLen = max(numStr1.size(), numStr2.size());
    if (numStr1.size() > numStr2.size())
    {
        for (int i = minLen; i < maxLen; i ++)
          numStr2.push_back('0');
    }
    else
    {
      for (int i = minLen; i < maxLen; i ++)
        numStr1.push_back('0');
    }
    int carry = 0, current_value = 0;
    for (int i = 0; i < maxLen; i ++)
    {
        current_value = numStr1[i] + numStr2[i] - '0' * 2 + carry;
        if (current_value > 9)
        {
          carry = 1;
        }
        else
        {
          carry = 0;
        }
        current_value = current_value % 10;
        sumStr.push_back(current_value + '0');
    }
    if(carry == 1) sumStr.push_back('1');
    //for (int i = sumStr.size(); i >= 0; i --)
     //   cout << sumStr[i];
    reverse(sumStr.begin(), sumStr.end()); 
    cout << sumStr <<  endl;
  }

  return 0;
}
