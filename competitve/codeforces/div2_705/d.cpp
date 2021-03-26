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
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif 
    
    int t=1; 
    while(t--) 
    { 
        solve(); 
        cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
}
// idea:
// For the ith number in array, save the times the prime-divisor div divides it (cnt_divisor[i][div]): save k in p**k = num[i]
// You only need to update the solution if this divisor is in all numbers
// in multiset cnt save for all divs for all numbers its k. At the begining we just leave it empty, as soon as all numbers contain this prime-div, you can update your solution

int const maxn = 2e5 + 5, max_val = 2e5 + 5;
ll mod = 1e9 + 7, ans = 1;
int nxt[max_val], n;
multiset <int> cnt[max_val];
map <int, int> cnt_divisor[maxn];

void add(int i, int x) {
    while (x != 1) {
        int div = nxt[x], add = 0; //div is smalles prime-divisor
        while (nxt[x] == div) add++, x = x / nxt[x]; //it appears add times

        int lst = cnt_divisor[i][div];
        cnt_divisor[i][div] += add; // the number i has the prime-div, add times
        int lst_min = 0;
        if ((int)cnt[div].size() == n) { // if div is in all n numbers 
            lst_min = (*cnt[div].begin());
        }
        if (lst != 0) {
            // p**k -> p**(k+add)
            cnt[div].erase(cnt[div].find(lst)); // delete one occurence of lst
        }
        cnt[div].insert(lst + add);
        if ((int)cnt[div].size() == n) {
            for (int j = lst_min + 1; j <= (*cnt[div].begin()); ++j) {
                ans = ans * (ll)div % mod;
            }
        }
    }
}

void solve() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, l, x;
    cin >> n >> q;

    for (int i = 2; i < maxn; ++i) { // sieve of eratosthenes 
        // for all elements note the smallest prime-divisor
        if (nxt[i] == 0) {
            nxt[i] = i;
            if (i > 10000) continue;
            for (int j = i * i; j < maxn; j += i) {
                if (nxt[j] == 0) nxt[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cin >> x;
        add(i, x);
    }

    for (int i = 1; i <= q; ++i) {
        cin >> l >> x;
        add(l, x);
        cout << ans << '\n';
    }

}
