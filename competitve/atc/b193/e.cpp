#include<bits/stdc++.h> 

#define ll long long
#define ull unsigned long long
#define ld long double
#define print(n) cout << n << endl
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n) // here you need to specify char[SIZE] first, reads to next space
#define ssL(n) scanf("%s",n) // here you need to specify char[SIZE] first, reads to NL
#define sss(n) getline(cin, n) // doesnt work after scanf and after cin needs getchar()
#define sc(n) scanf("%c",&n)
#define FOR(i, n) for(int i = 0; i<n; i++)
#define FORS(i, n) for(i; i<n; i++)
#define FORI(i, a, b) for(int i = a; i<b; i++)
#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

const int MOD = 1000000007;

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    // Euklidean Alg to solve GCD = x*a + y*b
    // Returns <GCD, x>
    // Note, that x is inverse of a in Z_(b):
    // a**(-1) = x
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

std::pair<long long, long long> crt(const std::vector<long long>& rem,
                                    const std::vector<long long>& mod) {
    // CRT will find unique x % (LCM(mod[0],mod[1],...,mod[n])) s.t.:
    // x = rem[0] % mod[0] 
    // returns (x, LCM), IFF possible, else (0, 0)
    //
    // Prereq: mod[i] have to be coprime (gdp(mod[i], mod[j]) == 1)
    // Intuition: Merge two conguences to one. and repeat.
    //
    // For 2 congruences:
    // x = rem1 % mod1
    // x = rem2 % mod2
    //   =>x = rem1 + k1*mod1
    //   =>x = rem2 + k2*mod2
    // =>rem1 - rem2 = mod1*(-k1) + mod2*k2
    //
    // With eukl Algo solve mod1*s + mod2*t = GCD(mod1, mod2)
    // multiply both sides with (rem1-rem2)/GCD
    // rem1 - rem2 = mod1*s (rem1 - rem2)/GCD + mod2*t (rem1 - rem2)/GCD  
    // As right sides its divided by GCD, so must left side => ASSERT! [1]
    //
    // The solution is:
    // x = rem1 + mod1*s(rem2-rem1)/GCD
    //
    // To prevent overflow take the modulo LCM as often as possible:
    // x = (rem1 + (s(rem2-rem1)/d % LCM) * mod1 % LCM ) % LCM
    //
    // However, LCM < 10**18 and mod1 < 10** 9 => overflow
    // Modulo Trick: ac % ab = a(c % b)
    // Here a=mod1 and b=mod2/GCD:
    // x* = rem1 + (s(rem2-rem1)/d % (mod2/GCD)) * mod1  % LCM [2]
    // We have successfully merged the first two concuences and created a new:
    // x = x* % LCM(mod1, mod2)
    //
    assert(rem.size() == mod.size());
    int n = int(rem.size());
    long long rem1 = 0, mod1 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= mod[i]);
        long long rem2 = safe_mod(rem[i], mod[i]);
        long long mod2 = mod[i];
        if (mod1 < mod2) {
            std::swap(rem1, rem2);
            std::swap(mod1, mod2);
        }
        if (mod1 % mod2 == 0) {
            if (rem1 % mod2 != rem2) return {0, 0}; // congruences are contradicting
            continue; // congruences are redundant
        }
        long long GCD, s;
        std::tie(GCD, s) = inv_gcd(mod1, mod2); // Eukl Alg to solve GCD = s*mod1 + t*mod2
        long long partlyLCM = (mod2 / GCD); // LCM(mod1, mod2) = mod1*mod2/GCD
        if ((rem2 - rem1) % GCD) return {0, 0}; // [1]

        long long x = (rem2 - rem1) / GCD % partlyLCM * s % partlyLCM * mod1; // [2] without rem1
        rem1 += x;
        mod1 *= partlyLCM;  // -> lcm(mod1, mod2)
        if (rem1 < 0) rem1 += mod1;
    }
    return {rem1, mod1}; // x, LCM
}

using namespace std; 
void solve(); 
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif 
    
    int t=1; 
    cin >> t;
    while(t--) 
    { 
        solve(); 
        cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 
  
void solve() 
{
    int X, Y, P, Q;
    cin >> X >> Y >> P >> Q;
    ll INF = 1ll << 62;
    ll ret = INF;

    for(ll i = X; i<X+Y; i++){
        for(ll j=P; j<P+Q; j++){
            ll t, lcm;
            vector<ll> rem{i, j};
            vector<ll> mod{2*X+2*Y, P+Q};
            tie(t, lcm) = crt({i, j}, {2*X+2*Y, P+Q});
            if(lcm!=0){
                ret = min(ret, t);
            }
        }
    }
    if(ret == INF){
        cout << "infinity";
    }
    else{
        cout << ret;
    }
}

