typedef struct No{
	    void* dado;
	    struct No* proximo;
}No;

typedef struct Fila{
	    No *inicio;
	    No *fim;
}Fila;

void inicializar(Fila *fila);

int estaVazia(Fila *fila);

int enqueue(Fila *fila, void *valor);

int dequeue(Fila *fila, void **valor);

int front(Fila *fila, void **valor);

int back(Fila *fila, void* *valor);

void imprimirFila(Fila *fila);

int contarElementos(Fila *fila);

void liberarFila(Fila *fila);
