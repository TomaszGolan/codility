int solution (vector<int> &A)
{
    int nEast = 0; // current number of cars travelling east (0)
    int nPass = 0; // number of passing cars
    
    for (auto &car : A) // loop over cars
        if (a == 0) nEast++; // car travelling east
        else if ((nPass += nEast) > 1000000000) return -1; // car travelling west (all current east-going cars pass it)
        
    return nPass;
}
