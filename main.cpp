#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "TEXT.h"
#include "EVKD.h"

using namespace std;

#define maxLength 50


int main(){
	int auswahl, ein;
	char *eingabe;
	TEXT *text = new TEXT();
	EVKD *evkd;
    char * name[] = { "Schmitz, Josef","Mueller, Josi","Schmitz, Anna",
						"Mueller, Josef","Schmitz, Josi","Mueller, Anna",
						"Meier, Josef","Zacher, Josi","Anker, Anna" };


	do{

		cout 
			<< "1 - Listenobjekt erstellen" << endl
			<< "2 - Liste anzeigen" << endl
			<< "3 - Element anhaengen" << endl
			<< "4 - Element sortiert einfuegen" << endl
			<< "5 - Element loeschen" << endl
			<< "6 - Liste sortieren" << endl
			<< "12 - Break" << endl;
		cin >> auswahl;
		cin.clear();


		switch(auswahl){

			case 1:  cout << endl << "Listenobjekt wird erstellt" << endl;
				text = new TEXT();
				for(int i = 0; i < 9; i++){
					text->anhaenge(name[i]);
				}
				break;

			case 2:  cout << endl << "Inhalt der Liste" << endl << endl;
				text->zeigDich();
				break;
			case 3:  cout << endl << "Wort eingeben, das angehaenget werden soll" << endl;
				eingabe = new char[maxLength];
				cin.getline(eingabe, maxLengt );
				cin.clear();
				text->anhaenge(eingabe);
				delete[] eingabe;
				break;
			case 4:  cout << endl << "Wort eingeben" << endl;
				eingabe = new char[maxLength];
				cin.getline(eingabe, maxLength);
				cin.clear();
				evkd = new EVKD(eingabe);
				text->einfuegeSortiert(evkd, text->Anz);
				delete[] eingabe;
				break;
			case 5:  cout << endl << "Welches Element soll geloescht werden?" << endl;
				cin >> ein;
				cin.clear();
				text->loesche(ein);
				break;
			case 6:  cout << endl << "Liste wird sortiert" << endl;
				text->iSort();
				break;

		}

} while(auswahl != 12);

}
