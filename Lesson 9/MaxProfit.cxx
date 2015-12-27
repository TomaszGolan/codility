int solution (vector <int> &A)
{
    if (A.size() < 2) return 0; // at least 2 days required to gain profit
    
    int maxProfit = 0;  // maximum profit
    int lastMin = A[0]; // last minimum price
    
    for (unsigned int i = 1; i < A.size(); i++) // loop over days
    {
        maxProfit = max (maxProfit, A[i] - lastMin); // update max profit
        lastMin = min (lastMin, A[i]); // update last min
    }
    
    return maxProfit;
}
