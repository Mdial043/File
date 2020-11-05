#include "pch.h"
#include <iostream>
using namespace std;
const char coin_sup_gauche = char(218);
const char coin_sup_droite = char(191);
const char coin_inf_gauche = char(192);
const char coin_inf_droite = char(217);
const char vertical = char(179);
const char horizontal = char(196);
const char espace = char(32);
void carasteristique(short &l) {
	cout << "Entrer la longueur:";
	cin >> l;
}
void Espace1(short l) {
	for (short i = 1; i <= 25 - (l + (l / 2)); i++)
	{
		cout << endl;
		for (short i = 1; i <= 25 - (l / 2); i++)
		{
			cout << espace;
		}
	}
}
void ligne1(short l) {
	Espace1(l);
	cout << coin_sup_gauche;
	for (short i = 1; i <= l - 2; i++)
	{
		cout << horizontal;
	}
	cout << coin_sup_droite;
	cout << endl;
}
void Espace2(short l) {
	for (short i = 1; i <= 25 - (l / 2); i++)
	{
		cout << espace;
	}

}
void Espinterm(short l) {
	for (short i = 1; i <= l - 2; i++)
	{
		cout << espace;

	}

}
void ligne2(short l) {
	for (short i = 1; i <= l - 2; i++)
	{
		Espace2(l);
		cout << vertical;
		Espinterm(l);
		cout << vertical;
		cout << endl;

	}

}
void Espace3(short l) {
	for (short i = 1; i <= 25 - (l + (l / 2)); i++)
	{
		cout << espace;
	}
}
void ligne3(short l) {

	Espace3(l);
	cout << coin_sup_gauche;
	for (short i = 1; i <= l - 1; i++)
	{
		cout << horizontal;
	}
	cout << coin_inf_droite;
	Espinterm(l);
	cout << coin_inf_gauche;
	for (short i = 1; i <= l - 2; i++)
	{
		cout << horizontal;
	}
	cout << coin_sup_droite;
	cout << endl;

}
void Espacemilieu(short l) {
	for (short i = 1; i <= (l * 3) - 3; i++)
	{
		cout << espace;

	}
}
void ligne4(short l) {
	for (short i = 1; i <= l - 2; i++)
	{
		Espace3(l);
		cout << vertical;
		Espacemilieu(l);
		cout << vertical;
		cout << endl;
	}
}
void ligne5(short l) {
	Espace3(l);
	cout << coin_inf_gauche;
	for (short i = 1; i <= l - 1; i++)
	{
		cout << horizontal;
	}
	cout << coin_sup_droite;
	Espinterm(l);
	cout << coin_sup_gauche;
	for (short i = 1; i <= l - 2; i++)
	{
		cout << horizontal;
	}
	cout << coin_inf_droite;
	cout << endl;
}
void Espace4(short l) {
	for (short i = 1; i <= 25 - (l / 2); i++)
	{
		cout << espace;
	}
}
void ligne6(short l) {

	for (short i = 1; i <= l - 2; i++)
	{
		Espace4(l);

		cout << vertical;
		Espinterm(l);
		cout << vertical;
		cout << endl;

	}

}
void ligne7(short l) {
	Espace4(l);
	cout << coin_inf_gauche;
	for (short i = 1; i <= l - 2; i++) {

		cout << horizontal;
	}
	cout << coin_inf_droite;
}
int main()
{
	short l;
	carasteristique(l);
	ligne1(l);
	ligne2(l);
	ligne3(l);
	ligne4(l);
	ligne5(l);
	ligne6(l);
	ligne7(l);
}
