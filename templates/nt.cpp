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

int eea(int a, int n, int &s, int &t){ //O(log min(a,n))
    // extended eucl algorithmn. Calculates gcd(a,n) and also
    // the bezout coefficients s, t: s*a + t*n = gcd(a,n)
    // Note that s == a**-1 (mod n) IF GCD(a,n) ==1
    //
    //
    // pass s and t as reference
    int xx = t = 0;
    int yy = s = 1;
    while(n){
        int q = a/n;
        int u = n; n =a%n; a=u;
        u = xx; xx = s-q*xx; s = u;
        u = yy; yy = t-q*yy; t = u;

    }
    return a; // gcd(a,n)
}
//int a = 25, b = 18, s, t;
//int gcd = eea(a,b,s,t);  // gcd = 1, s = -5 


// inverse using Fermats little theorem
long long inv(long long a, long long m){ // O(log m)
    // Fermats little theorem
    // a**(m-2) = a**(-1) (mod m)
    // REQUIREMENT m is prime (note: eea only requires gcd(a,m) = 1
    return modPow(a, m-2, m);
}


// inverse using EEA
int modInverse(int b, int m){ //O(log min(a,m))
    // returns -1 if there is no mod inverse, else returns mod inverse
    int s, t;
    int d = eea(b, m, s, t);
    if(d!=1) return -1;
    // b*s + t*m = 1 -> take mod m to get b*s = 1 (mod m)
    return save_mod(s,m);
}
//int a = 25, b = 18;
//int inv = modInverse(a,b); // this time: inv = 13 and not -5 as save mode!


