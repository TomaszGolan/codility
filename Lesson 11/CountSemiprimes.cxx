#include <cmath> // for sqrt

vector <int> solution (int N, vector <int> &P, vector <int> &Q)
{
  vector <int> smallestDivider (N + 1, 0); // 0 for primes
  
  int i = 1; // index to loop over
  int n = i; // i multiplicity
  
  // fill smallestDivider array with the smallest divider of index
  while ((n = ++i) <= sqrt (N)) if (smallestDivider[i] == 0) // no dividers above sqrt (N); proceed only primes
    while ((n += i) <= N) if (smallestDivider[n] == 0) smallestDivider[n] = i; // fill not filled multiplicities of i
  
  vector <int> pSums (N + 1, 0); // cumulative sum of no. of semi primes 
  
  for (i = 4; i <= N; i++) // no semi primes below 4; semi prime if prime after divided by smallest divider
    pSums[i] = pSums[i-1] + (smallestDivider[i] and smallestDivider[i / smallestDivider[i]] == 0);
   
  vector <int> nSemiPrimes (P.size(), 0); // storage for the result

  for (i = 0; i < P.size(); i++) nSemiPrimes[i] = pSums[Q[i]] - pSums[P[i] - 1]; // straightforward using pSum

  return nSemiPrimes;
}
