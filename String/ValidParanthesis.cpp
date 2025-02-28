#include <iostream>
#include <vector>
#include <string>
using namespace std;

int isValid(string s){
  if(s.size() == 1)
    return 0;
  vector<char> stack;
  for(int i=0;i<s.size();i++){
    if(s[i] == '(' or s[i] == '{' or s[i] == '[')
      stack.push_back(s[i]);
    else{
      if(stack.empty())
        return 0;

      if(s[i] == ')'){
        char top = stack.back();
        if(top == '('){
          stack.pop_back();
          continue;
        }
        else
          return 0;
      }
      if(s[i] == '}'){
        char top = stack.back();
        if(top == '{'){
          stack.pop_back();
          continue;
        }
        return 0;
      }
      if(s[i] == ']'){
        char top = stack.back();
        if(top == '['){
          stack.pop_back();
          continue;
        }
        return 0;
      }
    }
  }
  if(!stack.empty())
    return 0;

  return 1;
}

void solve(){
  string s = "()[{}";
  int ans = isValid(s);
  if(ans)
    cout << "True" << endl;
  else
    cout << "False" << endl;
}

int main(){
  solve();
  return 0;
}
