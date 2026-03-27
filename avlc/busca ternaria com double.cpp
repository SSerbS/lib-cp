#include <bits/stdc++.h>
using namespace std;

// Defina sua funcao unimodal (ex: distancia, parabola, etc)
double f(double x) {
    // Exemplo: f(x) = x^2
    return x * x; 
}

double ternary_search(double l, double r) {
    // 200 iteracoes e extremamente seguro para variaveis double
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
    // Retorna o valor MINIMO da funcao. 
    // Caso o problema peca o "x" que gera esse minimo, retorne 'l'.
    return f(l); 
}