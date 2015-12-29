int solution (int X, vector <int> &A)
{
    vector <bool> flag (X, false); // true for already counted leaves

    int goal = (1 + X) * X / 2;    // sum of required leaves positions
    
    for (unsigned int i = 0; i < A.size(); i++)     // loop over A
        if (not flag[A[i]] and (flag[A[i]] = true)) // if leaf not counted: change flag and count leaf
            if ((goal -= A[i]) == 0) return i;      // return current time if goal accomplished
    
    return -1;
}
