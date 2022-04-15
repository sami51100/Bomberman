#include <iostream>
#include <cstdlib>
#include "entete/Map.h"

using namespace std;

Map::Map(string nom)
{
    this->nom = nom;
}

void Map::creerMap()
{
    for (int i = 0; i < nbligne; i++)
    {
        for (int j = 0; j < nbcolonne; j++)
        {

            tab[i][j] = 0;
        }
    }
}

void Map::afficher()
{
    for (size_t i = 0; i < nbcolonne; i++)
    {
        cout << "----+";
    }
    cout << endl;

    for (int i = 0; i < nbligne; i++)
    {

        for (int j = 0; j < nbcolonne; j++)
        {
            if (convertir(i, j) == "I ")
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                cout << " " << char(178) << " ";

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << " |";
            }
            else if (convertir(i, j) == "W ")
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                cout << " " << char(177) << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << " |";
            }
            else if (tab[i][j] == 1 || tab[i][j] == 11)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << " "
                     << convertir(i, j);

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << " |";
            }
            else if (convertir(i, j) == "M " || convertir(i, j) == "F " || convertir(i, j) == "G ")
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << " "
                     << convertir(i, j);

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << " |";
            }
            else if (tab[i][j] == 7 || tab[i][j] == 12 || convertir(i, j) == "0 " || convertir(i, j) == "8 " || convertir(i, j) == "! ")
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << " "
                     << convertir(i, j);

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << " |";
            }
            else if (tab[i][j] == bomb1.getBomb() || tab[i][j] == bomb1.getExplosionH() || tab[i][j] == bomb1.getExplosionV())
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << " "
                     << convertir(i, j);

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << " |";
            }

            else
                cout << " " << convertir(i, j) << " |";
        }
        cout << endl;
    }
    for (size_t i = 0; i < nbcolonne; i++)
    {
        cout << "----+";
    }
    cout << endl;
}

void Map::remplirMur(Tile w)
{
    for (int i = 0; i < nbligne; i += 5)
    {
        for (int j = 0; j < nbcolonne; j += 3)
        {

            tab[i][j] = w.getValeur();
            tab[i][j + 1] = w.getValeur();
        }
    }
}

void Map::remplirSable(Tile w)
{
    for (int i = 0; i < nbligne; i += 2)
    {
        for (int j = 0; j < nbcolonne; j += 3)
        {
            tab[i][j] = w.getValeur();
        }
    }
}

void Map::remplirItem(Item &k)
{
    tab[k.getX()][k.getY()] = k.getValeur();
}

void Map::remplirPlayer(Bomberman &b)
{
    tab[b.getX()][b.getY()] = b.getValeur();
}

void Map::remplirMonstre(Ennemi &b)
{
    tab[b.getX()][b.getY()] = b.getValeur();
}

