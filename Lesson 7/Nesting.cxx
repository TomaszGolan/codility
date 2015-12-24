int solution (string &S)
{
    int open = 0;
    
    for (auto &s : S) 
        if (s == '(') open++;
        else if (--open < 0) return false;
        
    return open == 0;
}
