#include <stdio.h>

int main()
{
   int numEleitores;
   int votosBrancos;
   int votosValidos;
   int votosNulos;
   float percBrancos;
   float percNulos;
   float percValidos;
   

   printf("Digite o total de eleitores: ");
   scanf("%d", &numEleitores);
   
   printf("Digite o total de votos válidos: ");
   scanf("%d", &votosValidos);
   
   printf("Digite o total de votos em branco: ");
   scanf("%d", &votosBrancos);
   
   printf("Digite o total de votos nulos: ");
   scanf("%d", &votosNulos);

 
   percValidos = ((float)votosValidos / numEleitores) * 100;
   percNulos = ((float)votosNulos / numEleitores) * 100;
   percBrancos = ((float)votosBrancos / numEleitores) * 100;


   printf("Percentagem de votos em branco: %.2f%%\n", percBrancos);
   printf("Percentagem de votos nulos: %.2f%%\n", percNulos);
   printf("Percentagem de votos válidos: %.2f%%\n", percValidos);
   
   return 0;
}