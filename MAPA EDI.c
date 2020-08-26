#include <stdio.h> 
#include <stdlib.h> 

// Menus OK
void menualuno(){
	printf("------------------------------------------------------------------\n");
	printf("|             Aluno: Ezequiel Ribeiro - RA 18606645              |\n");
	printf("------------------------------------------------------------------\n");
}

void menu(){
	menualuno();
	printf("|  Digite 1 para listar todos os produtos cadastrados:           |\n");
	printf("|  Digite 2 para pesquisar um produto pelo codigo:               |\n");
	printf("|  Digite 3 para excluir um produto pelo codigo:                 |\n");
	printf("|  Digite 4 para fechar o programa:                              |\n");
	printf("|----------------------------------------------------------------|\n");
}

// Registro implementar o resto
struct Node {
	// int qtd;
	// double preco;
    int data; 
    struct Node* next; 
}; 

// Tamanho da lista OK
void lista_tam(struct Node* n){
	int contador = 1;
	while(n->next != NULL)
	{
		contador ++;
		n = n->next;
	}
	printf("\nLista com tam = %d\n", contador);
}

// Mostrar todos itens cadastrados OK
void lista_mostrar(struct Node* a) {
	while(a->next != NULL)
	{
		printf("%d, ", a->data);
		a = a->next;
	}
	printf("%d ", a->data); // Para imprimir o nó com next=NULL
}

// Mostrar itens pelo código OK
void lista_mostrar_cod(struct Node* n, int busca) {
	while(n->next != NULL)
	{
		if(n->data == busca)
		{
			menualuno();
			printf("CODIGO: %d encontrado.\n", n->data);
			printf("|----------------------------------------------------------------|\n");
			break;
		}
		
		n = n->next; 
		
		if (n->next == NULL && n->data == busca)
		{
			menualuno();
			printf("CODIGO: %d encontrado.\n", n->data);
			printf("|----------------------------------------------------------------|\n");
			break;
		}
	}
	
	if(n->next == NULL && n->data != busca)
	{
		menualuno();
		printf("CODIGO: %d nao encontrado.\n", busca);
		printf("|----------------------------------------------------------------|\n");
	}
}

void lista_apagar(struct Node* n, int busca) 
{  
	// Armazena o inicio da lista 
	struct Node* temp = NULL;
    temp = (struct Node*)malloc(sizeof(struct Node)); 
	*temp = *n;
	//printf("\n     Temp aponta para: %d\n", n->data);
	//printf("A busca está em: %d\n", busca);
	
	Node *anterior;
	printf("\n     Anterior aponta para: %d\n", anterior->data);
	Node *atual;
	
}

int main() {

	int busca = -1, escolha = 0;

    struct Node* p1 = NULL;
    struct Node* p2 = NULL;
    struct Node* p3 = NULL;

    p1 = (struct Node*)malloc(sizeof(struct Node)); 
    p2 = (struct Node*)malloc(sizeof(struct Node)); 
    p3 = (struct Node*)malloc(sizeof(struct Node)); 
  
    p1->data = 1; 
    p1->next = p2;
    
	p2->data = 2; 
    p2->next = p3;
	 
	p3->data = 3;
	p3->next = NULL;

	while(escolha != 4)
	{
		system("cls");
		menu();
		scanf("%d", &escolha);
		fflush(stdin);
		
		if(escolha == 1) {
			system("cls");
			menualuno();
			lista_mostrar(p1);
			printf("\n------------------------------------------------------------------\n");
			system("pause");
			
		} else if(escolha == 2) {
				system("cls");
				menualuno();
				printf("|  Digite o codigo a ser pesquisado:                             |\n");
				printf("------------------------------------------------------------------\n");
				scanf("%d", &busca);
				fflush(stdin);
				system("cls");
				lista_mostrar_cod(p1, busca);
				system("pause");
				
			} else if (escolha == 3) {
					system("cls");
					menualuno();
					printf("|  Digite o codigo do a ser excuido:                             |\n");
					printf("------------------------------------------------------------------\n");
					scanf("%d", &busca);
					fflush(stdin);
					lista_apagar(p1, busca);
					system("pause");
				} else {
					system("pause");
				}
	}
    return 0;
}
