template<int MOD>
struct mint {
  int x;
  mint(int x=0):x((x%MOD+MOD)%MOD){}
  mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
  mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
  mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
  mint operator+(const mint a) const {mint res(*this);return res+=a;}
  mint operator-(const mint a) const {mint res(*this);return res-=a;}
  mint operator*(const mint a) const {mint res(*this);return res*=a;}
  bool operator==(const mint& rhs) const { return val() == rhs.val(); }
  bool operator!=(const mint& rhs) const { return !(val() == rhs.val()); }
  bool operator>(const mint& rhs) const { return (val() > rhs.val()); }
  bool operator>=(const mint& rhs) const { return (val() >= rhs.val()); }
  bool operator<=(const mint& rhs) const { return (val() <= rhs.val()); }
  bool operator<(const mint& rhs) const { return (val() < rhs.val()); }
  int val() const { return x; }
  mint pow(int b) const {
    mint res(1), a(*this);
    while (b) {
      if (b & 1) res *= a;
      a *= a;
      b >>= 1;
    }
    return res;
  }
  mint inv() const {return pow(MOD-2);}
  mint& operator/=(const mint a) {return (*this) *= a.inv();}
  mint operator/(const mint a) const {mint res(*this);return res/=a;}
  std::string to_string() const { return std::string("{") + std::to_string(val()) + "}"; }
};
const int MOD = 998244353 ; 
using Mint=  mint<MOD>  ;
ostream& operator<<(ostream& os, const Mint& a) {os << a.x; return os;}