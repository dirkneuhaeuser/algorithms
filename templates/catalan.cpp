
// super catalans, overflow i>27
ll super[28];
super[0] = 0;
super[1] = 1;
for(int i=2; i<28; ++i){
    super[i] = ((6*i - 9) * super[i-1] - (i-3) * super[i-2]) / i;
    cout << super[i] << endl;
}

// catalans, overflow for i>32
ll cat[33];
cat[0] = 1;
for(int i=1; i<33; ++i){
    cat[i] = (4*i+1) * cat[i-1] / (i+2);
    cout << cat[i] << endl;
}


// mod catalans
int max_n = 100001;
ll cat[max_n];
cat[0] = 1;
for(int i=1; i<=max_n; ++i){
    cat[i] = ((4*i+2)%MOD * cat[i-1]%MOD *invEea(i+2, MOD)) % MOD;
    cout << cat[i] << endl;
}
