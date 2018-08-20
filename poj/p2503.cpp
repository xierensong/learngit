#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, string> dict;

    string line = "", value = "", key = "";
    //char line[100];
    //char value[100], key[100];
    int v_pos = 0, k_pos = 0;

    while (1)
    {
        
        getline(cin, line);
        if (line == "")
          break;
        
        /* 2
        cin.getline(line, 100);
        if (cin.gcount() == 1)
            break;       
        
        sscanf(line, "%s %s", value, key); 
        */
        v_pos = line.find(' ');  //查找第一个空格位置
        value = line.substr(0, v_pos); //取子串
        k_pos = line.rfind(' '); //找最后一个空格位置
        key = line.substr(v_pos + 1, k_pos - v_pos - 1); //取子串
        //cout << value << '\t' << key << endl;

        dict.insert(pair<string, string>(key, value));
    }
    char query[100];
    //while (cin >> query)  1
    while (~scanf("%s", query))
    {
       if ( dict.find(query) != dict.end() )
           cout << dict[query] << endl;
       else
           cout << "eh" << endl;
    }
    return 0;
}
