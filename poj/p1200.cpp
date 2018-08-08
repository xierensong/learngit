#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

#define N 16000001

bool hash[N];
char a[N];
int id[500];

int main()
{
    int n, nc;
    while (~scanf ("%d%d", &n, &nc))
    {
          scanf("%s", a);
          int strLen = strlen(a);
          int cnt = 0;
          int i = 0, j = 0;
          //init false
          memset(hash, false, sizeof(N));
          //初始化为-1
          memset(id, -1, sizeof(id));
          //生成id
          for (i = 0; i < strLen && cnt < nc; i ++)
          {
            if (id[a[i]] != -1 )
                  continue;
            id[a[i]] = cnt;  
            //cout << "id " << a[i] << '\t' << cnt << endl;
            cnt ++;
          }
          
          int ans = 0;
          for (i = 0; i < strLen - n + 1; i ++)
          {
                  int s = 0;
                  for (j = i; j < n + i; j ++)
                  {
                      s = s * nc + id[a[j]]; 
                      //cout << "s0: " << s << endl;
                  }
                  //cout << "s: " << s << endl;
                  if (hash[s])
                          continue;
                  ans++;
                  hash[s] = true;
          }
          printf ("%d\n", ans);


    }

    return 0;
}
