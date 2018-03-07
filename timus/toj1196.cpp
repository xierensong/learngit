#include <iostream>

using namespace std;

int searchDate (int *list, int length, int beSearched)
{
	int searchResult = 0; /*1:success; 0:failure.*/
	int start = 1, end = length;
	int mid = 0;

	/*cout << "list[1]" << list[1] << 
		 "length" << length <<
     	 "beSearched" << beSearched << endl;
*/
	while (start <= end)
	{
/*		cout << "start:" << start << 
			    "end:" << end << endl;
*/		mid = (end + start) /2;
		if (list[mid] == beSearched)
		{
			searchResult = 1;	
			break;
		}
		else if (list[mid] < beSearched)
		{
			start = mid + 1;	
/*			cout << "new start: " << start << endl;;
*/		}
		else
		{
			end = mid - 1;
/*			cout << " new end: " << end << endl;
*/		}
	}
/*	cout << "searchResult:" << searchResult << endl;
*/	return searchResult;	
}

int professorList[15001];
int main()
{
	int professorListLength;
	int studentListLength;
	int studentDate;
	int i;
	int coincidences = 0;
	
	cin >> professorListLength;
	for (i = 1; i <= professorListLength; i++)
	{
		cin >> professorList[i];
	}
	cin >> studentListLength;
	for (i = 1; i <= studentListLength; i++)
	{
		cin >> studentDate;
		if (searchDate(professorList, professorListLength, studentDate) == 1)
		{
			coincidences++;
		}
	}	
	cout << coincidences << endl;
	return 0;
}