void Map::mouvementPlayer(Bomberman &b, Bomb &bomb, Item &k1, Item &k2, Item &k3, Item &k4, Item &k5)
{
    int i = 0;
    char touche;
    cout << endl
         << "\t\t   w \n"
         << "touche :\ta  s  d \n\t\tposer une bombe : b\n\t\tse suicider : k\n";
    cin >> touche;

    // mouvement de player
    switch (touche)
    {
    case 'a':
        // deplacement gauche
        if (b.getY() > 0)
        {
            // si la case n'est pas occupé ou occupé par un item
            if (tab[b.getX()][b.getY() - 1] == 0 || tab[b.getX()][b.getY() - 1] == k1.getValeur() || tab[b.getX()][b.getY() - 1] == k2.getValeur() || tab[b.getX()][b.getY() - 1] == k3.getValeur() || tab[b.getX()][b.getY() - 1] == k4.getValeur() || tab[b.getX()][b.getY() - 1] == k5.getValeur())
            {
                // effet de l'item
                effetItem(b, bomb, k1, k2, k3, k4, k5, b.getX(), b.getY() - 1);

                // ajoute une bombe a la case si le joueur en a posé une
                if (tab[b.getX()][b.getY()] == bomb.getVarb())
                {
                    tab[b.getX()][b.getY()] = bomb.getBomb();
                }
                else
                {
                    tab[b.getX()][b.getY()] = 0;
                }

                b.setY(b.getY() - 1);
                tab[b.getX()][b.getY()] = b.getValeur();
            }
        }

        break;
    case 'd':
        // deplacement droite
        // si la case n'est pas en dehors du tableau
        if (b.getY() < nbcolonne - 1)
        {
            // si la case n'est pas occupé ou occupé par un item
            if (tab[b.getX()][b.getY() + 1] == 0 || tab[b.getX()][b.getY() + 1] == k1.getValeur() || tab[b.getX()][b.getY() + 1] == k2.getValeur() || tab[b.getX()][b.getY() + 1] == k3.getValeur() || tab[b.getX()][b.getY() + 1] == k4.getValeur() || tab[b.getX()][b.getY() + 1] == k5.getValeur())
            {
                // effet de l'item
                effetItem(b, bomb, k1, k2, k3, k4, k5, b.getX(), b.getY() + 1);

                // ajoute une bombe a la case si le joueur en a posé une
                if (tab[b.getX()][b.getY()] == bomb.getVarb())
                {
                    tab[b.getX()][b.getY()] = bomb.getBomb();
                }
                else
                {
                    tab[b.getX()][b.getY()] = 0;
                }
                b.setY(b.getY() + 1);
                tab[b.getX()][b.getY()] = b.getValeur();
            }
        }

        break;
    case 'w':
        // deplacement haut
        if (b.getX() > 0)
        {
            if (tab[b.getX() - 1][b.getY()] == 0 || tab[b.getX() - 1][b.getY()] == k1.getValeur() || tab[b.getX() - 1][b.getY()] == k2.getValeur() || tab[b.getX() - 1][b.getY()] == k3.getValeur() || tab[b.getX() - 1][b.getY()] == k4.getValeur() || tab[b.getX() - 1][b.getY()] == k5.getValeur())
            {
                // effet de l'item
                effetItem(b, bomb, k1, k2, k3, k4, k5, b.getX() - 1, b.getY());

                // ajoute une bombe a la case si le joueur en a posé une
                if (tab[b.getX()][b.getY()] == bomb.getVarb())
                {
                    tab[b.getX()][b.getY()] = bomb.getBomb();
                }
                else
                {
                    tab[b.getX()][b.getY()] = 0;
                }
                b.setX(b.getX() - 1);
                tab[b.getX()][b.getY()] = b.getValeur();
            }
        }

        break;
    case 's':
        // deplacement bas
        if (b.getX() < nbligne - 1)
        {
            if (tab[b.getX() + 1][b.getY()] == 0 || tab[b.getX() + 1][b.getY()] == k1.getValeur() || tab[b.getX() + 1][b.getY()] == k2.getValeur() || tab[b.getX() + 1][b.getY()] == k3.getValeur() || tab[b.getX() + 1][b.getY()] == k4.getValeur() || tab[b.getX() + 1][b.getY()] == k5.getValeur())
            {
                // effet de l'item
                effetItem(b, bomb, k1, k2, k3, k4, k5, b.getX() + 1, b.getY());

                // ajoute une bombe a la case si le joueur en a posé une
                if (tab[b.getX()][b.getY()] == bomb.getVarb())
                {
                    tab[b.getX()][b.getY()] = bomb.getBomb();
                }
                else
                {
                    tab[b.getX()][b.getY()] = 0;
                }
                b.setX(b.getX() + 1);
                tab[b.getX()][b.getY()] = b.getValeur();
            }
        }

        break;
    case 'b':

        if (b.getNbBomb() > 0)
        {
            /* parcour le tableau de bombe*/
            while (b.tabB[i].poser == true && i < b.tabB.size())
            {
                i++;
            }
            if (b.tabB[i].poser == false)
            {
                b.tabB[i].BombePosee();
                tab[b.getX()][b.getY()] = bomb.getVarb();
                b.setNbBomb(b.getNbBomb() - 1);
                b.tabB[i].setTmpi(b.getX());
                b.tabB[i].setTmpj(b.getY());
            }
        }

        break;
        // pour tuer le personnage
    case 'k':
        b.setVie(b.getVie() - 50);

        break;
        // pour arreter le programme
    case '0':
        exit(0);
    }

    explosionBombe(b, bomb);
}

