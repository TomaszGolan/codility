#include <stack>

int solution (string &S)
{
  stack <char> open; // stack of opening brackets

  for (auto &s: S)
    if (s == '(' or s == '[' or s == '{') open.push (s);   // opening bracket -> add to stack
    else if (open.size() == 0) return false;               // closing bracket before opening -> badly nested
    else if (s == ')' and open.top() != '(') return false; // closing bracket does not match last opened bracket
    else if (s == ']' and open.top() != '[') return false; // so badly nested
    else if (s == '}' and open.top() != '{') return false;
    else open.pop();                                       // bracket closed, remove from stack
    
  return open.size() == 0; // check if some opened brackets left
}
