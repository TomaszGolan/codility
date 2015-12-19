int solution (vector<int> &A)
{
    vector <int> nCirclesBorn (A.size(), 0); // number of circles which are born at point i
    vector <int> nCirclesDied (A.size(), 0); // number of circles which die at point i
    
    for (unsigned int i = 0; i < A.size(); i++) // loop over circles
    {
        nCirclesBorn[max ((long long)0, (long long)i - A[i])]++;            // circle is born at low edge (or 0)
        nCirclesDied[min ((long long)A.size() - 1, (long long)i + A[i])]++; // circle dies at high edge (or N-1)
    }
    
    int nIntersection = 0; // number of intersections
    int nCirclesAlive = 0; // number of circles which are sill alive
    
    for (unsigned int i = 0; i < A.size(); i++)
    {
        nCirclesAlive += nCirclesBorn[i] - nCirclesDied[i]; // update number of alive circles
        
        // if some circles die, number of intersection is increased
        // we have N alive circles and M of them died -> (N - M) stay alive and they all intersect with the dead ones
        nIntersection += nCirclesAlive * nCirclesDied[i];
        // dying circles also intersect with each other -> number of pairs newton(M over 2) = M * (M - 1) / 2
        nIntersection += nCirclesDied[i] * (nCirclesDied[i] - 1) / 2;
        
        if (nIntersection > 10000000) return -1; // reach limit
    }
    
    return nIntersection;
}
