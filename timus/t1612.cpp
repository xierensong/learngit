#include <iostream>
#include <string>

using namespace std;
int main()
{
    string word = "";
    int tramCount = 0;
    int trolleyCount = 0;
    int busCount = 0;
    
    while (cin >> word)
    {
        //去符号
       int pos = 0;
       int length = 0;
       string word1 = "";

       while (word.size() != 0)
       {
         pos = word.find_first_of(".,:!?-");  
         //cout <<"pos: " << pos << endl;
         if (pos != -1)    
         {
            length = word.size();           
            word1 = word.substr(0,pos);
            //cout << "word1:" << word1 << endl;
            word = word.substr(pos+1, word.size());
            //cout << "new word: " << word << endl;
         }
         else
         {
            word1 = word;
            word = "";
         }
         if (word1.substr(0,4) == "tram" && word1.size() == 4)
            tramCount ++;
         if (word1.substr(0,10) == "trolleybus" && word1.size() == 10)
            trolleyCount ++;
         if (word1.substr(0,3) == "bus" && word1.size() == 4)
            busCount ++;
       }
    }
    if (tramCount > trolleyCount)
        cout << "Tram driver" << endl;
    else if (trolleyCount > tramCount)
        cout << "Trolleybus driver" << endl;
    else
        cout << "Bus driver" << endl;
    return 0;
}

