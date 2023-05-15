#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "soccer.h"
#include "equipe.h"
#include "escalacao.h"


Time meuTime; // cria um objeto Time
#define MAX_LINE_SIZE 100

Quatro_quatro_dois quatro_quatro_dois;
Quatro_tres_tres quatro_tres_tres;
Tres_quatro_tres tres_quatro_tres;
Time time3;
Time time4;
Time time2 = {"Joinville", 120.0, 130.2, {} };

void chanceGol442(Quatro_quatro_dois quatro_quatro_dois);
void  chanceGol433(Quatro_tres_tres quatro_tres_tres);
void  chanceGol343(Tres_quatro_tres tres_quatro_tres);



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
            if (strcmp(quatro_quatro_dois.meio_campo[jogadorGol].posicao, "M") == 0){ 
                printf("%s (Meio-campista) fez o gol!\n", quatro_quatro_dois.meio_campo[jogadorGol].nome);}
                else{
            if(strcmp(quatro_quatro_dois.defensores[jogadorGol].posicao, "Z") == 0){ 
                printf("%s (Defensor) fez o gol!\n", quatro_quatro_dois.defensores[jogadorGol].nome);}
                else{ 
            if(strcmp(quatro_quatro_dois.atacantes[jogadorGol].posicao, "A") == 0){ 
                printf("%s (Atacante) fez o gol!\n", quatro_quatro_dois.atacantes[jogadorGol].nome);}
                    }
                }
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


void jogo2pt1(Time meuTime, Time timeAdversario)
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

void jogo(Time meuTime, Time time2)
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
    
}



// fim escalacao



