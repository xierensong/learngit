#include <iostream>

using namespace std;

typedef struct 
{
        int number;
        int sameNum;
        int samePos;
} GuessList;

int checkSameNum(int A[], int B[])
{
        int i = 0, j = 0;
        int result = 0;
        //cout << A[0] << '\t' <<  A[1] << '\t' << A[2] << '\t' << A[3] << endl;
        //cout << B[0] << '\t' <<  B[1] << '\t' << B[2] << '\t' << B[3] << endl;
        for (i = 0; i < 4; i ++)
        {
                for (j = 0; j < 4; j++)
                {
                        if (B[i] == A[j])
                        {
                            result ++;
                            A[j] = -1;
                            break;
                        }
                }
        }
        //cout<< "Number result: " << result << endl;

        return result;
}
int checkSamePos(int A[], int B[])
{
        int result = 0;
        int i = 0, j = 0;
        //cout << A[0] << '\t' <<  A[1] << '\t' << A[2] << '\t' << A[3] << endl;
        //cout << B[0] << '\t' <<  B[1] << '\t' << B[2] << '\t' << B[3] << endl;
        
        for (i = 0; i < 4; i++)
        {
                if (A[i] == B[i])
                        result ++;
        }
        //cout << "Pos result: " << result << endl;
        return result;
}
int main()
{
        int N = 0;
        GuessList guessList[100];
        int listLen = 0;
        int i,j;
        int flag = 0,result = 0;
        while (cin >> N)
        {
                if (N == 0)
                        break;
                flag = 0;
                for (i = 0; i < N; i ++)
                        cin >> guessList[i].number >> guessList[i].sameNum >> guessList[i].samePos;
                for (i = 1000; i <= 9999; i ++)
                {
                        //flag = 0;
                        //cout << "i:" << i << endl;
                        for (j = 0; j < N; j ++)
                        {
                                int A,B,C;
                                //cout << "j: " << j << endl;
                                A = guessList[j].number;
                                B = guessList[j].sameNum;
                                C = guessList[j].samePos; 
                                //cout << "A: " << A << endl;
                                int AList[4] = {A % 10, (A % 100) / 10, (A % 1000) / 100, A / 1000};
                                int BList[4] = {i % 10, (i % 100) / 10, (i % 1000) / 100, i / 1000};
                                int samePos = checkSamePos(AList, BList);
                                if (samePos != C)
                                {
                                        //cout << "no same position!" << endl;
                                        break;
                                }
                                int sameNum = checkSameNum(AList, BList);
                                if (sameNum != B)
                                {
                                        //cout << " no same number!" << endl;
                                        break;
                                }
                                else
                                        continue;
                                
                        }
                        if (j == N)
                        {
                            if (flag == 0)
                            {
                                    result = i;
                                    flag = 1;
                            }
                            else if (flag == 1)
                            {
                                    flag = 2;
                            }
                            else if (flag == 2)
                            {
                                    break;
                            }
                        }
                        //cout << "flag: " << flag << endl;
                }
                if (i == 10000)
                {
                        if (flag == 1)
                        {
                            cout << result << endl;
                        }
                        else
                        {
                            cout << "Not sure" << endl;
                        }
                }
                else
                    cout << "Not sure" << endl;
        }
        return 0;
}
