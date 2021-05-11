int pisanoPeriod(int mod){
    // if taken modulo m, eventually there will be a circle. Assuming it will be on 0,1, the period is:
    int fib1 = 0, fib2=1;
    int period = 0;
    while(true){ // assume, that there is indead a pisano period
        // by pigoen hole principle there is at least on tuple fib_i fib_i+1 which whill be equal to another one after n**2
        // doesnt have to be start though
        period++;
        int newFib = (fib1+fib2) % mod;
        fib1 = fib2;
        fib2 = newFib;
        if(fib1==0 && fib2==1){
            return period;
        }
    }
}


// bin coefficients without MOD with pascals formula. 
// overflow for n > 66
vector<vector<ll>>bincoefs(51, vector<ll>(51, 1)); // O(n**2) 
for(int n = 1; n<51; ++n){
    for(int m = 1; m< n; ++m){
        bincoefs[n][m] = bincoefs[n-1][m] + bincoefs[n-1][m-1];
    }
}
//bincoefs[41][3] is 41 C 3


// binomial Coefficent with MOD
long long C(long long n, long long k, long long m){ // O(log m) after faculty computation
    // binomial coeffiecents with modulo m
    // n! / ((n-k)! k!) 
    // to use the modular arithmetic, we need to finde the inverse of (n-k)! and k! 
    // factorials need to be precalculated and taken modulo
    if(n < k) return 0;
    return (((fact[n] * inv(fact[k], m)) % m) * inv(fact[n-k], m)) % m;
}

//long long fact[100001];
//fact[0]=1;
//for(int i=1; i<100001;++i){
//    fact[i] = (fact[i-1]*i)%MOD;
//}
//long long ret = C(100000, 50000, MOD);  // (100000 choose 50000)%1000000007 = 149033233


// catalan numbers with MOD // O(n log p)
// for n =0, 1, 2, 3,... the numbers are:
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, ....
int max_n = 100001;
ll cat[100001];
cat[0] = 1;
for(int n=0; n<max_n-1; ++n){
    cat[n+1] = ((4*n+2)%MOD * cat[n]%MOD *inv(n+2, MOD)) % MOD;
}
//cout << cat[100000] << endl; // is 


// catalan without MOD -> ll overflows at n=33
int max_n = 32;
ll cat[33];
cat[0] = 1;
for(int n=0; n<max_n-1; ++n){
    cat[n+1] = ((4*n+2) * cat[n] /(n+2);
}
