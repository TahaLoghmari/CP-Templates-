class Combinatorics 
{
  public:
    static const int N = 3*1e6; // max n and k for large values
    static const int maxn = 52; // Max n and k for small values
    int mod = 1e9 +7 ;
    vector<int> fact, inv, fact_inv;
    vector<vector<int>> C;
    Combinatorics(){
        fact.resize(N + 2);
        inv.resize(N + 2);
        fact_inv.resize(N + 2);
        C.resize(maxn + 1, vector<int>(maxn + 1));
        prec();
    }
    void prec() {
        fact[0] = 1;
        for (int j = 1; j <= N; j++) {
            fact[j] = fact[j - 1] * j % mod;
        }
        inv[1] = 1;
        for (int j = 2; j <= N; j++) {
            inv[j] = inv[mod % j] * (mod - mod / j) % mod;
        }
        fact_inv[0] = 1;
        for (int j = 1; j <= N; j++) {
            fact_inv[j] = inv[j] * fact_inv[j - 1] % mod;
        }
        C[0][0] = 1;
        for (int n = 1; n <= maxn; ++n) {
            C[n][0] = C[n][n] = 1;
            for (int k = 1; k < n; ++k) {
                C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;
            }
        }
    }
    int nCk(int n, int k) {
        if (k > n) return 0;
        return fact[n] * fact_inv[k] % mod * fact_inv[n - k] % mod;
    }
    int stars_and_bars(int n, int k) {
    //The number of ways to put n identical objects into k labeled boxes is
    return nCk(n + k - 1, n);
    }
    int stars_and_bars_2(int n, int k) {
        //The number of ways to have x1 + x2 + .. + xk = n , xi > 0 
        return nCk(n -1, k-1);
    }
};
