// complexidade temporal: O(sqrt(n))
// complexidade espacial: O(qntdivisores(n))

vector<int> getdivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n/i) divisors.push_back(n / i);
        }
    }

    return divisors;
}
