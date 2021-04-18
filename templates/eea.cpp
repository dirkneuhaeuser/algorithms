int eea(int a, int n, int &s, int &t){
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


int save_mod(int a, int m){
    return ((a%m) + m) % m;
}

int modInverse(int b, int m){
    // returns -1 if there is no mod inverse, else returns mod inverse
    int s, t;
    int d = eea(b, m, s, t);
    if(d!=1) return -1;
    // b*s + t*m = 1 -> take mod m to get b*s = 1 (mod m)
    return save_mod(s,m);
}
//int a = 25, b = 18;
//int inv = modInverse(a,b); // this time: inv = 13 and not -5 as save mode!
