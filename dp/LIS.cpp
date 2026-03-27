// LIS - Longest Increasing Subsequence O(N^2)
int lis(const vector<int>& a) {
    int n = a.size();
    int answer = 0;
    vector<int> dp(n, 1); // dp[i] = tam da maior subseq que termina em i
    
    for (int j = 0; j < n; ++j) {
        for (int i = j - 1; i >= 0; --i) {
            if (a[i] < a[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        answer = max(answer, dp[j]);
    }
    return answer;
}

// LIS - Longest Increasing Subsequence O(N log N)
int lis_nlogn(const vector<int>& a) {
    vector<int> dp; // dp[i] guarda o menor elemento final de uma LIS de tamanho i+1
    
    for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x; // Substitui para manter os finais o menor possível
        }
    }
    return dp.size();
}


