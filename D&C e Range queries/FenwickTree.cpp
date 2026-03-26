int n;
vector<int> BIT;

int find(int k)  //lowerbound
{
    int curr = 0, ans = 0, prevsum = 0;
    for (int i = 22; i >= 0; i--)
    {
        if (curr + (1 << i) <= n && BIT[curr + (1 << i)] + prevsum < k)
        {
            curr = curr + (1 << i);
            prevsum += BIT[curr];
        }
    }
    return (curr + 1);
}

int query(int x)
{
  int res = 0;
  while(x > 0)
    {
      res += BIT[x];
      x -= (x & -x)
    }
  return res;
}

void update(int x, int val)
{
    while (x <= n)
    {
        BIT[x] += val;
        x += (x & -x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    BIT = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; i++)
        update(i, 1);
}
