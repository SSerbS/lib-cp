vector<ll> dist(n, INF);
dist[s] = 0;

for(int rep = 0; rep < n - 1; rep++) {
    bool atualizou = false;
    for(auto [u, v, w] : edges) {
        if(dist[u] != INF && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            atualizou = true;
        }
    }
    // Se não atualizou ninguém, já achou os caminhos mínimos
    if(!atualizou) break; 
}

// Ciclo negativo?
bool cicloNegativo = false;
for(auto [u, v, w] : edges) {
    if(dist[u] != INF && dist[u] + w < dist[v]) {
        cicloNegativo = true;
        // Dependendo do problema, aqui você marca dist[v] = -INF
    }
}
