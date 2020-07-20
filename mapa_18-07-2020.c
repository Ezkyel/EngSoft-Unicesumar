#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Menus
void menualuno(){
	printf("------------------------------------------------------------------\n");
	printf("|             Aluno: Ezequiel Ribeiro - RA 18606645              |\n");
	printf("------------------------------------------------------------------\n");
}
void menu(){
	menualuno();
	printf("|  Digite 1 para cadastrar:                                      |\n");
	printf("|  Digite 2 para listar os livros:                               |\n");
	printf("|  Digite 3 para listar as revisas:                              |\n");
	printf("|  Digite 4 para listar todos os itens de uma caixa:             |\n");
	printf("|  Digite 5 pesquisar um item pelo numero ISBN:                  |\n");
	printf("|  Digite 6 para fechar o programa:                              |\n");
	printf("|----------------------------------------------------------------|\n");
}
void menucad(){
	printf("|  Digite 1 para livros:                                         |\n");
	printf("|  Digite 2 para revistas:                                       |\n");
	printf("|----------------------------------------------------------------|\n");
}

// Registro para os livros e revistas
int i;
struct livros{
	int tipo, edicao, isbn, ano, qtd, caixa;
	char titulo[50];
	char autor[50];
	char editora[50];
}; struct livros livro[100];

// Funcao para impressão
void imprimir(int i){
	printf("TITULO: %s", livro[i].titulo);
	printf("AUTOR: %s", livro[i].autor);
	printf("EDITORA: %s", livro[i].editora);
	printf("EDICAO: %d\n", livro[i].edicao);
	printf("ANO: %d\n", livro[i].ano);
	printf("ISBN: %d\n", livro[i].isbn );
	printf("QUANTIDADE DE EXEMPLARES: %d\n", livro[i].qtd);
	printf("ARMAZENADO NA CAIXA: %d\n\n", livro[i].caixa);
}

int main(){
	
	// Criação/Abertura do arquivo
	FILE *arq;
	arq = fopen("arquivo.txt", "a+");
	
	// Declaração das variáveis
	int j, busca, acha, a=0, entrada=0;
	
	//Leitura do arquivo
	rewind(arq);
	while (!feof(arq)){ 
		char get_tipo;
		fgets(&get_tipo, 50, arq);
		int ctoi = get_tipo - '0';
		livro[a].tipo = ctoi;
		
		fgets(livro[a].titulo, 50, arq);
		
		fgets(livro[a].autor, 50, arq);
		
		fgets(livro[a].editora, 50, arq);
		
		char get_edicao;
		fgets(&get_edicao, 50, arq);
		ctoi = get_edicao - '0';
		livro[a].edicao = ctoi;
		
		char get_ano;
		fgets(&get_ano, 50, arq);
		ctoi = get_ano - '0';
		livro[a].ano = ctoi;
		
		char get_isbn;
		fgets(&get_isbn, 50, arq);
		ctoi = get_isbn - '0';
		livro[a].isbn = ctoi;
		
		char get_qtd;
		fgets(&get_qtd, 50, arq);
		ctoi = get_qtd - '0';
		livro[a].qtd = ctoi;
		
		char get_caixa;
		fgets(&get_caixa, 50, arq);
		ctoi = get_caixa - '0';
		livro[a].caixa = ctoi;
		a++;    
	}
	
	while (entrada != 6){ // Cadastros
		menu();
		scanf("%d", &entrada);
		fflush(stdin);
		
		if (entrada == 1)
		{	
			system("cls");
			menualuno();
			menucad();
			scanf("%d", &entrada);
			livro[a].tipo = entrada;
			fprintf(arq, "%d\n", entrada);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite o titulo: ");
			scanf("%30[^\n]s", &livro[a].titulo);
			fprintf(arq, "%s\n", livro[a].titulo);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite o nome do autor: ");
			scanf("%30[^\n]s", &livro[a].autor);
			fprintf(arq, "%s\n", livro[a].autor);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite a editora: ");
			scanf("%30[^\n]s", &livro[a].editora);
			fprintf(arq, "%s\n", livro[a].editora);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite a edicao: ");
			scanf("%d", &livro[a].edicao);
			fprintf(arq, "%d\n", livro[a].edicao);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite o ano: ");
			scanf("%d", &livro[a].ano);
			fprintf(arq, "%d\n", livro[a].ano);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite o codigo ISBN: ");
			scanf("%d", &livro[a].isbn);
			fprintf(arq, "%d\n", livro[a].isbn);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite a quantidade de exemplares: ");
			scanf("%d", &livro[a].qtd);
			fprintf(arq, "%d\n", livro[a].qtd);
			fflush(stdin);
			
			system("cls");
			menualuno();
			printf("Digite o numero da caixa em que os exemplares serao armazenados: ");
			scanf("%d", &livro[a].caixa);
			fprintf(arq, "%d\n", livro[a].caixa);
			fflush(stdin);		
			a++;
			system("cls");
		} 
		else if(entrada == 2) // Listagem dos livros
		{
			system("cls");
			for(i=0; i<=a; i++)
			{
				if (livro[i].tipo == 1)
				{	
					imprimir(i);
				}
			}
		}
		else if(entrada == 3) // Listagem das revistas
		{
			system("cls");
			for(i=0; i<=a; i++)
			{
				if (livro[i].tipo == 2)
				{
					imprimir(i);
				}
			}
		}
		else if	(entrada == 4) // Listagem dos itens de uma caixa
		{
			system("cls");
			printf("Digite o numero da caixa que deseja buscar: ");
			scanf ("%d", &busca);
			i = 0;
			acha = 0;
			
			while (i <= a)
			{
				for(i=0; i<=a; i++)
				{
					if (livro[i].caixa == busca)
					{
						acha++;
						imprimir(i);
					}
					else if (i == a && acha == 0)
					{
						system("cls");
						printf("\nERRO: A caixa de numero %d nao existe!\n", busca);
						system("pause");
					}
				}
			}
		}	
		else if (entrada == 5) //Busca pelo código ISBN
		{
			system("cls");
			printf("Digite o codigo ISBN que deseja buscar: ");
			scanf ("%d", &busca);
			i = 0;
			acha = 0;
			
			while ((i < a) && (acha == 0))
			{
				if (livro[i].isbn == busca)
					acha = 1;
					else
						i++;
			}
			if (acha == 1)
				{
					imprimir(i);
				}
		}
		
	}
	
	fclose(arq);
	return 0;
}
