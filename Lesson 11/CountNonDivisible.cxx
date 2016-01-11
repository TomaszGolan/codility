#include <cmath> // for sqrt
#include <set>

void addFactor (vector <int> &factors, const int factor, const int max)
{
  const int N = factors.size(); // current no. of factors
  factors.push_back (factor);   // add the factor
  // each combination of factors is also a factor
  for (int i = 0; i < N; i++) if (factors[i] * factor < max) factors.push_back (factors[i] * factor);
}

vector <int> solution (vector <int> &A)
{
  const int N = 2 * A.size(); // element are expected to be within the range [1...2*A.size()]
  
  vector <int> smallestDivider (N + 1, 0); // 0 for primes
  
  int i = 1; // index to loop over
  int n = i; // i multiplicity
  
  // fill smallestDivider array with the smallest divider of index
  while ((n = ++i) <= sqrt (N)) if (smallestDivider[i] == 0) // no dividers above sqrt (N); proceed only primes
    while ((n += i) <= N) if (smallestDivider[n] == 0) smallestDivider[n] = i; // fill not filled multiplicities of i
    
  vector <int> nOccur (N + 1, 0); for (auto &a: A) nOccur[a]++; // no. of occurrence of n in A
    
  vector <int> nNonDiv (N + 1, 0);   // no. of non dividers of n
  nNonDiv[1] = A.size() - nOccur[1]; // all but 1 does not divide 1
  
  for (i = 2; i < nOccur.size(); i++) // loop over all numbers 
    if (not nOccur[i]) continue;      // check only existing numbers
    else if (smallestDivider[i] == 0) nNonDiv[i] = A.size() - nOccur[1] - nOccur[i]; // only 1 and i divide prime
    else
    {
      int nDividers = nOccur[1] + nOccur[i]; // no. of dividers of i, initialize with no. of 1 and i
      
      vector <int> factors; // all factors of i
      int number = i;       // copy of i
      
      while (smallestDivider[number]) // divide by smallest divider until prime
      {
        addFactor (factors, smallestDivider[number], i); // update factors 
        number /= smallestDivider[number];               // update number
      };
      
      addFactor (factors, number, i); // add last divider
            
      // update no. of dividers; use set to avoid double-counting                       
      for (auto &x : set <int> (factors.begin(), factors.end())) nDividers += nOccur[x];
      
      nNonDiv[i] = A.size() - nDividers; // no. of non-dividers = all - no. of dividers
    }
  
  // obtaining the answer based on nNonDiv is straightforward
  vector <int> res; for (auto &a : A) res.push_back (nNonDiv[a]);
  
  return res;
}
