// Class File for Speedway Manager

class CBaza
{
      public:
         CBaza(char *filename);
         char* GetTeamName(int TeamNumber);
         char* GetPlayerImie(int TeamNumber, int Zawodas);
         Team *itsDruzyny[8];
};

CBaza::CBaza(char *filename)
{
      FILE *Plik_Bazy_Danych;
//      Plik_Bazy_Danych = fopen(filename, "r");
//      if (Plik_Bazy_Danych==NULL) allegro_message ("Operacja ladowania Bazy Danych nie przebiegla pomyslnie");
      for (int i=0; i<8; i++) itsDruzyny[i]=new Team;
      char *Nazwa_Druzyny = new char[10];
//      fgets(Nazwa_Druzyny, 10, Plik_Bazy_Danych);
//      strcpy(itsDruzyny[0]->itsName, Nazwa_Druzyny);
//      fclose(Plik_Bazy_Danych);      
};

char* CBaza::GetTeamName(int TeamNumber)
{
      return itsDruzyny[TeamNumber]->itsName;
};

char* CBaza::GetPlayerImie(int TeamNumber, int Zawodas)
{
      return itsDruzyny[TeamNumber]->itsPlayer[Zawodas]->GetImie();
};

class CMenu
{
	public:
		CMenu();
		~CMenu() { delete [] opcje; };
		void add_option(char *tekst);
		void draw();
		int GetX() { return itsX; };
		int GetY() { return itsY; };
		void SetX(int val) { itsX=val; };
		void SetY(int val) { itsY=val; };
		int choose();
		void move_up();
		void move_down();
	private:
		int itsX, itsY;
		int IloscOpcji;
		int AktualnaPozycja;
		char **opcje;
};

CMenu::CMenu()
{
	IloscOpcji=0;
	AktualnaPozycja=1;
	itsX=10; itsY=10;
	*opcje = new char;
};

void CMenu::add_option(char *tekst)
{
	++IloscOpcji;
	strcpy(opcje[IloscOpcji-1], tekst);
};

void CMenu::draw()
{
	BITMAP *obraz=create_bitmap(300,300);
	for (int i=0; i<IloscOpcji; i++)
	{
		if (i==AktualnaPozycja-1)
		textprintf_ex(obraz, font, 0, 0+i*15, makecol(255,0,0), makecol(0,0,255), "%s", opcje[i]);
		else
		textprintf_ex(obraz, font, 0, 0+i*15, makecol(255,0,0), -1, "%s", opcje[i]);
	};
	acquire_screen();
	draw_sprite(screen, obraz, GetX(), GetY());
	release_screen();
	destroy_bitmap(obraz);
};

int CMenu::choose()
{
    draw();
    char val=0;
	do
	{
		char val=readkey()%256;
		if (val=='q') move_up();
		if (val=='a') move_down();
	}
	while (val!=13);
	return AktualnaPozycja;
};

void CMenu::move_up()
{
	if (AktualnaPozycja!=0) AktualnaPozycja--;
	draw();
};

void CMenu::move_down()
{
	if (AktualnaPozycja!=IloscOpcji) AktualnaPozycja++;
	draw();
};

// ---------------------------------------------------------------------
// --------------------------------------------------------------------=

void highcolor_fade_in(BITMAP *bmp_orig, int speed)
{
   BITMAP *bmp_buff;

    if ((bmp_buff = create_bitmap(SCREEN_W, SCREEN_H)))
    {
        int a;
        if (speed <= 0) speed = 16;
        
        for (a = 0; a < 256; a+=speed)
        {
            clear(bmp_buff);
            set_trans_blender(0,0,0,a);
            draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
            vsync();
            blit(bmp_buff, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
        }
        destroy_bitmap(bmp_buff);
    } 

    blit(bmp_orig, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
}

void highcolor_fade_out(int speed)
{
    BITMAP *bmp_orig, *bmp_buff;

    if ((bmp_orig = create_bitmap(SCREEN_W, SCREEN_H)))
    {
        if ((bmp_buff = create_bitmap(SCREEN_W, SCREEN_H)))
        {
            int a;
            blit(screen, bmp_orig, 0,0, 0,0, SCREEN_W, SCREEN_H);
            if (speed <= 0) speed = 16;
        
            for (a = 255-speed; a > 0; a-=speed)
            {
                clear(bmp_buff);
                set_trans_blender(0,0,0,a);
                draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
                vsync();
                blit(bmp_buff, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
            }
            destroy_bitmap(bmp_buff);
        }
        destroy_bitmap(bmp_orig);
    }

    rectfill(screen, 0,0, SCREEN_W,SCREEN_H, makecol(0,0,0));
}
