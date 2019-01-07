#include<iostream>
#include<string>

using namespace std;

int main()
{
    string enStr,unenStr;
    while (cin >> enStr >> unenStr)
    {
        string destStr;
        int len = enStr.size();
        for(int i = 0; i < len ; i++)
        {
            if (enStr[i] >= 'a' && enStr[i] <= 'y')
            {
                destStr.push_back(enStr[i] + 1 + 'A' - 'a');
            }
            else if (enStr[i] >= 'A' && enStr[i] <= 'Y')
            {
                destStr.push_back(enStr[i] + 1 + 'a' - 'A');
            }
            else if (enStr[i] == 'z')
            {
                destStr.push_back('A');
            }
            else if (enStr[i] == 'Z')
            {
                destStr.push_back('a');
            }
            else if (enStr[i] >= '0' && enStr[i] <= '8')
            {
              destStr.push_back(enStr[i] + 1);
            }
            else if (enStr[i] == '9')
            {
              destStr.push_back('0');
            }
        }
        cout << destStr << endl;
        destStr = "";
        len = unenStr.size();
        for(int i = 0; i < len ; i++)
        {
            if (unenStr[i] >= 'b' && unenStr[i] <= 'z')
            {
                destStr.push_back(unenStr[i] - 1 + 'A' - 'a');
            }
            else if (unenStr[i] >= 'B' && unenStr[i] <= 'Z')
            {
                destStr.push_back(unenStr[i] - 1 + 'a' - 'A');
            }
            else if (unenStr[i] == 'a')
            {
                destStr.push_back('Z');
            }
            else if (unenStr[i] == 'A')
            {
                destStr.push_back('z');
            }
            else if (unenStr[i] >= '1' && unenStr[i] <= '9')
            {
              destStr.push_back(unenStr[i] - 1);
            }
            else if (unenStr[i] == '0')
            {
              destStr.push_back('9');
            }
        }
        cout << destStr << endl;
    }
    return 0;
}
