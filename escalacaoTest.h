#ifndef ESCALACAO_H
#include "equipe.h"

typedef struct quatro_quatro_dois {
   Jogador defensores[4];
   Jogador meio_campo[4];
   Jogador  atacantes[2];
   Jogador goleiro;
   Jogador reserva[12];
} Quatro_quatro_dois;

typedef struct quatro_tres_tres {
   Jogador defensores[4];
   Jogador meio_campo[3];
   Jogador atacantes[3];
   Jogador reserva[12];
   Jogador goleiro;
} Quatro_tres_tres;

typedef struct tres_quatro_tres {
   Jogador defensores[3];
   Jogador meio_campo[4];
   Jogador atacantes[3];
   Jogador goleiro;
   Jogador reserva[12];
} Tres_quatro_tres;

void escalacao(Time meuTime, int escolha);


#define ESCALACAO_H

#endif // !escalacao.h