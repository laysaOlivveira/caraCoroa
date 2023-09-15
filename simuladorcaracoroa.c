#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CARA 1
#define COROA 2

int jogador;
int maquina;

void jogo();
void resultado(int result);
int verifica(int p1, int p2);


int main(){
    
    srand(time(NULL)); //fun p/ gerar numeros diferentes

    printf("                   CARA - COROA  ");

    printf("\nSerão 3 rodadas!\nA cada rodada você escolherá o lado que deseja!\n");

    for(int i = 0 ; i < 3 ; i++){ 
        jogo();
        printf("-------------------------------------------------------------------------------\n");
    }
    
    //Imprime resultado das 3 rodadas
    printf("Melhor de 3: ");
    if(jogador > maquina){
        printf("YOU WIN!\n");
    }
    else{
        printf("OPS! mais sorte na proxima vez...\n");
    }

    printf("\n Obrigada por jogar!");

    system("pause>nul");
    return 0;
}


void jogo(){

    int escolhaJogador;
    int sorteado;
    
    printf("\n 1.CARA 2.COROA \n Escolha: ");
    scanf("%d", &escolhaJogador); //jogador faz sua escolha
    
    //mostra a escolha
    printf("\n Voce escolheu: ");
    resultado(escolhaJogador);

    printf("\n Jogando moeda...");
    sorteado = rand()%2+1; //sorteia cara ou coroa

    //mostra qual lado saiu
    printf("\n A moeda caiu com ");
    resultado(sorteado);
    printf(" para cima.\n");

    //verifica ganhador
    int ganhador = verifica(escolhaJogador, sorteado);

    //mostra o ganhador
    printf("\n");
    if(ganhador == 1){
        printf("Você ganhou 1 ponto.\n");
        jogador++;
    }
    else if(ganhador == 2){
        printf("O computador ganhou 1 ponto.\n");
        maquina++;
    }
    
    printf("\n");
}


void resultado(int result){
    if(result == CARA){
        printf("CARA");
    }
    else{
        printf("COROA");
    }
}


/* Funcao que verifica qual jogador ganhou e retorna 1 ou 2 */
int verifica(int p1, int p2){

    int ganhador;

    if(p1 == p2){
        ganhador = 1;
    }
    else{
        ganhador = 2;
    }

    return ganhador;
}