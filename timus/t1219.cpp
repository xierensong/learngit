#include <iostream>

using namespace std;

int main()
{
        int length = 1000000;
        int i, j, k, l;
        while (length <= 1000000)
               for (j = 0; j <= 25; j++)
                       for (k = 0; k <= 25; k++)
                               for (l = 0; l <= 25; l++)
                               {
                                       if (length > 0)
                                       {
                                               cout << (char)('a' + j);
                                               length --;
                                       }
                                       if (length > 0)
                                       {
                                               cout << (char)('a' + k);
                                               length --;
                                       }
                                       if (length > 0)
                                       {
                                               cout << (char)('a' + l);
                                               length --;
                                       }
                                       //cout << endl;
                                       if (length <= 0)
                                               return 0;
                               }
        return 0;
}
