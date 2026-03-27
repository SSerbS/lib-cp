// Subset Sum O(N*T) - Array 1D
bool subsetSum(int t, const vector<int>& a) {
    vector<bool> dp(t + 1, false); // dp[s] = consigo fazer soma s?
    dp[0] = true;
    
    for (int x : a) {
        for (int i = t - x; i >= 0; --i) {
            if (dp[i]) {
                dp[i + x] = true;
            }
        }
    }
    return dp[t];
}
