#include <stdlib.h>
#include "utils.h"
#include <stdio.h>
#include <time.h>

int* merge(int* l1, int* l2, int tam1, int tam2){
  int k, i, j;
  i = j = 0;

  int* l3 = (int*) malloc(sizeof(int)*(tam1 + tam2));

  for(k = 0; k < tam1 + tam2; k++)
    l3[k] = ((l1[i] <= l2[j] && i < tam1) || j >= tam2) ? l1[i++] : l2[j++];

  return l3;
}

void merge_sort(int* l, int tam) {
  int m = tam/2;
  int* aux;

  if (tam > 1) {
    merge_sort(l, m);
    merge_sort(&l[m], tam - m);
  }

  aux = merge(l, &l[m], m, tam - m);

  for(int j = 0; j < tam; j++) l[j] = aux[j];
}

int selecaoMergeSort(int* l, int tam, int i){
  merge_sort(l, tam);
  return l[i];
}

int main(){
  Bool sucesso = TRUE;
  int i, tam, j, m;
  int* l;
  clock_t start, end;
  double elapsed;
  
  scanf(" %d", &tam);
  l = (int*) malloc(sizeof(int)*tam);

  for(j = 0; j < tam; j++) scanf(" %i", &l[j]);
  
  scanf(" %d", &i);
  start = clock();
  m = selecaoMergeSort(l, tam, i);
  end = clock();

  elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  for(j = 1; j < tam; j++) {
    //printf("%i\n", l[j]);
    if(l[j-1] > l[j])
      sucesso = FALSE;
  }

  if(sucesso){
    printf("Arranjo com %i elementos ordenado com sucesso\n", tam);
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
  return 0;
}


