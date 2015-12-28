#include <cmath> // for sqrt

int solution (int N)
{
  int nFactors = 0; // number of dividers
    
  int i = 0; // index
    
  while (++i < sqrt (N)) if (N % i == 0) nFactors += 2; // if there is divider < sqrt(N) there is another > sqrt(N)
  
  return i * i == N ? nFactors + 1 : nFactors; // if N = k^2, N was not counted in the loop above
}
