/*Na K-ésima iteração gera os
menores caminhos entre pares
(u, v) que somente passem por
um subconjunto de {1, 2, …, K}.
(note que o subconjunto pode ser o conjunto vazio)
No final, terá considerado todos
os vértices do grafo.
Complexidade: O(V³)
*/

vvll d(n+1, vll(n+1));

for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
