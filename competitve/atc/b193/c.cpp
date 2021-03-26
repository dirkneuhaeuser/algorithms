#include<bits/stdc++.h> 

#define LL long long
#define ULL unsigned long long
#define LD long double
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
    int K;
    cin >> K;
    int S[10] ={0}, T[10] ={0};
    int av[10] = {K , K , K, K, K , K, K, K, K, K};
    double valS =0, valT=0;
    int rest = 9*K-8;
    for(int i=0;i<4; i++){
        char num;
        cin >> num;
        int inum = num - '0';
        S[inum]++;
        av[inum]--;
    }
    char skip;
    cin >> skip;
    for(int i=0;i<4; i++){
        char num;
        cin >> num;
        int inum = num - '0';
        T[inum]++;
        av[inum]--;
    }
    cin >> skip;
    for(int i=1;i<10; i++){
        valS += pow(10,S[i])*i;
        valT += pow(10,T[i])*i;
    }
    double ret = 0;
    for(int i=1;i<10; i++){
        if(av[i] == 0) continue;
        double probS = (float)av[i] / (float)rest;
        int valSNew = valS;
        valSNew -= pow(10,S[i])*i;
        valSNew += pow(10,S[i]+1)*i;
        av[i] --;
        for(int j=1;j<10; j++){
            if(av[j] == 0) continue;
            double probT = (float)av[j] / (float)(rest-1);
            int valTNew = valT;
            valTNew -= pow(10,T[j])*j;
            valTNew += pow(10,T[j]+1)*j;
            if (valTNew < valSNew){
                ret += probS * probT;
            }
        }
        av[i] ++;
    }
    cout << ret;
}

