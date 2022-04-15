#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <windows.h>

#include "Map/entete/Map.h"

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size)
{
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

int main()
{
    char choix;
    srand((unsigned int)time(0));
    Map w("Bomberman");
    Bomb boom;

    int chiffre;
    int chiffre1 = 0;
    do
    {
        system("cls");
        gotoxy(20, 5);
        cout << " -------------------------- ";
        gotoxy(20, 6);
        cout << " |        " << w.nom << "        | ";
        gotoxy(20, 7);
        cout << " --------------------------";
        gotoxy(10, 9);
        cout << "1. Start Game";
        gotoxy(10, 10);
        cout << "2. Instructions";
        gotoxy(10, 11);
        cout << "3. Quit";
        gotoxy(10, 13);
        cout << "Select option: ";
        cin >> chiffre;

        if (chiffre == 1)
        {
            do
            {

                int X = rand() % w.nbligne;
                int Y = rand() % w.nbcolonne;
                SpeedUp spe(X, Y);
                X = rand() % w.nbligne;
                Y = rand() % w.nbcolonne;
                MoreBomb mbo(X, Y);
                X = rand() % w.nbligne;
                Y = rand() % w.nbcolonne;
                ScaleUp sca(X, Y);
                X = rand() % w.nbligne;
                Y = rand() % w.nbcolonne;
                PowerUp pow(X, Y);
                MoreLife mor;

                Monster mon1(7, 7);
                w.tabM.push_back(&mon1);

                Ghost gho1(11, 11);
                w.tabM.push_back(&gho1);

                Bowman bow1(10, 10);
                w.tabM.push_back(&bow1);

                Bomberman b;

                Wall wal;
                Sand san;

                w.creerMap();
                w.remplirMur(wal);
                w.remplirSable(san);

                w.remplirItem(mor);
                w.remplirItem(spe);
                w.remplirItem(mbo);
                w.remplirItem(sca);
                w.remplirItem(pow);

                for (size_t i = 0; i < w.tabM.size(); i++)
                {
                    w.remplirMonstre(*w.tabM[i]);
                }
                w.remplirPlayer(b);

                do
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    system("cls");
                    gotoxy(0, 0);
                    cout << b;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    w.tuerMonstre();
                    w.afficher();

                    w.mouvementPlayer(b, boom, mor, spe, mbo, sca, pow);
                    for (size_t i = 0; i < w.tabM.size(); i++)
                    {
                        w.mouvementMonstre(*w.tabM[i], b);
                    }

                } while (b.getVie() > 0 && w.victoire() == false);

                if (w.victoire() == true)
                {
                    system("cls");
                    gotoxy(20, 5);
                    cout << " -------------------------- ";
                    gotoxy(20, 6);
                    cout << " |        "
                         << "VICTOIRE !!!"
                         << "    | ";
                    gotoxy(20, 7);
                    cout << " --------------------------";
                }
                else
                {
                    system("cls");
                    gotoxy(20, 5);
                    cout << " -------------------------- ";
                    gotoxy(20, 6);
                    cout << " |        "
                         << "GAME OVER !!!"
                         << "   | ";
                    gotoxy(20, 7);
                    cout << " --------------------------";
                }
                w.tabM.clear();
                cout << "\nVoulez vous rejouer ? [y][n]\n";
                cin >> choix;
            } while (choix == 'y');
            break;
        }
        else if (chiffre == 2)

            do
            {
                system("cls");
                gotoxy(20, 5);
                cout << char(2) << " ------> Bomberman";
                gotoxy(20, 6);
                cout << "@ ------> Bomb";
                gotoxy(20, 7);
                cout << "F ------> Bowman";
                gotoxy(20, 8);
                cout << "M ------> Monster";
                gotoxy(20, 9);
                cout << "G ------> Ghost";

                gotoxy(10, 11);
                cout << "3. return\n";
                cin >> chiffre1;

            } while (chiffre1 != 3);

        system("cls");

    } while (chiffre != 3);

    return 0;
}