#include <stdio.h>

// Função para calcular o vetor de probabilidades
void calculaVetorDeProb1(float p[], int n) {
    p[0] = 1.0; // Probabilidade inicial, com 0 pessoas, é 1 (100%)
    
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * (365.0 - (i - 1)) / 365.0; // Fórmula para a probabilidade
    }
}

// Função para imprimir o vetor
void escVetor(float v[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%.6f ", v[i]); // Mostra 6 casas decimais
    }
    printf("...]\n");
}

int main() {
    int n = 367; // Tamanho do vetor (367 para incluir de 0 até 366 pessoas)
    float p[367]; // Vetor para armazenar as probabilidades

    // Calcula o vetor de probabilidades
    calculaVetorDeProb1(p, n);

    // Mostra os primeiros valores do vetor
    escVetor(p, 10); // Aqui mostramos os primeiros 10 elementos como exemplo

    return 0;
}


#include <stdio.h>

// Função para calcular o vetor de probabilidades usando a nova fórmula
void calculaVetorDeProb2(float p[], int n) {
    p[0] = 1.0; // Probabilidade inicial
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * (365.0 - (i - 1)) / 365.0;
    }
}

// Função para encontrar a posição do primeiro elemento menor que k
int posDoPrimeiroElementoMenorQuek(float v[], int n, float k) {
    for (int i = 0; i < n; i++) {
        if (v[i] < k) {
            return i;
        }
    }
    return -1; // Retorna -1 caso nenhum elemento seja menor que k
}



int main() {
    int n = 367; // Tamanho do vetor
    float p[367]; // Vetor de probabilidades

    // Calcula as probabilidades usando a função calculaVetorDeProb2
    calculaVetorDeProb2(p, n);

    // Determinar o número mínimo de pessoas para probabilidades superiores a 10%, 20%, ..., 90%
    float limites[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9}; // Limites de probabilidade
    int numLimites = sizeof(limites) / sizeof(limites[0]);

    printf("Número mínimo de pessoas para cada probabilidade:\n");
    for (int i = 0; i < numLimites; i++) {
        float probComplementar = 1.0 - limites[i]; // Probabilidade complementar
        int pessoas = posDoPrimeiroElementoMenorQuek(p, n, probComplementar);
        printf("Para %.0f%%: %d pessoas\n", limites[i] * 100, pessoas);
    }

    return 0;
}



int main() {
    int n = 367; // Tamanho do vetor (de 0 até 366 pessoas)
    float p1[367]; // Vetor para calculaVetorDeProb1
    float p2[367]; // Vetor para calculaVetorDeProb2

    // Calcula os dois vetores de probabilidades
    calculaVetorDeProb1(p1, n);
    calculaVetorDeProb2(p2, n);

    // Mostra os vetores calculados
    printf("Vetor calculado por calculaVetorDeProb1:\n");
    escVetor(p1, 10); // Exibe os primeiros 10 valores
    printf("Vetor calculado por calculaVetorDeProb2:\n");
    escVetor(p2, 10); // Exibe os primeiros 10 valores

    // Determina o número mínimo de pessoas para probabilidades superiores a 10%, 20%, ..., 90%
    printf("\nSeja q a probabilidade de pelo menos duas pessoas fazerem anos no mesmo dia.\n");
    printf("Seja n o número mínimo de pessoas para atingir essa probabilidade.\n");
    printf("\nq      n\n");

    float limites[] = {0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 0.90}; // Limites desejados
    int numLimites = sizeof(limites) / sizeof(limites[0]);

    for (int i = 0; i < numLimites; i++) {
        float probComplementar = 1.0 - limites[i]; // Probabilidade complementar
        int pessoas = posDoPrimeiroElementoMenorQuek(p1, n, probComplementar);
        printf("%.2f   %d\n", limites[i], pessoas);
    }

    return 0;
}
