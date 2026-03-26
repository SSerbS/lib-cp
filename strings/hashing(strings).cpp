static const ll P1 = 31;
static const ll P2 = 37;
static const ll M1 = 1e9 + 7;
static const ll M2 = 1e9 + 9;

ll powers1[MAXN], powers2[MAXN];
vector<pll> prefixA, prefixB;  //Guarda o hash da string do prefixo de tamanho i
void power(int n)
{
    powers1[0] = powers2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        powers1[i] = (powers1[i - 1] * P1) % M1;
        powers2[i] = (powers2[i - 1] * P2) % M2;
    }
}

void precompute_hashes(string &str1, vector<pll> &prefix)
{
    int n = str1.size();
    prefix.assign(n + 1, {0, 0});

    for (int i = 0; i < n; i++)
    {
        ll val = str1[i] - 'a' + 1;
        prefix[i + 1].first = ((prefix[i].first * P1) % M1 + val) % M1;
        prefix[i + 1].second = ((prefix[i].second * P2) % M2 + val) % M2;
    }
}

pll sub_hasher(int i, int j, vector<pll> &prefix)
{
    int len = j - i + 1;

    ll h1 = (prefix[j + 1].first - (prefix[i].first * powers1[len]) % M1 + M1) % M1;
    ll h2 = (prefix[j + 1].second - (prefix[i].second * powers2[len]) % M2 + M2) % M2;

    return {h1, h2};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    power(n);
    precompute_hashes(s, prefixA);
    precompute_hashes(s2, prefixB);
}
