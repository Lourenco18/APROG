/// Teste de Algoritmia e Programação
/// Dezembro de 2024

/// NOME   :
/// Número :

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/// função para escrever um vetor
void mostrarvetor(int v[], int n)
{
    printf("[ ");
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    printf("]\n");
}

/// função para baralhar um vetor de inteiros
void baralharvetor(int v[], int n)
{
    int p,k;
    for(int i=n-1;i>0;i--)
    {
        p=rand()%(i+1);              // à sorte entre 0 e i
        k=v[p]; v[p]=v[i]; v[i]=k;   // troca i com p
    }
   
}

/// função para copiar o vetor v para o vetor w
void copiarvetor(int v[], int w[], int n)
{
    for(int i=0;i<n;i++) w[i]=v[i];
}

/// Um caixeiro viajante pretende visitar 9 cidades (numeradas de 1 a 9)
/// e regressar à cidade de partida.
/// O custo de viajar da cidade A para a cidade B é c=(A-B)*(A-B)=(A-B)^2

/// Uma solução para o problema é partir da cidade 1 e visitar as
/// cidades 2, 3, 4, 5, 6, 7, 8 e 9 por esta ordem e regressar à cidade 1.
/// Chama-se a esta solução a solução natural do problema.

/// A solução natural pode ser representada pelo vetor natural
/// [ 1 2 3 4 5 6 7 8 9 ]

/// O custo de ir de 6 para 7 é (6-7)^2 =  1
/// O custo de ir de 9 para 1 é (9-1)^2 = 64

/// A solução natural
/// [ 1 2 3 4 5 6 7 8 9 ]  tem por isso um custo total de
///    1+1+1+1+1+1+1+1+64 = 72

/// A solução representada no vetor
/// [ 1 3 6 7 9 8 5 2 4 ]  tem por isso um custo total de
///    4+9+1+4+1+9+9+4+9  = 50

/// a)
///
/// Escreva a função 'vetorNatural' para criar o vetor
/// [ 1 2 3 . . . n ]
/// em que n deve ser passado à função
void vetorNatural(int v[], int n)
{
    
    for(int i=0;i<n;i++) v[i]=i+1;
    
}

/// b)
///
/// Escreva uma função 'custo' que devolve o custo
/// da solução do problema do caixeiro representada por
/// um vetor v de n elementos (não necessariamente 9)

int custo(int v[], int n)
{
    int c = 0;
    int custo = 0;
    c =(v[0]-v[n-1])*(v[0]-v[n-1]);
    for(int i = 0; i < n-1; i++)   {
        custo +=(v[i]-v[i+1])*(v[i]-v[i+1]);
    }
   c = c+custo;
    return c;
}

int main()
{
    srand(time(0)); // por causa da aleatoriedade

    /// c)
    ///
    /// Escreva o código que mostre a solução natural do problema do
    /// caixeiro viajante de 9 cidades e o respetivo custo.
    ///
    /// Resultado pretendido:
    /// Solução natural : [ 1 2 3 4 5 6 7 8 9 ]
    /// Custo da solução natural : 72
    int v[100], n = 9;
    vetorNatural(v,n);
    mostrarvetor(v,n);
    printf("Custo da solução natural : %d\n",custo(v,n));
    /// d)
    ///
    /// Escreva o código que tente 500 soluções à sorte do problema do
    /// caixeiro viajante de 9 cidades e escreva a melhor solução encontrada
    /// e o respetivo custo.
    /// Exemplo do resultado pretendido:
    /// Melhor solução encontrada : [ 8 9 7 6 3 1 2 4 5 ]
    /// Custo da melhor solução encontrada : 34
    int w[100];
    int melhor_vetor[100];
    copiarvetor(v,w,n);
    int total = 500;
    int melhor_custo = custo(v,n);
    for (int i = 0; i<total; i++){
        baralharvetor(w,n);
        if(melhor_custo > custo(w,n)){
            melhor_custo = custo(w,n);
            for(int j = 0; j<n; j++){
                melhor_vetor[j] = w[j]; 
            }
        }
    }
    mostrarvetor(melhor_vetor, n);
    printf("%d", melhor_custo);
  
    
    getchar();
    return 0;
}
