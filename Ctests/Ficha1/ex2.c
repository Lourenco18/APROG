#include <stdio.h>

int main()
{
    int dia_nasc, mes_nasc, ano_nasc;
    int dia_atual = 23, mes_atual = 9, ano_atual = 2024;
    int dias_ano = 365;
    int dias_mes = 30;
    int idade_dias;

    //pedir data de nascimento
    printf("Digite o dia que nasceu: ");
    scanf("%d", &dia_nasc);
    printf("Digite o mês que nasceu: ");
    scanf("%d", &mes_nasc);
    printf("Digite o ano que nasceu: ");
    scanf("%d", &ano_nasc);

    //calculo para calcular os dias de vida
    idade_dias = (ano_atual - ano_nasc) * dias_ano + (mes_atual - mes_nasc) * dias_mes + (dia_atual - dia_nasc);

   
    printf(" Tem %d dias de vida.\n", idade_dias);

    return 0;
}
