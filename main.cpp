#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> splitString(string _string, string delimeter);
string stringsVectorToString(const std::vector<std::string> &lst, const std::string &delim);

int main() {
  string str = "economist dad arctic notebook ball";

  vector<string> words = splitString(str, " ");
  sort(words.begin(), words.end());

  string resultStr = stringsVectorToString(words, " ");

  cout << resultStr;

  return 0;
}


vector<string> splitString(string _string, string delimeter) {
  int prevPos = 0;
  vector<string> resultVector;
  for (int i = 0; _string.find(delimeter, prevPos) != -1; i++) {
    int currentPos = _string.find(delimeter, prevPos + 1);

    string substred;
    if (i == 0) {
      substred = _string.substr(0, currentPos);
    } else {
      substred = _string.substr(prevPos + delimeter.length(), currentPos - prevPos - delimeter.length());
    }

    prevPos = currentPos;

    resultVector.push_back(substred);
  }

  return resultVector;
}

string stringsVectorToString(const std::vector<std::string> &lst, const std::string &delim)
{
  std::string ret;
  for(const auto &s : lst) {
    if(!ret.empty())
      ret += delim;
    ret += s;
  }
  return ret;
}