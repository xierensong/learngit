#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<cassert>
#include<vector>

using namespace std;

map<string,string> parseRule(string file_name)
{
  map<string, string> rule_dict;
  ifstream rule_file;
  string rule;
  rule_file.open(file_name);
  //assert(rule_file.is_open());
  while(getline(rule_file, rule))
  {
    cout << rule << endl;
    int key_pos = rule.find(':');
    string key = rule.substr(0, key_pos);
    string data = rule.substr(key_pos + 1,rule.size() - key_pos);
    cout << key << '\t' << data << endl;
    rule_dict[key] = data;
  }
  rule_file.close();
  return rule_dict;
}



int main()
{
  string rule_file = "rule.txt";
  string input_file = "input.txt";
  string output_file = "output.txt";

  map<string,string> rule_dict;
  rule_dict = parseRule(rule_file);

  ifstream infile;
  infile.open(input_file);
  //assert(rule_file.is_open());
  ofstream outfile;
  outfile.open(output_file);

  string line;
  string out_line;
  vector<string> words;
  //循环读文件
  while(getline(infile,line))
  {
    cout << line << endl;
    out_line = "";
    words.clear();
    int start = 0;
    int out_start = 0;
    int end = 0;
    string word = "";
    for(int i = 0; i < line.size(); i ++)
    {
        if (line[i] == ' ' || line[i] == '?')
        {
          end = i;
          word = line.substr(start, end - start);
          cout << "word:" << start << '\t' << end  << '\t' << word << endl;
          //words.push_back(word);
          auto iter = rule_dict.find(word);
          if (iter != rule_dict.end())
          {
            //out_line.replace(out_start, end - start, iter -> second);
            out_line += iter -> second;
            cout << "out line : " << out_line << endl;
          }
          else
          {
            out_line += word;
            cout << "out line : " << out_line << endl;
          }
          out_line.push_back(line[i]);
          start = i + 1;
        }
    }
    //last word
    if (start <= line.size() - 1)
    {  
        word = line.substr(start, line.size() - start);
        cout << "last word: " << start << '\t' << end << '\t' << word << endl;
        auto iter = rule_dict.find(word);
        if (iter != rule_dict.end())
        {
          //out_line.replace(start, end - start, iter -> second);
          out_line += iter -> second;
          cout << "out line : " << out_line << endl;
        }
        else
        {
          out_line += word;
          cout << "out line : " << out_line << endl;
        }
        //words.push_back(word);
    }
    outfile << out_line << endl;
  }
  outfile.close();
  infile.close();
}
