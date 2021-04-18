#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

// int up to 2*10^9 (2^31-1)
#define ll long long  // up to 9*10^18 (2^63 -1)
#define ull unsigned long long // up to 18*10^18 (2^64-1)
#define ld long double
#define FOR(i, n) for(int i=0; i<n; i++)
#define FORS(i, n) for(; i<n; i++)
#ifdef DIRK
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;
using namespace std; 




int s = 10000001;
vector<int> primes, smallest_prime(10000001,1);
void sieve(){
    for(ll i=2;i<s;++i){
        if(smallest_prime[i]==1){
            primes.push_back(i);
            smallest_prime[i] = i;
            for(ll j=i*i;j<s;j+=i){
                smallest_prime[j] = i;
            }
        }
    }
}

ll sumDiv(int n){
    int cur = smallest_prime[n];
    ll ret = 1;
    while(n!=1){
        ll total = 1, multiplier = cur;
        while(cur == smallest_prime[n]){
            n/=cur;
            total += multiplier;
            multiplier*=cur;
        }
        ret *= total;
    }
    
    return ret;
}


void solve(); 
vector<ll>s2i(s,-1);
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
    int count = 1;
    sieve();

    //for(int i = 2; i<s;++i){
    //    sums[i]=sumDiv(i);
    //}
    vector<ll>sums(s, 0);
    sums[1] = 1;
    for(int i = 2; i<s;++i){
        ll p = smallest_prime[i];
        ll cur = i;
        ll total = 1, multiplier =p;
        while(cur%p==0){
            cur/=p;
            total += multiplier;
            multiplier *= p;
        }
        sums[i] = total * sums[cur];
    }

    for(int i=sums.size()-1;i>=0;--i){
        if (sums[i] < s){
            s2i[sums[i]] = i;
        }
    }





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
    int c; cin >> c;
    cout << s2i[c];




     

}

