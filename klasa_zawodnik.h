class Zawodnik
{
	public:
		// Konstruktory i destruktory
		Zawodnik();
		~Zawodnik();

		// Get Functions
		char* GetImie() {return itsImie;};
		char* GetNazwisko() {return itsNazwisko;};
		char* GetNarodowosc() {return itsNarodowosc;};
		int GetForma() { return itsForma; };
		int GetRefleks() { return itsRefleks; };
		int GetNumber() { return itsNumber; };
		int GetIloscMechanikow() { return itsIloscMechanikow; };
		int GetStart() { return itsStart; };
		int GetWalka() { return itsWalka; };
		float GetKSM() { return itsKSM; };
		int GetPower() { return itsPower; };
		int GetTechnika_Jazdy() { return itsTechnika_Jazdy; };
		int GetZdrowie() { return itsZdrowie; };
		int GetWiek() { return itsWiek; };
		int GetOpony() { return itsOpony; };
		int GetMorale() { return itsMorale; };
		int GetIloscPkt() { return itsIloscPkt; };
		int GetIloscBonusow() { return itsIloscBonusow; };
		int GetIloscBiegow() { return itsIloscBiegow; };
		int GetIloscMeczow() { return itsIloscMeczow; };
		int GetIloscUpadkow() { return itsIloscUpadkow; };
		int GetIloscDefektow() { return itsIloscDefektow; };
		int GetIloscTasm() { return itsIloscTasm; };
		int GetStatus() { return itsStatus; };
				
		//Set Functions
		void SetForma(int value) { itsForma=value; };
		void SetRefleks(int value) { itsRefleks=value; };
		void SetNumber(int value) { itsNumber=value; };
		void SetImie(char* noweImie);
		void SetNazwisko(char* noweNazwisko);
		void SetIloscMechanikow(int value) { itsIloscMechanikow=value; };
		void SetStart(int value) { itsStart=value; };
		void SetWalka(int value) { itsWalka=value; };
		void SetKSM(float value) { itsKSM=value; };
		void SetZdrowie(int value) { itsZdrowie=value; };
		void SetWiek(int value) { itsWiek=value; };
		void SetOpony(int value) { itsOpony=value; };
		void SetNarodowosc(char *value) { strcpy(itsNarodowosc, value); };
		void SetStatus(int value) { itsStatus=value; };
		void SetMorale(int value) { itsMorale=value; };
		void SetIloscPkt(int value) { itsIloscPkt=value; };
		void SetIloscBonusow(int value) { itsIloscBonusow=value; };
		void SetIloscBiegow(int value) { itsIloscBiegow=value; };
		void SetIloscMeczow(int value) { itsIloscMeczow=value; };
		void SetIloscUpadkow(int value) { itsIloscUpadkow=value; };
		void SetIloscDefektow(int value) { itsIloscDefektow=value; };
		void SetIloscTasm(int value) { itsIloscTasm=value; };
		
	
		int itsForma;
		int itsRefleks;
		int itsNumber;
		int itsStart;
		int itsTechnika_Jazdy;
		int itsWalka;
		int itsPower;
		int itsIloscMechanikow;
		float itsKSM;
		int itsZdrowie;
		int itsWiek;
		int itsOpony;
		char *itsImie;
        char *itsNazwisko;
		char *itsNarodowosc;
		Motor itsMotor;
		bool itsWypozyczony;
		int itsStatus;
		int itsMorale;
		int itsIloscPkt;
		int itsIloscBonusow;
		int itsIloscBiegow;
		int itsIloscMeczow;
		int itsIloscUpadkow;
		int itsIloscDefektow;
		int itsIloscTasm;
};

Zawodnik::Zawodnik()
{
    itsImie = new char[20];
    itsNazwisko = new char[30];
    itsNarodowosc = new char[30];
    itsImie = "Imie zawodnika";
    itsNazwisko = "Nazwisko Zawodnika";
    itsNarodowosc = "Narodowosc Zawodnika";
   	itsForma=0;
	itsRefleks=0;
	itsNumber=0;
	itsWypozyczony=0;
};

Zawodnik::~Zawodnik()
{
   delete itsImie;
   delete itsNazwisko;
   delete itsNarodowosc;
};

void Zawodnik::SetImie(char* noweImie)
{
	itsImie=new char[sizeof(noweImie)];
	strcpy(itsImie, noweImie);
};

void Zawodnik::SetNazwisko(char *noweNazwisko)
{
	itsNazwisko=new char[sizeof(noweNazwisko)];
	strcpy(itsNazwisko, noweNazwisko);
};


