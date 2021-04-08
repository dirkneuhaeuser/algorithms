#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

// int up to 2*10^9 (2^31-1)
#define ll long long  // up to 9*10^18 (2^63 -1)
#define ull unsigned long long // up to 18*10^18 (2^64-1)
#define ld long double
#define FOR(i, n) for(int i=0; i<n; i++)
#define FORS(i, n) for(; i<n; i++)
//#ifdef DIRK
//#include "/Users/dirk/development/algorithms/templates/debug.h"
//#endif

const int MOD = 998244353;
using namespace std; 

long long _sieve_size;
bitset<10000010> bs; // numbers up to 10^7, if bit set, number is prime
vector<long long> primes;
vector<ull> smallestPrime;


void sieve(long long limit){ // O(N * (1/2, 1/3, 1/5, .., 1/lastPrime)) = O(N * log log N)
    _sieve_size = limit + 1;
    smallestPrime = vector<ull>(_sieve_size, 1);
    bs.set(); // assume all numbers are prime
    bs[0] = bs[1] = 0;
    for(long long i = 2; i < _sieve_size; ++i) if(bs[i]) {
        smallestPrime[i] = i;
        for(long long j = i*i; j<_sieve_size; j+= i){
            if(bs[j]) smallestPrime[j]=i;
            bs[j] = 0;
        }
        primes.push_back(i);
    }
}


void solve(); 
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifdef DIRK 
    freopen("/Users/dirk/development/algorithms/competitve/input.txt", "r", stdin); 
    freopen("/Users/dirk/development/algorithms/competitve/error.txt", "w", stderr); 
    freopen("/Users/dirk/development/algorithms/competitve/output.txt", "w", stdout); 
    #endif 
    
    int t=1; 
    //cin >> t;
    while(t--) 
    { 
        solve(); 
        cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

ull pow_mod (ull a, ull b, ull n){
    // returns pow(a,b) % n
    ull x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

ll mod(ll a, ll m){
    return ((a%m)+m) % m;
}


ll modPow(int b, int p, int m){
    if(p == 0){
        return 1;
    }
    ll ans = modPow(b, p/2, m);
    ans = mod(ans*ans, m);
    if (p&1) ans = mod(ans*b, m);
    return ans;
}


ull inv(ull a){
    return modPow(a, MOD-2, MOD);
}

ull fact[217001];

ull C(ll n, ll k){
    if(n < k) return 0;
    //cout << n << " " << k << endl;
    return (((fact[n] * inv(fact[k])) % MOD) * inv(fact[n-k])) % MOD;
}

void solve() 
{
    fact[0] = 1;
    for(int i =1; i<217001; ++i){
        fact[i] = (fact[i-1]*i) % MOD;

        //cout << fact[i] << endl;
    }



    ll N, M;
    cin >> N >> M;
    ll ret = 0;
    sieve(M+10000);
    for(int X=1; X<=M; X++){
        ull num = X;
        ull possX = 1;
        ull lastPrime = smallestPrime[num];
        ull cnt = 0;
        while(num != 1){
            if(lastPrime == smallestPrime[num]){
                cnt++;
                num /= smallestPrime[num];
            }else{
                ull bc = C(N-1 + cnt, N-1);
                //bc = bc%MOD;
                lastPrime = smallestPrime[num];
                cnt =0;
                possX = possX%MOD;
                possX *= bc;
                possX = possX%MOD;
            }
        }
        ull bc = C(N-1 + cnt, N-1);
        //bc = bc%MOD;
        possX = possX%MOD;
        possX *= bc;
        possX = possX%MOD;
        ret += possX;
        ret = ret%MOD;
        }

    cout << ret;

}

