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
