vector<int> v = {1, 2, 3};
// 1. Garanta que o vetor esteja ordenado
sort(v.begin(), v.end());

// 2. Use o loop do-while para iterar
// por todas as permutações
do {
    for (auto e : v) cout << e << ' ';
    cout << endl;
} while (next_permutation(v.begin(), v.end()));
