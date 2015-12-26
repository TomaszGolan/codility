#include <algorithm> // for sort

int solution (vector <int> &A)
{
  sort (A.begin(), A.end()); // sort array
  
  vector<int>::iterator it = A.begin(); // set iterator at the beginning of array
  
  int n = 0; // counter
  
  // inner loop -> increase n until adjacent numbers are equal
  // outer loop -> repeat until counter is odd (which means we found the number without pair)
  //               increase n to account first element in series
  while (n % 2 == 0 and ++n) while (*it == *next (it++)) n++;    
  
  return *prev(it); // return previous iterator (as it was increased within while condition)
}

// xor based solution

int solution (vector <int> &A)
{
    int x = 0; // we will xor to it all numbers

    for (auto &a : A) x = x xor a; // A xor A = 0; A xor 0 = A; A xor B xor A = B

    return x;
}
