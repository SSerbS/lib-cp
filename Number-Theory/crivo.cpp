const int LIM = 1e6 + 5;
bool isPrime[LIM];

// Complexidade Temporal: O(Nlog(log(N)))
// Complexidade Espacial: O(N)

vector<int> sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    vector<int> primes;
    for (int i = 2; i < LIM; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < LIM; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}
