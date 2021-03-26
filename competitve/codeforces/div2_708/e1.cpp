#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

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
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;
using namespace std; 
void solve(); 
void sieve(int n);



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif 
    
    int t=1; 
    sieve(10000001);
    cin >> t;
    while(t--) 
    { 
        solve(); 
        cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

vector<bool> primes(10000001, true);
vector<int> lastPrime(10000001, -1);

void sieve(int n){
    primes[0] = primes[1] = false;
    lastPrime[1] = 1;
    for(int i=2; i<= n; ++i){
        if(primes[i]){
            lastPrime[i] = i;
            for(int64_t j = int64_t(i)*i; j<=n;j+=i){
                if (primes[j]){
                    primes[j] = false;
                    lastPrime[j] = i;
                }
            }
        }
    }
}

int canonical(int n){
    int current = -1;
    int freq = 0;
    int ret=1;
    while(n != 1){
        if(lastPrime[n] == current){
            freq++;
        }else{
            if(freq&1 && current != -1){
                ret*=current;
            }
            current = lastPrime[n];
            freq=1;
        }
        assert(lastPrime[n] != 0);
        n = n/lastPrime[n];
    }
    if(freq&1 && current != -1){
        ret*=current;
    }
    return ret;
}

void solve() 
{
    // idea: reduce nums to its prime factorisation. As goal is to observe if product of 2 nums is perfect square, we can get rid of pf which are already squared and reduce numbers which are not squared to pf**1 as only the same pf is missing to make it sqaure. E.g. pf1**3 * pf2**2 -> pf1**1
    int n,k;
    cin >> n >> k;
    set<int> alr;
    int ret =1;
    for(int i =0; i<n;i++){
        int num;
        cin >> num;
        int can = canonical(num);
        if(!alr.insert(can).second){//insert returns <it, bool> with it to the element if it alr. exist and bool indicating it
            ret++;
            alr.clear();
            alr.insert(can);
        }
    }
    cout << ret;


    

}

