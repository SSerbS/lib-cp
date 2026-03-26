const int MAXN = 2e5 + 5; //MAXN <= 1e6
int a[MAXN], b[MAXN];
pair<ll, ll> valor[MAXN], prefA[MAXN], prefB[MAXN];

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r)
{
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        valor[i] = {uniform(1, 1e18), uniform(1, 1e18)};

    prefA[0] = prefB[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        prefA[i].first = prefA[i - 1].first + valor[a[i]].first;
        prefA[i].second = prefA[i - 1].second + valor[a[i]].second;

        prefB[i].first = prefB[i - 1].first + valor[b[i]].first;
        prefB[i].second = prefB[i - 1].second + valor[b[i]].second;
    }

    while (q--)
    {
        int l, r, L, R;
        cin >> l >> r >> L >> R;

        pair<ll, ll> hshA, hshB;
        hshA = {prefA[r].first - prefA[l - 1].first, prefA[r].second - prefA[l - 1].second};
        hshB = {prefB[R].first - prefB[L - 1].first, prefB[R].second - prefB[L - 1].second};

        cout << (hshA == hshB ? "Yes" : "No") << "\n";
    }

    return 0;
}
