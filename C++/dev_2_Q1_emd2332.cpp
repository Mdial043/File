#include <iostream>
#include<math.h>
#include<time.h>

using namespace std;
void aleatoireEntier_a_N_chiffres_binaires(short &N, unsigned short &interv, unsigned long long &test)//GENERER N BITS ALEATOIREMENT
{
	time_t temps;
	temps = time(NULL);
	srand(unsigned int(temps));

	double  frequenceattendue = test / interv;
	long freq[200] = { 0 };
	double terme = 0;
	long valeur = 0;
	double ppt = 0;
	double pgt = 0;
	for (long K = 0; K < test; K++)
	{
		terme = 0;
		for (long k = 0; k < N; k++)
		{
			ppt;
			pgt;
			double chiffre = (rand() % 2) / 2.0;
			terme = (terme / 2.0) + chiffre;
			if (terme < ppt)
			{
				ppt = terme;
			}
			if (terme > pgt)
			{
				pgt = terme;
			}


		}

		int index = 0;


		for (double i = 0; i < interv; i++)
		{
			double	y = (i / interv);
			double	z = ((i + 1) / interv);
			if (terme >= y && terme < z)
			{
				freq[index]++;
			}
			index++;

		}

	}
	cout << "LA PLUS PETITE VALEUR  EST : " << ppt << endl;
	cout << "LA PLUS GRANDE VALEUR  EST : " << pgt << endl << endl;
	cout << endl << endl << "FREQUENCE ATTENDUE :" << frequenceattendue << endl;
	cout << "INTERVALLE# :" << '\t' << "FREQUENCE:" << '\t' << "Erreur" << '\t' << "Erreur relative" << endl;
	double n = 0.0, q = 0.0;
	for (long i = 0; i < interv; i++)
	{
		q = freq[i] - frequenceattendue;


		if (q > 0)
		{
			n = n + q;
		}
		else if (q < 0)
		{
			n = n - q;
		}
		cout << i << '\t' << '\t' << freq[i] << '\t' << '\t'
			<< freq[i] - frequenceattendue << '\t' << "    "
			<< (100 * (freq[i] - frequenceattendue)) / (frequenceattendue) << " %" << endl;

	}
	cout << "ERREUR MOYENNE: " << n / interv << endl;
	cout << "ERREUR MOYENNE RELATIVE: " << (100 * (n / interv)) / (frequenceattendue) << endl;

}
void intervalle(double &intermed, double &sousinterv, unsigned short &interv)//AFFICHAGE DES INTERVALLES
{
	cout << "Lintervalle [0,1,0) sera subdivise en " << interv << " egaux (ou egal) :" << endl;
	intermed = 0.0;
	sousinterv = 1.0 / interv;
	double amplitude = 1.0 / interv;

	for (long i = 0; i < interv; i++)
	{
		cout << "Intervalle #" << i << ": [" << intermed << ", " << sousinterv << ")" << endl;
		intermed = sousinterv;
		sousinterv = intermed + amplitude;

	}
}


int main()
{
	short N = 0;
	unsigned short  interv = 0;
	unsigned long long test = 0;
	long freq[100] = { 0 };
	double intermed = 0.0;
	double sousinterv = 1.0 / interv;
	double amplitude = 0.0;

	cout << "Entrer le nombre de bit(s) : ";
	cin >> N;
	cout << endl;
	cout << "Entrer le nombre de test a faire :";
	cin >> test;
	cout << endl;
	cout << "Entrer le nombre de sous intervalle(s) : ";
	cin >> interv;
	cout << endl;
	if (N <= 64)
	{

		intervalle(intermed, sousinterv, interv);
		aleatoireEntier_a_N_chiffres_binaires(N, interv, test);
		


	}


}

