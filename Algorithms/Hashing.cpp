mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get_rand(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
int Power = get_rand(1252 , 279054253 ) + 161 ; 
const int MOD_X = 1000000181, MOD_Y = 998244353  ;
int add(int a, int b , int MOD ) { a += b;if (a >= MOD) a -= MOD;return a;}
int sub(int a, int b , int MOD ) { return add(a, MOD - b,MOD); }
int mul(int a, int b, int MOD) {return a * 1LL * b % MOD;} 
struct H 
{
  int x, y;
  H() = default;
  H(int _x): x(_x), y(_x) {}
  H(int _x, int _y): x(_x), y(_y) {}
  inline H operator+(const H& h) const { return H(add(x, h.x, MOD_X), add(y, h.y, MOD_Y)); }
  inline H operator-(const H& h) const { return H(sub(x, h.x, MOD_X), sub(y, h.y, MOD_Y)); }
  inline H operator*(const H& h) const { return H(mul(x, h.x, MOD_X), mul(y, h.y, MOD_Y)); }
  inline bool operator==(const H& h) const { return x == h.x && y == h.y; }
};
const int N = 2e6 ; 
vector<H> pw(N); 
void prec()
{
    pw[0] = 1;
    for ( int i = 0 ;i < N ; i++ )  pw[i+1] = pw[i] * Power;
}
struct Hash 
{
    vector<H> hash , rhash;
    int n ; 
    Hash(string& str) : n(str.size()) 
    {
        hash.resize(n+2);  rhash = hash ; 
        for ( int i = 0 ; i < n ; i++ ) hash[i+1] = hash[i] * Power + str[i] -'a' + 1,
        rhash[n] = 0;
        for(int i = n - 1 ; i >= 0 ;--i) rhash[i] = rhash[i + 1] * Power + str[i] - 'a' + 1 ;
    }
    H get_hash(int a, int b) 
    { 
        return hash[b+1] - (hash[a] * pw[b - a+1]);
    }
    H get_rhash(int a, int b) {
        return rhash[a] - (rhash[b + 1] * pw[b-a+1]);
    };
    bool is_palindrome ( int i , int j )
    {
        return get_hash(i,j) == get_rhash(i,j) ; 
    }
};
H combine( const H &h1, const H &h2 , int r2 , int l2 ) 
{
    H combined =  h1 * pw[r2 - l2 + 1]  + h2;
    return combined ;
}