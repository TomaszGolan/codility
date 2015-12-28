#include <cmath> // for sqrt

int solution (int N)
{    
  int maxDiv = 0; // maximu divisordivider < sqrt(N)
  
  for (unsigned int i = 1; i <= sqrt(N); i++) if (N % i == 0) maxDiv = i; // find maxDiv
      
  return 2 * (maxDiv + N / maxDiv);
}
