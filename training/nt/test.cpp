#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first
using namespace std; 

// 2**6 =  64
// 2**8 =  256
// 2**10 = 1,024
// 2**15 = 32,768
// 2**20 = 1,048,576
// 2**25 = 33,554,432
// 2**30 = 1,073,741,824
// 2**32 = 4,294,967,296

// int up to  2*10^9 (2^31-1)
// ll up to   9*10^18 (2^63 -1)
// ull up to 18*10^18 (2^64-1)/

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long, long> pll;
typedef pair<int, int> pii;

#define FOR(i, n) for(int i=0; i<n; i++)
#define FORS(i, n) for(; i<n; i++)
#ifdef DIRK
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;

bool isbase(string s, string base) {
    for(auto i : s) {
        bool works = false;
        for(auto j : base) {
            if(i == j) {
                works = true;
                break;
            }
        }
        if(!works) {
            return false;
        }
    }
    return true;
}

ll convert(string s, int base) {
    ll val = 0;
    for(auto i : s) {
        val *= base;
        if(i >= 'A' && i <= 'F') {
            val += i-'A'+10;
        }
        else {
            val += i-'0';
        }
    }
    return val;
}

bool isprime(ll n) {
    if(n < 2) return false;
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void reduce(int& top, int& bot) {
    if(top == 0) {
        bot = 1;
        return;
    }

    int gcd = __gcd(top, bot);
    top /= gcd;
    bot /= gcd;

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
    cin >> t;
    //int count = 1;
    while(t--) 
    { 
        //cout<<"Case #" << count++ << ": ";
        solve(); 
        cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 
void solve() 
{
    int top = 0;
    int bot = 0;

    string s;
    cin >> s;

    if(isbase(s, "01")) {
        bot++;
        if(isprime(convert(s, 2))) {
            top++;
        }
    }

    if(isbase(s, "01234567")) {
        bot++;
        if(isprime(convert(s, 8))) {
            top++;
        }
    }

    if(isbase(s, "0123456789")) {
        bot++;
        if(isprime(convert(s, 10))) {
            top++;
        }
    }

    if(isbase(s, "0123456789ABCDEF")) {
        bot++;
        if(isprime(convert(s, 16))) {
            top++;
        }
    }

    reduce(top, bot);
    cout << top << "/" << bot << endl;
}

