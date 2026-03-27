// Knapsack O(N*W) - Array 1D
int knapsack(int W, const vector<int>& w, const vector<int>& v) {
    int n = w.size();
    vector<int> dp(W + 1, 0); // dp[w] = melhor valor com capacidade w
    
    for (int i = 0; i < n; ++i) {
        // Percorremos de trás pra frente para usar o item apenas 1 vez
        for (int k = W - w[i]; k >= 0; --k) {
            dp[k + w[i]] = max(dp[k + w[i]], dp[k] + v[i]);
        }
    }
    return dp[W];
}