void Map::tuerMonstre()
{
    for (size_t j = 0; j < tabM.size(); j++)
    {
        if (tabM[j]->getNbvie() <= 0)
        {
            tabM[j]->Vivant = false;
            if (tab[tabM[j]->getX()][tabM[j]->getY()] != player1.getValeur())
            {
                // tab[tabM[j].getX()][tabM[j].getY()] = 0;
            }
        }
    }
}
void Map::explosionBombe(Bomberman &b, Bomb &bomb)
{
    int i = 0;
    // parcours le tableau de bombe
    while (b.tabB[i].poser == true && i < b.tabB.size())
    {

        // met a vide l'emplacement ou la bombe a explosé
        if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj()] == bomb.getBomb())
        {
            // augmente le compteur de la bombe a chaque tour
            b.tabB[i].setCompteur(b.tabB[i].getCompteur() + 1);

            if (b.tabB[i].getCompteur() == 3)
            {                                                                // verifie si l'explosion touche le joueur et ne detruit pas les mur indestructible
                for (int porte = 1; porte <= b.tabB[i].getPortee(); porte++) // pour faire en sorte d'exploser une case de plus lorsque la porte augmente
                {
                    if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() - porte] != wall.getValeur())
                    {
                        // parcours le tableau de monstre
                        for (size_t j = 0; j < tabM.size(); j++)
                        {
                            if (b.tabB[i].getTmpi() == tabM[j]->getX() && b.tabB[i].getTmpj() - porte == tabM[j]->getY())
                            {
                                tabM[j]->setNbvie(tabM[j]->getNbvie() - bomb.getDegat());
                            }
                        }
                        // si l'explosion touche le player on retire la vie du player
                        if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() - porte] == tab[b.getX()][b.getY()])
                        {
                            b.setVie(b.getVie() - b.tabB[i].getDegat());
                        }
                        else
                            tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() - porte] = bomb.getExplosionH();
                    }
                    if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() + porte] != wall.getValeur())
                    {
                        for (size_t j = 0; j < tabM.size(); j++)
                        {
                            if (b.tabB[i].getTmpi() == tabM[j]->getX() && (b.tabB[i].getTmpj() + porte) == tabM[j]->getY())
                            {
                                tabM[j]->setNbvie(tabM[j]->getNbvie() - bomb.getDegat());
                            }
                        }
                        if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() + porte] == tab[b.getX()][b.getY()])
                        {
                            b.setVie(b.getVie() - b.tabB[i].getDegat());
                        }
                        else
                            tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() + porte] = bomb.getExplosionH();
                    }
                    if (tab[b.tabB[i].getTmpi() - porte][b.tabB[i].getTmpj()] != wall.getValeur())
                    {
                        for (size_t j = 0; j < tabM.size(); j++)
                        {
                            if (b.tabB[i].getTmpi() - porte == tabM[j]->getX() && b.tabB[i].getTmpj() == tabM[j]->getY())
                            {
                                tabM[j]->setNbvie(tabM[j]->getNbvie() - bomb.getDegat());
                            }
                        }
                        if (tab[b.tabB[i].getTmpi() - porte][b.tabB[i].getTmpj()] == tab[b.getX()][b.getY()])
                        {
                            b.setVie(b.getVie() - b.tabB[i].getDegat());
                        }
                        else
                            tab[b.tabB[i].getTmpi() - porte][b.tabB[i].getTmpj()] = bomb.getExplosionV();
                    }
                    if (tab[b.tabB[i].getTmpi() + porte][b.tabB[i].getTmpj()] != wall.getValeur())
                    {
                        for (size_t j = 0; j < tabM.size(); j++)
                        {
                            if (b.tabB[i].getTmpi() + porte == tabM[j]->getX() && b.tabB[i].getTmpj() == tabM[j]->getY())
                            {
                                tabM[j]->setNbvie(tabM[j]->getNbvie() - bomb.getDegat());
                            }
                        }
                        if (tab[b.tabB[i].getTmpi() + porte][b.tabB[i].getTmpj()] == tab[b.getX()][b.getY()])
                        {
                            b.setVie(b.getVie() - b.tabB[i].getDegat());
                        }
                        else
                            tab[b.tabB[i].getTmpi() + porte][b.tabB[i].getTmpj()] = bomb.getExplosionV();
                    }
                }
            }
            else if (b.tabB[i].getCompteur() == 5)
            {
                for (int porte = 1; porte <= b.tabB[i].getPortee(); porte++)
                {
                    if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj()] != b.getValeur())
                    {
                        tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj()] = 0;
                    }
                    if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() - porte] != wall.getValeur() && tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() - porte] != b.getValeur())
                    {
                        tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() - porte] = 0;
                    }
                    if (tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() + porte] != wall.getValeur() && tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() + porte] != b.getValeur())
                    {
                        tab[b.tabB[i].getTmpi()][b.tabB[i].getTmpj() + porte] = 0;
                    }
                    if (tab[b.tabB[i].getTmpi() - porte][b.tabB[i].getTmpj()] != wall.getValeur() && tab[b.tabB[i].getTmpi() - porte][b.tabB[i].getTmpj()] != b.getValeur())
                    {
                        tab[b.tabB[i].getTmpi() - porte][b.tabB[i].getTmpj()] = 0;
                    }
                    if (tab[b.tabB[i].getTmpi() + porte][b.tabB[i].getTmpj()] != wall.getValeur() && tab[b.tabB[i].getTmpi() + porte][b.tabB[i].getTmpj()] != b.getValeur())
                    {
                        tab[b.tabB[i].getTmpi() + porte][b.tabB[i].getTmpj()] = 0;
                    }
                }
            }
        }
        i++;
    }
}

