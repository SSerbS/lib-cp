// Cria um mapa de inteiros
map<int, int> m; // O(1)

// Insere o elemento 5 no mapa
m[5] = 1; // O(log n)

// Verifica se o elemento 5 está no mapa
m.count(5) // O(log n)

// Encontra o elemento 5 no mapa
m.find(5) // O(log n)

// Acessa o valor associado ao elemento 5 no mapa
m[5] // O(log n)

// Remove o elemento 5 do mapa
m.erase(5) // O(log n)

// Cria um multimapa de inteiros
multimap<int, int> ms; // O(1)

// Insere o elemento 5 no multimapa
ms.insert({5, 1}); // O(log n)

// Verifica quantas vezes o elemento 5 está no multimapa
ms.count(5) // O(log n * k),
            // onde k é o número de ocorrências de 5

// Encontra o primeiro elemento 5 no multimapa
ms.find(5) // O(log n)

// Remove a primeira ocorrência do elemento 5 do multimapa
ms.erase(ms.find(5)) // O(log n)
