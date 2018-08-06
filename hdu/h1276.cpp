#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main()
{
        int N = 0;
        scanf ("%d", &N);
        while (N--)
        {
            int M = 0;
            queue<int> myQ[2];
            scanf ("%d", &M);
            int i = 0;
            for (i = 1; i <= M; i++)
                myQ[0].push(i);
            int loop = 0; //报数循环

            while (1)
            {
               //cout << "loop: " << loop << endl;
               int No = loop % 2;
               //2报数
               if (No == 0)
               {
                   //cout << "2报数" << endl;
                   int length = myQ[No].size();
                   //cout << "length: " << length << endl;
                   if (length <= 3)
                    {      
                            length --;
                            while (length--)
                            {
                                    cout << myQ[No].front() << ' ' ;
                                    myQ[No].pop();
                            }
                            /*
                            while (!myQ[No].empty())
                            {
                                    cout << myQ[No].front() << ' ';
                                    myQ[No].pop();
                                    if (myQ[No].empty()==0)
                                    {
                                            cout << myQ[No].front();
                                            break;
                                    }
                            }*/
                            cout << myQ[No].front() << endl;
                            //cout << endl;
                            break;
                    }
                    else
                    {
                        for (int i = 1; i <= length; i ++)
                        {
                                int value = myQ[No].front();
                                //cout <<"current value: " << value << endl;
                                int Np = (No + 1) % 2;
                                if (i % 2 != 0)
                                {
                                        myQ[Np].push(value);
                                }
                                myQ[No].pop();

                        }
                    }
               }
               //3报数
               else
               {
                    //cout << "3报数" << endl;
                    int  length = myQ[No].size();
                    //cout << "length: " << length << endl;
                    if (length <= 3)
                    {
                            length --;
                            while (length--)
                            {
                                    cout << myQ[No].front() << ' ';
                                    myQ[No].pop();
                            }
                            /*
                            while (!myQ[No].empty())
                            {
                                    cout << myQ[No].front() << ' ';
                                    myQ[No].pop();
                                    if (myQ[No].empty() == 0)
                                    {
                                            cout << myQ[No].front();
                                            break;
                                    }
                            }*/
                            cout << myQ[No].front() << endl;
                            //cout << endl;
                            break;
                    }
                    else
                    {
                            //while (!myQ[No].empty())
                            for (int i = 1; i <= length; i ++)
                            {
                                    int value = myQ[No].front();
                                    //cout <<"current value: " << value << endl;
                                    int Np = (No + 1) % 2;
                                    if (i % 3!= 0)
                                    {
                                            myQ[Np].push(value);
                                    }
                                    myQ[No].pop();
                            }
                    }
               }
               loop ++;            
            }            
        }

        return 0;
}
