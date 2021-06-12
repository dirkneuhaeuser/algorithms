//
// you need start-value x0 and implement the functino f
//
// mu start of cycle
// lambda length of cycle
// note: in cycle we have: f(x_i) == f(x_{i+k*lambda})
// therfore: working with hare and tortoise -> if the values are the same we know i = k*lambda
//
// then going the same way again, will have the  f(x_i) = f(x_{i+i}) eveywhere in cicle, in particular at mu

int t = f(x0), h = f(f(x0));
while(t != h){
    t = f(t); h = f(f(h));
}
int mu = 0; h =x0; // t = k*lambda
while(t != h){ // determining cycle start index
    mu++;
    t = f(t); h = f(h);
}
h = f(t);
int lambda = 1;
while(t != h){ // determining cycle length
    lambda++;
    h = f(h);
}

