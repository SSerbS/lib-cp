const int MAXN = 2e5 + 5;
ll prefxorA[MAXN], prefxorB[MAXN];
int a[MAXN], b[MAXN];
mt19937_64 rng((int)chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r)
{
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<ll, ll> valor;

    // Entradas
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        if (!valor.count(a[i]))
        {
            valor[a[i]] = uniform(1, 1e18);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!valor.count(b[i]))
        {
            valor[b[i]] = uniform(1, 1e18);
        }
    }

    map<int, bool> valorA, valorB;

    prefxorA[0] = prefxorB[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!valorA[a[i]])
        {
            prefxorA[i] = prefxorA[i - 1] ^ valor[a[i]];
            valorA[a[i]] = true;
        }
        else
            prefxorA[i] = prefxorA[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!valorB[b[i]])
        {
            prefxorB[i] = prefxorB[i - 1] ^ valor[b[i]];
            valorB[b[i]] = true;
        }
        else
            prefxorB[i] = prefxorB[i - 1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (prefxorA[x] == prefxorB[y])
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
    }

    return 0;
}
