int solution (int N)
{    
  int n   = 0; // current number of zeros sequence 
  int max = 0; // the longest sequence

  while (N % 2 == 0) N /= 2; // skip preceding zeros

  while ((N /= 2) > 1)           // divide by 2 until reach 1
    if (N % 2) n = 0;            // N is  odd, so 1 appears in binary -> reset counter
    else if (++n > max) max = n; // N is even, so 0 appears in binary -> increase current counter and update maximum 

  return max;
}
