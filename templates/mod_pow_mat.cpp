//int mat_n = 2;

struct Matrix {
    vector<vector<ll>> mat;
    int mat_n;
    //ll mat[mat_n][mat_n];
    Matrix(int s):mat(s, vector<ll>(s,0)), mat_n(s){};
};

// DP speed up with matrix multiplication
Matrix matMul(Matrix a, Matrix b){
    int mat_n = a.mat_n;
    Matrix ret(mat_n);
    //memset(ret.mat, 0, sizeof ret.mat);
    for(int i=0; i<mat_n; ++i){
        for(int k=0; k<mat_n; ++k){
            if(a.mat[i][k]==0) continue;
            for(int j = 0; j<mat_n; ++j){
                ret.mat[i][j] += smod(a.mat[i][k], MOD) * smod(b.mat[k][j], MOD);
                ret.mat[i][j] = smod(ret.mat[i][j], MOD);
            }
        }
    }
    return ret;
}

Matrix modPowMat(Matrix base, ll pot){ // O(log p) iterative version 
    int mat_n = base.mat_n;
    Matrix ret(mat_n);
    //memset(ret.mat, 0, sizeof ret.mat);
    for(int i=0; i<mat_n; ++i){
        ret.mat[i][i] = 1;
    }
    while(pot){
        if(pot&1) ret = matMul(ret, base);
        base = matMul(base, base);
        pot >>= 1;
    }
    return ret;
}

// STEPS:
// 1. CHANGE MOD
// 2. SET UP TRANSITION MATRIX A (with recurrence equations)
// 3. SET UP INITIAL VECTOR y_0
// 4. Calculate: (A^t) * y_0 = y_t

// IMPORTANT: 
// Important: y_{t+1} is one step ahead of y_t and both have the same order 


// 1. EXAMPLE (RECURRSION EQUATION)
// (MOD)-fibonacci in O(2*log(i)), where i is the ith fib number:
// [1, 1][1, 0] * [fib(n+1), fib(n)] = [fib(n+2), fib(n+1)]
        
//Matrix A(2);
//A.mat[0][0] = 1;
//A.mat[0][1] = 1;
//A.mat[1][0] = 1;
//A.mat[1][1] = 0;
//
//Matrix ret = modPowMat(A, n);
//cout << ret.mat[0][1] << endl;  //the n-th fib number, modulo MOD in O(log n)


// 2. EXAMPLE (RECURRSION EQUATION)
// x_t = a0 + a1*x_{t-1} + a2*x_{t-2} + ... + an * x_{t-n}
// A:= [[1,0,0], [a0, a1, a2], [0, 1,0]
// y_0 = [1, x_1, x_0]
// => A^t = [1, x_t, x_{t-1}]
// Attention: only power the matrix, if t > degree


// 3. EXAMPLE (# Paths of Length L)
// The number of ways from a to b in an undirected graph of Length L
// trans[i][j]:= number of ways to get from j to i (IMPORTANT: COL 2 ROW)
// Matrix ret = modPowMat(trans, L);
// cout << ret.mat[end][start] << endl;


// 4. EXAMPLE (AD-Hoc)
// Calculate a^n + b^n from 
// p := a + b
// q := a * b
//
// x_n := a^n + b^n 
// => playing around:
// xn = p * x_{n-1} - q * x_{n-2}
//
// Ax = b
// [[p, -q],[1, 0]]  *  [x_{n-1}, x_{n-2}] =  [x_n, x_{n-1}]

