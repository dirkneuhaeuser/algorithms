def sieve_of_eratosthenes(n):
    primes = [True for _ in range(n+1)]
    p = 2
    while(p**2 <=n ):
        if primes[p]:
            for i in range(p**2, n+1, p):
                primes[i] = False
    

        p += 1

    return primes

for i, is_prime in enumerate(sieve_of_eratosthenes(100)):
    if is_prime and i > 1:
        print('The number {} is a prime'.format(i))


    
