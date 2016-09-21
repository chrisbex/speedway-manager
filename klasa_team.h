class Team
{
	public:
		Team();
		Team(char *TeamName);
		~Team();


		char *itsName;
		Zawodnik *itsPlayer[20];
};

Team::Team()
{
	itsName=new char[40];
	itsName="New Team";
	for (int i=0; i<20; i++) itsPlayer[i]=new Zawodnik();
};

Team::Team(char *TeamName)
{
	itsName=new char[strlen(TeamName)];
	strcpy(itsName, TeamName);
	for (int i=0; i<20; i++) itsPlayer[i]=new Zawodnik;
};

Team::~Team()
{
    delete itsName;
	delete [] itsPlayer;
};
