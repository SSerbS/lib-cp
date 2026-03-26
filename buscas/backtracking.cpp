  void backtrack( /* estado atual */ ) {
    // 1. Caso Base: É uma solução completa e válida?
    if (é_solucao_completa(estado_atual)) {
        return armazenar_solucao(estado_atual);
    }

    // 2. Iterar sobre todas as próximas escolhas (Transições)
    for (cada_proxima_escolha) {

        // 3. Poda: A escolha é válida?
        if (é_valida(proxima_escolha)) {

            // 4. FAZER (Aplicar a transição)
            aplica_escolha(proxima_escolha);

            // 5. Recursão (Avançar para o próximo estado)
            backtrack( /* novo estado */ );

            // 6. DESFAZER (O Backtrack real)
            desfaz_escolha(proxima_escolha);
        }
    }

}
