int gcd (int a, int b) // greatest common divisor by Euclidean
{
  if (a % b == 0) return b;
  else return gcd (b, a % b);
}

int solution (int N, int M)
{
  return N / gcd (N, M); // at largest common multiple (N*M/gcd(N,M)) the wrapper is found; lcm / M chocolates eaten
}
