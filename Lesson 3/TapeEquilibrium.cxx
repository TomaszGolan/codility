#include <numeric> // for accumulate

int solution (vector<int> &A)
{    
    // init values assume P = 1
    int  left = A[0];
    int right = accumulate (A.begin() + 1, A.end(), 0);
    int  diff = abs (left - right);
    
    for (unsigned int i = 1; i < A.size() - 1; i++) // loop over numbers
    {
         left += A[i]; // increase left split by next number, so left = sum up to i
        right -= A[i]; // decrease right split by next number, so right = sum from i+1
        
        int tempDiff = abs (left - right);    // current difference
        if (tempDiff < diff) diff = tempDiff; // update difference if smaller
    }
    
    return diff;
}
