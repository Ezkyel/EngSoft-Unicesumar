#include<stdlib.h>
#include<stdio.h>
#define TMAX 10

// Implementação de push e pop em pilhas

struct Pilha{
		int data[TMAX], ini, fim;
	};

struct Pilha pilha;

void push(int i){
	if(pilha.fim == TMAX){
		printf("ERRO: Pilha cheia!\n");
	} else {
		pilha.data[pilha.fim] = i;
		pilha.fim++;
	}
}

int pop(){
	int i;
	if(pilha.ini == pilha.fim){
		printf("ERRO: Pilha vazia!\n");
	} else {
		pilha.fim--;
		i = pilha.data[pilha.fim];
		return i;
	}
}

int main(){
	
	int i, j, k;
	
	while (i != -1){
		printf("Digite 1 para push e 2 para pop: ");
		scanf("%d", &i);
		fflush(stdin);
		system("cls");
		j=0;
		
		if(i == 1){
			printf("Digite o elemento a ser empilhado: ");
			scanf("%d", &i);
			push(i);
			fflush(stdin);
			while(j <= TMAX){
				printf("Posicao %d = %d\n", j, pilha.data[j]);
				j++;
			}
		} if(i == 2){
			system("cls");
			pop();
			while(j <= TMAX){
				printf("Posicao %d = %d\n", j, pilha.data[j]);
				j++;
			}
		}
	}
	
	return 0;
}

