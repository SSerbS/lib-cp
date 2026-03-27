// Durante as transições de estado da sua DP, você deve preencher:
// if (novo_valor > dp[v]) { dp[v] = novo_valor; rec[v] = u; }
// rec[v] = u: "O melhor jeito de chegar em v foi vindo de u
vector<int> recuperar_caminho(int estado_base, int estado_final, const vector<int>& rec) {
    vector<int> caminho;
    int s = estado_final;
    
    while (s != estado_base) {
        caminho.push_back(s);
        s = rec[s];
    }
    caminho.push_back(estado_base);
    
    reverse(caminho.begin(), caminho.end());
    return caminho;
}
