ull pow_mod (ull a, ull b, ull n){
    // returns pow(a,b) % n
    ull x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

ll mod(ll a, ll m){
    return ((a%m)+m) % m;
}


ll modPow(int b, int p, int m){
    if(p == 0){
        return 1;
    }
    ll ans = modPow(b, p/2, m);
    ans = mod(ans*ans, m);
    if (p&1) ans = mod(ans*b, m);
    return ans;
}


ull inv(ull a){
    return modPow(a, MOD-2, MOD);
}

ull fact[217001];

ull C(ll n, ll k){
    if(n < k) return 0;
    //cout << n << " " << k << endl;
    return (((fact[n] * inv(fact[k])) % MOD) * inv(fact[n-k])) % MOD;
}

