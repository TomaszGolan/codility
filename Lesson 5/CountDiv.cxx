int solution (int A, int B, int K)
{
    // if B == A -> there is one divisible if single element is divisible
    // if K > B -> there is one divisible if A == 0
    if (B == A or K > B) return A % K == 0 ? 1 : 0;
    // if B == K -> B is divisible, A may be divisible if A == 0
    if (B == K) return 1 + (A == 0);
    
    // first divisible element is K if K >= A; or A if divisible by K; or (A/K + 1) * K
    int first = K >= A ? K : (A % K == 0) ? A : (A / K + 1) * K;
    int last = (B / K) * K; // last divisible element

    // nof divisible elements is equal (last - first) / K + 1
    // edges: A == 0 is an extra divisible number, as well as B == K 
    return (last - first) / K + 1 + (A == 0) + (B == K);
}
