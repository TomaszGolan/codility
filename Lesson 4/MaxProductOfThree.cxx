#include <algorithm> // for sort

int solution (vector<int> &A)
{
    sort (A.begin(), A.end()); // sort array
    
    // maximal product is a product of three last elements or a product of two smallest (if both negative) and the last
    return max (A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3], A[0] * A[1] * A[A.size() - 1]);
}
