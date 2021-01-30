#define ERRO_PILHA_VAZIA - 1
#define ERRO_PILHA_CHEIA - 2

typedef struct{
	char *dados;
	int topo;
	int capacidade;
}PilhaChar;

int ordemOperadores (int sinal);
void inicializa_pilha_char( PilhaChar *p, int c );
int pilha_vazia_char( PilhaChar p );
int pilha_cheia_char( PilhaChar p );
int empilha_char( PilhaChar *p, char info );
int desempilha_char( PilhaChar *p, char *info );
int le_topo_char( PilhaChar p, char *info );
void mostra_pilha_char( PilhaChar p );
void desaloca_pilha_char( PilhaChar *p );

typedef struct{
	int *dados;
	int topo;
	int capacidade;
}Pilha;

void inicializa_pilha( Pilha *p, int c );
int pilha_vazia( Pilha p );
int pilha_cheia( Pilha p );
int empilha( Pilha *p, int info );
int desempilha( Pilha *p, int *info );
int le_topo( Pilha p, int *info );
int Retorna_pilha( Pilha p );
void desaloca_pilha( Pilha *p );
