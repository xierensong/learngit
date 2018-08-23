#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define mod 1000000
#define MAX 100005
//int cows[100005];
int feature[100005][31];
int c[1000005][31];
//int HashTable[92083];
int HashTable[MAX*10];
int K = 0;

int Hash(int *array)
{
	int s = 0;
	for (int i = 0; i<K; i++)
		s = ((s << 2) + (array[i] >> 4)) ^ (array[i] << 10);
	s = s % 92083;
	s = s < 0 ? s + 92083 : s;
	return s;
}

int Hash_1(int *cc)
{
	int j,key=0;
	for(j=1;j<K;j++)
		key=key% mod +cc[j]<<2;//此处用 * 乘超时 
	key=abs(key)% mod;//此处得到的key可能会是负数，所以取绝对值 

	return key;
}

void print(int N)
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << feature[i][j] << '\t';
		cout << endl;
	}
}

int main()
{
	int N;
	int tmp = 0, x = 0;
	int maxLen = 0;
	scanf("%d %d", &N, &K);
	//memset(cows, 0, N);
	memset(feature[0], 0, K);
    memset(HashTable, -1, sizeof(HashTable));
    HashTable[0] = 0;
    int key = 0;
    int j = 0;
    //int *a, *b;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &x);
		
		for (j = 0; j < K; j++)
		{
			//feature[i][K - 1 - j] = x % 2;
            feature[i][K - 1 - j] = feature[i - 1][K - 1 - j] + x % 2;
            c[i][K - 1 - j] = feature[i][K - 1 - j] - feature[i][K - 1];
			x = x >> 1;
		}
		key = Hash_1(c[i]);
		/*	
	    if (HashTable[key] == -1)
	    {
			HashTable[key] = i;
			
		}
		*/
		while (HashTable[key] != -1)
		{
				j = 0;
				//比较feature数组是否相同
				while (j < K)
				{
					//if (*(a + j) == *(b + j))
                    if (c[i][j] == c[HashTable[key]][j])
						j++;
					else
						break;
				}
				//遇到相同数组,计算间隔。
				if (j == K && maxLen < (i - HashTable[key]))
				{
				    maxLen = i - HashTable[key];
					break;
				}
				//处理冲突
				key= (key+1) % (MAX * 10);
                //key = (key+1) % 92083;
		}
        
        if (HashTable[key] == -1)
        {
            HashTable[key] = i;

        }
        
		//cout << "key " << key << '\t'
		//    << "hashtable " << HashTable[key] << endl;
		//cout << "maxLen " << maxLen << endl;
	}
	cout << maxLen << endl;

	return 0;
}
