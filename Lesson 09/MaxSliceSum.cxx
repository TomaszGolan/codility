int solution (vector <int> &A)
{
  int globalMax = A[0]; // maximum slice
  
  vector <int> :: iterator it = A.begin(); // iterator to loop over numbers
    
  while (*it < 0 and ++it != A.end()) globalMax = max (globalMax, *it); // skip all negative numbers
  
  if (it == A.end()) return globalMax; // if there is no positive numbers -> maximum is the single negative
    
  int maxEndAt  = 0; // maximum slice ended at given index
    
  for (it = prev(it); it != A.end(); ++it) // loop over numbers
  {
    maxEndAt  = max (0, maxEndAt + *it);   // update maximum slice ended at (last + current or 0)
    globalMax = max (globalMax, maxEndAt); // update global maximum
  }
  
  return globalMax;
}
