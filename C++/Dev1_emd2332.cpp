
#include "pch.h"
#include<fstream>
#include <iostream>
#include<string>
//#include<time.h>
using namespace std;

const short  uneGrilleDimension = 9;
typedef short uneGrille[uneGrilleDimension][uneGrilleDimension];
const short bloc_A_Debut = 0;
const short bloc_A_Fin = 2;
const short bloc_B_Debut = 3;
const short bloc_B_Fin = 5;
const short bloc_C_Debut = 6;
const short bloc_C_Fin = 8;


bool sont_rangees_OK(uneGrille grille)
{
	bool VERIFICATION = true;

	// Tâche : Vérifications des rangées
	for (int rangee = 0; rangee < uneGrilleDimension; rangee++)
	{
		// Mettre les compteurs à zéro avant de vérifier UNE rangée.
		int frequence[uneGrilleDimension] = { 0 };

		// Pour la rangée, nous allons compter la fréquence des chiffres 1 à 9. 
			// Le chiffre #K est associé au compteur #(K-1) d'où (grille[rangee][colonne]) - 1.
		for (int colonne = 0; colonne < uneGrilleDimension; colonne++)
			++frequence[(grille[rangee][colonne]) - 1];

		// vérifier que chaque chiffre n'apparaît qu'exactement une seule fois (ni plus, ni moins)
		// dans une rangée.
		for (int K = 0; K < uneGrilleDimension; K++)
			if (frequence[K] != 1)
			{
				VERIFICATION = false;
				cout << "La rangee " << rangee << " est fautive." << endl;
				break; // Une erreur dans la rangée suffit pour dire que la rangée est fautive.
			}
	}//fin de Vérifications des rangées.
	return VERIFICATION;

}
bool sont_colonnes_OK(uneGrille grille)
{
	bool VERIFICATION = true;

	// Tâche : Vérifications des colonnes
	for (int colonne = 0; colonne < uneGrilleDimension; colonne++)
	{
		// Mettre les compteurs à zéro avant de vérifier UNE colonne.
		int frequence[uneGrilleDimension] = { 0 };

		// Pour la colonne, nous allons compter la fréquence des chiffres 1 à 9. 
			// Le chiffre #K est associé au compteur #(K-1) d'où (grille[rangee][colonne]) - 1.
		for (int rangee = 0; rangee < uneGrilleDimension; rangee++)
			++frequence[(grille[rangee][colonne]) - 1];

		// vérifier que chaque chiffre n'apparaît qu'exactement une seule fois (ni plus, ni moins)
		// dans une colonne.
		for (int K = 0; K < uneGrilleDimension; K++)
			if (frequence[K] != 1)
			{
				VERIFICATION = false;
				cout << "La colonne " << colonne << " est fautive." << endl;
				break; // Une erreur dans la colonne suffit pour dire que la colonne est fautive.
			}
	}//fin de Vérifications des colonnes.
	return VERIFICATION;
}


bool sont_blocs_OK(uneGrille grille)
{

	// Mettre les compteurs à zéro avant de vérifier les blocs.
	int frequence[uneGrilleDimension][uneGrilleDimension] = { 0 };
	// La rangée #K de frequence[][] contient les compteurs pour le bloc #K.

	// Le chiffre #K est associé au compteur (colonne) #(K-1) d'où (grille[rangee][colonne]) - 1.

	// On fait l'acquisition des fréquences pour tous les blocs avant de vérifier.
	for (int rangee = 0; rangee < uneGrilleDimension; rangee++)
		for (int colonne = 0; colonne < uneGrilleDimension; colonne++)
		{
			short numero_de_bloc = ((rangee / 3) * 3) + colonne / 3; // Voir la formule de l'énoncé du labo #1.
			++frequence[numero_de_bloc][(grille[rangee][colonne]) - 1];
		}

	bool VERIFICATION = true;

	for (short bloc = 0; bloc < uneGrilleDimension; bloc++)
	{
		// vérifier que chaque chiffre n'apparaît qu'exactement une seule fois (ni plus, ni moins)
		// dans un bloc.
		for (int K = 0; K < uneGrilleDimension; K++)
			if (frequence[bloc][K] != 1)
			{
				VERIFICATION = false;
				cout << "Le bloc " << bloc << " est fautif." << endl;
				break; // Une erreur dans le bloc suffit pour dire que le bloc est fautif.
			}

	}//fin de Vérifications des blocs.
	return VERIFICATION;
}

