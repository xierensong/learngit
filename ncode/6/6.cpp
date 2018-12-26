#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct GradeType
{
    string name;
    int grade;
}GradeType;

int cmp1(GradeType g1,GradeType g2)
{
    return g1.grade > g2.grade;
}
int cmp2(GradeType g1, GradeType g2)
{
  return g1.grade < g2.grade;
}
int main()
{
    int n = 0,m = 0;
    string name;
    int grade;
    GradeType nameGrade;
    
    while(cin >> n >> m)
    {
    vector<GradeType> gradeVec;
    while(n--)
    {
        cin >> name >> grade;
        nameGrade.name = name;
        nameGrade.grade = grade;
        gradeVec.push_back(nameGrade);
    }
    if (m == 0)
    {
      stable_sort(gradeVec.begin(), gradeVec.end(), cmp1);
    }
    else
    {
      stable_sort(gradeVec.begin(), gradeVec.end(), cmp2);
    }
    for(auto it = gradeVec.begin(); it != gradeVec.end(); it++)
        cout << it -> name << ' ' << it -> grade << endl;
    }
    return 0;
}
