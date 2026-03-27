//Complexidade de Tempo: O(n2n)

for (int mask = 0; mask < (1 << n); mask++) {
    for (int bit = 0; bit < n; bit++) {
        if (mask & (1 << (bit))) {
            // bit esta no subconjunto
        }
    }
}
