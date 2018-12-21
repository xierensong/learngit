#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
typedef struct ERRINFO
{
  string fileInfo;
  int count;
}ERRINFO;

class matcher
{
  public:
    matcher(string &cmpStr)
    {
        matchStr = cmpStr;
    }
    bool operator () (vector<ERRINFO>::value_type item)
    {
        return item.fileInfo == matchStr;
    }
  private:
    string matchStr;
};

int main()
{
  string lineStr,errStr;
  vector<ERRINFO> errRecord;

  while(getline(cin, lineStr))
  {
    int pos = lineStr.find_last_of('\\'); 
    int size = lineStr.size();
    errStr = lineStr.substr(pos + 1, size);
    string fileName;
    pos = errStr.find_first_of(' ');
    fileName = errStr.substr(0, pos);
    //cout << fileName << endl;

    size = fileName.size();
    if (size > 16)
    {
        fileName = fileName.substr(size - 16, size);
    }
    string lineNo;
    pos = errStr.find_last_of(' ');
    lineNo = errStr.substr(pos + 1, errStr.size());
    //cout << lineNo << endl;
    string fileInfoStr = fileName + ' ' + lineNo;
    //cout << fileInfoStr << endl;
    ERRINFO errInfo1;
    auto result = find_if (errRecord.begin(), errRecord.end(), matcher(fileInfoStr));
    if (result != errRecord.end())
    {
      result -> count ++;
    }
    else
    {
        errInfo1.fileInfo = fileInfoStr;
        errInfo1.count = 1;
        errRecord.push_back(errInfo1);
    }

  }
  int len = errRecord.size();
  if (len < 8)
  {
    for(auto it = errRecord.begin(); it != errRecord.end(); it++)
    {
      cout << it->fileInfo << ' ' << it->count << endl;
    }
  }
  else
  {
    for (int i = len - 8; i < len; i ++)
      cout << errRecord[i].fileInfo << ' ' << errRecord[i].count << endl;
  }

  return 0;
}
