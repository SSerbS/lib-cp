const ll MAXN = 200001;
const ll INF = 1e18;
int n, q;

struct Node
{
    ll sum = 0, pref = 0, suf = 0, best = 0;
    ll max_val = -INF; // Campo para BS generica por valor individual
};

Node segtree[4 * MAXN], a[MAXN];

Node merge(const Node &L, const Node &R)
{
    Node res;
    res.sum = L.sum + R.sum;
    res.pref = max(L.pref, L.sum + R.pref);
    res.suf = max(R.suf, R.sum + L.suf);

    res.best = max({L.best, R.best, L.suf + R.pref});

    return res;
}

void build(int l = 0, int r = n - 1, int idx = 0)
{
    if (l == r)
    {
        segtree[idx] = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(l, m, 2 * idx + 1);
    build(m + 1, r, 2 * idx + 2);
    segtree[idx] = merge(segtree[2 * idx + 1], segtree[2 * idx + 2]);
}

Node query(int L, int R, int l = 0, int r = n - 1, int idx = 0)
{
    if (R < l || L > r)
        return Node{};  //elemento neutro
    if (L <= l && r <= R)
        return segtree[idx];
    int m = (l + r) / 2;
    return merge(query(L, R, l, m, 2 * idx + 1), query(L, R, m + 1, r, 2 * idx + 2));
}

int bs(ll k, int l = 0, int r = n - 1, int idx = 0) {
    // CONDICAO DE PARADA: Se a propriedade do no nao satisfaz o criterio, nao desce
    // Para "primeiro elemento >= k", checamos se o maximo no intervalo eh >= k
    if (segtree[idx].max_val < k) return -1;

    if (l == r) return l; // Encontramos a folha

    int m = (l + r) / 2;
    
    // Tenta primeiro o filho da esquerda para garantir que seja o "primeiro" indice
    int res = bs(k, l, m, 2 * idx + 1);
    
    // Se nao encontrou na esquerda, busca na direita
    if (res == -1) {
        res = bs(k, m + 1, r, 2 * idx + 2);
    }
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = Node{x, max(0, x), max(0, x), max(0, x)};
    }
    build();
    return 0;
}
