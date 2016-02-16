vector <int> generate2powers (const int N) // create a vector with N powers of 2
{
  vector <int> pow2 {1}; // initialize with 2^0
  
  for (int i = 1; i < N; i++) pow2.push_back (2 * pow2[i-1]); // create the rest in a loop
  
  return pow2;
}

class BinaryFib // store Fibonacci numbers in binary form
{
  private:
    
    static const int N = 30; // limit for number of significant bits (B[i] <= 30)
    vector <bool> bits;      // bit representation of the number
    
  public:
          
    BinaryFib () : bits (N, 0) {bits[0] = 1;}; // binary 1
    
    BinaryFib (const BinaryFib &a, const BinaryFib &b) : bits (N) // create by adding two binary numbers
    {
      bool excess = 0; // 1 and 1 -> bit = 0, excess = 1; otherwise excess = 0
      
      for (int i = 0; i < N; i++) // add first 30 bits
      {
        bits[i] = a.bits[i] xor b.bits[i] xor excess; // xor them all
        excess = excess ? a.bits[i] or b.bits[i] : a.bits[i] and b.bits[i]; // update excess (at least two 1 -> 1)
      }
    }
    
    int modulo (const int n) // calculate modulo 2^n and convert to decimal
    {
      static const vector <int> pow2 = generate2powers (N); // create 30 powers of 2
      
      int decimal = 0; // output decimal
      
      // no contribution from powers >= n (2^m % 2^n = 0 if m >= n)
      for (int i = 0; i < n; i++) decimal += bits[i] * pow2[i]; // convert bits to decimal
      
      return decimal;
    }    
};

vector <BinaryFib> generateFibonacci (const int N) // generate N binary Fibonacci numbers
{
  vector <BinaryFib> fib = {BinaryFib (), BinaryFib ()}; // initialize with two first Fibonacci numbers {1, 1}
  
  for (int i = 2; i <= N; i++) fib.push_back (BinaryFib (fib[i-2], fib[i-1])); // f_n = sum of two previous
  
  return fib;
}

vector <int> solution (vector <int> &A, vector <int> &B)
{
  vector <BinaryFib> fib = generateFibonacci (A.size()); // prepare Fibonacci numbers
  vector <int> res (A.size()); // storage for output
  
  // number of possible ways for N rungs = Nth Fibonacci number
  for (unsigned int i = 0; i < A.size(); i++) res[i] = (fib[A[i]].modulo(B[i]));
  
  return res;
}
