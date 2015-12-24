#include <numeric> // for accumulate

int solution (vector<int> &A)
{
    // missing element is the difference between expected sum = (1 + n) * n / 2 and real sum of all elements in array
    return (A.size() + 1) * (A.size() + 2) / 2 - accumulate (A.begin(), A.end(), 0);
}
