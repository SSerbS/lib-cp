const ll MAXN = 200001;
const ll INF = 1e18;
int n, q;

struct Node
{
    ll sum = 0, pref = 0, suf = 0, best = 0;
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
