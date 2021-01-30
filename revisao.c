#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "biblioteca.h"
#define ERRO -1
int converteChar(int p);


int main(int argc, char const *argv[])
{
    //Definiçâo de variaveis 
    char infixa [50];
    strcpy(infixa,"");
    char posfixa [50];
    strcpy(posfixa,"");
    int posicaoPosfixa=0;
    char c[2]={' ','\0'};
    char x;
    int valida=1;
    int i=0;
    char carc;

    //entrada da string
    printf("Digite uma expressão:");
   /*Estou fazendo a entrada atraves de um char, e dps passo para uma str
     fazendo dessa maneira pra garantir que os espaços na digitaçao não interfiram 
   */
   do{
      carc=getchar();
      if(carc!=' '){
         infixa[i]=carc;
         i++;
      }
   }while (carc!='\n');
    infixa[i-1]='\0';
    system("cls");

    //Inicialização da pilha 
    PilhaChar Saida;
    inicializa_pilha_char(&Saida,strlen(infixa));
    
    for ( i = 0; i < strlen(infixa); i++)
    {

        c[0]=infixa[i];
       switch (infixa[i])
       {
       case'0'...'9':
          posfixa[posicaoPosfixa]=c[0];
          posicaoPosfixa++;  
           break;
        case '(':
            empilha_char(&Saida,c[0]);
            break;
        case ')':
            while ((le_topo_char(Saida,&x)!=ERRO_PILHA_VAZIA)&&(x!='('))
            {
               desempilha_char(&Saida,&x);
               posfixa[posicaoPosfixa]=x;
               posicaoPosfixa++;
            }
            if(le_topo_char(Saida,&x)==ERRO_PILHA_VAZIA){
               printf("Erro: nâo tem '(' e nem ')'");
               valida=ERRO;
            }else{
               desempilha_char(&Saida,&x);
            }
            break;
            case'*':
            case'-':
            case'/':
            case'+':
               le_topo_char(Saida,&x);
               if((le_topo_char(Saida,&x)==ERRO_PILHA_VAZIA)||(x=='(')){
                  empilha_char(&Saida,c[0]);
               }else{
                  while ((le_topo_char(Saida,&x)!=ERRO_PILHA_VAZIA  )&&(ordemOperadores(x)>=ordemOperadores(c[0])))
                  {
                     	desempilha_char(&Saida,&x);
                        posfixa[posicaoPosfixa]=x;
                        posicaoPosfixa++;
                  }
                  empilha_char(&Saida,c[0]);
               }
               break;
       default:
        valida=-1;
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
        }
        else{
            printf("Erro: '(' nao foi fechado!\n");
        }
     } 

     //Definição de variaveis
     int tamanho=strlen(posfixa);
     Pilha Soma;
     inicializa_pilha(&Soma,tamanho);
     int auxi1=0;
     int auxi2=0;
     //separação 

     for ( i = 0; i < tamanho; i++)
     {
         c[0]=posfixa[i];
        if ((c[0]>=48)&&(c[0]<=57)){
            int j=(int)c[0];
            int recebe=converteChar(j);
            empilha(&Soma,recebe);   //gcc revisao.c pilha.c -o a
        }else{
           int result=0;
           desempilha(&Soma,&auxi2);
           desempilha(&Soma,&auxi1);
           switch (c[0])
           {
           case '+':
               result=auxi1+auxi2;
              break;
           case '-':
               result=auxi1-auxi2;
              break;
           case '*':
              result=auxi1*auxi2;
              break;
           case '/':
              result=auxi1/auxi2;
              break;   
           }
          empilha(&Soma,result);
        }
     }

   
   double resultadoPosfixa= Retorna_pilha(Soma); 
   //printf("%.1f",resultadoPosfixa);
   printf("------------------------------------------\n");
    printf("Aqui a expressão infixa: ");
    printf("%s = %.1f\n",infixa,resultadoPosfixa);
    printf("------------------------------------------\n");
    printf("Aqui a expressão posfixa: ");
    printf("%s = %.1f\n",posfixa,resultadoPosfixa);
    printf("------------------------------------------\n\n");
   desaloca_pilha(&Soma);
   desaloca_pilha_char(&Saida);
    return 0;
}

//Funções
int converteChar(int p){
   int retornoInteiro=(p-48);
   return retornoInteiro;
}

void desaloca_pilha_char( PilhaChar *p ){
	

	free( p->dados );
}

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

int Retorna_pilha( Pilha p ){
	if( pilha_vazia( p ) )
		printf("Pilha vazia!\n\n");
	else{
		int i;
		//printf("Resultado:\n");
		for( i = 0; i <= p.topo ; i++ )
			return p.dados[i];
	}
}

void desaloca_pilha( Pilha *p ){
	free( p->dados );

}