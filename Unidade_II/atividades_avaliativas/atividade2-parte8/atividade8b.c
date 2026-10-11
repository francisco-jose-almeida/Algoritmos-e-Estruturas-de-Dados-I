#include "entidade.h"
#include "raylib.h"

int main(){

	Entidade* vetor[3];

	TipoEntidade tipo=ENTIDADE_JOGADOR;
	Vector2 pos=(Vector2){200,300};
	vetor[0]=entidadeCriar(tipo,pos);

	tipo=ENTIDADE_INIMIGO;
	pos=(Vector2){400,300};
	vetor[1]=entidadeCriar(tipo,pos);

	tipo=ENTIDADE_ITEM;
	pos=(Vector2){600,300};
	vetor[2]=entidadeCriar(tipo,pos);



	InitWindow(800,600,"Atividade8b");

	 while(!WindowShouldClose()){
		BeginDrawing();

		ClearBackground(RAYWHITE);

		for(int i=0;i<3;i++){
			entidadeDesenhar(vetor[i]);
		}
		

		EndDrawing();
	 }

	 CloseWindow();


	return 0;
}
