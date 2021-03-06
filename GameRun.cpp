// Header File for Speedway Manager
// Everything should init here

#include <allegro.h>
#include <almp3.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "data\header.h"
#include "klasa_motor.h"
#include "klasa_zawodnik.h"
#include "klasa_team.h"
#include "kb2000.h"
#include "KButton.h"

// GLOBAL Variables
DATAFILE *MyData;
SAMPLE *Music;
CBaza BazaDanych("DB001.dat");
int Wyjscie=0;
int choose=5;

// Global Functions
void Game_Initialize()
{
    allegro_init();
    set_window_title("Speedway Manager v0.0");
    install_keyboard();
    install_mouse();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0);   
    install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL);
    
//    show_mouse(screen);
};

void Title()
{
     BITMAP *buffer = (BITMAP *)MyData[TitleScreen].dat;
     highcolor_fade_in(buffer, 20);
     textprintf_ex(screen, font, 40, 210, makecol(0, 0, 0), -1,
	      "Driver Karty Dzwiekowej: %s", digi_driver->name);
     textprintf_ex(screen, font, 40, 220, makecol(0, 0, 0), -1,
		  "Driver Karty Graficznej: %s", gfx_driver->name);
     ALMP3_MP3 *mp3 = almp3_create_mp3(MyData[Muzyka].dat, MyData[Muzyka].size);
     char *wynik;
     if (mp3!=NULL) wynik="OK"; else wynik="Error - No Music";     
     textprintf_ex(screen, font, 40, 240, makecol(0, 0, 0), -1,
          "Loading Music:  ");
     Music = almp3_create_sample_from_mp3(mp3);
     textprintf_ex(screen, font, 160, 240, makecol(0, 0, 0), -1, "%s", wynik);
     almp3_destroy_mp3(mp3);
     textprintf_ex(screen, font, 40, 450, makecol(0, 0, 0), -1,
          "Speedway Manager v0.0");
     show_mouse(screen);
     while (!mouse_b) {};
     highcolor_fade_out(9);
     destroy_bitmap(buffer);
};

int MenuScreen()
{
    BITMAP *bmp = (BITMAP *)MyData[Title1].dat;
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    SAMPLE *klik = (SAMPLE *)MyData[Klik1].dat;
    highcolor_fade_in(bmp, 20);
    
    while (!mouse_b)
    {
    clear(buffer);
    blit(bmp, buffer, 0, 0, 0, 0, bmp->w, bmp->h);
    if (mouse_y<128 && mouse_y>100) rect(buffer, 31, 100, 633, 128, makecol(255,255,0));
    if (mouse_y<160 && mouse_y>133) rect(buffer, 31, 133, 633, 160, makecol(255,255,0));
    if (mouse_y<192 && mouse_y>163) rect(buffer, 31, 163, 633, 192, makecol(255,255,0));
    if (mouse_y<392 && mouse_y>359) rect(buffer, 30, 359, 633, 392, makecol(255,255,0));
    acquire_screen();
    show_mouse(buffer);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    show_mouse(NULL);
    release_screen();
    }
    
    int chose=0;
    if (mouse_y<160 && mouse_y>133) chose=2; else
    if (mouse_y<128 && mouse_y>100) chose=1; else
    if (mouse_y<392 && mouse_y>359) Wyjscie=1;
    play_sample(klik, 255, 28, 1000, 0);
    highcolor_fade_out(15);
    return chose;
};

void O_Autorach_Screen()
{
     BITMAP *bmp;
     bmp=(BITMAP *)MyData[oAutorze].dat;
     highcolor_fade_in(bmp, 20);
     while (!mouse_b) {};
     highcolor_fade_out(20);
};

void DataBases_Screen()
{
     BITMAP *bmp, *buffer, *buffer2;
     bmp = (BITMAP *)MyData[BazyDanych].dat;
     buffer = (BITMAP *)MyData[BazyDanych].dat;
     highcolor_fade_in(bmp, 20);
     line(screen, 0, 40, 639, 40, 0);
     line(screen, 0, 27, 639, 27, 0);
     textprintf_ex(screen, font, 40, 30, 0, -1, "Baza Danych Speedway Manager");
     line(screen, 0, 60, 639, 60, 0);
     line(screen, 0, 73, 639, 73, 0);
     textprintf_ex(screen, font, 40, 63, 0, -1, "Druzyny znajdujace sie w Bazie Danych:");
     for (int i=0; i<8; i++)     
     textprintf_ex(screen, font, 40, 10*i+90, 0, -1, "%d. %s", i+1, BazaDanych.GetTeamName(i));
     blit(screen, buffer, 0, 0, 0, 0, screen->w, screen->h);
     buffer2 = create_bitmap(SCREEN_W, SCREEN_H);
     blit(buffer, buffer2, 0, 0, 0, 0, buffer->w, buffer->h);
     while (!mouse_b) 
     {
           acquire_screen();
           blit(buffer2, screen, 0, 0, 0, 0, buffer2->w, buffer2->h);
           blit(buffer2, buffer, 0, 0, 0, 0, buffer2->w, buffer2->h);
           if (mouse_y>90 && mouse_y<100)
           {   line(buffer, 40, 98, 230, 98, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[0]->itsPlayer[k]->GetImie());
           };
           if (mouse_y>100 && mouse_y<110)
           {   line(buffer, 40, 108, 230, 108, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[1]->itsPlayer[k]->GetImie());
           };
           if (mouse_y>110 && mouse_y<120)
           {   line(buffer, 40, 118, 230, 118, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[2]->itsPlayer[k]->GetImie());
           };
           if (mouse_y>120 && mouse_y<130) 
           {   line(buffer, 40, 128, 230, 128, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[3]->itsPlayer[k]->GetImie());
           };
           if (mouse_y>130 && mouse_y<140) 
           {   line(buffer, 40, 138, 230, 138, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[4]->itsPlayer[k]->GetImie());
           };
           if (mouse_y>140 && mouse_y<150)
           {   line(buffer, 40, 148, 230, 148, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[5]->itsPlayer[k]->GetImie());
                        };
           if (mouse_y>150 && mouse_y<160)
           {   line(buffer, 40, 158, 230, 158, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[6]->itsPlayer[k]->GetImie());
                        };
           if (mouse_y>160 && mouse_y<170)
           {   line(buffer, 40, 168, 230, 168, 0);
               for (int k=0; k<20; k++) textprintf_ex(buffer, font, 40, 10*k+200, 0, -1,
                        "%d. %s", k+1, BazaDanych.itsDruzyny[7]->itsPlayer[k]->GetImie());
                        };
           show_mouse(buffer);
           blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
           show_mouse(NULL);
           release_screen();
     };
     highcolor_fade_out(20);
};
     
