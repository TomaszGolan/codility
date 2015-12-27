// this solution gets score 92%, failing at one test (first from large_sequence tests)

int solution (vector <int> &A)
{
  if (A.size() == 3) return 0; // only empty slice possible
  
  int maxSlice = 0; // max slice
  
  int sum = 0;     // current slice 
  int min = 10001; // the smallest value in the current slice
  bool isFull = true; // the maximum slice has full possible length
    
  for (unsigned i = 1; i < A.size() - 1; i++) // loop over number (first and last can not be part of sum)
  {
    sum += A[i]; // increase current sum
    
    if (min > A[i]) min = A[i]; // update current minimum
    
    int candidate = max (sum, sum - min); // candidate for max slice (we can drop min by setting P accordingly)
    
    if (isFull) candidate = sum - min; // we have to drop min in the case of full length slice
    
    maxSlice = max (maxSlice, candidate); // update maxSlice
    
    if (sum < 0) // reset current slice if sum is negative
    {
      isFull = false;
      sum = 0;
      min = 10001;
    }
  }
  
  return maxSlice;
}
