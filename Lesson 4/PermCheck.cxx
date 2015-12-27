#include <algorithm> // for find

int solution (vector <int> &A)
{
    vector <int> occurrence (A.size(), 0); // how many times numbers occur
    
    for (auto &a : A) if (a < A.size() + 1)      // loop over A and skip numbers greater than N
        if (++occurrence[a-1] > 1) return false; // return false if a number occurs more than once (not permutation)
    
    // if there is a missing number (occurrence == 0) is not a permutation  
    return find (occurrence.begin(), occurrence.end(), 0) != occurrence.end() ? false : true;
}
