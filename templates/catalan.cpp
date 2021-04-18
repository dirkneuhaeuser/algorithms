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

// inverse using Fermats little theorem
long long inv(long long a, long long m){
    // Fermats little theorem
    // a**(m-2) = a**(-1) (mod m)
    // REQUIREMENT m is prime (note: eea only requires gcd(a,m) = 1
    return modPow(a, m-2, m);
}


void catalan(){
    // for n =0, 1, 2, 3,... the numbers are:
    // 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, ....
    // examples:
    //   - # of distinct binary trees with n vertices
    //   - # of ways expresseion n pairs of parentheses could match: n=2 pairs: ()() (()) 
    //   - # of ways a polygon with n+2 sides can be triangled
    //   - # of ways you can pass from (0, 0) to (n, n) in a grid without passing the diagonal (being only in the lower half)
    int p = MOD;
    int max_n = 100001;
    ll cat[100001];
    cat[0] = 1;
    for(int n=0; n<max_n-1; ++n){
        cat[n+1] = ((4*n+2)%p * cat[n]%p *inv(n+2, p)) % p;
    }
    //cout << cat[100000] << endl; // is 
}
