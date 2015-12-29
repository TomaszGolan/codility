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

// the implementation based on: http://rafal.io/posts/codility-max-double-slice-sum.html

int solution (vector <int> &A)
{
  vector <int> maxEndAt   (A.size(), 0); // maximum slice which starts at given index
  vector <int> maxStartAt (A.size(), 0); // maximum slice which ends at given index

  // fill vectors of max slices
  for (unsigned int i = 1; i < A.size() - 1; i++)   maxEndAt[i] = max (0, maxEndAt[i-1] + A[i]);
  for (unsigned int i = A.size() - 2; i > 0; i--) maxStartAt[i] = max (0, maxStartAt[i+1] + A[i]);

  int maxSlice = 0; // max double slice

  // loop over possible P and merge max slices - the one ends at P-1 and the other which starts at P+1
  // to get max double slice for given P; update maxSlice if necessary
  for (unsigned int i = 1; i < A.size() - 1; i++) maxSlice = max (maxSlice, maxEndAt[i-1] + maxStartAt[i+1]);

  return maxSlice;
}
