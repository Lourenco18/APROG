
#include <stdio.h>

int main() {
    int diaria = 60;
    float taxa_maior_15 = 5.50;
    float taxa_8_15 = 6;
    float taxa_menor_8 = 8;
    int dias;
    char nome[50];
    float valor_final = 0;

  printf("Qual é o seu nome? ");
    scanf("%s", nome);
    
    // Entrada de dados
    printf("Quantos dias esteve no hotel? ");
    scanf("%d", &dias);
    
  
    
    // Verificação dos dias e cálculo do valor final
    if (dias > 0) {
        if (dias > 15) {
            valor_final = dias * diaria + taxa_maior_15 * dias;
        } else if (dias >= 8 && dias <= 15) {
            valor_final = dias * diaria + taxa_8_15 * dias;
        } else {
            valor_final = dias * diaria + taxa_menor_8 * dias;
        }

        // Exibir o resultado
        printf("Nome: %s\n", nome);
        printf("Valor final: %.2f\n", valor_final);
    } else {
        printf("Valor inválido\n");
    }

    return 0;
}
