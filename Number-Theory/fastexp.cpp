ll fastexp(ll base, ll exp){ // não colocar exp negativo
    ll ans = 1;
    while(exp > 0){
        if(exp & 1){
            ans *= base;
        }
        base *= base;
        exp>>=1;
    }
    return ans;
}
