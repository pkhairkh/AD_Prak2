#include "EVDK.h"

TEXT::TEXT(){
	Anz = 0;
	Start = nullptr;
}



void TEXT::anhaenge ( char *In) {

    EVKD uebergabe(&In);
    if(this->Start!=NULL){
        EVKD* temp(this->Start);
        while (temp->getNext() != null) {
            temp = temp->getNext();
        }
        temp->setNext(uebergabe);       
    }
}  

void TEXT::einfuegeSortiert(EVKD * In, int Max){
        
        if(Anz+1>Max){
            cout << "max amount reached " << endl;
            return;
        }

        if(this->Start==NULL){
            this->Start=&(*In);
            return;
        }
        if(In>Start){
            In->setNext((*Start));
            Start=&(*In);
            return;
        }
        EVKD * vergleich(Start);
        for(int i=0; i<Anz; i++){
            // Wenn das nächste Objekt mit dem verglichen werden soll nicht existiert
            // sind wir am Ende der Liste angelagt und können einfügen.
            if(vergleich->getNext() == NULL){
                vergleich->setNext((*In));
            }
            
            // Wenn In zwischen dem aktuellen und dem nächste liegt, füge dort ein.
            else if ((*In)>(*vergleich) && vergleich->getNext()>In){
                EVKD temp = EVKD(In->getDaten(), vergleich->getNext());
                vergleich->setNext((*In));
            }

            // Kein treffer, wiederhole mit nächstem Objekt
            else{
                vergleich = vergleich->getNext();
            }
            
        }
}

void TEXT::zeigeDich(){
	if(this->start != nullptr){
		int i = 1;
		EVKD *tmp = this->start;
		while(tmp->getNext() != nullptr){
			cout << i << ": Adresse: " << tmp << "  Inhalt:  " << tmp->getDaten() << " Next: " << tmp->getNext() << endl;
			i++;
			tmp = tmp->getNext();
		}
		cout << i << ": Adresse: " << tmp << "  Inhalt:  " << tmp->getDaten() << " Ich bin das Letzte" << endl;
	}
}

void TEXT::iSort(){
	int i = 2;
	EVKD *tmp;
	if(this->anz > 1){
		while(i <= this->anz){
			tmp = loesche(i);
			einfuegeSortiert(tmp, i - 1);
			i++;
		}
	}
}

void TEXT::loesche(int Pos){
        if(Pos>this->Anz){
            cout << "Element an Position " << Pos << " konnte nicht gelöscht werden, da es außerhalb der Elemente liegt." << endl;
            return;
        }
        EVKD *preobj(this->Start);
        if(preobj==NULL){
            cout << "Element an Position " << Pos << " konnte nicht gelöscht werden, da es keine Elemente gibt." << endl;
            return;
        }
        for(int i=0; i<Pos-1;i++){
            preobj=(preobj->getNext());
        }
        EVKD *posobj(preobj->getNext());
        EVKD *nextobj(posobj->getNext());
        if(posobj!=NULL){
            if(nextobj!=NULL){
               preobj->setNext(*nextobj);
               delete posobj;
            }
            else{
                // (*preobj).setNext(nullptr);
                delete posobj;
            }
        }
        else{
            cout << "Das Element exisitert nicht." << endl;
        }
}