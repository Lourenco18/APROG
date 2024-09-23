#include <stdio.h>

int main() {
    // Definindo as variáveis para armazenar informações
    char nome[50];
    int idade;

    // Coletando as informações do usuário
    printf("Digite o seu nome: ");
   fgets(nome, sizeof(nome), stdin); // Usa fgets para capturar strings

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    // Apresentando as informações coletadas
    printf("\nInformações recolhidas:\n");
    printf("Nome: %s", nome);
    printf("Idade: %i\n", idade);

    return 0;
}
