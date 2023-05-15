#ifndef EQUIPE_UTIL_H
#define EQUIPE_UTIL_H


typedef struct jogador
{
    char nome[30];
    char posicao[3];
    int tatica;
    int tecnica;
    int fisico;
} Jogador;

typedef struct time
{
    char nome[30];
    float defesa;
    float ataque;
    Jogador jogadores[25];
} Time;

float calcular_medias(Jogador *jogadores, int num_jogadores, Time *meuTime);
void imprimir_time(Time meuTime);

#endif // !equipe.h