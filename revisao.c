#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "biblioteca.h"
#define ERRO -1

int main(int argc, char const *argv[])
{
    //Definiçâo de variaveis 
    char infixa [50]="1+2*3-4";
    char posfixa [50];
    int posicaoPosfixa=0;
    char c;
    char x;
    int valida=1;
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
        case ')':
            while ((le_topo_char(Saida,&c)==valida)&&(x!='('))
            {
               desempilha_char(&Saida,&x);
               posfixa[posicaoPosfixa]=x;
               posicaoPosfixa++;
            }if(pilha_vazia_char(Saida)==ERRO_PILHA_VAZIA){
               printf("Erro: nâo tem '(' e nem ')'");
               valida=ERRO;
            }else{
               desempilha_char(&Saida,&x);
            }
            break;
            case'+':
               le_topo_char(Saida,&x);
               if((pilha_vazia_char(Saida)==ERRO_PILHA_VAZIA)||(x!='(')){
                  empilha_char(&Saida,c);
               }else{
                  while ((le_topo_char(Saida,&c)!=ERRO_PILHA_VAZIA  )&&(ordemOperadores(x)>=ordemOperadores(c)))
                  {
                     	desempilha_char(&Saida,&x);
                        posfixa[posicaoPosfixa]=x;
                        posicaoPosfixa++;
                  }
                  empilha_char(&Saida,c);
               }
               break;
            case'-':
               le_topo_char(Saida,&x);
               if((pilha_vazia_char(Saida)==ERRO_PILHA_VAZIA)||(x!='(')){
                  empilha_char(&Saida,c);
               }else{
                  while ((le_topo_char(Saida,&c)!=ERRO_PILHA_VAZIA  )&&(ordemOperadores(x)>=ordemOperadores(c)))
                  {
                     	desempilha_char(&Saida,&x);
                        posfixa[posicaoPosfixa]=x;
                        posicaoPosfixa++;
                  }
                  empilha_char(&Saida,c);
               }
               break; 
            case'*':
               le_topo_char(Saida,&x);
               if((pilha_vazia_char(Saida)==ERRO_PILHA_VAZIA)||(x!='(')){
                  empilha_char(&Saida,c);
               }else{
                  while ((le_topo_char(Saida,&c)!=ERRO_PILHA_VAZIA  )&&(ordemOperadores(x)>=ordemOperadores(c)))
                  {
                     	desempilha_char(&Saida,&x);
                        posfixa[posicaoPosfixa]=x;
                        posicaoPosfixa++;
                  }
                  empilha_char(&Saida,c);
               }
               break; 
            case'/':
               le_topo_char(Saida,&x);
               if((pilha_vazia_char(Saida)==ERRO_PILHA_VAZIA)||(x!='(')){
                  empilha_char(&Saida,c);
               }else{
                  while ((le_topo_char(Saida,&c)!=ERRO_PILHA_VAZIA  )&&(ordemOperadores(x)>=ordemOperadores(c)))
                  {
                     	desempilha_char(&Saida,&x);
                        posfixa[posicaoPosfixa]=x;
                        posicaoPosfixa++;
                  }
                  empilha_char(&Saida,c);
               }
               break; 
       default:
           break;
       }
    }


    if(valida== 1){
        while((le_topo_char(Saida,&x)!= ERRO_PILHA_VAZIA) && (x != '(')){
            desempilha_char(&Saida,&x);
            posfixa[posicaoPosfixa] = x;
            posicaoPosfixa++;
                
        }
        if((le_topo_char(Saida,&x)== ERRO_PILHA_VAZIA)){
            posfixa[posicaoPosfixa] = '\0';
            printf("%s\n",posfixa);
        }
        else{
            printf("Erro: '(' nao foi fechado!\n");
        }
     } 
     
     
   //  printf("%s",infixa);
   //  printf("-------------------\n");
   //  printf("%s",posfixa);
   //  printf("-------------------\n");
   //  printf("-------------------\n");
    

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

int ordemOperadores (int sinal){
   int M_M=1;
   int X_X=2;
	if(sinal=='('){
		return 0;
	}else if((sinal=='+')||(sinal=='-')){
		return M_M;
	}else if ((sinal=='*')||(sinal=='/')){
		return X_X;	
	}
}



void inicializa_pilha( Pilha *p, int c ){
	p->dados = malloc( sizeof(int) * c );
	p->capacidade = c;
	p->topo = -1;	
}

int pilha_vazia( Pilha p ){
	return p.topo == -1;
}

int pilha_cheia( Pilha p ){
	return p.topo == p.capacidade - 1;
}

int empilha( Pilha *p, int info ){
	if( pilha_cheia( *p ) )
		return ERRO_PILHA_CHEIA;
	
	p->topo++;
	p->dados[p->topo] = info;
	return 1; // Sucesso	
}

int desempilha( Pilha *p, int *info ){
	if( pilha_vazia( *p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p->dados[p->topo];
	p->topo--;
	return 1; // Sucesso
}

int le_topo( Pilha p, int *info ){
	if( pilha_vazia( p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p.dados[p.topo];
	return 1; // Sucesso
}

void mostra_pilha( Pilha p ){
	if( pilha_vazia( p ) )
		printf("Pilha vazia!\n\n");
	else{
		int i;
		printf("Dados da pilha:\n");
		for( i = 0; i <= p.topo ; i++ )
			printf("%d\n", p.dados[i]);
		printf("\n");
	}
}

void desaloca_pilha( Pilha *p ){
	free( p->dados );

}