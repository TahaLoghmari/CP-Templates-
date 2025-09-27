int countSetBits(int n)  {
    n++;
    int res = 0;
    for (int i=0; i<62; i++) {
        int size = (1LL<<(i+1));
        res += ((n/size)*(size/2));
        // Bits in last group.
        int rem = n%size;
        // Add set bits from last group.
        if (rem-size/2>0) res+= (rem-size/2);
    }
    
    return res;
}