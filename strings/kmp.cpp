#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Pi(string &t)
{
    vector<int> p(t.size(), 0);

    for (int i = 1, j = 0; i < t.size(); i++)
    {
        while (j > 0 && t[j] != t[i])
            j = p[j - 1];
        if (t[j] == t[i])
            j++;
        p[i] = j;
    }

    return p;
}

// Função KMP Search
// Retorna uma lista de índices (0-indexed) onde o padrão 'p' ocorre no texto 't'
vector<int> kmp_search(const string &t, const string &p) {
    int n = t.size();
    int m = p.size();
    vector<int> occurrences;
    
    if (m == 0) return occurrences; // Caso borda

    vector<int> pi = Pi(p);

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && p[j] != t[i])
            j = pi[j - 1];
        if (p[j] == t[i])
            j++;
        
        // Se j atingiu o tamanho do padrão, encontramos uma ocorrência
        if (j == m) {
            occurrences.push_back(i - m + 1);
            j = pi[j - 1]; // Continua a busca para encontrar ocorrências sobrepostas
        }
    }
    return occurrences;
}

void solve()
{
    string s;
    cin >> s;
    int result = s.size() - Pi(s)[s.size() - 1];

    cout << (s.size() % result == 0 ? result : s.size()) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        solve();
        if (n != 0)
            cout << "\n";
    }

    return 0;
}
