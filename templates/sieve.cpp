long long _sieve_size;
bitset<10000010> bs; // numbers up to 10^7, if bit set, number is prime
vector<long long> primes;

void sieve(long long limit){ // O(N * (1/2, 1/3, 1/5, .., 1/lastPrime)) = O(N * log log N)
    _sieve_size = limit + 1;
    bs.set(); // assume all numbers are prime
    bs[0] = bs[1] = 0;
    for(long long i = 2; i < _sieve_size; ++i) if(bs[i]) {
        for(long long j = i*i; j<_sieve_size; j+= i) bs[j] = 0;
        primes.push_back(i);
    }
}

bool isPrime(long long number){
    if(number < _sieve_size){ return primes[number]; } // O(1) for small numbers < sieve_size
    // works only for primes < sieve_size*sieve_size(10**14, if sieve_size = 10**7)
    for(int i =0; i<primes.size() && primes[i] * primes[i] <= number; i++){ // O(# primes) < O(Sqrt(N))
        if(number%primes[i] == 0){
            return false;
        }
    }
    return true; // NOTE, for numbers >  10**14 incorrect!
}

//sieve(10000000); // sieve of 10**7 is max -> else change bitset
//cout << isPrime(4398050705407) << endl; // big prime
