class TEXT{

    private:
    class EVKD *Start;

    public:
    int Anz;
    
    TEXT(){};

    TEXT(int Anz): Start(NULL) {};

    void anhaenge ( char *In) {};      

    void einfuegeSortiert(EVKD * In, int Max){};

    void loesche(int Pos){};

    void zeigDich(){};

    void iSort(){};
};