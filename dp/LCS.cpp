// A abordagem top-down (recursiva com memoização)
// LCS - Longest Common Subsequence O(N*M)
string a, b;
vector<vector<int>> dp;

// Para usar, inicialize: dp.assign(n, vector<int>(m, -1));
int lcs(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    if (a[i] == b[j]) {
        return dp[i][j] = 1 + lcs(i - 1, j - 1);
    } else {
        return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    }
}


// Abordagem Bottom-Up
/*evita o overhead de chamadas recursivas e o risco de Stack Overflow
em strings muito grandes, construindo a tabela iterativamente*/
// LCS - Longest Common Subsequence O(N*M)
int lcs_bu(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    // dp[i][j] = LCS dos prefixos a[0..i-1] e b[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
