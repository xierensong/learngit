#include <iostream>
#include <string>

using namespace std;

string makePalindrome (string str, int flag)
{
        string newStr = str, a="x";
        int length = newStr.size();
        int i = 0;

        // i:前半部分游标
        i = (flag == 0) ? (length - 1) : (length - 2);
        //j:后半部分游标
        for (; i >= 0; i --)
        {
            a[0] = str[i];
            newStr.append(a);
        }
        //cout << newStr << endl;
        return newStr;
}

string addone (string str)
{
   int length = str.size();
   int i = 0;
   int flag = 0, midPos = 0,start = 0;
   string a = "x";
   i = length - 1;
   while (str[i] >= '9')
   {
           str[i] = '0';
           i --;
           if (i < 0)
           {
                str.insert(0,"1");
                a[0] = '1';
                str.append(a);
                break;
           }
   } 
   str[i]++;
   return str;
}
int main()
{
    string str = "", halfStr = "", palindrome = "", a = "x";
    int i,pos,length = 0, flag = 0;

    cin >> str;
    flag = str.size() % 2 == 0 ? 0 : 1;
    pos = (flag == 0) ? (str.size() / 2 - 1) : (str.size() / 2);
    halfStr = str.substr(0, pos + 1);
    palindrome = makePalindrome(halfStr, flag);
    while  (palindrome < str)
    {
          halfStr = addone(halfStr);
          //cout << "halfStr:" << halfStr << endl;
          palindrome = makePalindrome(halfStr, flag);
          //cout << "palindrome:" << palindrome << endl;
    }
    
    cout << palindrome << endl;
    return 0;
}
