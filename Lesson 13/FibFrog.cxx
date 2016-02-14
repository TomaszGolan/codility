#include <algorithm> // for reverse
#include <queue>

vector <int> generateFibonacci (const int N) // generate Fibonacci numbers <= N (in descending order)
{
  vector <int> fib = {1, 2}; // initialize with two first relevant Fibonacci numbers
  
  int n = 0; // current Fibonacci number
  
  while ((n = *prev (prev (fib.end())) + *prev (fib.end())) <= N) fib.push_back (n); // fill vector until n <= N

  reverse (fib.begin(), fib.end()); // reverse order

  return fib;
}

typedef pair <int, int> Leaf; // (distance from the beginning, number of jumps required to get to the leaf)

int solution (vector <int> &A)
{  
  vector <int> fib = generateFibonacci (A.size() + 1); // generate Fibonacci numbers 
  
  queue <Leaf> leaves;      // queue of visited leaves
  leaves.push (Leaf(-1,0)); // initial leaf at position -1 

  while (true)
  {
    if (leaves.empty()) return -1; // no path found
    
    Leaf leaf = leaves.front(); // get last leaf
    leaves.pop();               // remove last leaf from queue
    
    for (auto &n : fib) // loop over Fibonacci numbers (in descending order*)
    {
      int nextLeaf = leaf.first + n; // next possible leaf position
      
      if (nextLeaf == A.size()) return leaf.second + 1; // end of path - frog reached destination
      
      if (nextLeaf > A.size() or A[nextLeaf] == 0) continue; // out of range or no leaf at this position
      
      leaves.push (Leaf (nextLeaf, leaf.second + 1)); // add new path to leaf
      
      A[nextLeaf] = 0; // "remove" this leaf - if other path lead to this leaf it would not be shorter (because *)
    }
  }
}

