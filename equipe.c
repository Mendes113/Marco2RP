#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipe.h"
#include "manipulaArquivo.h"

Time meuTime;

void calcular_medias(Jogador *jogadores, int num_jogadores, Time *meuTime)
{
    float soma_tatica = 0, soma_tecnica = 0, soma_fisico = 0, soma_defesa = 0, soma_ataque = 0;
    float a = 0.5, b = 0.3, c = 0.2, d = 0.4, e = 0.5, f = 0.1; // valores iniciais das constantes

    for (int i = 0; i < num_jogadores; i++)
    {
        soma_tatica += jogadores[i].tatica;
        soma_tecnica += jogadores[i].tecnica;
        soma_fisico += jogadores[i].fisico;
    }

    meuTime->defesa = (a * soma_tatica) + (b * soma_tecnica) + (c * soma_fisico);
    meuTime->ataque = (d * soma_tatica) + (e * soma_tecnica) + (f * soma_fisico);

    printf("Defesa: %.2f\n", meuTime->defesa);
    printf("Ataque: %.2f\n", meuTime->ataque);
}

void imprime_jogadores(Jogador *jogadores, int num_jogadores)
{
    for (int i = 0; i < num_jogadores; i++)
    {
        printf("Nome: %s\n", jogadores[i].nome);
        printf("Posicao: %s\n", jogadores[i].posicao);
        printf("Tatica: %d\n", jogadores[i].tatica);
        printf("Tecnica: %d\n", jogadores[i].tecnica);
        printf("Fisico: %d\n\n", jogadores[i].fisico);
    }
}

// treinamento do time (aumenta atributos +1 : técnica, físico e tática)
void treinamento(Time meuTime) {
    int tipoTreinamento;
    printf("Selecione o tipo de treinamento:\n");
    printf("1. Treino técnico\n");
    printf("2. Treino físico\n");
    printf("3. Treino tático\n");
    scanf("%d", &tipoTreinamento);

    int i;
    switch(tipoTreinamento) {
        case 1:
            for (i = 0; i < 25; i++) {
                meuTime.jogadores[i].tecnica++;
                printf("Realizando treino técnico...\n");
            }
            break;
        case 2:
            for (i = 0; i < 25; i++) {
                meuTime.jogadores[i].fisico++;
                printf("Realizando treino físico...\n");
            }
            break;
        case 3:
            for (i = 0; i < 25; i++) {
                meuTime.jogadores[i].tatica++;
                printf("Realizando treino tático...\n");
            }
            return;
        default:
            printf("Tipo de treinamento inválido!\n");
            break;
    }
}

//----------------------------------------------//


char criar_time(Time *meuTime)
{
    char nome[30];
    printf("Digite o nome do time: ");
    scanf("%s", nome);
    strcpy(meuTime->nome, nome);
    printf("Time criado com sucesso!\n");
    return 1;
}