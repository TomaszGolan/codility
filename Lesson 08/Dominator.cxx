#include <stack>

int solution (vector <int> &A)
{
  stack <int> remains; // numbers which were not removed
  
  for (auto &a : A) // loop over numbers
    if (remains.size() == 0 or a == remains.top()) remains.push (a); // the same number, add it to stack
    else remains.pop(); // different numbers cancel each other
  
  // at this point remains contains only the number which occurred the most often in A
  
  if (remains.size() == 0) return -1; // there is no dominator if stack is empty
  
  int counter = 0; // counter for occurrences
  
  for (unsigned int i = 0; i < A.size(); i++) // loop over number to check number of occurrences
    if (A[i] == remains.top()) if (++counter > A.size() / 2) return i; // if counter > n/2 -> it is dominator
    
  return -1; // there is no dominator
}
