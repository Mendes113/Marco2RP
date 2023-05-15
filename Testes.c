#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "soccer.h"
#include "equipe.h"
#include "escalacaoTest.h"
#include <time.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 100
#include <math.h> // Inclua a biblioteca math.h para usar a função fabs

#define TOLERANCE 0.01 // Defina a tolerância desejada

Quatro_quatro_dois quatro_quatro_dois;
Quatro_tres_tres quatro_tres_tres;
Tres_quatro_tres tres_quatro_tres;

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

// Teste para a função leArquivo
MU_TEST(test_leArquivo)
{
    // Cria um arquivo temporário com dados fictícios
    FILE *arquivo = fopen("temp.txt", "wb");
    if (arquivo == NULL)
    {
        mu_fail("Erro ao criar arquivo temporário");
        return;
    }

    fprintf(arquivo, "Jogador1;A;4;5;3\n");
    fprintf(arquivo, "Jogador2;Z;3;4;5\n");
    fclose(arquivo);

    leArquivo("temp.txt");

    // Testa se os jogadores foram lidos corretamente
    mu_assert_string_eq("Jogador1", meuTime.jogadores[0].nome);
    mu_assert_string_eq("A", meuTime.jogadores[0].posicao);
    mu_assert_int_eq(4, meuTime.jogadores[0].tatica);
    mu_assert_int_eq(5, meuTime.jogadores[0].tecnica);
    mu_assert_int_eq(3, meuTime.jogadores[0].fisico);

    mu_assert_string_eq("Jogador2", meuTime.jogadores[1].nome);
    mu_assert_string_eq("Z", meuTime.jogadores[1].posicao);
    mu_assert_int_eq(3, meuTime.jogadores[1].tatica);
    mu_assert_int_eq(4, meuTime.jogadores[1].tecnica);
    mu_assert_int_eq(5, meuTime.jogadores[1].fisico);

    // Remove o arquivo temporário
    remove("temp.txt");
}

// metodo de salvar o arquivo
void salvarArquivo(char *nomeArquivo, Time meuTime)
{
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < 25; i++)
    {
        fprintf(arquivo, "%s;%s;%d;%d;%d\n", meuTime.jogadores[i].nome, meuTime.jogadores[i].posicao,
                meuTime.jogadores[i].tecnica, meuTime.jogadores[i].fisico, meuTime.jogadores[i].tatica);
    }
    fclose(arquivo);
    printf("Arquivo salvo com sucesso.\n");
}

//----------------------------------------------//

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
// Função para treinar a técnica de todos os jogadores
void treinar_tecnica(Time *meuTime)
{
    for (int i = 0; i < 25; i++)
    {
        if (meuTime->jogadores[i].tecnica < 10)
        { // verifica se a técnica é menor que 10
            meuTime->jogadores[i].tecnica++;
        }
    }
}

// Função para treinar a tática de todos os jogadores
void treinar_tatica(Time *meuTime)
{
    for (int i = 0; i < 25; i++)
    {
        if (meuTime->jogadores[i].tatica < 10)
        { // verifica se a tática é menor que 10
            meuTime->jogadores[i].tatica++;
        }
    }
}

// Função para treinar o físico de todos os jogadores
void treinar_fisico(Time *meuTime)
{
    for (int i = 0; i < 25; i++)
    {
        if (meuTime->jogadores[i].fisico < 10)
        { // verifica se o físico é menor que 10
            meuTime->jogadores[i].fisico++;
        }
    }
}

