
#include <stdio.h>
//inverter um vetor 
void inverter(int v1[], int v2[], int n){
    for(int i =0; i< n; i++){
        v2[i]= v1[n-i-1];
    }
    

}
// Função para imprimir o vetor
void escVetor(int v[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]); // Mostra 6 casas decimais
    }
    printf("]\n");
}
//criar vetor
void criarvet(int v1[], int n){
    for(int i =0; i< n; i++){
        v1[i]= i+1;
    }

}
int main(){
    int n = 10, v1[100], v2[100];
    //criar vetor determinante o n
    criarvet(v1, n);
    escVetor(v1,n);
    inverter(v1,v2,n);
    printf("Vetor invertido \n");
    escVetor(v2,n);
    return 0;
}