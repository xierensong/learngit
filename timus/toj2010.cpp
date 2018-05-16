#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long n, x, y;
	long King_hits, Knight_hits, Bishop_hits, Rook_hits, Queen_hits;

	cin >> n;
	cin >> x >> y;

	King_hits = 0;
	if (x + 1 <= n)
		King_hits ++;
	if (x - 1 >= 1)
		King_hits ++;
	if (y + 1 <= n)
		King_hits ++;
	if (y - 1 >= 1)
		King_hits ++; 
	if (x + 1 <= n && y + 1 <= n)
		King_hits ++;
	if (x + 1 <= n && y - 1 >= 1)
		King_hits ++;
	if (x - 1 >= 1 && y + 1 <= n)
		King_hits ++;
	if (x - 1 >= 1 && y - 1 >= 1)
		King_hits ++;
	
	cout << "King: " << King_hits << endl;

	Knight_hits = 0;
	if (x + 1 <= n && y + 2 <= n)
		Knight_hits ++;
	if (x + 1 <= n && y - 2 >= 1)
		Knight_hits ++;
	if (x - 1 >= 1 && y - 2 >= 1)
		Knight_hits ++;
	if (x - 1 >= 1 && y + 2 <= n)
		Knight_hits ++;

    if (x + 2 <= n && y + 1 <= n)
        Knight_hits ++; 
    if (x + 2 <= n && y - 1 >= 1)
        Knight_hits ++; 
    if (x - 2 >= 1 && y - 1 >= 1)
        Knight_hits ++; 
    if (x - 2 >= 1 && y + 1 <= n)
        Knight_hits ++; 
	cout << "Knight: " << Knight_hits << endl;

	Bishop_hits = 0;
	int leftX = x - 1;
	int leftY = y - 1;
	int rightX = n - x;
	int rightY = n - y;
	Bishop_hits += min (leftX, leftY);
	Bishop_hits += min (leftX, rightY);
	Bishop_hits += min (rightX, leftY);
	Bishop_hits += min (rightX, rightY);
	cout << "Bishop: " << Bishop_hits << endl;
	
	Rook_hits = 2 * n - 2;
	cout << "Rook: " << Rook_hits << endl;

	Queen_hits = Rook_hits + Bishop_hits;
	cout << "Queen: " << Queen_hits << endl;
	return 0;
}
