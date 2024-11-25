/// Teste de Algoritmia e Programação
/// Dezembro 2024

/// NOME   :
/// Número :

/// Pode-se estimar o valor de PI lançando dardos sobre um alvo quadrado com um círculo inscrito.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/// função que devolve um real à sorte entre 0 e 1
float real_a_sorte_01() {
    return 1.0 * rand() / RAND_MAX;
}

/// a)
///
/// Escreva uma função 'realAsorte' que devolva um real à sorte entre a e b (inteiros)
/// Use a função anterior.
/// Sugestão : Calcule um nº à sorte entre 0 e (b-a) e some-lhe a.
float realAsorte(int a, int b) {
    return a + (b - a) * real_a_sorte_01();
}

/// b)
///
/// Escreva a função 'vetorAsorte' que crie um vetor com n reais à sorte entre -r e r
/// Use a função anterior
void vetorAsorte(int n, float r, float v[]) { 
    for (int i = 0; i < n; i++) {
        v[i] = realAsorte(-r, r);
    }
}

/// c)
///
/// Escreva uma função 'dentroDoCirculo' que recebe as coordenadas x e y de um ponto
/// e o raio r de um círculo centrado na origem e devolve :
/// 1 - se o ponto pertence ao círculo
/// 0 - se o ponto não pertence ao círculo
/// ( um ponto pertence ao círculo se x^2 + y^2 < r^2 )
int dentroDoCirculo(float x, float y, float r) {
    return (x * x + y * y <= r * r) ? 1 : 0;
}

int main() {
    srand(time(0)); // Inicializar o gerador de números aleatórios

    /// d)
    /// Escreva o código que usando as funções anteriores, estime o valor de pi lançando 10000 dardos
    
    int n = 10000;      // Número de dardos
    float r = 1.0;      // Raio do círculo (1 para simplificar)
    int Ac = 0;         // Contador de dardos dentro do círculo
    int Aq = n;         // Total de dardos (igual ao número de lançamentos)

    for (int i = 0; i < n; i++) {
        // Gerar coordenadas (x, y) à sorte entre -r e r
        float x = realAsorte(-r, r);
        float y = realAsorte(-r, r);

        // Verificar se o ponto (x, y) está dentro do círculo
        if (dentroDoCirculo(x, y, r)) {
            Ac++;
        }
    }

    // Estimar o valor de pi
    float pi_estimado = 4.0 * Ac / Aq;

    // Exibir resultados
    printf("Número de dardos dentro do círculo (Ac): %d\n", Ac);
    printf("Número total de dardos lançados (Aq): %d\n", Aq);
    printf("Valor estimado de PI: %.6f\n", pi_estimado);

    return 0;
}