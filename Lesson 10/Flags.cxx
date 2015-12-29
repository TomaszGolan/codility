int solution (vector <int> &A)
{
  if (A.size() < 3) return 0; // no way to have a peak    
    
  unsigned int lastPeak = 0;  // last peak position
  vector <unsigned int> pDis; // distance between peaks
    
  for (unsigned int i = 1; i < A.size() - 1; i++)  // loop over hills looking for peaks
    if (A[i] > A[i-1] and A[i] > A[i+1])           // this is a peak
    {
      if (lastPeak) pDis.push_back (i - lastPeak); // insert distance between last two peaks
      lastPeak = i;
    }
  
  if (pDis.size() == 0) return lastPeak != 0; // one peak -> one flag or no peaks -> no flags
      
  unsigned int nFlags   = 1; // number of flags to process
         
  while (nFlags++) // increase nFlags until it is possible to fill peaks
  {   
    bool impossible = true; // current nFlags can not be set on peaks
    
    unsigned int goodPeaks = 1; // number of peaks with flag
    unsigned int distance  = 0; // current distance between peaks with flag
        
    for (auto &d : pDis) // loop over distances between peaks
      if ((distance += d) >= nFlags) // increase distance and check if it is enough to put flag
      {
        distance = 0; // reset distance
        if (++goodPeaks == nFlags) impossible = false; // put flag and check if nFlag is possible
      }
    
    if (impossible) return nFlags - 1; // if current nFlags is impossible return the previous one
  };
  
  return -1; // never should get here
}
