void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> contador(MAXN, 0);
    vector<pair<int, int>> cordenadas;
    vector<int> v;
    vector<ll> psum(1, 0);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        v.push_back(l);
        v.push_back(r + 1);
        cordenadas.push_back({l, r + 1});
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto [l, r] : cordenadas)
    {
        int pos1 = lower_bound(v.begin(), v.end(), l) - v.begin();
        int pos2 = lower_bound(v.begin(), v.end(), r) - v.begin();

        contador[pos1]++;
        contador[pos2]--;
    }
    for (int i = 1; i < contador.size(); i++){
          psum.push_back(psum[psum.size() - 1] + contador[i]);
    }
    while(q--){
        ll pos; cin >> pos;  
        //Acessamos o valor das queries com o limite superior - 1.
        cout << psum[(upper_bound(v.begin(), v.end(), pos) - v.begin()) - 1] << "\n";

    }
}