bool EstSudoku(uneGrille grille)
{
	bool rangees_OK = sont_rangees_OK(grille);
	bool colonnes_OK = sont_colonnes_OK(grille);
	bool blocs_OK = sont_blocs_OK(grille);

	return rangees_OK && colonnes_OK && blocs_OK;

} // fin -  EstSudoku( )

void lecture(uneGrille &jeton)
{
	ifstream lecture;
	lecture.open("sudoku.txt", ios::out);
	long contenant = 0;

	for (long i = 0; i < 9; i++)
	{
		//cout << " ";
		for (long j = 0; j < 9; j++)
		{
			//cout << endl;
			lecture >> contenant;
			jeton[i][j] = contenant;

		}

	}
	lecture.close();
}
void affichage(uneGrille &jeton)
{	//AFFICHAGE LIGNE DU HAUT;
	long compteur = 0;
	long compteur2 = 0;
	static char N = ' ';
	short a = 0, b = 1, c = 2;
	for (long i = 0; i < 1; i++)
	{
		cout << char(201);
		for (long i = 0; i < 35; i++)
		{

			compteur++;
			if (compteur == 12)
			{
				cout << char(203);
				compteur = 0;
			}
			else
			{
				cout << char(205);

			}
		}
		cout << char(187) << endl;
	}
	for (long y = 0; y < 3; y++)
	{
		compteur = 0;
		cout << char(186);
		//PREMIER AFFICHAGE (Ro)

		for (long j = 0; j < 9; j++)
		{
			compteur++;
			if (compteur % 3 == 0)
			{
				if (jeton[a][j] == 0)
				{
					cout << " " << N << " " << char(186);
				}
				else
				{
					cout << " " << jeton[a][j] << " " << char(186);
				}
			}
			else
			{
				if (jeton[a][j] == 0)
				{
					cout << " " << N << " " << char(179);
				}
				else
				{
					cout << " " << jeton[a][j] << " " << char(179);
				}
			}

		}
		cout << endl;

		compteur = 0;
		long compteur2 = 0;

		for (long k = 0; k < 1; k++) //AFFICHAGE LIGNE INTERMEDIAIRE
		{
			cout << char(186);
			for (long l = 0; l < 36; l++)
			{
				compteur++;
				compteur2++;
				if (compteur == 12)
				{
					compteur2 = 0;
					cout << char(186);
					compteur2 = 0;

				}
				else if (compteur2 == 4)
				{

					compteur2 = 0;
					cout << char(197);

				}
				else
				{
					cout << char(196);
				}
			}


		}
		cout << endl;

		compteur = 0;
		cout << char(186);
		//PREMIER AFFICHAGE (R1)
		for (long j = 0; j < 9; j++)
		{
			compteur++;
			if (compteur % 3 == 0)
			{
				if (jeton[b][j] == 0)
				{
					cout << " " << N << " " << char(186);
				}
				else
				{
					cout << " " << jeton[b][j] << " " << char(186);
				}
			}
			else
			{
				if (jeton[b][j] == 0)
				{
					cout << " " << N << " " << char(179);
				}
				else
				{
					cout << " " << jeton[b][j] << " " << char(179);
				}
			}

		}
		cout << endl;



		compteur = 0;
		compteur2 = 0;

		for (long k = 0; k < 1; k++) //AFFICHAGE LIGNE INTERMEDIAIRE
		{
			cout << char(186);
			for (long l = 0; l < 36; l++)
			{
				compteur++;
				compteur2++;
				if (compteur == 12)
				{
					compteur2 = 0;
					cout << char(186);
					compteur = 0;

				}
				else if (compteur2 == 4)
				{

					compteur2 = 0;
					cout << char(197);

				}
				else
				{
					cout << char(196);
				}
			}


		}
		cout << endl;



		compteur = 0;
		compteur2 = 0;
		cout << char(186);
		for (long j = 0; j < 9; j++)//AFFICHAGE R3
		{
			compteur++;
			if (compteur % 3 == 0)
			{
				if (jeton[c][j] == 0)
				{
					cout << " " << N << " " << char(186);
				}
				else
				{
					cout << " " << jeton[c][j] << " " << char(186);
				}
			}
			else
			{
				if (jeton[c][j] == 0)
				{
					cout << " " << N << " " << char(179);
				}
				else
				{
					cout << " " << jeton[c][j] << " " << char(179);
				}
			}

		}
		cout << endl;


		if (y == 2)
		{
			compteur = 0;
			compteur2 = 0;
			long cpt = 0, cpt1 = 0;

			for (long k = 0; k < 1; k++) //AFFICHAGE LIGNE INTERMEDIAIRE
			{
				cout << char(200);
				for (long l = 0; l < 35; l++)
				{
					compteur++;
					compteur2++;
					if (compteur == 12)
					{
						cpt++;
						if (cpt == 36)
						{
							compteur = 0;
							cout << char(186);
						}
						else
						{
							compteur2 = 0;
							cout << char(205);
							compteur = 0;

						}


					}
					else if (compteur2 == 4)
					{

						compteur2 = 0;
						cout << char(205);

					}
					else
					{
						cout << char(205);
					}
				}


			}
			cout << char(188);
			cout << endl;
		}
		else
		{
			compteur = 0;
			compteur2 = 0;
			long cpt = 0, cpt1 = 0;

			for (long k = 0; k < 1; k++) //AFFICHAGE LIGNE INTERMEDIAIRE
			{
				cout << char(186);
				for (long l = 0; l < 35; l++)
				{
					compteur++;
					compteur2++;
					if (compteur == 12)
					{
						cpt++;
						if (cpt == 36)
						{
							compteur = 0;
							cout << char(186);
						}
						else
						{
							compteur2 = 0;
							cout << char(206);
							compteur = 0;

						}


					}
					else if (compteur2 == 4)
					{

						compteur2 = 0;
						cout << char(205);

					}
					else
					{
						cout << char(205);
					}
				}


			}
			cout << char(186);
			cout << endl;
		}
		a += 3, b += 3, c += 3;
	}


}
void verification(uneGrille &jeton)
{
	cout << endl << endl << "Sudoku " << endl;
	if (EstSudoku(jeton))
		cout << " N'est pas Sudoku = la reponse attendue. " << endl;
	else
		cout << " Est Sudoku => fonction fautive." << endl;

}
bool contrainte(uneGrille &jeton, string b, string c)
{
	int x = stoi(b);
	int y = stoi(c);
	switch (x)
	{
	case 0: if (y != 1 && y != 2) { return false; } break;
	case 1: if (y != 0 && y != 2) { return false; } break;
	case 2: if (y != 0 && y != 1) { return false; } break;
	case 3: if (y != 4 && y != 5) { return false; } break;
	case 4: if (y != 3 && y != 5) { return false; } break;
	case 5: if (y != 3 && y != 4) { return false; } break;
	case 6: if (y != 7 && y != 8) { return false; } break;
	case 7: if (y != 6 && y != 8) { return false; } break;
	case 8: if (y != 6 && y != 7) { return false; } break;
	}
	return true;
}
void echangerRangees(uneGrille &jeton, string b, string c)
{
	int x = stoi(b);
	int y = stoi(c);
	contrainte(jeton, b, c);
	short z = 0;
	if (contrainte(jeton, b, c))
	{

		for (long i = 0; i < 9; i++)
		{
			z = jeton[x][i];
			jeton[x][i] = jeton[y][i];
			jeton[y][i] = z;
		}
		affichage(jeton);
		cout << endl;
	}
	else
	{
		cout << "Veuillez verifier vos valeurs" << endl;
	}
}
void echangerColonnes(uneGrille &jeton, string b, string c)
{
	int x = stoi(b);
	int y = stoi(c);
	contrainte(jeton, b, c);
	short z = 0;
	if (contrainte(jeton, b, c))
	{
		for (long i = 0; i < 9; i++)
		{
			z = jeton[i][x];
			jeton[i][x] = jeton[i][y];
			jeton[i][y] = z;
		}
		affichage(jeton);
		cout << endl;
	}
	else
	{
		cout << "Veuillez verifier vos valeurs" << endl;
	}

}
void echangerGroupesHorizontaux(uneGrille &jeton, long &indice, long &N)
{

	short z = 0;

	for (long j = 0; j < 9; j++)
	{
		z = jeton[indice][j];
		jeton[indice][j] = jeton[N][j];
		jeton[N][j] = z;

		z = jeton[indice + 1][j];
		jeton[indice + 1][j] = jeton[N + 1][j];
		jeton[N + 1][j] = z;

		z = jeton[indice + 2][j];
		jeton[indice + 2][j] = jeton[N + 2][j];
		jeton[N + 2][j] = z;
	}

	affichage(jeton);
	cout << endl;

}
void echangespecialhorizontaux(uneGrille &jeton, string b, string c)
{
	long indice = 0;
	long N = indice + 3;
	if (b == "A")
	{
		if (c == "B")
		{
			echangerGroupesHorizontaux(jeton, indice, N);
		}
		else if (c == "C")
		{
			N = indice + 6;
			echangerGroupesHorizontaux(jeton, indice, N);
		}
		else
		{
			cout << "Erreur" << endl;
		}
	}
	else if (b == "B")
	{
		indice = 3;
		if (c == "A")
		{

			N = indice - 3;
			echangerGroupesHorizontaux(jeton, indice, N);
		}
		else if (c == "C")
		{
			N = indice + 3;
			echangerGroupesHorizontaux(jeton, indice, N);
		}
		else
		{
			cout << "Erreur" << endl;
		}
	}
	else if (b == "C")
	{
		indice = 6;
		if (c == "A")
		{
			N = indice - 6;
			echangerGroupesHorizontaux(jeton, indice, N);
		}
		else if (c == "B")
		{
			N = indice - 3;
			echangerGroupesHorizontaux(jeton, indice, N);
		}
		else
		{
			cout << "Erreur" << endl;
		}

	}
	else
	{
		cout << "Erreur" << endl;
	}

}
void echangerGroupesVerticaux(uneGrille &jeton, long &indice, long &N)
{
	short z = 0;

	for (long j = 0; j < 9; j++)
	{

		z = jeton[j][indice];
		jeton[j][indice] = jeton[j][N];
		jeton[j][N] = z;

		z = jeton[j][indice + 1];
		jeton[j][indice + 1] = jeton[j][N + 1];
		jeton[j][N + 1] = z;

		z = jeton[j][indice + 2];
		jeton[j][indice + 2] = jeton[j][N + 2];
		jeton[j][N + 2] = z;

	}
	affichage(jeton);
	cout << endl;
}
void echangespecialverticaux(uneGrille &jeton, string b, string c)
{
	long indice = 0;
	long N = indice + 3;
	if (b == "A")
	{
		if (c == "B")
		{
			echangerGroupesVerticaux(jeton, indice, N);
		}
		else if (c == "C")
		{
			N = indice + 6;
			echangerGroupesVerticaux(jeton, indice, N);
		}
		else
		{
			cout << "Erreur" << endl;
		}
	}
	else if (b == "B")
	{
		indice = 3;
		if (c == "A")
		{

			N = indice - 3;
			echangerGroupesVerticaux(jeton, indice, N);
		}
		else if (c == "C")
		{
			N = indice + 3;
			echangerGroupesVerticaux(jeton, indice, N);
		}
		else
		{
			cout << "Erreur" << endl;
		}
	}
	else if (b == "C")
	{
		indice = 6;
		if (c == "A")
		{
			N = indice - 6;
			echangerGroupesVerticaux(jeton, indice, N);
		}
		else if (c == "B")
		{
			N = indice - 3;
			echangerGroupesVerticaux(jeton, indice, N);
		}
		else
		{
			cout << "Erreur" << endl;
		}

	}
	else
	{
		cout << "Erreur" << endl;
	}

}
void permuter(uneGrille &jeton)
{
	string nom;//Nom du fichier;
	string a, b, c;
	ifstream lecteur;
	cout << "Veuillez entrer le nom du fichier: ";
	cin >> nom;
	lecteur.open(nom, ios::out);
	while (a != "F")
	{
		lecteur >> a >> b >> c;

		if (a == "R")
		{
			cout << a << " " << b << " " << c << " " << endl;
			echangerRangees(jeton, b, c);

		}
		else if (a == "C")
		{
			cout << a << " " << b << " " << c << " " << endl;
			echangerColonnes(jeton, b, c);
		}
		else if (a == "V")
		{
			cout << a << " " << b << " " << c << " " << endl;
			echangespecialverticaux(jeton, b, c);

		}
		else if (a == "H")
		{
			cout << a << " " << b << " " << c << " " << endl;
			echangespecialhorizontaux(jeton, b, c);


		}

	}
	lecteur.close();
}

void conserver(uneGrille &jeton, long  &garde)
{
	cout << "Entrer le nombre de chiffre que vous souhaitez garder :" << endl;
	cin >> garde;
	long supprimer = 81 - garde;
	long T[9] = { 0,1, 2, 3, 4, 5, 6, 7, 8 };
	long i = 0;
	while (i < supprimer)
	{
		long k = rand() % 9;
		long y = rand() % 9;
		if (jeton[k][y] != 0)
		{
			jeton[T[k]][T[y]] = 0;
			i++;
		}

	}
	affichage(jeton);
}

int main()
{

	long contenant = 0;
	long garde = 0;
	uneGrille sudoku;
	lecture(sudoku);
	affichage(sudoku);
	permuter(sudoku);
	//verification(sudoku);
	conserver(sudoku, garde);
	return 0;
}

