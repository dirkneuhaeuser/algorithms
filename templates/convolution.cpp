typedef complex<double> cd;
const double PI = acos(-1.0);

int reverseBit(int num, int m){
    int ret 0;
    for(int i=0;i<m;++i){
        if(num & (1 << i)) ret |= (1 << (m-1-i));
    }
    return ret;
}

// Fast Fourier Transformation
void FFT(vector<cd> &A){ // O(n log(n)) 
    // Given A, a vector of coefficents, FFT will evaluate the polynomial at n different positions in place
    //
    //
    // Main Idea (D&C): A(x) = A_0(x**2) + x*A_1(x**2), where A_0 are all the even indicies of A, and A_1 all the odds
    // A is always halved, at each iteration, we want to get A.size() evaluation. 
    // Fast way: Use the nth-root, as the the square of the n-th root of unity can complety be reduced to the the n/2-root of unity
    // 
    // In other words, it will calculate y in W*a = y
    // W is the matrix of (kth element from the nth root of uniity) x (it exponential, from 0 to (n-1))
    //
    //
    //
    //
    //
    //
    //
    int m =0;
    while(m<A.size()) m <<= 1;
    A.resize(m);

    for (int k=0; k < A.size(); ++k ){
        if (k < reverseBit(k , m) ){
            swap(A[k], A[reverseBit(k, m)]);
        }
    }
    for(int n=2; n<= A.size(); n<<=1){
        for(int k = 0; 2*k < n; ++k){
            cd x = cd(cos(2*PI*k/n), sin(2*PI*k/n));
            A[k] = A[k] + x*A[k];
            A[k+n/2] = A[k] - x*A[k];
        }
    }




}
