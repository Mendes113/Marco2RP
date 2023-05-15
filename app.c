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


int main()
{
    Time timeAdversario = {"Time Adversario", 13.90, 13.20, {}};
    Time time3 = {"Time Adversario", 13.90, 13.20, {}};
    Time time4 = {"Time Adversario", 13.90, 13.20, {}};
    leArquivo("jogadores.txt");
    calcular_medias(meuTime.jogadores, 24, &meuTime);
    escalacao(meuTime);
    jogo(meuTime, timeAdversario);

   
    
    return 0;
}