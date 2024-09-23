#include <stdio.h>

int main() {
    int seg;
    int min;
    int hora;
    int resto;

    printf("DIGITE o número de segundos: ");
    scanf("%d", &seg);

    min = seg / 60;      
    hora = min / 60;    
    min = min % 60;      
    resto = seg % 60;  

    printf("Resultado: %02d:%02d:%02d\n", hora, min, resto);  

    return 0;
}