void escalacao(Time meuTime, int escolha)
{
    // printf("Escalações disponíveis: \n");
    // printf("1 - 4-4-2 \n");
    // printf("2 - 4-3-3 \n");
    // printf("3 - 3-4-3 \n");
    // printf("Escolha a escalação do seu time: \n");

    // scanf("%d", &escolha);
    int contadorAtacante = 0;
    int contadorZagueiro = 0;
    int contadorMeio = 0;
    int numZagueiros = 0;
    int numMeio = 0;
    int numAtacantes = 0;
    int numReserva = 0;
    int numGoleiro = 0;
    int contadorGoleiro = 0;
    switch (escolha)
    {
    case 1:

        printf("Você escolheu a escalaçAo 4-4-2 \n");

        for (int i = 0; i < 25; i++)
        {
            Jogador jogador = meuTime.jogadores[i];
            if (strcmp(jogador.posicao, "A") == 0)
            {
                contadorAtacante++;
            }
            if (strcmp(jogador.posicao, "Z") == 0)
            {
                contadorZagueiro++;
            }
            if (strcmp(jogador.posicao, "M") == 0)
            {

                contadorMeio++;
            }
            if (strcmp(jogador.posicao, "G") == 0)
            {

                contadorGoleiro++;
            }
        }
        while (contadorAtacante > 2)
        {
            int atacante1 = -1, atacante2 = -1;
            while (atacante1 == atacante2)
            {
                srand(time(NULL));
                atacante1 = rand() % contadorAtacante;
                atacante2 = rand() % contadorAtacante;
            }
            printf("Atacantes escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "A") == 0)
                {
                    if (atacante1 == 0 || atacante2 == 0)
                    {
                        printf("- %s\n", jogador.nome);
                        if (atacante1 == 0)
                        {
                            quatro_quatro_dois.atacantes[0] = jogador;
                        }
                        else
                        {
                            quatro_quatro_dois.atacantes[1] = jogador;
                        }
                        numAtacantes++;
                    }
                    else if (numReserva < contadorAtacante)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_quatro_dois.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    atacante1--;
                    atacante2--;
                }
            }
            contadorAtacante = 2;
        }
        while (contadorZagueiro > 2 && numZagueiros < 4)
        {
            int zagueiro1 = -1, zagueiro2 = -1, zagueiro3 = -1, zagueiro4 = -1;
            while (zagueiro1 == zagueiro2 || zagueiro1 == zagueiro3 || zagueiro1 == zagueiro4 || zagueiro2 == zagueiro3 || zagueiro2 == zagueiro4 || zagueiro3 == zagueiro4)
            {
                srand(time(NULL));
                zagueiro1 = rand() % contadorZagueiro;
                zagueiro2 = rand() % contadorZagueiro;
                zagueiro3 = rand() % contadorZagueiro;
                zagueiro4 = rand() % contadorZagueiro;
            }
            printf("Zagueiros escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "Z") == 0)
                {
                    if (zagueiro1 == 0 || zagueiro2 == 0 || zagueiro3 == 0 || zagueiro4 == 0)
                    {
                        printf("- %s\n", jogador.nome);
                        if (zagueiro1 == 0)
                        {
                            quatro_quatro_dois.defensores[0] = jogador;
                        }
                        else if (zagueiro2 == 0)
                        {
                            quatro_quatro_dois.defensores[1] = jogador;
                        }
                        else if (zagueiro3 == 0)
                        {
                            quatro_quatro_dois.defensores[2] = jogador;
                        }
                        else if (zagueiro4 == 0)
                        {
                            quatro_quatro_dois.defensores[3] = jogador;
                        }

                        numZagueiros++;
                    }
                    else if (numReserva < contadorZagueiro)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_quatro_dois.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    zagueiro1--;
                    zagueiro2--;
                    zagueiro3--;
                    zagueiro4--;
                }
            }
            contadorZagueiro = 4;
        }

        while (contadorMeio > 2 && numMeio < 4)
        {
            int meio1 = -1, meio2 = -1, meio3 = -1, meio4 = -1;
            while (meio1 == meio2 || meio1 == meio3 || meio1 == meio4 || meio2 == meio3 || meio2 == meio4 || meio3 == meio4)
            {
                srand(time(NULL));
                meio1 = rand() % contadorMeio;
                meio2 = rand() % contadorMeio;
                meio3 = rand() % contadorMeio;
                meio4 = rand() % contadorMeio;
            }
            printf("Meio escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "M") == 0)
                {
                    if (meio1 == 0 || meio2 == 0 || meio3 == 0 || meio4 == 0)
                    {
                        printf("- %s\n", jogador.nome);
                        if (meio1 == 0)
                        {
                            quatro_quatro_dois.meio_campo[0] = jogador;
                        }
                        else if (meio2 == 0)
                        {
                            quatro_quatro_dois.meio_campo[1] = jogador;
                        }
                        else if (meio3 == 0)
                        {
                            quatro_quatro_dois.meio_campo[2] = jogador;
                        }
                        else if (meio4 == 0)
                        {
                            quatro_quatro_dois.meio_campo[3] = jogador;
                        }
                        numMeio++;
                    }
                    else if (numReserva < contadorMeio)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_quatro_dois.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    meio1--;
                    meio2--;
                    meio3--;
                    meio4--;
                }
            }
            contadorMeio = 4;
        }

        while (contadorGoleiro > 0 && numGoleiro == 0)
        {
            int goleiro1 = -1;
            while (goleiro1 == -1)
            {
                srand(time(NULL));
                goleiro1 = rand() % contadorGoleiro;
            }
            printf("Goleiro escolhido:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "G") == 0)
                {
                    if (goleiro1 == 0)
                    {
                        printf("- %s\n", jogador.nome);
                        quatro_quatro_dois.goleiro = jogador;
                        numGoleiro++;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_quatro_dois.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    goleiro1--;
                }
            }
            contadorGoleiro = 1;
        }
        break;

    case 2:
        printf("Voce escolheu a Escalaçao 4-3-3\n");

        for (int i = 0; i < 25; i++)
        {
            Jogador jogador = meuTime.jogadores[i];
            if (strcmp(jogador.posicao, "A") == 0)
            {
                contadorAtacante++;
            }
            if (strcmp(jogador.posicao, "Z") == 0)
            {
                contadorZagueiro++;
            }
            if (strcmp(jogador.posicao, "M") == 0)
            {

                contadorMeio++;
            }
            if (strcmp(jogador.posicao, "G") == 0)
            {
                contadorGoleiro++;
            }
        }

        while (contadorAtacante > 3)
        {
            int atacante1 = -1, atacante2 = -1, atacante3 = -1;
            while (atacante1 == atacante2 || atacante1 == atacante3 || atacante2 == atacante3)
            {
                srand(time(NULL));
                atacante1 = rand() % contadorAtacante;
                atacante2 = rand() % contadorAtacante;
                atacante3 = rand() % contadorAtacante;
            }
            printf("Atacantes escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "A") == 0)
                {
                    if (atacante1 == 0 || atacante2 == 0 || atacante3 == 0)
                    {
                        printf("- %s\n", jogador.nome);

                        if (atacante1 == 0)
                        {
                            quatro_tres_tres.atacantes[0] = jogador;
                        }
                        else if (atacante2 == 0)
                        {
                            quatro_tres_tres.atacantes[1] = jogador;
                        }
                        else if (atacante3 == 0)
                        {
                            quatro_tres_tres.atacantes[2] = jogador;
                        }
                        numAtacantes++;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_tres_tres.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    atacante1--;
                    atacante2--;
                    atacante3--;
                }
            }
            contadorAtacante = 3; // Sai do loop while
        }
        while (contadorZagueiro > 2 && numZagueiros < 4) // Executa no máximo 4 vezes
        {
            int zagueiro1 = -1, zagueiro2 = -1, zagueiro3 = -1, zagueiro4 = -1;
            while (zagueiro1 == zagueiro2 || zagueiro1 == zagueiro3 || zagueiro1 == zagueiro4 || zagueiro2 == zagueiro3 || zagueiro2 == zagueiro4 || zagueiro3 == zagueiro4)
            {
                srand(time(NULL));
                zagueiro1 = rand() % contadorZagueiro;
                zagueiro2 = rand() % contadorZagueiro;
                zagueiro3 = rand() % contadorZagueiro;
                zagueiro4 = rand() % contadorZagueiro;
            }
            printf("Zagueiros escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "Z") == 0)
                {
                    if (zagueiro1 == 0 || zagueiro2 == 0 || zagueiro3 == 0 || zagueiro4 == 0)
                    {
                        printf("- %s\n", jogador.nome);

                        if (zagueiro1 == 0)
                        {
                            quatro_tres_tres.defensores[0] = jogador;
                        }
                        else if (zagueiro2 == 0)
                        {
                            quatro_tres_tres.defensores[1] = jogador;
                        }
                        else if (zagueiro3 == 0)
                        {
                            quatro_tres_tres.defensores[2] = jogador;
                        }
                        else if (zagueiro4 == 0)
                        {
                            quatro_tres_tres.defensores[3] = jogador;
                        }
                        numZagueiros++;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_tres_tres.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    zagueiro1--;
                    zagueiro2--;
                    zagueiro3--;
                    zagueiro4--;
                }
            }
            contadorZagueiro = 4;
        }

        while (contadorMeio > 2 && numMeio < 3)
        {
            int meio1 = -1, meio2 = -1, meio3 = -1;
            while (meio1 == meio2 || meio1 == meio3 || meio2 == meio3)
            {
                srand(time(NULL));
                meio1 = rand() % contadorMeio;
                meio2 = rand() % contadorMeio;
                meio3 = rand() % contadorMeio;
            }
            printf("Meio escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "M") == 0)
                {
                    if (meio1 == 0 || meio2 == 0 || meio3 == 0)
                    {
                        printf("- %s\n", jogador.nome);

                        if (meio1 == 0)
                        {
                            quatro_tres_tres.meio_campo[0] = jogador;
                        }
                        else if (meio2 == 0)
                        {
                            quatro_tres_tres.meio_campo[1] = jogador;
                        }
                        else if (meio3 == 0)
                        {
                            quatro_tres_tres.meio_campo[2] = jogador;
                        }

                        numMeio++;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_tres_tres.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    meio1--;
                    meio2--;
                    meio3--;
                }
            }
            contadorMeio = 3;
        }

        while (contadorGoleiro > 0 && numGoleiro == 0)
        {
            int goleiro1 = -1;
            while (goleiro1 == -1)
            {
                srand(time(NULL));
                goleiro1 = rand() % contadorGoleiro;
            }
            printf("Goleiro escolhido:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "G") == 0)
                {
                    if (goleiro1 == 0)
                    {
                        printf("- %s\n", jogador.nome);
                        quatro_tres_tres.goleiro = jogador;
                        numGoleiro++;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        quatro_tres_tres.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    goleiro1--;
                }
            }
            contadorGoleiro = 1;
        }

        break;

    case 3:
        printf("Voce escolheu a Escalaçao 3-4-3\n");

        for (int i = 0; i < 25; i++)
        {
            Jogador jogador = meuTime.jogadores[i];
            if (strcmp(jogador.posicao, "A") == 0)
            {
                contadorAtacante++;
            }
            if (strcmp(jogador.posicao, "Z") == 0)
            {
                contadorZagueiro++;
            }
            if (strcmp(jogador.posicao, "M") == 0)
            {
                contadorMeio++;
            }
            if (strcmp(jogador.posicao, "G") == 0)
            {
                contadorGoleiro++;
            }
        }

        while (contadorAtacante > 3)
        {
            int atacante1 = -1, atacante2 = -1, atacante3 = -1;
            while (atacante1 == atacante2 || atacante1 == atacante3 || atacante2 == atacante3)
            {
                srand(time(NULL));
                atacante1 = rand() % contadorAtacante;
                atacante2 = rand() % contadorAtacante;
                atacante3 = rand() % contadorAtacante;
            }
            printf("Atacantes escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "A") == 0)
                {
                    if (atacante1 == 0 || atacante2 == 0 || atacante3 == 0)
                    {
                        printf("- %s\n", jogador.nome);

                        if (atacante1 == 0)
                        {
                            tres_quatro_tres.atacantes[0] = jogador;
                        }
                        else if (atacante2 == 0)
                        {
                            tres_quatro_tres.atacantes[1] = jogador;
                        }
                        else if (atacante3 == 0)
                        {
                            tres_quatro_tres.atacantes[2] = jogador;
                        }

                        numAtacantes++;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        tres_quatro_tres.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    atacante1--;
                    atacante2--;
                    atacante3--;
                }
            }
            contadorAtacante = 3;
        }
        while (contadorZagueiro > 2 && numZagueiros < 4)
        {
            int zagueiro1 = -1, zagueiro2 = -1, zagueiro3 = -1;
            while (zagueiro1 == zagueiro2 || zagueiro1 == zagueiro3 || zagueiro2 == zagueiro3)
            {
                srand(time(NULL));
                zagueiro1 = rand() % contadorZagueiro;
                zagueiro2 = rand() % contadorZagueiro;
                zagueiro3 = rand() % contadorZagueiro;
            }

            printf("Zagueiros escolhidos:\n");
            for (int i = 0; i < 25; i++)
            {
                Jogador jogador = meuTime.jogadores[i];
                if (strcmp(jogador.posicao, "Z") == 0)
                {
                    if (zagueiro1 == 0 || zagueiro2 == 0 || zagueiro3 == 0)
                    {
                        printf("- %s\n", jogador.nome);

                        if (zagueiro1 == 0)
                        {
                            tres_quatro_tres.defensores[0] = jogador;
                        }
                        else if (zagueiro2 == 0)
                        {
                            tres_quatro_tres.defensores[1] = jogador;
                        }
                        else if (zagueiro3 == 0)
                        {
                            tres_quatro_tres.defensores[2] = jogador;
                        }

                        numZagueiros++;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        tres_quatro_tres.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                    zagueiro1--;
                    zagueiro2--;
                    zagueiro3--;
                }
                contadorZagueiro = 3;
            }

            while (contadorMeio > 2 && numMeio < 4)
            {
                int meio1 = -1, meio2 = -1, meio3 = -1, meio4 = -1;
                while (meio1 == meio2 || meio1 == meio3 || meio1 == meio4 || meio2 == meio3 || meio2 == meio4 || meio3 == meio4)
                {
                    srand(time(NULL));
                    meio1 = rand() % contadorMeio;
                    meio2 = rand() % contadorMeio;
                    meio3 = rand() % contadorMeio;
                    meio4 = rand() % contadorMeio;
                }
                printf("Meio escolhidos:\n");
                for (int i = 0; i < 25; i++)
                {
                    Jogador jogador = meuTime.jogadores[i];
                    if (strcmp(jogador.posicao, "M") == 0)
                    {
                        if (meio1 == 0 || meio2 == 0 || meio3 == 0 || meio4 == 0)
                        {
                            printf("- %s\n", jogador.nome);

                            if (meio1 == 0)
                            {
                                tres_quatro_tres.meio_campo[0] = jogador;
                            }
                            else if (meio2 == 0)
                            {
                                tres_quatro_tres.meio_campo[1] = jogador;
                            }
                            else if (meio3 == 0)
                            {
                                tres_quatro_tres.meio_campo[2] = jogador;
                            }
                            else if (meio4 == 0)
                            {
                                tres_quatro_tres.meio_campo[3] = jogador;
                            }
                            numMeio++;
                        }
                        meio1--;
                        meio2--;
                        meio3--;
                        meio4--;
                    }
                    else if (numReserva < 4)
                    {
                        printf("- %s (Reserva)\n", jogador.nome);
                        tres_quatro_tres.reserva[numReserva] = jogador;
                        numReserva++;
                    }
                }
                contadorMeio = 4;
            }
            while (contadorGoleiro > 0 && numGoleiro == 0)
            {
                int goleiro1 = -1;
                while (goleiro1 == -1)
                {
                    srand(time(NULL));
                    goleiro1 = rand() % contadorGoleiro;
                }
                printf("Goleiro escolhido:\n");
                for (int i = 0; i < 25; i++)
                {
                    Jogador jogador = meuTime.jogadores[i];
                    if (strcmp(jogador.posicao, "G") == 0)
                    {
                        if (goleiro1 == 0)
                        {
                            printf("- %s\n", jogador.nome);
                            tres_quatro_tres.goleiro = jogador;
                            numGoleiro++;
                        }
                        else if (numReserva < 4)
                        {
                            printf("- %s (Reserva)\n", jogador.nome);
                            tres_quatro_tres.reserva[numReserva] = jogador;
                            numReserva++;
                        }
                        goleiro1--;
                    }
                }
                contadorGoleiro = 1;
            }

            break;

        default:
            printf("Opção inválida\n");
            break;
        }
    }
}

void mostra442(Quatro_quatro_dois quatro_quatro_dois)
{
    printf("4-4-2:\n");
    printf("Atacantes:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("- %s\n", quatro_quatro_dois.atacantes[i].nome);
    }
    printf("Meio-campistas:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("- %s\n", quatro_quatro_dois.meio_campo[i].nome);
    }
    printf("Zagueiros:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("- %s\n", quatro_quatro_dois.defensores[i].nome);
    }

    printf("Goleiro:\n");
    for (int i = 0; i < 1; i++)
    {
        printf("- %s\n", quatro_quatro_dois.goleiro.nome);
    }

    printf("Reservas:\n");
    for (int i = 0; i < 11; i++)
    {
        printf("- %s\n", quatro_quatro_dois.reserva[i].nome);
    }
}

void mostra433(Quatro_tres_tres quatro_tres_tres)
{
    printf("4-3-3:\n");
    printf("Atacantes:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("- %s\n", quatro_tres_tres.atacantes[i].nome);
    }
    printf("Meio-campistas:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("- %s\n", quatro_tres_tres.meio_campo[i].nome);
    }
    printf("Zagueiros:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("- %s\n", quatro_tres_tres.defensores[i].nome);
    }
    printf("Goleiro:\n");
    for (int i = 0; i < 1; i++)
    {
        printf("- %s\n", quatro_quatro_dois.goleiro.nome);
    }

    printf("Reservas:\n");
    for (int i = 0; i < 11; i++)
    {
        printf("- %s\n", quatro_quatro_dois.reserva[i].nome);
        if (quatro_tres_tres.reserva[i].nome == NULL)
        {
            break;
        }
    }
}

void mostra343(Tres_quatro_tres tres_quatro_tres)
{
    printf("3-4-3:\n");
    printf("Atancates:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("- %s\n", tres_quatro_tres.atacantes[i].nome);
    }
    printf("Meio-campistas:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("- %s\n", tres_quatro_tres.meio_campo[i].nome);
    }
    printf("Zagueiros:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("- %s\n", tres_quatro_tres.defensores[i].nome);
    }
    printf("Goleiro:\n");
    for (int i = 0; i < 1; i++)
    {
        printf("- %s\n", quatro_quatro_dois.goleiro.nome);
    }

    printf("Reservas:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("- %s\n", quatro_quatro_dois.reserva[i].nome);
        if (tres_quatro_tres.reserva[i].nome == NULL)
        {
            break;
        }
    }
}

Time time3;
Time time4;
Time time2 = {"Joinville", 120.0, 130.2, {} };

void chanceGol442(Quatro_quatro_dois quatro_quatro_dois);
void chanceGol433(Quatro_tres_tres quatro_tres_tres);
void chanceGol343(Tres_quatro_tres tres_quatro_tres);

void chanceGol442(Quatro_quatro_dois quatro_quatro_dois)
{
    int jogadorEscolhido = rand() % 3; // Escolhe um índice aleatório entre 0 e 2

    float pesoAtacante = 1.0;
    float pesoMeioCampo = 0.8;
    float pesoZagueiro = 0.6;
    float chanceMarcaGol = 0.0;
    int golFeito = 0;

    int numJogadoresEscolhidos = 0;
    int jogadoresEscolhidos[11];

    for (int i = 0; i < 11; i++)
    {
        float pesoJogador = 0.0;

        if (strcmp(quatro_quatro_dois.atacantes[i].posicao, "A") == 0)
            pesoJogador = pesoAtacante;
        else if (strcmp(quatro_quatro_dois.meio_campo[i].posicao, "M") == 0)
            pesoJogador = pesoMeioCampo;
        else if (strcmp(quatro_quatro_dois.defensores[i].posicao, "Z") == 0)
            pesoJogador = pesoZagueiro;

        chanceMarcaGol = (quatro_quatro_dois.atacantes[i].tecnica * pesoJogador) +
                         (quatro_quatro_dois.meio_campo[i].tecnica * pesoMeioCampo) +
                         (quatro_quatro_dois.defensores[i].tecnica * pesoZagueiro) +
                         (quatro_quatro_dois.goleiro.tecnica * 0.1);

        if (i == jogadorEscolhido && golFeito == 0)
        {
            jogadoresEscolhidos[numJogadoresEscolhidos] = i;
            numJogadoresEscolhidos++;
        }
    }

    if (numJogadoresEscolhidos > 0 && golFeito == 0)
    {
        int jogadorGol = jogadoresEscolhidos[rand() % numJogadoresEscolhidos];

        if (strcmp(quatro_quatro_dois.meio_campo[jogadorGol].posicao, "M") == 0 ||
            strcmp(quatro_quatro_dois.defensores[jogadorGol].posicao, "Z") == 0
            || strcmp(quatro_quatro_dois.atacantes[jogadorGol].posicao, "A") == 0)

        {
            if (strcmp(quatro_quatro_dois.meio_campo[jogadorGol].posicao, "M") == 0)
                printf("%s (Meio-campista) fez o gol!\n", quatro_quatro_dois.meio_campo[jogadorGol].nome);
            if(strcmp(quatro_quatro_dois.defensores[jogadorGol].posicao, "Z") == 0)
                printf("%s (Defensor) fez o gol!\n", quatro_quatro_dois.defensores[jogadorGol].nome);
            if(strcmp(quatro_quatro_dois.atacantes[jogadorGol].posicao, "A") == 0)
                printf("%s (Atacante) fez o gol!\n", quatro_quatro_dois.atacantes[jogadorGol].nome);

            golFeito = 1;
        }
    }

    

   
}


void chanceGol433(Quatro_tres_tres quatro_tres_tres)
{
    int jogadorEscolhido = rand() % 3; // Escolhe um índice aleatório entre 0 e 2

    float pesoAtacante = 1.0;
    float pesoMeioCampo = 0.8;
    float pesoZagueiro = 0.6;
    float chanceMarcaGol = 0.0;
    int golFeito = 0;

    int numJogadoresEscolhidos = 0;
    int jogadoresEscolhidos[11];

    for (int i = 0; i < 11; i++)
    {
        float pesoJogador = 0.0;

        if (strcmp(quatro_tres_tres.atacantes[i].posicao, "A") == 0)
            pesoJogador = pesoAtacante;
        else if (strcmp(quatro_tres_tres.meio_campo[i].posicao, "M") == 0)
            pesoJogador = pesoMeioCampo;
        else if (strcmp(quatro_tres_tres.defensores[i].posicao, "Z") == 0)
            pesoJogador = pesoZagueiro;

        chanceMarcaGol = (quatro_tres_tres.atacantes[i].tecnica * pesoJogador) +
                         (quatro_tres_tres.meio_campo[i].tecnica * pesoMeioCampo) +
                         (quatro_tres_tres.defensores[i].tecnica * pesoZagueiro) +
                         (quatro_tres_tres.goleiro.tecnica * 0.1);

        if (i == jogadorEscolhido && golFeito == 0)
        {
            jogadoresEscolhidos[numJogadoresEscolhidos] = i;
            numJogadoresEscolhidos++;
        }
    }

    if (numJogadoresEscolhidos > 0 && golFeito == 0)
    {
        int jogadorGol = jogadoresEscolhidos[rand() % numJogadoresEscolhidos];

        if (strcmp(quatro_tres_tres.meio_campo[jogadorGol].posicao, "M") == 0 ||
            strcmp(quatro_tres_tres.defensores[jogadorGol].posicao, "Z") == 0
            || strcmp(quatro_tres_tres.atacantes[jogadorGol].posicao, "A") == 0)

        {
            if (strcmp(quatro_tres_tres.meio_campo[jogadorGol].posicao, "M") == 0)
                printf("%s (Meio-campista) fez o gol!\n", quatro_tres_tres.meio_campo[jogadorGol].nome);
            if(strcmp(quatro_tres_tres.defensores[jogadorGol].posicao, "Z") == 0)
                printf("%s (Defensor) fez o gol!\n", quatro_tres_tres.defensores[jogadorGol].nome);
            if(strcmp(quatro_tres_tres.atacantes[jogadorGol].posicao, "A") == 0)
                printf("%s (Atacante) fez o gol!\n", quatro_tres_tres.atacantes[jogadorGol].nome);

            golFeito = 1;
        }
    }

    

   
}
void chanceGol343(Tres_quatro_tres tres_quatro_tres)
{
    int jogadorEscolhido = rand() % 3; // Escolhe um índice aleatório entre 0 e 2

    float pesoAtacante = 1.0;
    float pesoMeioCampo = 0.8;
    float pesoZagueiro = 0.6;
    float chanceMarcaGol = 0.0;
    int golFeito = 0;

    int numJogadoresEscolhidos = 0;
    int jogadoresEscolhidos[11];

    for (int i = 0; i < 11; i++)
    {
        float pesoJogador = 0.0;

        if (strcmp(tres_quatro_tres.atacantes[i].posicao, "A") == 0)
            pesoJogador = pesoAtacante;
        else if (strcmp(tres_quatro_tres.meio_campo[i].posicao, "M") == 0)
            pesoJogador = pesoMeioCampo;
        else if (strcmp(tres_quatro_tres.defensores[i].posicao, "Z") == 0)
            pesoJogador = pesoZagueiro;

        chanceMarcaGol = (tres_quatro_tres.atacantes[i].tecnica * pesoJogador) +
                         (tres_quatro_tres.meio_campo[i].tecnica * pesoMeioCampo) +
                         (tres_quatro_tres.defensores[i].tecnica * pesoZagueiro) +
                         (tres_quatro_tres.goleiro.tecnica * 0.1);

        if (i == jogadorEscolhido && golFeito == 0)
        {
            jogadoresEscolhidos[numJogadoresEscolhidos] = i;
            numJogadoresEscolhidos++;
        }
    }

    if (numJogadoresEscolhidos > 0 && golFeito == 0)
    {
        int jogadorGol = jogadoresEscolhidos[rand() % numJogadoresEscolhidos];

        if (strcmp(tres_quatro_tres.meio_campo[jogadorGol].posicao, "M") == 0 ||
            strcmp(tres_quatro_tres.defensores[jogadorGol].posicao, "Z") == 0
            || strcmp(tres_quatro_tres.atacantes[jogadorGol].posicao, "A") == 0)

        {
            if (strcmp(tres_quatro_tres.meio_campo[jogadorGol].posicao, "M") == 0)
                printf("%s (Meio-campista) fez o gol!\n", tres_quatro_tres.meio_campo[jogadorGol].nome);
            if(strcmp(tres_quatro_tres.defensores[jogadorGol].posicao, "Z") == 0)
                printf("%s (Defensor) fez o gol!\n", tres_quatro_tres.defensores[jogadorGol].nome);
            if(strcmp(tres_quatro_tres.atacantes[jogadorGol].posicao, "A") == 0)
                printf("%s (Atacante) fez o gol!\n", tres_quatro_tres.atacantes[jogadorGol].nome);

            golFeito = 1;
        }
    }

    

   
}


int jogo2pt1(Time meuTime, Time timeAdversario)
{
    int i = 0;
    int golsTime3 = 0, golsTime4 = 0;

    float pesoZero = 0.7;
    float pesoUm = 0.8;
    float pesoDois = 0.8;
    float pesoTres = 0.7;
    float pesoQuatro = 0.4;
    float pesoCinco = 0.3;
    float pesoSeis = 0.2;
    float pesoSete = 0.1;
    float pesoOito = 0.1;

    srand((unsigned int)time(NULL));

    int numGolsTime3 = (int)(rand() % 7);
    float golsPonderadosTime3 = 0.0;
    switch (numGolsTime3)
    {
    case 0:
        golsPonderadosTime3 = pesoZero;
        break;
    case 1:
        golsPonderadosTime3 = pesoUm;
        break;
    case 2:
        golsPonderadosTime3 = pesoDois;
        break;
    case 3:
        golsPonderadosTime3 = pesoTres;
        break;
    case 4:
        golsPonderadosTime3 = pesoQuatro;
        break;
    case 5:
        golsPonderadosTime3 = pesoCinco;
        break;
    case 6:
        golsPonderadosTime3 = pesoSeis;
        break;
    }
    golsTime3 = (int)(golsPonderadosTime3 * 6);

    int numGolsTime4 = (int)(rand() % 7);
    float golsPonderadosTime4 = 0.0;
    switch (numGolsTime4)
    {
    case 0:
        golsPonderadosTime4 = pesoZero;
        break;
    case 1:
        golsPonderadosTime4 = pesoUm;
        break;
    case 2:
        golsPonderadosTime4 = pesoDois;
        break;
    case 3:
        golsPonderadosTime4 = pesoTres;
        break;
    case 4:
        golsPonderadosTime4 = pesoQuatro;
        break;
    case 5:
        golsPonderadosTime4 = pesoCinco;
        break;
    case 6:
        golsPonderadosTime4 = pesoSeis;
        break;
    }
    golsTime4 = (int)(golsPonderadosTime4 * 6);

    printf("Jogo 2");
    printf("Fim Primeiro Tempo: Time3 %d x %d Time 4 \n", golsTime3, golsTime4);

    return golsTime3, golsTime4;
}



void segundoTempo(Time time3, Time time4, int *golsTime3, int *golsTime4)
{
    float pesoZero = 0.7;
    float pesoUm = 0.8;
    float pesoDois = 0.8;
    float pesoTres = 0.7;
    float pesoQuatro = 0.4;
    float pesoCinco = 0.3;
    float pesoSeis = 0.2;

    srand((unsigned int)time(NULL));

    int numGolsTime3SegTempo = (int)(rand() % 7);
    float golsPonderadosTime3SegTempo = 0.0;
    switch (numGolsTime3SegTempo)
    {
    case 0:
        golsPonderadosTime3SegTempo = pesoZero;
        break;
    case 1:
        golsPonderadosTime3SegTempo = pesoUm;
        break;
    case 2:
        golsPonderadosTime3SegTempo = pesoDois;
        break;
    case 3:
        golsPonderadosTime3SegTempo = pesoTres;
        break;
    case 4:
        golsPonderadosTime3SegTempo = pesoQuatro;
        break;
    case 5:
        golsPonderadosTime3SegTempo = pesoCinco;
        break;
    case 6:
        golsPonderadosTime3SegTempo = pesoSeis;
        break;
    }
    int golsTime3SegTempo = (int)(golsPonderadosTime3SegTempo * 6);

    int numGolsTime4SegTempo = (int)(rand() % 7);
    float golsPonderadosTime4SegTempo = 0.0;
    switch (numGolsTime4SegTempo)
    {
    case 0:
        golsPonderadosTime4SegTempo = pesoZero;
        break;
    case 1:
        golsPonderadosTime4SegTempo = pesoUm;
        break;
    case 2:
        golsPonderadosTime4SegTempo = pesoDois;
        break;
    case 3:
        golsPonderadosTime4SegTempo = pesoTres;
        break;
    case 4:
        golsPonderadosTime4SegTempo = pesoQuatro;
        break;
    case 5:
        golsPonderadosTime4SegTempo = pesoCinco;
        break;
    case 6:
        golsPonderadosTime4SegTempo = pesoSeis;
        break;
    }
    int golsTime4SegTempo = (int)(golsPonderadosTime4SegTempo * 6);

    *golsTime3 += golsTime3SegTempo;
    *golsTime4 += golsTime4SegTempo;
    printf("Fim de jogo: Time3 %d x %d Time 4 \n", *golsTime3, *golsTime4);
}

int jogo(Time meuTime, Time time2)
{

    int golsMeuTime = 0, golstime2 = 0;
    srand((unsigned int)time(NULL));

    double probabilidadeMeuTime = meuTime.ataque / (6.0 * meuTime.ataque + time2.defesa);
    double probabilidadetime2 = time2.ataque / (6.0 * time2.ataque + meuTime.defesa);

    time_t start_time = time(NULL); // obtém o tempo de início do jogo

    time_t last_attempt_time = start_time; // obtém o tempo da última tentativa de gol
    printf("Inicio de jogo! Placar: Meu time %d x %d Time adversario\n", golsMeuTime, golstime2);
    while (difftime(time(NULL), start_time) < 90.0)
    { // loop de 90 minutos

        
        // Verifica se já passaram 5 segundos desde a última tentativa de gol
        if (difftime(time(NULL), last_attempt_time) >= 5.0)
        {
            last_attempt_time = time(NULL); // atualiza o tempo da última tentativa de gol

            // meu time ataca
            if ((double)rand() / RAND_MAX < probabilidadeMeuTime)
            {
                golsMeuTime++;

                printf("Meu time marcou um gol! Placar: Meu time %d x %d Time adversario\n", golsMeuTime, golstime2);
                if (quatro_quatro_dois.atacantes[0].nome != NULL && strlen(quatro_quatro_dois.atacantes[0].nome) > 0)
                {
                    chanceGol442(quatro_quatro_dois);
                }

                if (quatro_tres_tres.atacantes[0].nome != NULL && strlen(quatro_tres_tres.atacantes[0].nome) > 0)
                {
                    chanceGol433(quatro_tres_tres);
                }

                if (tres_quatro_tres.atacantes[0].nome != NULL && strlen(tres_quatro_tres.atacantes[0].nome) > 0)
                {
                    chanceGol343(tres_quatro_tres);
                }

                // time adversario ataca
                if ((double)rand() / RAND_MAX < probabilidadetime2)
                {
                    golstime2++;
                    printf("Time adversario marcou um gol! Placar: %s %d x %d Time adversario\n", meuTime.nome, golsMeuTime, golstime2);
                }
            }
        }
    }
    printf("Fim de tempo! Placar final: Meu time %d x %d Time adversario\n", golsMeuTime, golstime2);
    
    return golsMeuTime,golstime2;
}





MU_TEST(test_salvarArquivo)
{
    // Cria um arquivo temporário com dados fictícios
    FILE *arquivo = fopen("temp.txt", "wb");
    if (arquivo == NULL)
    {
        mu_fail("Erro ao criar arquivo temporário");
        return;
    }

    fprintf(arquivo, "Jogador1;A;4;5;3\n");
    fprintf(arquivo, "Jogador2;Z;3;4;5\n");
    fclose(arquivo);

    salvarArquivo("temp.txt", meuTime);

    // Testa se os jogadores foram lidos corretamente
    mu_assert_string_eq("Jogador1", meuTime.jogadores[0].nome);
    mu_assert_string_eq("A", meuTime.jogadores[0].posicao);
    mu_assert_int_eq(4, meuTime.jogadores[0].tatica);
    mu_assert_int_eq(5, meuTime.jogadores[0].tecnica);
    mu_assert_int_eq(3, meuTime.jogadores[0].fisico);

    mu_assert_string_eq("Jogador2", meuTime.jogadores[1].nome);
    mu_assert_string_eq("Z", meuTime.jogadores[1].posicao);
    mu_assert_int_eq(3, meuTime.jogadores[1].tatica);
    mu_assert_int_eq(4, meuTime.jogadores[1].tecnica);
    mu_assert_int_eq(5, meuTime.jogadores[1].fisico);

    // Remove o arquivo temporário
    remove("temp.txt");
}

MU_TEST(test_treinamento_tecnico)
{
    // Cria um arquivo temporário com dados fictícios

    leArquivo("jogadores.txt");

    // Chama diretamente a função treinamento com o tipo de treinamento
    treinar_tecnica(&meuTime);

    // Testa se os jogadores foram treinados corretamente

    mu_assert_int_eq(3, meuTime.jogadores[0].tecnica);

    mu_assert_int_eq(10, meuTime.jogadores[1].tecnica);
}
MU_TEST(test_treinamento_tatico)
{
    // Cria um arquivo temporário com dados fictícios

    leArquivo("jogadores.txt");

    // Chama diretamente a função treinamento com o tipo de treinamento
    treinar_tatica(&meuTime);

    // Testa se os jogadores foram treinados corretamente

    mu_assert_int_eq(3, meuTime.jogadores[0].tatica);

    mu_assert_int_eq(4, meuTime.jogadores[1].tatica);
}

MU_TEST(test_treinamento_fisico)
{
    // Cria um arquivo temporário com dados fictícios

    leArquivo("jogadores.txt");

    // Chama diretamente a função treinamento com o tipo de treinamento
    treinar_fisico(&meuTime);

    // Testa se os jogadores foram treinados corretamente

    mu_assert_int_eq(5, meuTime.jogadores[0].fisico);

    mu_assert_int_eq(5, meuTime.jogadores[1].fisico);
}

MU_TEST(test_escalacao_4_4_2)
{ // Cria um arquivo temporário com dados fictícios

    Time meuTime;

    leArquivo("jogadores.txt");
    int escolha = 1;
    // Chame a função de escalacao
    escalacao(meuTime, escolha);

    int numAtacantes = 0;
    int numZagueiros = 0;
    int numMeioCampo = 0;
    int numReservas = 0;
    for (int i = 0; i < 2; i++)
    {
        if (quatro_quatro_dois.atacantes->posicao[i] != 'A')
        {
            numAtacantes++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (quatro_quatro_dois.defensores->posicao[i] != 'Z')
        {
            numZagueiros++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (quatro_quatro_dois.meio_campo->posicao[i] != 'M')
        {
            numMeioCampo++;
        }
    }

    mu_assert_int_eq(2, numAtacantes);
    mu_assert_int_eq(4, numZagueiros);
    mu_assert_int_eq(4, numMeioCampo);
}

MU_TEST(test_escalacao_4_3_3)
{ // Cria um arquivo temporário com dados fictícios

    Time meuTime;

    leArquivo("jogadores.txt");
    int escolha = 2;
    // Chame a função de escalacao
    escalacao(meuTime, escolha);

    int numAtacantes = 0;
    int numZagueiros = 0;
    int numMeioCampo = 0;
    int numReservas = 0;
    for (int i = 0; i < 3; i++)
    {
        if (quatro_tres_tres.atacantes->posicao[i] != 'A')
        {
            numAtacantes++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (quatro_tres_tres.defensores->posicao[i] != 'Z')
        {
            numZagueiros++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (quatro_tres_tres.meio_campo->posicao[i] != 'M')
        {
            numMeioCampo++;
        }
    }

    mu_assert_int_eq(3, numAtacantes);
    mu_assert_int_eq(4, numZagueiros);
    mu_assert_int_eq(3, numMeioCampo);
}

MU_TEST(test_escalacao_3_4_3)
{ // Cria um arquivo temporário com dados fictícios

    Time meuTime;

    leArquivo("jogadores.txt");
    int escolha = 3;
    // Chame a função de escalacao
    escalacao(meuTime, escolha);

    int numAtacantes = 0;
    int numZagueiros = 0;
    int numMeioCampo = 0;
    int numReservas = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tres_quatro_tres.atacantes->posicao[i] != 'A')
        {
            numAtacantes++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (tres_quatro_tres.defensores->posicao[i] != 'Z')
        {
            numZagueiros++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (tres_quatro_tres.meio_campo->posicao[i] != 'M')
        {
            numMeioCampo++;
        }
    }

    mu_assert_int_eq(3, numAtacantes);
    mu_assert_int_eq(3, numZagueiros);
    mu_assert_int_eq(4, numMeioCampo);
}

MU_TEST(test_jogo){

   
    Time timeAdversario;
    leArquivo("jogadores.txt");
    int escolha = 1;
    escalacao(meuTime, escolha);
  int resultado = jogo(meuTime, time2);
    
    // Verifique se o resultado é válido
    mu_assert(resultado >= 0, "Erro: resultado inválido.");
}

MU_TEST(test_jogo2){

   
    Time time3 =  {"Jonmas", 120.0, 130.2, {} };
    Time time4 =  {"JUNZA", 120.0, 130.2, {} };
    leArquivo("jogadores.txt");
    int escolha = 1;
    
  int resultado = jogo2pt1(time3, time4);
    
    // Verifique se o resultado é válido
    mu_assert(resultado >= 0, "Erro: resultado inválido.");
}


MU_TEST(test_chanceGol442){
    
}





// Função que roda todos os testes
MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_leArquivo);
    MU_RUN_TEST(test_salvarArquivo);
    MU_RUN_TEST(test_treinamento_tecnico);
    MU_RUN_TEST(test_treinamento_fisico);
    MU_RUN_TEST(test_treinamento_tatico);
    MU_RUN_TEST(test_escalacao_4_4_2);
    MU_RUN_TEST(test_escalacao_4_3_3);
    MU_RUN_TEST(test_escalacao_3_4_3);
    MU_RUN_TEST(test_jogo2);
    MU_RUN_TEST(test_jogo);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}