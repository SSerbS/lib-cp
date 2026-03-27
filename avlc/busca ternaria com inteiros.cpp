long long f_int(long long x) {
    return x * x;
}

long long ternary_search_int(long long l, long long r) {
    while (r - l > 2) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        
        // Se quisermos maximizar, altere para: f_int(m1) < f_int(m2)
        if (f_int(m1) > f_int(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    
    // O x que gera o minimo esta entre l e r. Avaliamos todos.
    long long ans = f_int(l);
    for (long long i = l + 1; i <= r; i++) {
        ans = min(ans, f_int(i)); // Se quiser maximo, troque para max()
    }
    return ans;
}