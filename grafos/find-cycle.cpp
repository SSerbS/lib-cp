bool vis[MAXN];
vector<int> ciclo;

int dfs(int atual, int anterior) {
    if (vis[atual]) return atual;
    vis[atual] = true;

    for (int nxt : adj[atual]) {
        if (nxt == anterior) continue;
        int fim = dfs(nxt, atual);

        if (fim == -2) return -2;
        if (fim != -1) {
            ciclo.push_back(atual);
            if (atual == fim) return -2;
            else return fim;
        }
    }

    return -1;
}
