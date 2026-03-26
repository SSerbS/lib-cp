#include <bits/stdc++.h>
using namespace std;

// Defina sua função unimodal (ex: distância, parábola, etc)
double f(double x) {
    // Exemplo: f(x) = x^2
    return x * x; 
}

double ternary_search(double l, double r) {
    // 200 iterações é extremamente seguro para variáveis double
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        
        // Se quisermos maximizar, altere para: f(m1) < f(m2)
        if (f(m1) > f(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    // Retorna o valor MÍNIMO da função. 
    // Caso o problema peça o "x" que gera esse mínimo, retorne 'l'.
    return f(l); 
}