// convertis les int en string pour l'affichage
string Map::convertir(int i, int j)
{

    std::stringstream ss;
    ss << char(3) << " ";
    std::string coeur = ss.str();

    std::stringstream sp;
    sp << char(175) << " ";
    std::string speed = sp.str();

    std::stringstream jo;
    jo << char(2) << " ";
    std::string joueur = jo.str();

    std::stringstream jb;
    jb << char(2) << "!";
    std::string joueurb = jb.str();

    std::stringstream ev;
    ev << char(186) << " ";
    std::string explosionVertical = ev.str();

    std::stringstream eh;
    eh << char(205) << char(205);
    std::string explosionHorizontal = eh.str();

    if (tab[i][j] == 0)
    { // affichage herbe
        return "_ ";
    }
    else if (tab[i][j] == player1.getValeur())
    { // affichage du player
        return joueur;
    }
    else if (tab[i][j] == wall.getValeur())
    { // affichage d'un mur invincible
        return "I ";
    }
    else if (tab[i][j] == sand.getValeur())
    { // affichage d'un mur destructible
        return "W ";
    }
    else if (tab[i][j] == ghos.getValeur())
    { // affichage d'un ghost:4
        return "G ";
    }
    else if (tab[i][j] == bowm.getValeur())
    { // affichage d'un bowman:5
        return "F ";
    }
    else if (tab[i][j] == mons.getValeur())
    { // affichage d'un monstre:6
        return "M ";
    }
    else if (tab[i][j] == morL.getValeur())
    { // affichage morelife
        return coeur;
    }
    else if (tab[i][j] == morB.getValeur())
    { // affichage morebomb : 0
        return "0 ";
    }
    else if (tab[i][j] == power.getValeur())
    { // affichage powerup : 8
        return "8 ";
    }
    else if (tab[i][j] == scal.getValeur())
    { // affichage scaleup : !
        return "! ";
    }
    else if (tab[i][j] == spee.getValeur())
    { // affichage speedup : =
        return speed;
    }
    else if (tab[i][j] == bomb1.getVarb())
    { // affichage player qui pose une bombe : P!
        return joueurb;
    }
    else if (tab[i][j] == bomb1.getBomb())
    { // affichage d'une bombe : @
        return "@ ";
    }
    else if (tab[i][j] == bomb1.getExplosionH())
    { // affichage de l'explosion horizontale : --
        return explosionHorizontal;
    }
    else if (tab[i][j] == bomb1.getExplosionV())
    { // affichage de l'explosion verticale : |
        return explosionVertical;
    }
    else
    {
        return "R";
    }
}

// gerer les mouvements aleatoire des monstres
void Map::mouvementMonstre(Ennemi &b, Bomberman &bo)
{
    if (b.Vivant == true)
    {
        int aleatoire;
        if (bo.getX() < b.getX())
        {
            aleatoire = 2; // vers le haut
        }
        else if (bo.getX() > b.getX())
        {
            aleatoire = 3;
        }
        else
        {
            if (bo.getY() < b.getY())
            {
                aleatoire = 0;
            }
            else if (bo.getY() > b.getY())
            {
                aleatoire = 1;
            }
        } // mouvement du monstre aleatoire
        if (b.getValeur() != ghos.getValeur())
        {
            if (tab[b.getX()][b.getY() + 1] == 2 || tab[b.getX() + 1][b.getY()] == 2 || tab[b.getX()][b.getY() - 1] == 2 || tab[b.getX() - 1][b.getY()] == 2 || tab[b.getX()][b.getY() + 1] == 3 || tab[b.getX() + 1][b.getY()] == 3 || tab[b.getX()][b.getY() - 1] == 3 || tab[b.getX() - 1][b.getY()] == 3)
            {
                aleatoire = rand() % 4;
            }
        }
        int tmp;
        switch (aleatoire)
        {
        case 0:
            // deplacement gauche
            if (b.getY() > 0) // debordement de la map
            {
                effetMonstre(b, bo, 0, -1, 0);
            }

            break;
        case 1:
            // deplacement droite
            if (b.getY() < nbcolonne - 1)
            {
                effetMonstre(b, bo, 0, 1, 1);
            }

            break;
        case 2:
            // deplacement haut
            if (b.getX() > 0)
            {
                effetMonstre(b, bo, -1, 0, 2);
            }
            break;
        case 3:
            // deplacement bas
            if (b.getX() < nbligne - 1)
            {
                effetMonstre(b, bo, 1, 0, 3);
            }
            break;
        }
    }
}

