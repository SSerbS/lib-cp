vi adj[MAXN];
int deg[MAXN];
int n;

vi toposort(vector<pii>& edges){
  memset(deg,0,sizeof(deg));

  for(auto [u,v] : edges){
    deg[v]++;
  }

  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(deg[i] == 0) q.emplace(i);
  }

  vi ord;
  while(!q.empty()){
    int u = q.front(); q.pop();
    ord.emplace_back(u);
    for(int v : adj[u]){
      deg[v]--;
      if(deg[v] == 0) q.emplace(v);
    }
  }

  return ord;
}
