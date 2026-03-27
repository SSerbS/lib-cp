/*Time Complexity: O(Tklogn)
T: e o numero de casos de teste.
k: e o numero de bases primas utilizadas no vetor bases (neste caso, k=12).
n: e o valor que esta sendo testado.
*/
vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll mul_mod(ll a, ll b, ll mod)
{
    return ((__int128)a % mod * (__int128)b % mod) % mod;
}

ll fexp(ll a, ll b, ll mod)
{
    ll ret = 1;

    while (b > 0)
    {
        if (b & 1)
            ret = mul_mod(a, ret, mod);
        a = mul_mod(a, a, mod);
        b >>= 1;
    }

    return ret;
}

bool miillerTest(ll a, ll d, ll n)
{
    ll x = fexp(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1)
    {
        x = mul_mod(x, x, n);
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    return false;
}

bool is_prime(ll n)
{
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    ll d = n - 1;

    while (d % 2 == 0)
    {
        d >>= 1;
    }

    for (int a : bases)
    {
        if (a == n)
            break;
        if (!miillerTest(a, d, n))
            return false;
    }
    return true;
}
void solve()
{
    ll n;
    cin >> n;

    cout << is_prime(n) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
