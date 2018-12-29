#include<iostream>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

int a[10]; // 入栈序列
int b[10]; // 出栈序列
int N;

int valid()
{
    stack<int> st;
    int i = 0;
    int j = 0;
    //入栈
    for (i = 0; i < N; i ++)
    {
        st.push(a[i]);
        while(!st.empty())
        {
            int topVal = st.top();
            //如果当前元素满足
            if (topVal == b[j])
            {
                //cout << "pass:" << topVal << endl;
                st.pop();
                j++;
            }
            else
            {
              //cout << "match fail" << endl;
              break;
            }
        }
    }
    //判栈内序列
    while(!st.empty())
    {
      int at = st.top();
      if (at == b[j])
      {
        //cout << " out stack:" << at << endl;
        st.pop();
        j++;
      }
      else
      {
        //cout << " error " << endl;
        return 0;
      }
    }
    return 1;
}

int cmp(int a, int b)
{
  return a < b;
}

int main()
{
  vector<string> output;
  string tmpStr = "";

  cin >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> a[i];
    b[i] = a[i];
    tmpStr += a[i] + '0'; 
  }
  sort(b, b + N, cmp);

  //cout << tmpStr << endl;
  //output.push_back(tmpStr); 
  do
  {
    //cout << "current " << endl;
    //for (int i = 0; i < N; i ++)
      //cout << b[i] << ' ';
    //cout << endl;
    
    string tmpStr = "";

    if (valid())
    {
        for(int i = 0; i < N; i++)
            tmpStr += b[i] + '0';
        //cout << tmpStr << endl;
        output.push_back(tmpStr);
    }
  }
  while(next_permutation(b, b + N));

  //cout << "xulie" << endl;
  for (auto it = output.begin(); it != output.end(); it ++)
  {
    int size = it->size();
    for (int i = 0; i < size; i++)
        cout << (*it)[i] << ' ';
    cout << endl;
  }
  return 0;
}
