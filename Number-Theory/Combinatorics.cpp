const int MAXK = 1005;
const ll MOD = 1e9 + 7;
ll fact[MAXK], invFact[MAXK];

ll mod_mul(ll a, ll b)
{
    return (a % MOD * b % MOD) % MOD;
}

ll mod_sub(ll a, ll b)
{
    return ((a % MOD - b % MOD) + MOD) % MOD;
}

ll mod_add(ll a, ll b)
{
    return (a % MOD + b % MOD) % MOD;
}

ll fexp(ll a, ll b)
{
    ll ret = 1;

    while (b > 0)
    {
        if (b & 1)
            ret = mod_mul(ret, a);

        a = mod_mul(a, a);
        b >>= 1;
    }

    return ret;
}

int inv(int a)
{
    return fexp(a, MOD - 2);
}

void precompute()
{
    invFact[0] = fact[0] = fact[1] = 1;
    for (int i = 1; i < MAXK; i++)
    {
        fact[i] = mod_mul(fact[i - 1], i);
        invFact[i] = inv(fact[i]);
    }
}

ll binomial(ll k, ll i)
{
    if (i > k || i < 0)
        return 0;

    return mod_mul(mod_mul(fact[k], invFact[i]), invFact[k - i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    ll n, m; cin >> n >> m;
    /*
        Stars and Bars:
        n-1 barras para criar n espaços;
        O número total de símbolos será m + (n - 1;
        (m + n - 1)!/(m!(n - 1)!);
    */
    
    cout << binomial(n+m-1, n-1) << "\n";

    return 0;
}
