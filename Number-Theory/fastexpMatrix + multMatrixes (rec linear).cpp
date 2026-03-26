void multMat(vvll& A, vvll& B, vvll& C, int mod){ // 6x6
    for(int i = 0; i < 6; i++){ //limpa identidade
        for(int j = 0; j < 6; j++){
            C[i][j] = 0;
        }
    }
    for(int i = 0; i < 6; i++){
        for(int k = 0; k < 6; k++){
            for(int j = 0; j < 6; j++){
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j])) % mod;
            }
        }
    }
    A = C;
}

ll fastexpM(ll exp, ll mod){
    vvll T ={{1,1,1,1,1,1},
            {1,0,0,0,0,0},
            {0,1,0,0,0,0},
            {0,0,1,0,0,0},
            {0,0,0,1,0,0},
            {0,0,0,0,1,0}};
    vvll base(6,vll(6)); base[0][0] = 1;
    vvll C(6,vll(6));
    vvll ans = C;
    for(int i = 0; i < 6; i++){
        ans[i][i] = 1;
    }
    while(exp){
        if(exp & 1){
            multMat(ans,T,C,mod);
        }
        multMat(T,T,C,mod);
        exp >>= 1;
    }
    multMat(ans, base, C, mod);
    return ans[0][0];
}
