#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string cmd;
  stack<long long> s;
  while (1)
  {
    cin >> cmd;
    if (cmd == "QUIT")
    {
      break;
    }
    else if (cmd == "END")
    {
      //스택 초기화
      while (!s.empty())
      {
        s.pop();
      }
    }
    else
    {
      if (cmd == "NUM")
      {
        long long x;
        cin >> x;
        s.push(x);
      }
      else if (cmd == "POP")
      {
        if (!s.empty())
        {
          s.pop();
        }
      }
      else if (cmd == "INV")
      {
        long long top = s.top();
        s.pop();
        s.push(-top);
      }
      else if (cmd == "DUP")
      {
        int top = s.top();
        s.push(top);
      }
      else if (cmd == "SWP")
      {
      }
      else if (cmd == "ADD")
      {
      }
      else if (cmd == "SUB")
      {
      }
      else if (cmd == "MUL")
      {
      }
      else if (cmd == "DIV")
      {
      }
      else if (cmd == "MOD")
      {
      }
    }
  }
  return 0;
}