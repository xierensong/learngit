#include <iostream>
#include <algorithm>
using namespace std;

int A[10001][101];
int paraInB[10001];
int paraEndB[10001];
int N=0,L=0;

int calcM_1(int (*A)[101])
{
        int countM = 0;
        int i,j,k;
        int start;
        fill(paraInB,paraInB+10001,0);
        fill(paraEndB,paraEndB+10001,0);
        for (i = 0; i < N; i++)
        {
                if (A[i+1][0] == 0 && A[i+1][1]==0)
                {
                        //cout << "-0-" << endl;
                        j = L - 1;
                        while(A[i][j] == 0)
                        {
                                paraEndB[countM]++;
                                j--;
                        }
                        if (A[i][0] == 0 && A[i][1] == 0)
                        {
                                start = 2;
                        }
                        else
                        {
                                start = 0;
                        }
                        for (k = j; k >= start; k--)
                        {
                                if (A[i][k]==0)
                                {
                                        paraInB[countM]++;
                                }
                        }
                        paraInB[countM] += paraEndB[countM];
                        countM++;
                }
                else
                {
                        //cout << "-1-" << endl;
                        if (A[i][0] == 0 && A[i][1] == 0)
                        {
                                start = 2;
                        }
                        else
                        {
                                start = 0;
                        }
                        for (k = L - 1; k >= start; k--)
                        {
                                if (A[i][k] == 0)
                                        paraInB[countM]++;
                        }
                }
        }
        paraInB[countM-1] -= paraEndB[countM-1];
        //cout << "in func: " << countM << endl;
        return countM;
}

int calcM(int (*A)[101])
{
        int countM = -1;
        int i = 0, j = 0, k = 0;
        fill(paraInB,paraInB+10001,0);
        fill(paraEndB,paraEndB+10001,0);
        for (i = 0; i < N; i ++)
        {
                if (A[i][0] == 0 && A[i][1] == 0)
                {
                        countM ++;
                        if ( i > 0)
                        {
                            j = L - 1;
                            while (A[i - 1][j] == 0)
                            {
                                    paraEndB[countM-1]++;
                                    j--;
                            }
                        }

                        for(k = 2; k < L; k ++)
                        {
                           if (A[i][k] == 0)
                                paraInB[countM]++;
                        } 
                }
                else
                {
                    for (k = 0; k < L; k++)
                    {
                            if (A[i][k] == 0)
                                    paraInB[countM]++;
                    }
                }
        }
        //处理最后一段末尾的0
        j = L - 1;
        while (A[N - 1][j] == 0)
        {
                paraEndB[countM]++;
                j--;
        }
        //最后一段paraInB默认去掉尾0
        paraInB[countM] = paraInB[countM] - paraEndB[countM];
    return  countM + 1;
}

int main()
{
        int M;
        int wordCount = 0;    
        while(1)
        {    
        wordCount = 0;
        cin >> N >> L >> M;

        int i,j;
        for (i = 0; i < N; i++)
                for (j = 0; j < L; j++)
                    cin >> A[i][j];
        fill(A[N],A[N]+L,0);
       //生成段落数
       int count = 0;
       count = calcM_1(A);
       /*
       cout << count << endl;
       for (i = 0; i < count; i ++)
               cout << paraInB[i] << '\t' << paraEndB[i] << endl;
        */
        if (count > M)
        {
                for (i = 0; i < M - 1; i ++)
                {
                        int loc = 0;
                        for (j = 0; j < count - 1; j++)
                        {
                                if (paraEndB[j] > paraEndB[loc])
                                        loc = j;
                        }
                        wordCount += paraInB[loc] - paraEndB[loc];
                        //cout << paraInB[loc] << '\t' << paraEndB[loc] << '\t' << paraInB[loc] - paraEndB[loc] << endl;
                        paraEndB[loc] = -1;
                        //cout << "loc:" << loc << endl;
                }
                //剩余段落开头补齐+段落(中和尾)空格
                for (i = 0; i < count; i++)
                {
                        if (paraEndB[i] != -1)
                        {
                                wordCount += 2 + paraInB[i];
                                //cout << i << '\t' <<  paraInB[i] << endl;
                        }
                }
                //末尾为空
                wordCount -= 2;
        }
        else if (count == M)
        {
                for (i = 0; i < M - 1; i ++)
                        wordCount += paraInB[i] - paraEndB[i];
         
                //文章尾空不算
                wordCount += paraInB[M - 1];
        } 
        cout << wordCount << endl;
        }
        return 0;
}
