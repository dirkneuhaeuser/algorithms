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
void solve() 
{
    int n, m, q;
    cin >> n >> m >>q;
    vector<pair<int, int>> bags;
    for(int i=0;i <n; i++){
        int size, value;
        cin >> size >> value;
        bags.push_back({value, size});
    }

    sort(bags.begin(), bags.end());
    reverse(bags.begin(), bags.end());

    vector<int> boxes(1,0);
    for(int i=0;i <m; i++){
        int cap; 
        cin >>cap;
        boxes.push_back(cap);
    }
    for(int i=0;i <q; i++){
        ll ret = 0;
        int L, R;
        cin >> L >> R;
        vector<bool>alr(m+1, false);
        for(int j = L; j <=R ; j++){
            alr[j] = true;
        }
        for(auto bag: bags){
            int smallest = 1<<30;
            int idx = -1;
            for(int k = 1;k<=m;k++){
                if(!alr[k] && get<1>(bag) <= boxes[k] && boxes[k] < smallest){
                    smallest = boxes[k];
                    idx = k;
                }
            }
            if(smallest != (1<<30)){
                alr[idx] = true;
                ret += get<0>(bag);
            }
        }
        cout << ret << endl;
        
    }



}

