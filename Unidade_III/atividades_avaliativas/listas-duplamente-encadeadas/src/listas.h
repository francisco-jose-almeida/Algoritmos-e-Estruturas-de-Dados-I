typedef struct No{
	int dado;
	struct No* anterior;
	struct No* proximo;
}No;
typedef struct Lista{
	No* inicio;
	No* fim;
}Lista;

void inicializar(Lista *lista);

void inserirInicio(Lista *lista, int valor);
void inserirFinal(Lista *lista, int valor);
void inserirPosicao(Lista *lista, int valor, int posicao);

void removerInicio(Lista *lista);
void removerFinal(Lista *lista);
void removerValor(Lista *lista, int valor);

No *buscar(Lista *lista, int valor);

void imprimirDireto(Lista *lista);
void imprimirInverso(Lista *lista);

int contarElementos(Lista *lista);

void liberarLista(Lista *lista);
