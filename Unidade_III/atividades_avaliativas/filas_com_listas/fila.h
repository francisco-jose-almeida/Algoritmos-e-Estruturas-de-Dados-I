typedef int Tipo;

typedef struct No{
	    Tipo dado;
	    struct No* proximo;
}No;

typedef struct Fila{
	    No *inicio;
	    No *fim;
}Fila;

void inicializar(Fila *fila);

int estaVazia(Fila *fila);

int enqueue(Fila *fila, Tipo valor);

int dequeue(Fila *fila, Tipo *valor);

int front(Fila *fila, Tipo *valor);

int back(Fila *fila, Tipo *valor);

void imprimirFila(Fila *fila);

int contarElementos(Fila *fila);

void liberarFila(Fila *fila);
