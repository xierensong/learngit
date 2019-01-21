#include<iostream>
#include<algorithm>
using namespace std;

int p[120]; //每件商品的单价
int b[120]; //每件商品的积分
int v[120]; //每件商品的价值
int dp[120][120][10];
int main()
{
  int n,v1,v2,k;
  while(cin >> n >> v1 >> v2 >> k)
  {
    int  price, bonus, value;
    for(int i = 1; i < 120; i++)
    {
      p[i] = 0;
      b[i] = 0;
      v[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
      cin >> price >> bonus >> value;
      p[i] = price;
      b[i] = bonus;
      v[i] = value;
    }    
    for(int ii = 0; ii < 120; ii++)
      for(int jj = 0; jj < 120; jj++)
        for(int kk = 0; kk < 10; kk++)
        dp[ii][jj][kk] = 0;

    //前ii个商品
    for(int ii = 1; ii <= n; ii++)
    {
      //cout <<"ii:" << '\t' << ii << '\t' << n << endl;
      //小于jj钱
      for(int jj = v1; jj >= 0; jj--)
      {
        //cout <<"jj:" << '\t' <<  jj << '\t' << v1 << endl;
        //小于kk积分
        for(int kk = v2; kk >= 0; kk--)
        {
          //cout <<"kk:" << '\t' <<  kk << '\t' << v2 << endl;
          for(int ll = k; ll >= 0; ll--)
          {
            //cout <<"ll:" << '\t' << ll << '\t' << k << endl;
            int maxValue = 0;
            maxValue = max(dp[jj][kk][ll], maxValue);
            if(jj - p[ii] >= 0)
                maxValue = max(maxValue, dp[jj-p[ii]][kk][ll] + v[ii]);
            if(kk-b[ii] >= 0)
                maxValue = max(maxValue, dp[jj][kk-b[ii]][ll] + v[ii]);
            if (ll - 1 >= 0)
               maxValue = max(maxValue, dp[jj][kk][ll - 1] + v[ii]);
            dp[jj][kk][ll] = maxValue;
            //cout << ii << '\t' << jj << '\t' << kk  << '\t' << ll <<
             //'\t' << dp[ii][jj][kk][ll] << endl;
          }
        }
      }
    }
    cout << dp[v1][v2][k] << endl;
  }
  return 0;
}
