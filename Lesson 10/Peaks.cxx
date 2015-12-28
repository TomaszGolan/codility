int solution (vector <int> &A)
{
  vector <int> peaks; // position of peaks
  
  // fill peaks ids
  for (unsigned int i = 1; i < A.size() - 1; i++) if (A[i] > A[i - 1] and A[i] > A[i+1]) peaks.push_back (i);
  
  if (peaks.size() == 0) return 0; // no peaks

  for (unsigned int nBlocks = peaks.size(); nBlocks > 1; nBlocks--) // nBlocks can not be greater than no. of peaks
  {
    if (A.size() % nBlocks) continue; // can not divide A into nBlocks
    
    unsigned int blockSize = A.size() / nBlocks; // length of single block
    unsigned int nPeaks = 0; // number of peaks found per block
    
    for (auto &peak : peaks)
      if (peak / blockSize > nPeaks) break;          // previous block does not have a peak
      else if (peak / blockSize == nPeaks) nPeaks++; // first peak in block
      
    if (nBlocks == nPeaks) return nBlocks;
  }
    
  return 1; // whole A
}
