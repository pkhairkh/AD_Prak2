#pragma once
#include <stdlib.h>
#include <string.h>

class EVKD{
    private:

    char *Daten;
    int Anz;
    EVKD *Next;

    public:

    EVKD(){}

    EVKD(char * LPSZDaten, EVKD *N)
            : Daten(LPSZDaten), Next(N){};

    EVKD( EVKD *E1) {
        Daten = E1->Daten;
        Anz = E1->Anz;
        Next = E1->Next;
    };

    char * getDaten() { 
        return Daten; 
        }

    int getAnzahl() ;

    EVKD * getNext() ;

    void setNext(EVKD &N);

    bool operator== (EVKD &E1) ;

    bool operator> ( EVKD &E1) ;
};