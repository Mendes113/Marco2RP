#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalacao.h"
#include "equipe.h"

Quatro_quatro_dois quatro_quatro_dois;
Quatro_tres_tres quatro_tres_tres;
Tres_quatro_tres tres_quatro_tres;

void escalacao(Time meuTime)
{
    printf("Escalações disponíveis: \n");
    printf("1 - 4-4-2 \n");
    printf("2 - 4-3-3 \n");
    printf("3 - 3-4-3 \n");
    printf("Escolha a escalação do seu time: \n");
    int escolha = 0;
    scanf("%d", &escolha);
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