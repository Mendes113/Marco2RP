#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "soccer.h"
#include "manipulaArquivo.h"
#define MAX_LINE_SIZE 100
Time meuTime;
void leArquivo(char *nomeArquivo)
{
    FILE *arquivo;
    char linha[100];
    int i = 0;
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    // Lê cada linha do arquivo e divide em campos separados por ';'
    int contador = 0;
    Jogador jogadores[25]; // Cria um vetor de jogadores para armazenar os dados
    while (fgets(linha, MAX_LINE_SIZE, arquivo) != NULL && contador <= 24)
    {
        /* This code is reading a line from a file and splitting it into fields separated by semicolons.
        The `strtok` function is used to split the line into tokens, which are then stored in the
        `jogadores` array of `struct Jogador`. */

        char *token;
        token = strtok(linha, ";");
        strcpy(jogadores[i].nome, token);

        token = strtok(NULL, ";");
        strcpy(jogadores[i].posicao, token);

        //  usando a função strtok(). A primeira chamada de strtok() é feita com a variável linha como primeiro argumento e ; como segundo argumento.

        token = strtok(NULL, ";");
        jogadores[i].tatica = atoi(token);

        token = strtok(NULL, ";");
        jogadores[i].tecnica = atoi(token);

        token = strtok(NULL, ";");
        jogadores[i].fisico = atoi(token);

        i++;
    }
    fclose(arquivo);

    for (int j = 0; j < i; j++)
    {
        meuTime.jogadores[j] = jogadores[j]; // adiciona o jogador ao vetor de jogadores do Time
    }
}

//metodo de salvar o arquivo
void salvarArquivo(char* nomeArquivo, Time meuTime) {
    FILE* arquivo;
    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < 25; i++) {
        fprintf(arquivo, "%s;%s;%d;%d;%d\n", meuTime.jogadores[i].nome, meuTime.jogadores[i].posicao, 
                meuTime.jogadores[i].tecnica, meuTime.jogadores[i].fisico, meuTime.jogadores[i].tatica);
    }
    fclose(arquivo);
    printf("Arquivo salvo com sucesso.\n");
}

//----------------------------------------------//

