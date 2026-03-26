vvi adj;
vb vis, color;

bool dfs(int v){
  vis[v] = 1;
  for(int u : adj[v]){
    if(!vis[u]){
      color[u] = !color[v];
      if(!dfs(u)) return 0;
    }
    else if(color[v] == color[u]) return 0;
  }
return 1;
}  
