const int MOD = 1e9 + 7 ; 
int makemod( int v , int MOD = MOD ){v = (-MOD <= v && v < 2*MOD) ? v : v % MOD;if (v < 0) v += MOD;if (v >=MOD ) v -= MOD;return v ; }  
int add(int a, int b,int Mod = MOD) { return  makemod ( makemod(a) + makemod(b) ) ; } 
int sub ( int a , int b , int Mod = MOD ){ return makemod (   makemod(a) -  makemod(b) )  ; }
int mult(int a, int b,int Mod = MOD) { return makemod(  makemod(a) * makemod(b) ) ; } 
int mod_pow(int a, int b, int Mod = MOD) {int res = 1;a = makemod(a);while (b > 0) {if (b & 1) {res = makemod(res * a);}a = makemod(a * a);b >>= 1;}return res;}
int mod_inv(int a, int Mod = MOD) {return mod_pow(a, Mod - 2, Mod); }
int divi(int a, int b, int Mod = MOD) {return makemod(makemod(a) * mod_inv(b, Mod));}