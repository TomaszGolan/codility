vector<int> solution (string &S, vector <int> &P, vector <int> &Q)
{
    vector <int> answer (P.size(), 0); // init result vector with M elements
    
    vector <int> pSumA (S.size() + 1, 0.0); // prefix sums for A
    vector <int> pSumC (S.size() + 1, 0.0); // prefix sums for C
    vector <int> pSumG (S.size() + 1, 0.0); // prefix sums for G
        
    for (unsigned int i = 0; i < S.size(); i++) // loop over DNA
    {
        // update prefix sums - stay the same unless corresponding letter occurs
        pSumA[i+1] = pSumA[i] + (S[i] == 'A');
        pSumC[i+1] = pSumC[i] + (S[i] == 'C');
        pSumG[i+1] = pSumG[i] + (S[i] == 'G');
    }
    
    for (unsigned int i = 0; i < P.size(); i++) // loop over queries 
    {
        // if (for given range) prefix sum changed -> the element exist within the range
        if (pSumA[Q[i]+1] - pSumA[P[i]] > 0) answer[i] = 1;      // at least one A within the range
        else if (pSumC[Q[i]+1] - pSumC[P[i]] > 0) answer[i] = 2; // at least one C within the range
        else if (pSumG[Q[i]+1] - pSumG[P[i]] > 0) answer[i] = 3; // at least one G within the range
        else answer[i] = 4;                                      // otherwise T is minimal impact factor
    }
    
    return answer;
}
