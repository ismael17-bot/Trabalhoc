#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "biblioteca.h"

int main(int argc, char const *argv[])
{
    //Definiçâo de variaveis 
    char infixa [50]="1+3*4-3";
    char posfixa [50];
    int posicaoPosfixa=0;
    char c;
    char x;
    int valida=0;
    int i=0;

    //Inicialização da pilha 
    PilhaChar Saida;
    inicializa_pilha_char(&Saida,strlen(infixa));

   
    for ( i = 0; i < strlen(infixa); i++)
    {
        c=infixa[i];
       switch (c)
       {
       case'0':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break;
        case'1':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break;
        case'2':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break;
        case'3':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break; 
        case'4':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break; 
        case'5':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break;
        case'6':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break;
        case'7':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break;
        case'8':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break;
        case'9':
          posfixa[posicaoPosfixa]=c;
          posicaoPosfixa++;  
           break; 
        case '(':
            empilha_char(&Saida,c);
            break;
        //case ')':

       
       default:
           break;
       }
    }
    printf("%s",infixa);
    printf("-------------------\n");
    printf("%s",posfixa);
    printf("-------------------\n");
    printf("-------------------\n");
    

    return 0;
}


//Funções

void inicializa_pilha_char( PilhaChar *p, int c ){
	p->dados = malloc( sizeof(char) * c );
	p->capacidade = c;
	p->topo = -1;	
}

int pilha_vazia_char( PilhaChar p ){
	return p.topo == -1;
}

int pilha_cheia_char( PilhaChar p ){
	return p.topo == p.capacidade - 1;
}

int empilha_char( PilhaChar *p, char info ){
	if( pilha_cheia_char( *p ) )
		return ERRO_PILHA_CHEIA;
	
	p->topo++;
	p->dados[p->topo] = info;
	return 1; // Sucesso	
}

int desempilha_char( PilhaChar *p, char *info ){
	if( pilha_vazia_char( *p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p->dados[p->topo];
	p->topo--;
	return 1; // Sucesso
}

int le_topo_char( PilhaChar p, char *info ){
	if( pilha_vazia_char( p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p.dados[p.topo];
	return 1; // Sucesso
}

void mostra_pilha_char( PilhaChar p ){
	if( pilha_vazia_char( p ) )
		printf("Pilha vazia!\n\n");
	else{
		int i;
		printf("Dados da pilha:\n");
		for( i = 0; i <= p.topo ; i++ )
			printf("%c\n", p.dados[i]);
		printf("\n");
	}
}
