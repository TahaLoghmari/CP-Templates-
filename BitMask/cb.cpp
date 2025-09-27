int cb(unsigned int n) 
{
    if (n == 0) return 1;  
    // floor(log2(n)) + 1 ; => precision issues
    int count = 0;
    while (n != 0) 
    {
        n >>= 1;
        count++;
    }
    return count;
}