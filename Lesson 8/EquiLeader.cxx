#include <stack>

int findDominator (vector <int> &A) // taken from Dominator.cxx
{
  stack <int> remains; // numbers which were not removed
  
  for (auto &a : A) // loop over numbers
    if (remains.size() == 0 or a == remains.top()) remains.push (a); // the same number, add it to stack
    else remains.pop(); // different numbers cancel each other
  
  // at this point remains contains only the number which occurred the most often in A
  
  if (remains.size() == 0) return -1; // there is no dominator if stack is empty
  
  int counter = 0; // counter for occurrences
  
  for (unsigned int i = 0; i < A.size(); i++) // loop over number to check number of occurrences
    if (A[i] == remains.top()) if (++counter > A.size() / 2) return remains.top(); // if counter > n/2 -> it's dominator
    
  return -1; // there is no dominator
}

int solution (vector <int> &A)
{
  const int dominator = findDominator (A); // find "global" dominator
  
  // if two subsets have the same dominator, it must be "global" dominator
  
  if (dominator == -1) return 0; // there is no "global" dominator
    
  vector <int> pSum (A.size() + 1, 0); // prefix sums for dominator occurrences 
  
  for (unsigned int i = 1; i < A.size() + 1; i++) pSum[i] = pSum[i-1] + (A[i - 1] == dominator); // fill pSum
        
  int counter = 0; // counter for equi leaders
    
  for (unsigned int i = 0; i < A.size() - 1; i++) // loop over equi leaders candidates
    // if the number of dominator's occurrences in both subsets is greater than half of subsets size -> equi leader
    if (pSum[i + 1] > (i + 1) / 2 and pSum[A.size()] - pSum[i + 1] > (A.size() - i - 1) / 2) counter++;
        
  return counter;
}
