const int max_n = 2;

struct Matrix {long long mat[max_n][max_n] = {0}; };

long long save_mod(long long a, long m){
    // makes sure that the number is positive
    return ((a%m) + m) % m;
}
Matrix matMul(Matrix a, Matrix b){ // O(n**3)
    Matrix ans;
    for(int i=0; i<max_n; ++i){
        for(int j=0;j<max_n; ++j){
            ans.mat[i][j] = 0;
        }
    }
    for(int i=0; i<max_n; ++i){
        for(int k=0;k<max_n; ++k){
            if(a.mat[i][k] == 0) continue; // optimisation! thats why we go throut k before j.
            for(int j = 0; j<max_n; ++j){
                ans.mat[i][j] += save_mod(save_mod(a.mat[i][k], MOD) * save_mod(b.mat[k][j], MOD), MOD);
            }
        }
    }
    return ans;
}

Matrix matPow(Matrix base, int p){ // O(n**3 log(p))
    Matrix ans;
    for(int i=0; i<max_n; ++i){
        for(int j=0; j<max_n; ++j){
            ans.mat[i][j] = i == j; // identiy matrix
        }
    }
    while(p){
        // D&C:
        // b**0 = 1 (basecase)
        // if p even: b**p = b**(p/2) * b**(p/2) 
        // if p odd: b**p = b**(p/2) * b**(p/2) * b
        if(p&1){
            ans = matMul(ans, base);
        }
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

//Matrix a;
//a.mat[0][0] = 2;
//a.mat[0][1] = 1;
//a.mat[1][1] = 2;
//
//Matrix ret = matPow(a, 2);
//cout << ret.mat[0][0] << endl;
//cout << ret.mat[0][1] << endl;
//cout << ret.mat[1][0] << endl;
//cout << ret.mat[1][1] << endl;


// DP speed up with matrix multiplication
// fibonacci in O(2*log(i)), where i is the ith fib number:
// fib(n+1) + fib(n) = fib(n+2)
// fib(n+1) = fib(n+1)
// [1, 1][1, 0] * [fib(n+1), fib(n)] = [fib(n+2), fib(n+1)]
// [1, 1][1, 0]**i * [1, 0] = [fib(i+1), fib(i)]
// // Matrix a, f;
// // a.mat[0][0] = 1;
// // a.mat[0][1] = 1;
// // a.mat[1][0] = 1;
// // Matrix ret = matPow(a, 11);
// // cout << ret.mat[1][0] << endl;

