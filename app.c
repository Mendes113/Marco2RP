#include <stdio.h>
#include <stdlib.h>
#include "soccer.c"
#include "equipe.c"
#include <string.h>
#include "equipe.h"
#include "escalacao.h"
#include "escalacao.c"
#include "manipulaArquivo.c"
#include "manipulaArquivo.h"
#include "minunit.h"


void menuInicio(){
    leArquivo("jogadores.txt");
    int op = 0;
    printf("Novo jogo:\n");
    printf("Escolha um time:\n");
    printf("1. Barcelona\n");
    printf("2. Real Madrid\n");
    printf("3. Manchester United\n");
    printf("4. Bayern de Munique\n");
    scanf("%d", &op);

   do{ 
    switch(op){
        case 1:
            printf("Você escolheu o Barcelona!\n");
            criar_time(&meuTime);
            break;  
        case 2:
            printf("Você escolheu o Real Madrid!\n");
             criar_time(&meuTime);
            break;
        case 3:
            printf("Você escolheu o Manchester United!\n");
             criar_time(&meuTime);
            break;
        case 4:
            printf("Você escolheu o Bayern de Munique!\n");
             criar_time(&meuTime);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
   } while(op < 1 || op > 4);
   
}

//funcionou
void menuPrincipal() {
    int opcao = 0;
      int opcaoEscala = 0;

    printf("1. Escalar time\n");
    printf("2. Treinar time\n");
    printf("3. Jogar partida\n");
    printf("4. Listar todos os jogadores\n");
    printf("5. Mostrar jogadores da escalação\n");
    printf("6. Ver Tabela de campoenato\n");
    printf("7. Salvar\n");
    printf("8. Sair\n");

    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Opcao selecionada: Escalar time\n");
            escalacao(meuTime);
            break;
        case 2:
            printf("Opcao selecionada: Treinar time\n");
            treinamento(meuTime);
            break;
        case 3:
            printf("Opcao selecionada: Jogar partida\n");
            jogo(meuTime , time2);
            break;

        case 4:
            printf("Opcao selecionada: Listar todos os jogadores\n");
            imprime_jogadores(meuTime.jogadores,24);
            // printf("Opcao selecionada: Salvar\n");
            // salvarArquivo("jogadores.txt", meuTime);
            break;

        case 5:
          
            printf("Opcao selecionada: Mostrar jogadores da escalação\n");
            printf("1. 4-3-3\n");
            printf("2. 4-4-2\n");
            printf("3. 3-4-3\n");
            printf("4. Voltar\n");

            scanf("%d", &opcaoEscala);
            switch (opcaoEscala)
            {
            case 1:
                printf("Opcao selecionada: 4-3-3\n");
                mostra433(quatro_tres_tres);
                break;

            case 2:
                printf("Opcao selecionada: 4-4-2\n");
                mostra442(quatro_quatro_dois);
                break;

            case 3:

                printf("Opcao selecionada: 3-4-3\n");
                mostra343(tres_quatro_tres);
                break;

            case 4:
                printf("Opcao selecionada: Voltar\n");
                menuPrincipal();
                break;

                // Lógica para sair do programa
                break;



            default:
                printf("Opcao invalida!\n");
                break;
            }
            mostra343(tres_quatro_tres);
            mostra442(quatro_quatro_dois);
            mostra433(quatro_tres_tres);
            // printf("Opcao selecionada: Sair\n");
            // Lógica para sair do programa
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

