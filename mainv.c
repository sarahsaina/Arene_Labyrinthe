#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void perso()
{
    int a,b;
    char joueur=168;
}

void affichage(int taille,int** map) //affiche l'ar�ne
{
    int i,j;
    printf(" ");
    for (i=1;i<taille+2;i++)
    {
        Color(13,0);
        printf("~~");
    }
    printf("\n");
    for (j=taille-1;j>=0;j--)
    {
        if (j == 0)
        {
            Color(10,0);
            printf("->");
        }else
        {
            Color(13,0);
            printf(" |");
        }
        for (i = 0; i < taille; i++)
        {
            if (map[i][j] == 0)
            {
                Color(0,2);
                printf("  ");
            }else
            {
                Color(0,1);
                printf("  ");
            }
        }
        if (j == taille-1)
        {
            Color(10,0);
            printf("->");
        }else
        {
            Color(13,0);
            printf("| ");
        }
        printf("\n");
    }
    printf(" ");
    for (i=1;i<taille+2;i++)
    {
        Color(13,0);
        printf("~~");
    }
    printf("\n");
    Color(15,0);
}

void creation(int taille,int** map) //cr�e l'ar�ne
{
    int i, j;
    for (i=0;i<taille;i++)
    {
        for (j=0;j<taille;j++)
        {
            if (rand() / (RAND_MAX+1.0) < 0.2) //Un mur a une probabilit� de 0.3 d'appara�tre sur une case
            {
                map[i][j] = 1;//il y aura un mur
            }else
            {
                map[i][j] = 0;//il n'y a pas de mur
            }
        }
    }
}

void ia(int taille, int** map)
{
  int i,j;
   Color(0,15);
   printf(" "); //affichage de la case ia
   if (map[i+1][j]=1 && map [i][j+1]=1 && map[i][j-1]) //si il y a un mur en haut et � droite et � gauche, l'ia descend
   {
        map[i][j]=map[i-1][j];
   }
   else if (map[i-1][j]=1 && map [i][j+1]=1 && map[i][j-1]) //si il y a un mur en bas et � droite et � gauche, l'ia monte
    {
        map[i][j]=map[i+1][j];
    }
    else if (map[i-1][j]=1 && map [i][j+1]=1 && map[i][j-1]) //si il y a un mur en bas et en haut et � gauche, l'ia va � droite
    {
        map[i][j]=map[i][j+1];
    }
    else if (map[i-1][j]=1 && map [i][j+1]=1 && map[i][j-1]) //si il y a un mur en bas et en haut et � droite, l'ia va � gauche
    {
        map[i][j]=map[i][j-1];
    }
    else{
        rand()
    }
}

int main()
{
    int taille=39;//taille du labyrinthe (il est carr�)
    int entree_x = 0;
    int entree_y = 0;
    int sortie_x = taille-1;
    int sortie_y = taille-1;
    int** map=NULL;
    int i;
    system("cls");
    map=malloc(taille*sizeof(int*));
    for(i=0;i<taille;i++)
    {
        map[i]=malloc(taille*sizeof(int));
    }
    srand(time(NULL));
    creation(taille,map);
    map[entree_x][entree_y] = 0;
    map[sortie_x][sortie_y] = 0;
    affichage(taille,map);
    ia(taille,map);

    for(i=0;i<taille;i++)
    {
        free(map[i]);
    }
    free(map);
    return 0;
}

