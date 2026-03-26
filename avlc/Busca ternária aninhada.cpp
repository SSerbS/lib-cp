// Função unimodal multi-dimensional (ex: soma de distâncias para N pontos)
double f_2d(double x, double y) {
    return x*x + y*y; 
}

// 1. Busca interna: recebe um X fixo e faz busca ternária no Y
double ternary_search_Y(double x, double ly, double ry) {
    for (int i = 0; i < 200; i++) {
        double m1 = ly + (ry - ly) / 3.0;
        double m2 = ry - (ry - ly) / 3.0;
        
        if (f_2d(x, m1) > f_2d(x, m2)) {
            ly = m1;
        } else {
            ry = m2;
        }
    }
    return f_2d(x, ly); // Retorna o valor mínimo com aquele X fixo
}

// 2. Busca externa: Faz a busca ternária em X
double ternary_search_X(double lx, double rx, double ly, double ry) {
    for (int i = 0; i < 200; i++) {
        double m1 = lx + (rx - lx) / 3.0;
        double m2 = rx - (rx - lx) / 3.0;
        
        // A função objetivo da busca externa avalia o resultado ótimo da interna
        if (ternary_search_Y(m1, ly, ry) > ternary_search_Y(m2, ly, ry)) {
            lx = m1;
        } else {
            rx = m2;
        }
    }
    
    // Retorna a melhor resposta global. 
    // Se o problema pedir o ponto (X, Y), você precisará recuperar o 'ly' que gera esse mínimo.
    return ternary_search_Y(lx, ly, ry); 
}