void Map::effetMonstre(Ennemi &b, Bomberman &bo, int DI, int DJ, int deplacement)
{
    // si le monstre n'est pas un ghost
    if (b.getValeur() != ghos.getValeur())
    {
        if (tab[b.getX() + DI][b.getY() + DJ] == 0)
        {
            tab[b.getX()][b.getY()] = 0;
            if (deplacement == 0)
            {
                b.setY(b.getY() - 1);
            }
            else if (deplacement == 1)
            {
                b.setY(b.getY() + 1);
            }
            else if (deplacement == 2)
            {
                b.setX(b.getX() - 1);
            }
            else if (deplacement == 3)
            {
                b.setX(b.getX() + 1);
            }

            tab[b.getX()][b.getY()] = b.getValeur();
        } // si la case est un player ou un player qui pose une bombe
        else if (tab[b.getX() + DI][b.getY() + DJ] == bo.getValeur() || tab[b.getX() + DI][b.getY() + DJ] == bo.boom.getVarb())
        {
            b.attaquerPlayer(bo);
        }
    }
    else if (b.getValeur() == ghos.getValeur()) // si c'est un ghost
    {
        if (tab[b.getX() + DI][b.getY() + DJ] != bo.getValeur() && tab[b.getX() + DI][b.getY() + DJ] != bo.boom.getVarb() && tab[b.getX() + DI][b.getY() + DJ] != bo.boom.getBomb() && tab[b.getX() + DI][b.getY() + DJ] != mons.getValeur() && tab[b.getX() + DI][b.getY() + DJ] != bowm.getValeur() && tab[b.getX() + DI][b.getY() + DJ] != bo.boom.getExplosionH() && tab[b.getX() + DI][b.getY() + DJ] != bo.boom.getExplosionV() && tab[b.getX() + DI][b.getY() + DJ] != ghos.getValeur())
        {
            tab[b.getX()][b.getY()] = b.tmp;
            b.tmp = tab[b.getX() + DI][b.getY() + DJ];

            if (deplacement == 0)
            {
                b.setY(b.getY() - 1);
            }
            else if (deplacement == 1)
            {
                b.setY(b.getY() + 1);
            }
            else if (deplacement == 2)
            {
                b.setX(b.getX() - 1);
            }
            else if (deplacement == 3)
            {
                b.setX(b.getX() + 1);
            }
            tab[b.getX()][b.getY()] = b.getValeur();
        }
        else if (tab[b.getX() + DI][b.getY() + DJ] == bo.getValeur() || tab[b.getX() + DI][b.getY() + DJ] == bo.boom.getVarb())
        {
            b.attaquerPlayer(bo);
        }
    }
}
void Map::effetItem(Bomberman &b, Bomb &bomb, Item &k1, Item &k2, Item &k3, Item &k4, Item &k5, int i, int j)
{

    // si la case est un item on appel la methode de l'effet de l'item
    if (tab[i][j] == k1.getValeur())
    {
        k1.effetBomb(bomb);
        k1.effetPlayer(b);
    }
    else if (tab[i][j] == k2.getValeur())
    {
        k2.effetBomb(bomb);
        k2.effetPlayer(b);
    }
    else if (tab[i][j] == k3.getValeur())
    {
        k3.effetBomb(bomb);
        k3.effetPlayer(b);
    }
    else if (tab[i][j] == k4.getValeur())
    {
        for (size_t i = 0; i < b.tabB.size(); i++)
        {
            k4.effetBomb(b.tabB[i]);
        }

        k4.effetPlayer(b);
    }
    else if (tab[i][j] == k5.getValeur())
    {
        k5.effetBomb(bomb);
        k5.effetPlayer(b);
    }
}

bool Map::victoire()
{
    int cmp = 0;

    for (size_t j = 0; j < tabM.size(); j++)
    {
        if (tabM[j]->Vivant == false)
        {
            cmp++;
        }
    }
    if (cmp == tabM.size())
    {
        return true;
    }
    else
        return false;
}