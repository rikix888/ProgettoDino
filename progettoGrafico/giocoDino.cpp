#include "giocoDino.h"
#include <iostream>
#include <string>
using namespace std;

giocoDino::giocoDino(){
    dinoY = LIVELLO;
    isSalto = false;
    isCaduta = false;
    velocitaSalto = 20;
    timerOstacolo = 0;
    inizaOstacolo();
}

void giocoDino::musica()
{
    PlayMusic(76, CROMA);  // G6
    PlayMusic(76, CROMA);  // G6
    PlayMusic(0, CROMA);

    PlayMusic(76, CROMA);  //  G6
    PlayMusic(0, CROMA);

    PlayMusic(72, CROMA);  // E2
    PlayMusic(76, SEMIMINIMA);
    PlayMusic(79, SEMIMINIMA);
    PlayMusic(0, SEMIMINIMA);

    PlayMusic(67, SEMIMINIMA);
    PlayMusic(0, SEMIMINIMA);

    for (int i = 0; i < 2; i++)
    {
        PlayMusic(72, SEMIMINIMA);
        PlayMusic(0, CROMA);

        PlayMusic(67, SEMIMINIMA);
        PlayMusic(0, CROMA);

        PlayMusic(64, SEMIMINIMA);
        PlayMusic(0, CROMA);

        PlayMusic(69, SEMIMINIMA);
        PlayMusic(71, SEMIMINIMA);
        PlayMusic(70, CROMA);
        PlayMusic(69, SEMIMINIMA);

        PlayMusic(67, CROMA);
        PlayMusic(76, CROMA);
        PlayMusic(79, CROMA);
        PlayMusic(81, SEMIMINIMA);

        PlayMusic(77, CROMA);
        PlayMusic(79, CROMA);
        PlayMusic(0, CROMA);

        PlayMusic(76, SEMIMINIMA);
        PlayMusic(72, SEMICROMA);
        PlayMusic(74, SEMICROMA);
        PlayMusic(71, SEMIMINIMA);
        PlayMusic(0, CROMA);
    }

    for (int i = 0; i < 2; i++)
    {
        PlayMusic(79, CROMA);
        PlayMusic(78, CROMA);
        PlayMusic(77, CROMA);
        PlayMusic(75, SEMIMINIMA);
        PlayMusic(76, CROMA);
        PlayMusic(0, CROMA);

        PlayMusic(68, CROMA);
        PlayMusic(69, CROMA);
        PlayMusic(72, CROMA);
        PlayMusic(0, CROMA);

        PlayMusic(69, CROMA);
        PlayMusic(72, CROMA);
        PlayMusic(74, CROMA);
        PlayMusic(0, SEMIMINIMA);

        PlayMusic(79, CROMA);
        PlayMusic(78, CROMA);
        PlayMusic(77, CROMA);
        PlayMusic(75, SEMIMINIMA);
        PlayMusic(76, CROMA);
        PlayMusic(0, CROMA);


        PlayMusic(84, CROMA);
        PlayMusic(84, CROMA);
        PlayMusic(84, CROMA);
        PlayMusic(0, SEMIMINIMA);
        PlayMusic(0, SEMIMINIMA);

        PlayMusic(79, CROMA);
        PlayMusic(78, CROMA);
        PlayMusic(77, CROMA);
        PlayMusic(75, SEMIMINIMA);
        PlayMusic(76, CROMA);
        PlayMusic(0, CROMA);

        PlayMusic(68, CROMA);
        PlayMusic(69, CROMA);
        PlayMusic(72, CROMA);
        PlayMusic(0, CROMA);

        PlayMusic(69, CROMA);
        PlayMusic(72, CROMA);
        PlayMusic(74, CROMA);
        PlayMusic(0, SEMIMINIMA);

        PlayMusic(75, SEMIMINIMA);
        PlayMusic(0, CROMA);
        PlayMusic(74, SEMIMINIMA);
        PlayMusic(0, CROMA);
        PlayMusic(72, SEMIMINIMA);
        PlayMusic(0, SEMIMINIMA);
        PlayMusic(0, SEMIBREVE);


    }




    /*
60 do
61 di d
62 re
63 re d
64 mi
65 fa
66 fa d
67 sol
68 sol d
69 la
70 la d
71 si
72 do
*/
}

