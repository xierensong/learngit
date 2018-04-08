#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

#define MAX_VERTEX_NUM 301

typedef struct VertexType
{
	int INumber;
	string memberName;
} VertexType;

VertexType vexs[MAX_VERTEX_NUM];
int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {0};

int visited[MAX_VERTEX_NUM] = {0};

/*
	>=0:success; -1:fail.
*/
int searchVexs(int length, string memberName)
{
	int i = 0;
	for (i = 0; i < length; i ++)
	{
		//cout << memberName << '\t' << vexs[i].memberName << endl;
		if (vexs[i].memberName == memberName)		
			return i;	
	}
	return -1;	
}
void DFS(int, int);
void DFSTraverse(int length)
{
	int i = 0;
	int v = 0;
	for (i = 0; i < length; i ++)
		visited[i] = 0;

	v = searchVexs(length, "Isenbaev");
	vexs[v].INumber = 0;
	DFS(length, v);
	/*
	for (i = 0; i < length; i ++)
		if (!visited[i]) DFS(length, i);
	*/
}

void DFS(int length, int v)
{
	cout << "DFS:\tthe current vex: " << v << endl;
	int j = 0;
	visited[v] = 1;
	for (j = 0; j < length; j ++)
	{
		if (AdjMatrix[v][j] == 1)
		{
			if (!visited[j])
				DFS(length, j);
			else if (vexs[j].INumber == -1)
			{
				vexs[j].INumber = vexs[v].INumber + 1;
				//cout << "DFS:\t" << "the current vex's number:" << vexs[j].INumber << endl;
			}
		}
	}
}

void BFSTraverse(int length)
{
	int i = 0;
	int v = 0;
	int u = 0;
	
	//cout << "BFS:\t" << endl;

	for (i = 0; i < length; i ++)
		visited[i] = 0;

	queue<int> VQueue;

	v = searchVexs(length, "Isenbaev");
	vexs[v].INumber = 0;
	visited[v] = 1;
	VQueue.push(v);
	while (!VQueue.empty())
	{
		u = VQueue.front();	
		VQueue.pop();
		//cout << "current vertex:\t" << u << endl;
		for (i = 0; i < length; i ++)
		{
			if(AdjMatrix[u][i] == 1)
			{
			//cout << "enter for loop:" << endl;
			//cout << "AdjMatrix[u][i]:" << AdjMatrix[u][i] << endl;
			//cout << "i:\t" << i << endl;		
			if (!visited[i])
				{
					vexs[i].INumber = vexs[u].INumber + 1;
					//cout << "current vertex:\t" << i << '\t' << "vertex number:\t"<< vexs[i].INumber << endl;
					visited[i] = 1;
					VQueue.push(i);
				}
				//cout << endl;
			}
			/*
			else
			{
				cout << "AdjMatrix[u][i]:" << AdjMatrix[u][i] << endl;
				cout << "error !" << endl;
				cout << endl;
			}
			*/
		}
	}	

	/*
	for (i = 0; i < length; i ++)
	{
		if (!visited[v])	
		{
			visited[v] = 1;
			
		}
	}
	*/
}

int main()
{
	VertexType tmpVex;
	
	int n = 0;
	int length = 0;
	int i, j;
	int a1 = 0, a2 = 0, a3 = 0;
	int location = 0;
	string memberName;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> memberName;
		location = searchVexs(length, memberName);
		//cout << "a1's location: " << location << endl;
		if (location < 0)
		{
			vexs[length].INumber = -1;
			vexs[length].memberName = memberName;
			a1 = length;
			length ++;
		}
		else
		{
			a1 = location;
		}

		cin >> memberName;
        location = searchVexs(length, memberName);
		//cout << "a2 location: " << location << endl;
        if (location < 0)
        {   
            vexs[length].INumber = -1;
            vexs[length].memberName = memberName;
            a2 = length;	
			length ++;
        }   
        else
        {   
            a2 = location;
        }

        cin >> memberName;
        location = searchVexs(length, memberName);
		//cout << "a3 location: " << location << endl;
        if (location < 0)
        {   
            vexs[length].INumber = -1;
            vexs[length].memberName = memberName;
            a3 = length;
			length ++;
        }   
        else
        {   
            a3 = location;
        }
		//cout << "a1 a2 a3:" << a1 << '\t' << a2 << '\t' << a3 << endl;		
		AdjMatrix[a1][a2] = 1;
		AdjMatrix[a2][a3] = 1;
		AdjMatrix[a1][a3] = 1;	
		AdjMatrix[a2][a1] = 1;
		AdjMatrix[a3][a2] = 1;
		AdjMatrix[a3][a1] = 1;	
	}
	/*
	for (i = 0; i < length; i ++)
	{
		cout << "i:\t" <<i << '\t' << vexs[i].INumber << '\t' <<  vexs[i].memberName << endl;
	}
	*/
	int count = 0;
	for (i = 0; i < length; i ++)
	{	
		//cout << endl;
		for (j = 0; j < length; j ++)
		{
			//cout << AdjMatrix[i][j] << '\t';
			count += AdjMatrix[i][j];
		}
		//cout << '\t' << vexs[i].memberName;
	}
	//cout << endl;
	//cout << "count: " << count << endl;
	BFSTraverse(length);
	/*
	for (i = 0; i < length; i ++)
		cout << "i:\t" <<i << '\t' << vexs[i].INumber << '\t' <<  vexs[i].memberName << endl;
	*/
	map<string, int> memberRelation;
	map<string, int>::iterator iter;
	for (i = 0; i < length; i++)
		memberRelation[vexs[i].memberName] = vexs[i].INumber;

	for (iter = memberRelation.begin(); iter != memberRelation.end(); iter++)
	{
		if (iter->second == -1)
			cout << iter->first << ' ' << "undefined" << endl;
		else
			cout << iter->first << ' ' << iter->second << endl;
	}

	
	return 0;
}
