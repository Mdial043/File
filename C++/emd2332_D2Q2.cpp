#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;
ifstream lecture;
ofstream ecrire;
bool estclientArrive(double probabilite)
{
	double valeur = 100 * rand() / 32768; // 0 <= valeur < 100.0
	return valeur < probabilite;
}
long obtenirDureeTransaction(long dureeMinimum, long dureeMaximum)
{
	return dureeMinimum + rand() % (dureeMaximum - dureeMinimum + 1);
}

struct unclient
{
	long tempArrivee;
	long dureeTransaction;
};

template <typename unType>
struct unNoeud
{

	unType info;
	unNoeud<unType> *suivant;
};


template <typename unType>
class uneFile
{
private:

	unNoeud<unType> *Queue;

	unNoeud<unType> *tete;
	long nombre;

public:


	uneFile()
	{
		tete = new unNoeud<unType>;
		Queue = tete;
		tete->suivant = NULL;
	}

	bool estVide()
	{
		return NULL == tete->suivant;
	}

	bool estPleine()
	{
		return false;
	}
	void inserer(unType nouveauclient)
	{

		unNoeud<unType> *temporaire = new unNoeud<unType>;
		temporaire->suivant = NULL;
		temporaire->info = nouveauclient;

		Queue->suivant = temporaire;
		Queue = temporaire;
		nombre++;
	}
	void enlever(unType &client)
	{

		unNoeud <unType> *temp = tete->suivant;
		client = temp->info;
		tete->suivant = temp->suivant;
		delete temp;
		if (estVide())
		{
			Queue = tete;
		}
		nombre--;
	}
	long estCombien() { return nombre; }
};


int main()
{
	long dureeTransanction = 0, nombreclient = 0, tempDattente, horloge = 0, m = 0;
	double dureeMoyenneDat = 0, dureeMoyenneTran = 0, n = 0; string fichier; unclient client;
	client.dureeTransaction = 0, client.tempArrivee = 0; long clientattente = 0;
	double probabilite = 0.0;
	long durmin = 0, durmax = 0, tempD = 0, TempA = 0, dureeT = 0, pcdat = 0, pgdat = 0, pcdtr = 0, pgdtr = 0;



	cout << "veillez saisir le nom du fichier : " << endl;
	cin >> fichier;
	lecture.open(fichier, ios::in);



	lecture >> probabilite >> durmin >> durmax;


	time_t temps;
	temps = time(NULL);
	srand(unsigned int(temps));
	long stockage = 0;

	uneFile <unclient> file;
	unclient guichet;


	ecrire.open("stat.txt", ios::out);
	while ((horloge < 480) || (!file.estVide()))
	{
		horloge++;

		ecrire << "HORLOGE : " << horloge << endl;
		ecrire << "CLIENTS DANS LA FILE : " << file.estCombien() << endl << endl;

		if (estclientArrive(probabilite) && (horloge < 480))
		{

			client.tempArrivee = horloge;

			client.dureeTransaction = obtenirDureeTransaction(durmin, durmax);
			file.inserer(client);

			ecrire << "CLIENT ARRIVE , DUREE DE TRANSACTION:" << client.dureeTransaction;
			ecrire << "=============================================================" << endl;
		}
		if ((dureeTransanction == 0))
		{
			if (!file.estVide())
			{

				nombreclient++;
				file.enlever(guichet);



				dureeTransanction = guichet.dureeTransaction - 1;

				tempDattente = horloge - guichet.tempArrivee;
				if (tempDattente != 0) { clientattente++; }
				dureeMoyenneDat += tempDattente;
				dureeMoyenneTran += dureeTransanction;

				if (pcdat > tempDattente)
					pcdat = tempDattente;
				if (pgdat < tempDattente)
					pgdat = tempDattente;

				if (pcdtr > dureeTransanction)
					pcdtr = dureeTransanction;

				if (pgdtr < dureeTransanction)
					pgdtr = dureeTransanction;

				ecrire << "client : " << nombreclient << endl;
				ecrire << "temps d'arrive       : " << guichet.tempArrivee << " minutes " << endl;

				ecrire << "temps d'attente      : " << tempDattente << " minutes " << endl;
				ecrire << "duree transaction    : " << guichet.dureeTransaction << " minutes " << endl;
				ecrire << "------------------------------------------------------------------------" << endl;






			}

		}
		else
		{
			dureeTransanction--;
		}

	}

	ecrire << "*******************************************************" << endl;
	ecrire << "duree moyenne d'attente dans ls file          : " << dureeMoyenneDat / nombreclient << " minutes" << endl;
	ecrire << "plus courte duree d'attende dans la file      : " << pcdat << " minutes" << endl;
	ecrire << "plus longue duree d'attende dans la file      : " << pgdat << " minutes" << endl;
	ecrire << "duree moyenne de transaction dans la file     : " << dureeMoyenneTran / nombreclient << " minutes" << endl;
	ecrire << "plus courte duree de transaction              : " << pcdtr << " minutes" << endl;
	ecrire << "plus grande duree de transaction dans la file : " << pgdtr << " minutes" << endl;


	lecture.close();
	ecrire.close();
	return 0;
}
