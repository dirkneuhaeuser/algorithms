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


// gets all combinations from [0,...n) taken r at a time - better for small r
void comb1(int n, int r, vector<vector<int>> &rets, int start, vector<int> &cur){
    // total cobminations: (nCr)
    // comb({ 1 2 3 4 5 }, 3) =
    //  { 1, comb({ 2 3 4 5 }, 2) } and
    //  { 2, comb({ 3 4 5 }, 2) } and
    //  { 3, comb({ 4 5 }, 2) }
    if(cur.size()==r){
        rets.push_back(cur);
        return;
    }
    for(int i=start;i<n;++i){
        cur.push_back(i);
        comb1(r, rets, i+1, cur);
        cur.pop_back();
    }
}
//vector<int>  cur;
//vector<vector<int>> ret;
//comb1(5, 3, ret, 0, cur); // ret = [[0, 1, 2], [0, 1, 3], [0, 1, 4], [0, 2, 3], [0, 2, 4], [0, 3, 4], [1, 2, 3], [1, 2, 4], [1, 3, 4], [2, 3, 4]]


// gets all combinations from [0,..n) taken r at a time - better for small (nCk)
void comb2(int N, int K, vector<vector<int>> &rets){
    // gets all possible K combinations from vector all; Total (nCk)
    // requirement all.size>= K
    assert(N >=K);
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
 
    // print integers and permute bitmask
    do {
        vector<int> cur;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            //if (bitmask[i]) std::cout << " " << i;
            if (bitmask[i]) cur.push_back(i);
        }
        rets.push_back(cur);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}
//vector<vector<int>> ret;
//comb2(5, 3, ret); // ret = [[0, 1, 2], [0, 1, 3], [0, 1, 4], [0, 2, 3], [0, 2, 4], [0, 3, 4], [1, 2, 3], [1, 2, 4], [1, 3, 4], [2, 3, 4]]


// combinations of putting r elements in  k bins
// total number of combinations: ((r+k-1)Cr)
vector<vector<int>> combBins(int k, int r){
    // idea: take smallest none-zero element and shift one unit of it to the right. The rest of this column needs to restart from 0
    // it also tries all combinations for this (larger) combination
    vector<vector<int>> combinations;
    //assert(r!==0) // edge case,...might be to check
    vector<int> bins(k,0);  
    bins[0] = r;
    while (true){ 
        combinations.push_back(bins);
        int i=0;
        for (; bins[i] == 0; i++); // Look for smallest value
        if (i == k-1) break; // Done
        bins[i+1]++; // Increase value of one die with smallest value by one
        bins[0] = bins[i]-1; // Turn others into ones
        if (i > 0){
            bins[i] = 0;
        }
    }
    return combinations;
}
//int r = 8; // the number of dices
//int k = 6; // each dice could fall onto 1...6
//vector<vector<int>> ret = combBins(k, r); //[[8, 0, 0, 0, 0, 0], [7, 1, 0, 0, 0, 0], ...]

// dearangement (permuations where no element stays at its initial position), overflows at n
ll derange[22];
derange[1] = 0;
derange[2] = 1;
for(int i =3; i<22; ++i){
    derange[i] = (i-1) * (derange[i-1] + derange[i-2]);
    cout << derange[i] <<endl;
}


