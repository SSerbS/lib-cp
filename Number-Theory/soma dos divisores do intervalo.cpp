//Complexidade Temporal: O(N log N)
//Complexidade Espacial: O(N)

long long sumDivisors[LIM];

void sieve() {
    for (int i = 1; i < LIM; i++) {
        for (int j = i; j < LIM; j += i) {
            sumDivisors[j] += i;
        }
    }
}
