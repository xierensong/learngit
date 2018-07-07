#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string line = "", reverseLine = "";
    stack<char> S;
    int lineLen = 0;
    int i = 0; 
    string tmp = "a";
    
    while (getline(cin, line))
    {
        reverseLine = "";
        lineLen = line.size();
        //cout << "line length: " << lineLen << endl;
        //cout << " line : " << line << endl;
        i = 0;
        while (i <= lineLen - 1)   
        {
           if ((line[i] >='a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
           {
               //cout << "current char: " << line[i] << endl;
               S.push(line[i]);
           }
           else
           {
               while (!S.empty()) 
                {
                    tmp[0] = S.top();
                    //cout << "tmp: " << tmp[0] << endl;
                    reverseLine.append(tmp);
                    //cout << " reverse line:" << reverseLine << endl;
                    S.pop();
                }
               tmp[0] = line[i];
               reverseLine.append(tmp); 
           }
           i++;
        }
        while (!S.empty())
        {
           tmp[0] = S.top();
           reverseLine.append(tmp);
           S.pop(); 
        }
        //cout << "werqe" << endl;
        cout << reverseLine << endl; 
    }
            
    return 0;
}
