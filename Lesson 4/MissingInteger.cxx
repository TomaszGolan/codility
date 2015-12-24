#include <set> // for set

int solution (vector<int> &A)
{        
    set <int> setA; // sorted, distinct elements
    
    for (auto &a : A) if (a > 0) setA.insert (a); // fill set with positive integers
 
    set <int> :: iterator it = setA.begin(); // set iterator at the beginning of set

    // if set is empty (no positive variables) or first element != 1 -> 1 is the smallest missing integer
    if (setA.size() == 0 or *it > 1) return 1;
    // if set has one element -> the smallest missing integer is 1 or 2
    if (setA.size() == 1) return *it == 1 ? 2 : 1;

    while (it++ != prev(setA.end()))              // loop over set and check if the difference between elements is 1
        if (*next(it) - *it != 1) return *it + 1; // if not -> missing integer is found
        
    return *prev(setA.end()) + 1; // if there is no missing integer -> minimum is the last one + 1
}