void giocoDino::musicaFine()
{
    PlayMusic(64, SEMIMINIMA);
    PlayMusic(0, CROMA);
    PlayMusic(60, SEMIMINIMA);
    PlayMusic(0, SEMIMINIMA);
    PlayMusic(55, SEMIMINIMA);

    PlayMusic(69, CROMA);
    PlayMusic(71, CROMA);
    PlayMusic(69, CROMA);

    PlayMusic(68, CROMA);
    PlayMusic(70, CROMA);
    PlayMusic(69, CROMA);

    PlayMusic(64, CROMA);
    PlayMusic(62, CROMA);
    PlayMusic(64, CROMA);




        /*
    60 do
    61 di d
    62 re
    63 re d
    64 mi
    65 fa
    66 fa d
    67 sol
    68 sol d
    69 la
    70 la d
    71 si
    72 do
    */
}

void giocoDino::inizaOstacolo() {
    for (int i = 0; i < MAX_OSTACOLI; ++i) {
        ostacoloX[i] = 0;
        ostacoloY[i] = 0;
        ostacoloPresente[i] = false;
    }
}

void giocoDino::creaOstacolo() {
    for (int i = 0; i < MAX_OSTACOLI; ++i) {
        if (!ostacoloPresente[i]) {
            ostacoloX[i] = ALTEZZA;
            ostacoloY[i] = LIVELLO;
            ostacoloPresente[i] = true;
            break;
        }
    }
}

void giocoDino::aggiornaDino() {
    if (isSalto) {
        dinoY -= velocitaSalto;
        if (dinoY <= LIVELLO - ALTEZZA_SALTO) {
            isSalto = false;
            isCaduta = true;
        }
    }
    else if (isCaduta) {
        dinoY += velocitaSalto;
        if (dinoY >= LIVELLO) {
            dinoY = LIVELLO;
            isCaduta = false;
        }
    }
}

void giocoDino::aggiornaOstacolo() {
    for (int i = 0; i < MAX_OSTACOLI; ++i) {
        if (ostacoloPresente[i]) {
            ostacoloX[i] -= VELOCITA_OSTACOLO;
            if (ostacoloX[i] < -OSTACOLO_ALTEZZA) {
                ostacoloPresente[i] = false;
            }
        }
    }
}

bool giocoDino::controlloTocco() {
    for (int i = 0; i < MAX_OSTACOLI; ++i) {
        if (ostacoloPresente[i]) {
            if (DINO_X + ALTEZZA_DINO > ostacoloX[i] && DINO_X < ostacoloX[i] + OSTACOLO_ALTEZZA &&
                dinoY + LARGHEZZA_DINO > ostacoloY[i] && dinoY < ostacoloY[i] + OSTACOLO_LARGHEZZA) {
                return true;
            }
        }
    }
    return false;
}

void giocoDino::disegnaTutto() {
    Clear(White);
    DrawRectangle(DINO_X, dinoY, ALTEZZA_DINO, LARGHEZZA_DINO, Black, Black);
    for (int i = 0; i < MAX_OSTACOLI; ++i) {
        if (ostacoloPresente[i]) {
            DrawRectangle(ostacoloX[i], ostacoloY[i], OSTACOLO_ALTEZZA, OSTACOLO_LARGHEZZA, Red, Red);
        }
    }
    Present();
}

void giocoDino::scritta()
{

        DrawString(580, 200, "THE END", "Castellar", 80, Black, true);
        Present();


}

void giocoDino::avvio() {
    UseDoubleBuffering(true);

    while (true) {

        musica();

        ClearInputBuffer();
        char key = LastKey();

        if (key == Keys::Esc) {
            CloseWindow();
        }
        else if (key == ' ' && dinoY == LIVELLO) {
            isSalto = true;
        }

        aggiornaDino();
        aggiornaOstacolo();

        if (++timerOstacolo >= INTERVALLO_OSTACOLI) {
            creaOstacolo();
            timerOstacolo = 0;
        } 
        if (controlloTocco())
        {
            scritta();

            ResetMusic(); 

            Wait(600);
            
            PlayMusic(76, SEMIMINIMA);
            PlayMusic(0, CROMA);
            PlayMusic(72, SEMIMINIMA);
            PlayMusic(0, SEMIMINIMA);
            PlayMusic(67, SEMIMINIMA);

            PlayMusic(69, SEMIMINIMA);
            PlayMusic(71, SEMIMINIMA);
            PlayMusic(69, SEMIMINIMA);

            PlayMusic(68, SEMIMINIMA);
            PlayMusic(70, CROMA);
            PlayMusic(69, CROMA);

            PlayMusic(64, CROMA);
            PlayMusic(62, CROMA);
            PlayMusic(64, SEMIMINIMA);
            PlayMusic(0, SEMIMINIMA);

            Wait(5000);

            CloseWindow();
        }
        disegnaTutto();

        Wait(30);

    }

}

