// Codeforces Round #696 (Div. 2) Problem E
#include<bits/stdc++.h> 

#define LL long long
#define ULL unsigned long long
#define LD long double
#define el cout << '\n'
#define print(n) cout << n << endl
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
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
#define FORI(i, a, b) for(int i = a; i<b; i++)
#define FORS(i, n) for(i; i<n; i++)

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
    /*is Single Test case?*/cin>>t; 
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
    ULL p; cin >> p;
    // idea: even: [ 8 ||  0 , 1 2, 3, 4, 5, 6, || 9, 10, 12, 13, 14, 15, 16 || 7 ].    Note: 8 = 16/2 
    // idea: odd: [ 8 ||  0 , 1 2, 3, 4, 5, 6, || 9, 10, 12, 13, 14, 15 || 7 ]          NOTE; 8 = 15/2 + 1
    // even n = 2 [1 || 0]
    // odd n = 3 [2|| 0 ||1]
    ULL total = 0;
    vector<ULL> v;
    bool odd = p&1;
    if(odd){
        v.push_back(p/2+1);
        FOR(i, p/2){
            v.push_back(i);
            total += pow((p-v.size()),2);
        }
        FORI(i, p/2+2, p){
            v.push_back(i);
            total += pow((v.size()-1),2);
        }
        v.push_back(p/2);
        total += pow((v.size()-1),2);

    }else{
        v.push_back(p/2);
        FOR(i, p/2 -1 ){
            v.push_back(i);
            total += pow((p-v.size()),2);
        }
        FORI(i, p/2 + 1, p){
            v.push_back(i);
            total += pow((v.size()-1),2);
        }
        v.push_back(p/2-1);
        total += pow((v.size()-1),2);
    }
    // costs
    cout << total << endl;

    // perm
    for (auto x: v){
        cout << x + 1 << " ";
    }
    cout << endl;
    // Num of steps
    cout << p -1 << endl;

    // steps
    ULL cur = p-1;
    ULL next = v[cur];
    while(next != 0){
        cout << next + 1 << " " << cur + 1 << endl;
        next = v[next];
    }
    cur = 0;
    next = v[0];
    while(next != p-1){
        cout << next + 1<< " " << cur + 1<< endl;
        next = v[next];
    }
    cout << 1 << " " << p;


} 