int pai[MAXN], sz[MAXN];

int find(int u){
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    
    pai[v] = u;
    sz[u] += sz[v];
}

int main(){
    for(int u=0; u<MAXN; u++)
        pai[u] = u,
        sz[u] = 1;
}