void OptionsScreen()
{
     BITMAP *buffer, *bmp;
     FONT *f2;
     f2 = (FONT *)MyData[Font2].dat;
     buffer=create_bitmap(SCREEN_W, SCREEN_H);
     bmp=(BITMAP *)MyData[OptionScreen].dat;
     SAMPLE *klik = (SAMPLE *)MyData[Klik1].dat;
     textprintf_ex(bmp, f2, 40, 132, 0, -1, "Muzyka");
     textprintf_ex(bmp, f2, 40, 172, 0, -1, "Bazy Danych");
     textprintf_ex(bmp, f2, 40, 212, 0, -1, "O Autorach");
     textprintf_ex(bmp, f2, 40, 252, 0, -1, "Ilosc Graczy");
     textprintf_ex(bmp, f2, 215, 410, makecol(255,255,255), -1, "Back To Menu");
     highcolor_fade_in(bmp, 20);
     int choose = 0;
     do 
     {
         clear(buffer);
         blit(bmp, buffer, 0, 0, 0, 0, bmp->w, bmp->h);
         if (mouse_y>130 && mouse_y<160) { rect(buffer, 25, 130, 615, 160, makecol(255,255,0)); choose = 1; };
         if (mouse_y>170 && mouse_y<200) { rect(buffer, 25, 170, 615, 200, makecol(255,255,0)); choose = 2; };
         if (mouse_y>210 && mouse_y<240) { rect(buffer, 25, 210, 615, 240, makecol(255,255,0)); choose = 3; };
         if (mouse_y>250 && mouse_y<280) { rect(buffer, 25, 250, 615, 280, makecol(255,255,0)); choose = 4; };
         if (mouse_y>400 && mouse_y<450 && mouse_x>200 && mouse_x<400)
            rect(buffer, 200, 400, 400, 450, makecol(255,255,0));
         acquire_screen();
         show_mouse(buffer);
         blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h); 
         show_mouse(NULL);
         release_screen();
     } while (!mouse_b);
     switch (choose)
     {      case 1:  play_sample(Music, 255, 28, 1000, 1); 
                     break;
            case 3:  play_sample(klik, 255, 28, 1000, 0);
                     O_Autorach_Screen();
                     break;
            case 2:  play_sample(klik, 255, 28, 1000, 0);
                     DataBases_Screen();
                     break;
     };
};

void MainMenu()
{
     BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
     BITMAP *background;
     SAMPLE *klik;
     background=(BITMAP *)MyData[MainMenu1].dat;
     klik=(SAMPLE *)MyData[Klik1].dat;
     highcolor_fade_in(background, 20);
     
     while(!mouse_b)
     {
         clear(buffer);
         blit(background, buffer, 0, 0, 0, 0, background->w, background->h);
         if (mouse_y>115 && mouse_y<130) rect(buffer, 0, 115, 639, 130, makecol(0,255,0));
         if (mouse_y>140 && mouse_y<155) rect(buffer, 0, 140, 639, 155, makecol(0,255,0));
         if (mouse_y>190 && mouse_y<205) rect(buffer, 0, 190, 639, 205, makecol(0,255,0));
         if (mouse_y>400 && mouse_y<425 && mouse_x>50 && mouse_x<400) rect(buffer, 50, 400, 400, 425, makecol(0,255,0));
         acquire_screen();
         show_mouse(buffer);
         blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
         show_mouse(NULL);
         release_screen();
     };
     play_sample(klik, 255, 28, 1000, 0);
     highcolor_fade_out(20);
};
 
int main(void)
{
    Game_Initialize();
    MyData=load_datafile("data\\DataFile.dat");
    Title();
/*    BazaDanych.itsDruzyny[0]->itsPlayer[0]->SetImie("Miroslaw Kowalik");
    BazaDanych.itsDruzyny[0]->itsPlayer[1]->SetImie("Wieslaw Jagus");
    BazaDanych.itsDruzyny[0]->itsPlayer[2]->SetImie("Robert Kosciecha");
    BazaDanych.itsDruzyny[0]->itsPlayer[3]->SetImie("Karol Zabik");
    BazaDanych.itsDruzyny[0]->itsPlayer[4]->SetImie("Adrian Miedzinski");
    BazaDanych.itsDruzyny[0]->itsPlayer[5]->SetImie("Ryan Sullivan"); */
    while (Wyjscie!=1)
    {
          choose=MenuScreen();
          switch (choose)
          {
                 case 1: MainMenu();
                         break;
                 case 2: OptionsScreen();
                         break;
                 
                 default: choose=5;
                          continue;
          };
   };
    highcolor_fade_out(20);
    destroy_sample(Music);
    unload_datafile(MyData);
}; 
END_OF_MAIN();


