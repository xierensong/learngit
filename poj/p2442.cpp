#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

//int a[105][2005];
int old[2005],new1[2005], heap[2005];
int main()
{
        int T;
        scanf ("%d", &T);
        while (T--)
        {
                int m, n;
                int heapTop = 0, cValue = 0;
                scanf ("%d%d", &m, &n);
                int i = 0, j = 0, k = 0,l = 0;
                /*
                for (i = 0; i < m; i++)
                        for (j = 0; j < n; j ++)
                            scanf ("%d", & a[i][j]);
                            
                //初始化
                for (i = 0; i < n; i ++)
                        old[i] = a[0][i];
                */
                for (i = 0; i < n; i ++)
                        scanf ("%d" , &old[i]);
                sort(old, old + n);
                /*
                for (int i = 0; i < n; i ++)
                        heap[i] = old[i];
                        */
                for (i = 1; i < m; i ++)
                {
                        /*
                        cout << "old:" << endl;
                        for (j = 0; j < n; j ++)
                        {
                                cout << old[j] << '\t';
                        }
                        cout << endl;
                        
                        cout << "new:" << endl;
                        for (int j = 0; j < n; j ++)
                        {
                                cout << new1[j] << '\t';
                        }
                        cout << endl;
                        cout << "heap:" << endl;
                        for (int j = 0; j < n; j ++)
                        {
                                cout << heap[j] << '\t';
                        }
                        cout << endl;
                        */
                        /*
                        for (j = 0; j < n; j ++)
                                new1[j] = a[i][j];
                        */
                        for (j = 0; j < n; j ++)
                                scanf ("%d", &new1[j]);
                        sort (new1, new1 + n);
                        /*
                        cout << "new1:" << endl;
                        for (j = 0; j < n; j ++)
                                cout << new1[j] << '\t';
                        cout << endl;
                        */
                        for (j = 0; j < n; j ++)
                                heap[j] = old[0] + new1[j];
                        /*
                        cout << "heap0:" << endl;
                        for (j = 0; j < n; j ++)
                                cout << heap[j] << '\t';
                        cout << endl;
                        */
                        make_heap (heap, heap + n);
                        //pop_heap (heap, heap + n);
                        /*
                        cout << "heap1:" << endl;
                        for (int j = 0; j < n; j++)
                                cout << heap[j] << '\t';
                        cout << endl;
                        */
                        //heapTop = heap[n-1];
                        /*
                        cout << "heapTop: " << heapTop << endl;
                        */
                        for (j = 1; j < n; j ++)
                        {
                                for (k = 0; k < n && old[j] + new1[k] < heap[0]; k ++)
                                {
                                      //cout << "exchange " << endl;
                                      pop_heap (heap, heap + n);
                                      heap[n-1] = old[j] + new1[k];
                                      push_heap (heap, heap + n);
                                }
                                /*
                                if (k < n)
                                        break;
                                        */
                        }
                        /*
                        cout << "heap2: " << endl;
                        for (int j = 0; j < n; j ++)
                                cout << heap[j] << '\t';
                        cout << endl;
                        */
                        //push_heap(heap, heap + n);
                        sort_heap(heap, heap + n);
                        /*
                        cout << "heap3: " << endl;
                        for (int j = 0; j < n; j ++)
                                cout << heap[j] << '\t';
                        cout << endl;
                        */
                        for (j = 0; j < n; j ++)
                                old[j] = heap[j];
                }
                for (i = 0; i < n - 1; i ++)
                {
                        //cout << old[i] << ' ';
                        printf ("%d ", old[i]);
                }
                printf ("%d\n",old[n - 1]);
                //cout << old[n - 1] << endl;

        }
        return 0;
}
