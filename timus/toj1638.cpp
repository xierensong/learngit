#include <iostream>

using namespace std;

int main()
{
	int volumeNoCover = 0;
	int cover = 0;
	int firstVolumeNo = 0;
	int endVolumeNo = 0;
	int book = 0;

	cin >> volumeNoCover >> cover 
		>> firstVolumeNo >> endVolumeNo;

	book = volumeNoCover + cover * 2;	

	if (firstVolumeNo < endVolumeNo)
	{
		cout << (endVolumeNo - firstVolumeNo - 1) * book + 2 * cover << endl;	
	}
	else
	{
		cout << (firstVolumeNo - endVolumeNo) * book + volumeNoCover << endl;
	}
	return 0;
}
