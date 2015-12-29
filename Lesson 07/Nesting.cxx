int solution (string &S)
{
    int open = 0; // number of currently opened brackets
        
    for (auto &s : S) 
        if (s == '(') open++;              // new (
        else if (--open < 0) return false; // new ), if open is negative -> closed before opening -> badly nested
        
    return open == 0; // properly nested if no. of ( == no. of )
}
