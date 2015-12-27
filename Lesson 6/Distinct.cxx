#include <set>

int solution(vector <int> &A)
{    
    return (set <int> (A.begin(), A.end())).size(); // set stores only unique elements
}
