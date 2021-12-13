ll smod(ll a, ll m=MOD){return((a%m) +m) %m;}
ll eea(ll a, ll n, ll &s, ll &t){ll xx = t = 0; ll yy = s = 1;while(n){ll q = a/n;ll u = n; n =a%n; a=u; u = xx; xx = s-q*xx; s = u;u = yy; yy = t-q*yy; t = u;}return a;}
ll invEea(ll b, ll m=MOD){ll s, t; ll d = eea(b, m, s, t); if(d!=1) return -1; return smod(s,m);}
ll modPow(ll b, ll p, ll m=MOD){if(p == 0){return 1;}ll a=modPow(b,p/2,m);a=smod(a*a,m);if(p&1)a=smod(a*smod(b, m),m);return a;}
ll invFerm(ll a, ll m=MOD){ return modPow(a, m-2,m);}
ll modAdd(ll a, ll b, ll m=MOD){return smod(a+b, m);};
ll modSub(ll a, ll b, ll m=MOD){return smod(a-b, m);};
ll modMul(ll a, ll b, ll m=MOD){return smod(a*b, m);};
ll modDiv(ll a, ll b, ll m=MOD){return smod(a*invEea(a, m), m);};
