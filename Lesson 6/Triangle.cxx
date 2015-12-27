#include <algorithm> // for sort

int solution (vector <int> &A)
{
    if (A.size() < 3) return false; // need at least 3 elements to build a triangle
    
    sort (A.begin(), A.end()); // sort array
    
    for (unsigned int i = 0; i < A.size() - 2; i++)         // loop over sorted array, only need to check adjacent
        if ((long long)A[i] + A[i+1] > A[i+2]) return true; // numbers; long long to prevent go out of int range
        
    return false; // no adjacent number fulfil triangle condition
}
