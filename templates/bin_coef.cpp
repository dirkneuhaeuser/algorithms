long long save_mod(long long a, long m){
    // makes sure that the number is positive
    return ((a%m) + m) % m;
}

long long modPow(long long b, long long p, long long m){ // O(log p)
    // D&C:
    // b**0 = 1 (basecase)
    // if p even: b**p = b**(p/2) * b**(p/2) 
    // if p odd: b**p = b**(p/2) * b**(p/2) * b
    if(p == 0){
        return 1;
    }
    long long ans = modPow(b, p/2, m);
    ans = save_mod(ans*ans, m);
    if (p&1) ans = save_mod(ans*b, m);
    return ans;
}


long long inv(long long a, long long m){
    // Fermats little theorem
    // a**(m-2) = a**(-1) (mod m)
    // REQUIREMENT m is prime (note: eea only requires gcd(a,m) = 1
    return modPow(a, m-2, m);
}

long long fact[100001];

long long C(long long n, long long k, long long m){
    // binomial coeffiecents with modulo m
    // n! / ((n-k)! k!) 
    // to use the modular arithmetic, we need to finde the inverse of (n-k)! and k! 
    // factorials need to be precalculated and taken modulo
    if(n < k) return 0;
    return (((fact[n] * inv(fact[k], m)) % m) * inv(fact[n-k], m)) % m;
}

//fact[0]=1;
//for(int i=1; i<100001;++i){
//    fact[i] = (fact[i-1]*i)%MOD;
//}
//long long ret = C(100000, 50000, MOD);  // (100000 choose 50000)%1000000007 = 149033233
