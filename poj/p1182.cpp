#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 50005
int array[MAX * 3];

void init()
{
    for (int i = 1; i < MAX * 3; i ++)
        array[i] = i;
}

int find (int x)
{
    //if root node
    if (array[x] == x)
        return x;
    //not root node
    else
        //update root in the path recursly
        return array[x] = find(array[x]);
}

void Union (int x, int y) 
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        array[fx] = fy;
}

void print()
{
    for (int i = 1; i <= 80; i++)
        cout << array[i] << '\t';
    cout << array[50001] << '\t'
        << array[50002] << '\t'
        << array[50003] << endl;
}
int main()
{
    int N,K;
    int fake = 0;
    scanf ("%d%d", &N, &K);
    
    fake = 0;
    init();
    //scanf ("%d%d", &N, &K);
    while (K--)
    {
        int D,X,Y;
        scanf ("%d%d%d", &D, &X, &Y);

        //rule 2
        if (X > N || Y > N)
        {
            fake++;
            continue;
        }
        //rule 3
        if (D == 2 && X == Y)
        {
            fake++;
            continue;
        }
        //rule 1
        if (D == 1)
        {
            if (find(X) == find(Y + N) || find(X) == find(Y + 2 * N))
                fake ++;
            else
            {
                Union (X, Y);
                Union (X + N, Y + N);
                Union (X + 2 * N, Y + 2 * N);
            }
        }
        else if (D == 2)
        {
            if (find(X) == find(Y) || find(X) == find(Y + 2 * N))
                fake ++;
            else
            {
                Union(X, Y + N);
                Union(X + N, Y + 2 * N);
                Union(X + 2 * N, Y);
            }
        }
        //print();
        //cout << "fake: " << fake << endl;
    }
	cout << fake << endl;
    
    return 0;
}
