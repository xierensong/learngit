#include <iostream>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
        int n = 0;
        while (~scanf("%d", &n))
        {
                char str1[11], str2[11];
                scanf ("%s%s", str1,str2);
                stack<char> myStack;
                vector <string> myVect;
                int j = 0;
                for (int i = 0; i < n; i++)
                {
                        if (str1[i] == str2[j])
                        {
                            /*
                            cout << "0: " << "i: " << i << '\t'
                                    << "str1: " << str1[i] << '\t'
                                    << "j: " << j << '\t'
                                    << "str2: " << str2[j] << '\t'
                                    << endl;
                                    */
                            myVect.push_back("in");
                            j ++;
                            while (!myStack.empty())
                            {
                                    //cout << "00: " << endl;
                                    char ch1 = myStack.top();
                                    //cout << "ch1: " << ch1 << endl;
                                    if (ch1 == str2[j])
                                    {
                                            /*
                                            cout << "000: " << "j: " << '\t' << j << '\t'
                                                    << "str2: " << str2[j] << endl; */
                                            myStack.pop();
                                            myVect.push_back("out");
                                            j++;
                                    }
                                    else
                                    {
                                            break;
                                    }
                            }
                            myVect.push_back("out");
                        }
                        else
                        {
                                /*
                                cout << "1: " << "i: " << i << '\t'
                                       << "str1: " << str1[i] << endl; 
                                       */
                                myStack.push(str1[i]);
                                myVect.push_back("in");
                        }
                }
                if (j >= n - 1)
                {
                        cout << "Yes." << endl;
                        for (vector<string>::iterator it = myVect.begin();
                               it != myVect.end(); ++it)
                                cout << *it << endl;
                        cout << "FINISH" << endl;
                }
                else
                {
                        cout << "No." << endl;
                        cout << "FINISH" << endl;
                }
        }
        return 0;
}
