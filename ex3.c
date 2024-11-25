#include <stdio.h>

// Função para calcular a média dos valores de um vetor
float calcular_media(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (float)soma / tamanho;
}

int main()
{
   int v[100], n = 3, posicao = 0; 
   
   // Entrada de valores no vetor
   for (int i = 0; i < n; i++) {
         printf("Digite o valor da casa %d do vetor: ", i);
         scanf("%d", &v[i]);
   }

   int maior = v[0]; // Inicializa o maior valor como o primeiro elemento
   for (int i = 1; i < n; i++) {
      if (v[i] > maior) {
         maior = v[i];
         posicao = i;
      }
   }

   // Calcula a média usando a função
   float media = calcular_media(v, n);

   // Exibe os resultados
   printf("A média dos valores do vetor é: %.2f\n", media);
   printf("O maior valor do vetor é: %d e está na posição %d\n", maior, posicao);
   return 0;
}