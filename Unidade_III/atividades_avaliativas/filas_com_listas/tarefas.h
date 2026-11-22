#define SIZE_DESC 128
#define MAX_SIZE 32

typedef struct Tarefas{
	Fila *fila;
	char* descricoes[MAX_SIZE];
	int inicio;
	int fim;
}Tarefas;

void inicializarTarefas(Tarefas *tarefas);

int addTarefa(Tarefas *tarefas, int id, char *texto);

int execProxima(Tarefas *tarefas, int *id, char **texto);

int consultProxima(Tarefas *tarefas, int *id, char **texto);

void listarTarefas(Tarefas *tarefas);

void liberarTarefas(Tarefas *tarefas);
