vector<tuple<int, int, int>> arestas;
// implementar dsu
sort(arestas.begin(), arestas.end());

ll totalCost = 0;
for(auto [cost, u, v] : arestas){
    if( find(u) != find(v) ){
        join(u, v);
        totalCost += cost;
        // salvar u e v se quiser salvar as arestas da mst
    }
}
