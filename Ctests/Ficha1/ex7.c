#include <stdio.h>

int main()
{
    int mensal = 25;
    int valor_kwh;
    int valor_total_empresa = mensal * 12;
    float valor_total_cliente = 0;
    float valor_a_cobrar;
    float total;

    for (int i = 1; i <= 12; i++)
    {
        printf("Escreva a quantidade de kWh que usou no mês %d: ", i);
        scanf("%d", &valor_kwh);
        valor_total_cliente += 0.18 * valor_kwh;
    }

    if (valor_total_cliente != valor_total_empresa)
    {
        if (valor_total_cliente < valor_total_empresa)
        {
            valor_a_cobrar = valor_total_empresa - valor_total_cliente;
            total = valor_total_empresa - valor_a_cobrar;
        }
        else
        {
            valor_a_cobrar = valor_total_cliente - valor_total_empresa;
            total = valor_a_cobrar + valor_total_empresa;
        }

        printf("Valor a pagar: %.2f\n", total);
    }
    else
    {
        printf("Não há diferença a ser cobrada.\n");
    }

    return 0;
}
