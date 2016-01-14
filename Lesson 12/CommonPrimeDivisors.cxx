int gcd (int a, int b) // greatest common divisor by Euclidean
{
  if (a % b == 0) return b;
  else return gcd (b, a % b);
}

bool samePrimeDivisors (int a, int b, int k = 2) // check if two numbers have the same set of prime divisors
{     
  if (a == b) return true; // same number => same set of divisors
    
  if (gcd (a, b) == 1) return false; // coprime numbers => different set of prime divisors
    
  if (a % k == 0 and b % k == 0) // divide by current k until possible only if both are divisible by k
  {                              // at some point either a == b or a and b are coprime
    while (a % k == 0) a /= k;   
    while (b % k == 0) b /= k;
  }
  
  return samePrimeDivisors (a, b, ++k); // increase k and run recursively with current a and b 
}

int solution (vector <int> &A, vector <int> &B)
{
  int counter = 0; // count number of good pairs
  
  for (unsigned int i = 0; i < A.size(); i++) if (samePrimeDivisors (A[i], B[i])) counter++;
  
  return counter;
}
