// Class For Speedway Manager
// uses allegro.h

class KButton
{
	public:
		KButton(char *caption, int X, int Y, int W, int H);
		KButton();
		~KButton() { destroy_bitmap(obraz); delete itsCaption; };
		void draw_button();
		void OnMouseOver();

	private:
		BITMAP *obraz;
		char *itsCaption;
		int itsX, itsY;
		int itsW, itsH;
		int itsTextColor;
};

KButton::KButton(char *caption, int X, int Y, int W, int H)
{
	itsCaption=new char[strlen(caption)];
	strcpy(itsCaption, caption);
	itsX=X;
	itsY=Y;
	itsW=W;
	itsH=H;
	obraz=create_bitmap(itsW, itsH);
	clear_to_color(obraz, makecol(255,0,0));
	itsTextColor=makecol(255,255,255);
};

KButton::KButton()
{
	itsX=30; 
	itsY=30;
	itsW=50;
	itsH=15;
	obraz=create_bitmap(itsW, itsH);
};

void KButton::draw_button()
{
	rect(obraz, 1, 1, itsW, itsH, 0);
	textprintf_ex(obraz, font, 10, (itsH%2+itsH/2)-4, itsTextColor, -1, "%s", itsCaption);
	acquire_screen();
	draw_sprite(screen, obraz, itsX, itsY);
	release_screen();
};

void KButton::OnMouseOver()
{
     itsTextColor=makecol(0,0,255);
     draw_button();
};

// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------


