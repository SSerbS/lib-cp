#include <iostream>
#include <vector>
using namespace std;

vector<int> a, ans(2e5);

struct Query
{
    int l, r, idx;
};

void dnc(int l, int r, vector<Query> &queries)
{
    if (l > r || queries.empty())
        return;
    int m = (l + r) / 2;
    vector<Query> left, right, cur;
    for (Query qr : queries)
    {
        if (qr.l <= m && m <= qr.r)
            cur.push_back(qr);
        else if (qr.r < m)
            left.push_back(qr);
        else
            right.push_back(qr);
    }
    dnc(l, m - 1, left);
    dnc(m + 1, r, right);
    vector<int> suf = {a[m]}, pref = {a[m]};
    for (int i = m - 1; i >= l; i--)
        suf.push_back(min(a[i], suf.back()));
    for (int i = m + 1; i <= r; i++)
        pref.push_back(min(a[i], pref.back()));

    for (Query qr : cur)
    {
        ans[qr.idx] = min(suf[m - qr.l], pref[qr.r - m]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a.push_back(b);
    }
    vector<Query> queries;
    for (int i = 0; i < q; i++)
    {
        Query query;
        cin >> query.l >> query.r;
        query.l--;
        query.r--;
        query.idx = i;
        queries.push_back(query);
    }
    dnc(0, n - 1, queries);

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}
