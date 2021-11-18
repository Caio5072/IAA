#include "utils.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int* l, int tam) {
  int pivot = l[tam-1];
  int i = -1;
  int j;

  for(j = 0; j < tam-1; j++)
    if(l[j] <= pivot)
      troca(&l[++i], &l[j]);
  troca(&l[i+1], &l[j]);

  return i + 1;
}

int selecaoQuickSort(int* l, int tam, int i){
  int q;
  if (tam == 1) return l[0];
  
  q = partition(l, tam);
  if(i < q)
    return selecaoQuickSort(l, q, i);
  else if(i > q)
    return selecaoQuickSort(&l[q+1], tam - (q + 1), i - (q + 1));

  return l[q];
}

int main(){
  Bool sucesso = TRUE;
  int i, tam, j, m;
  int* l;
  clock_t start, end;
  double elapsed;

 // m = selecaoMergeSort(l, tam, i);
  
  scanf(" %d", &tam);
  l = (int*) malloc(sizeof(int)*tam);

  for(j = 0; j < tam; j++) scanf(" %i", &l[j]);
  
  scanf(" %d", &i);
  start = clock();
  m = selecaoQuickSort(l, tam, i);
  end = clock();

  elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  for(j = 0; j < i; j++) {
    //printf("%i ", l[j]);
    if(l[j] > l[i])
      sucesso = FALSE;
  }

  for(j = i + 1; j < tam; j++){
    if(l[j] < l[i])
      sucesso = FALSE;
  }

  if(sucesso){
    printf("Abaixo do pivô %i só há valores menores que ele e acima dele só há valores maiores\n", i);
    if(m){
      printf("Valor %d foi encontrado na posição %d\n", m, i);
    }
    else{
      printf("Não foi possível encontrar nenhum valor na posição %d\n", i);
    }
  }
  else
    puts("Algo deu errado");

  printf("Tempo de processamento: %.2lf segundos.\n", elapsed);

  printf("\n");
  //printf("%d\n", m);
  return 0;
}


/*
0 5 3 2 1
i = 1
0 2 3 5 1
q = 1
i2 = 3
tam = 5
pivot = l[tam-1] = 4
q
*/