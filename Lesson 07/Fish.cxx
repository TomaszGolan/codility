#include <stack>

int solution (vector <int> &A, vector <int> &B)
{
  stack <int> alive; // alive fishes indices 
    
  for (unsigned int i = 0; i < A.size(); i++) // loop over fishes
    if (B[i] == 1) alive.push (i); // i-th fish is flowing downstream 
    else // i-th fish is flowing upstream; 
    {    //while there are smaller fishes flowing downstream -> they are eaten 
      while (alive.size() and B[alive.top()] == 1 and A[alive.top()] < A[i]) alive.pop();
      if (alive.size() == 0 or B[alive.top()] == 0) alive.push (i); // there was nothing more to eat
      //else i-th fish was eaten
    }
    
  return alive.size();
}
