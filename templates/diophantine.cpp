ll s, t;
// step1: x*s + y*t = q
ll d = eea(x, y, s, t);
// step2: 
assert(q%d==0);

// step3: adjust for real eqauation
s *= (q/d);
t *= (q/d);

// step4: prepare left and right LCM shifting
ll left = y/d;
ll right = x/d;


// step5: In order to move to the right direction, make sure you always shit positive units
ll moveLeftForwardL = left<0? (-1)*left: left;
ll moveLeftForwardR = left<0? (-1)*right: right;

ll moveRightForwardL = right<0? (-1)*left: left;
ll moveRightForwardR = right<0? (-1)*right: right;

// step6: Get correct start punct and/or traverse through all possible solutions
if(s<1){
    if(s==0){
        s+= moveLeftForwardL;
        t-= moveLeftForwardR;
    }else{
        ll times = abs(s)/moveLeftForwardL + 1; // + 1 assures that it is at least one and smallest positive
        s += moveLeftForwardL*times;
        t -= moveLeftForwardR*times;
    }
}
if(s>1){
    ll times = (s-1)/moveLeftForwardL;
    s -= moveLeftForwardL*times;
    t += moveLeftForwardR*times;
}
if(t<1){
    if(t==0){
        s-= moveRightForwardL;
        t+= moveRightForwardR;
    }else{
        ll times = abs(t)/moveRightForwardR + 1; // + 1 assures that it is at least one and smallest positive
        s -= moveRightForwardL*times;
        t += moveRightForwardR*times;
    }
}
