#include <cfloat> // for DBL_MAX

int solution (vector <int> &A)
{
    // there must be a 2- or 3-length slice which holds the minimum average
    // if the slice length is even -> it can be split into 2-length slices
    // if the slice length is odd -> it can be split into 3-length slice and some 2-length slices
    // along the subslices there must be at least one which average is the same or smaller as for whole slice
        
    double minSlice = DBL_MAX; // set current minimum as max double
    int P = 0;                 // set starting P as zero (if all numbers are the same, 0 is the first index)
    
    for (unsigned int i = 0; i < A.size() - 1; i++) // loop over numbers
    {
        // take smaller slice from 2- and 3-length slices (unless there is no more 3-length slices, end of array)      
        const double slice = (i < A.size() - 2) ? min ((A[i] + A[i + 1]) / 2.0, (A[i] + A[i + 1] + A[i+2]) / 3.0) : 
                                                  (A[i] + A[i + 1]) / 2.0;
        
        if (slice >= minSlice) continue; // go to the next P if current slice is larger than minimum

        // update current minimum 
        minSlice = slice; 
        P = i;
    }
    
    return P;
}
