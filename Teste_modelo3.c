/// Teste de Algoritmia e Programação
/// Dezembro de 2024

/// NOME   :
/// Número :

#include <stdio.h>
#include <math.h> // Para a função fabs()

/// NOTA EXPLICATIVA sobre PROGRESSÕES GEOMÉTRICAS
/// Chama-se progressão geométrica uma sucessão em que cada termo é igual ao produto do termo
/// imediatamente anterior por um número real r a que se chama razão.
/// A soma de todos os (infinitos) termos de uma progressão geométrica de razão r (-1<r<1) e
/// primeiro termo U0 é dada por S = U0 / (1-r)

/// a)
///
/// Escreva uma função 'somarVetor' que devolve a soma dos n elementos de um vetor de números reais.
float somarVetor(float v[], int n) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) { // Corrigido: ponto e vírgula e declaração de `i`
        soma += v[i];
    }
    return soma;
}

/// b)
///
/// Escreva uma função 'somaTodosTermos' que devolve a soma de todos os (infinitos)
/// elementos de uma progressão geométrica, pela respetiva fórmula.
/// de primeiro termo U0 (real) e razão r (real e |r|<1).
float somaTodosTermos(float U0, float r) {
    if (r <= -1 || r >= 1) { // Garantir que a razão esteja no intervalo (-1, 1)
        printf("Erro: A razão deve estar em (-1, 1).\n");
        return 0;
    }
    return U0 / (1 - r);
}

/// c)
///
/// Escreva uma função 'calcularTermos' que preenche um vetor com os n termos (reais),
/// de uma progressão geométrica de primeiro termo U0 (real) e razão r (real)
///
/// Exemplo: U0=1 r=2 n=5 deve resultar
///          v = [ 1 2 4 8 16 ]

void calcularTermos(float v[], int n, float r, float U0) {   
    v[0] = U0; // Primeiro termo da progressão
    for (int i = 1; i < n; i++) { // Corrigido: declaração de `i`
        v[i] = v[i - 1] * r; // Cada termo é o anterior multiplicado por r
    }
}

int main() {
    /// d)
    ///
    /// Escreva o código que determine (e escreva) qual valor do erro (diferença em módulo)
    /// que se obtém por aproximar a soma de todos os termos da progressão geométrica
    /// de primeiro termo 2.0 e razão 0.1 pela soma dos seus primeiros 5 termos.
    ///
    /// É obrigatório utilizar todas as funções anteriores.

    float v[100];       // Vetor para armazenar os termos
    int n = 5;          // Número de termos
    float U0 = 2.0;     // Primeiro termo da progressão
    float r = 0.1;      // Razão da progressão

    // c) Calcular os termos da progressão
    calcularTermos(v, n, r, U0);

    // a) Calcular a soma dos primeiros n termos
    float soma_n_termos = somarVetor(v, n);

    // b) Calcular a soma infinita
    float soma_infinita = somaTodosTermos(U0, r);

    // d) Calcular o erro em módulo
    float erro = fabs(soma_infinita - soma_n_termos);

    // Exibir os resultados
    printf("Soma dos primeiros %d termos: %.6f\n", n, soma_n_termos);
    printf("Soma infinita: %.6f\n", soma_infinita);
    printf("Erro (diferença em módulo): %.6f\n", erro);

    getchar();
    return 0;
}