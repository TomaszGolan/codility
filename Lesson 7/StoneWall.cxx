// fill from left to right; fill with height of starting point until filling is possible
// this solution is scored 85% as it fails increasing skyline, like 1, 2, 3...

int solution (vector <int> &H)
{  
  unsigned int nBlocks = 0;            // minimum number of blocks to build given skyline
  unsigned int lastNotFilled = 0;      // the last column which was found to not be fully filled
  vector <int> currentH (H.size(), 0); // current height at i to i+1 meter
  
  while (true) // do until done
  {
    unsigned int id = lastNotFilled; // column to start with
    
    while (id < H.size() and H[id] == currentH[id]) id++; // look for the next not completely filled column
        
    if (id >= H.size()) return nBlocks; // skyline is completely filled
    
    lastNotFilled = id; // update last not filled column
            
    nBlocks++; // next block in use
    
    int h = H[id] - currentH[id]; // height to fill
                        
    for (unsigned int i = id; i < H.size(); i++) // loop over column
      if (H[id] <= H[i])                         // fill with h if possible
      {                                          // and update last not filled column id by first non empty one
        currentH[i] += h;
        if (H[i] > currentH[i] and id == lastNotFilled) lastNotFilled = i;
      }
      else break; // stop if filling is not possible
  };       
}

// the implementation of official solution: http://blog.codility.com/2012/06/sigma-2012-codility-programming.html

#include <stack>

int solution (vector <int> &H)
{
  stack <int> notDone; // heights of blocks which has not ended yet
  int nBlocks = 0;     // number of used blocks
    
  for (auto &h : H) // loop over columns
  {
    while (notDone.size() and h < notDone.top()) notDone.pop(); // close all blocks higher than current column
    
    if (notDone.size() and h == notDone.top()) continue; // same height -> same block
    
    notDone.push (h); // put column at the end of stack
    nBlocks++;        // which means new block
  }
  
  return nBlocks;
}
