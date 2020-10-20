#include <iostream>
#include <fstream>
#include <istream>
#include <windows.h>
#include <time.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESCAPE 27
#define WOLNE 32
#define MUR 178
#define GRACZ 94
#define POINT_1 186
#define POINT_2 187

#define GORA 1
#define DOL 2
#define LEWO 3
#define PRAWO 4

const int MAX_ROZMIAR_MAPY = 20;
const int ROZMIAR_MAPY_X = 20;
const int ROZMIAR_MAPY_Y = 20;
const int MAPA[MAX_ROZMIAR_MAPY][MAX_ROZMIAR_MAPY] = {
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE},
  {WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE,WOLNE}
};
int mapa[MAX_ROZMIAR_MAPY][MAX_ROZMIAR_MAPY];
int rozmiarX, rozmiarY;
int punkty[10][2];

void zapisz(string nazwa_pliku) {
  ofstream plik(nazwa_pliku);
  if(plik.good()) {
    plik << ROZMIAR_MAPY_X << " " << endl;
    plik << ROZMIAR_MAPY_Y << " " << endl;
    for(int i=0; i<ROZMIAR_MAPY_Y; i++) {
      for(int j=0; j<ROZMIAR_MAPY_X; j++) {
        plik << MAPA[i][j] << " ";
      }
      plik << endl;
    }
    plik.close();
  }
  else {
    cout << "Nie mozna uzyskac dostepu do pliku.";
  }
}

void rozmiescPunkty(int pozX, int pozY) {
  for(int i=0; i<10; i++) {
    do {
      punkty[i][0] = rand() % rozmiarX;
      punkty[i][1] = rand() % rozmiarY;
    } while(mapa[punkty[i][1]][punkty[i][0]]!=WOLNE && punkty[i][0]==pozX && punkty[i][1]==pozY);
  }
}

void wczytaj(string nazwa_pliku) {
  string sData, x, y;
  ifstream plik(nazwa_pliku);
  plik >> x >> y;
  rozmiarX = stoi(x);
  rozmiarY = stoi(y);
  for(int i=0; i<stoi(y); i++) {
    for(int j=0; j<stoi(x); j++) {
      plik >> sData;
      mapa[i][j] = stoi(sData);
    }
  }
  plik.close();
}

void wypisz(int pozX, int pozY) {
  static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  cout.flush();
  COORD coord = {0, 0};
  SetConsoleCursorPosition(hOut, coord);
  for(int i=0; i<MAX_ROZMIAR_MAPY; i++) {
    for(int j=0; j<MAX_ROZMIAR_MAPY; j++) {
      if(pozX==j && pozY==i) {
        cout << (char)GRACZ;
      }
      else {
        for(int a=0; a<10; a++) {
          if(j==punkty[a][0] && i==punkty[a][1]) cout << (char)POINT_1;
          else cout << (char)mapa[i][j];
        }
      }
    }
    cout << endl;
  }
}

bool sprawdzMape(int pozX, int pozY, int kierunek) {
  switch(kierunek) {
    case GORA:
      if(mapa[pozY-1][pozX]==WOLNE && pozY>0) {
        return true;
      }
      break;
    case DOL:
      if(mapa[pozY+1][pozX]==WOLNE && pozY<rozmiarY-1) {
        return true;
      }
      break;
    case LEWO:
      if(mapa[pozY][pozX-1]==WOLNE && pozX>0) {
        return true;
      }
      break;
    case PRAWO:
      if(mapa[pozY][pozX+1]==WOLNE && pozX<rozmiarX-1) {
        return true;
      }
      break;
  }
  return false;
}



int main() {
  srand(time(NULL));
  int pozycjaX = 1;
  int pozycjaY = 1;
  bool czyGra = true;
  bool czyZmiana = true;
  rozmiescPunkty(pozycjaX, pozycjaY);

  zapisz("mapa.txt");
  wczytaj("mapa.txt");
  system("color a");
  wypisz(pozycjaX, pozycjaY);

  while(czyGra) {
    if(GetAsyncKeyState(VK_ESCAPE)) {
      czyGra = false;
    }//if(GetAsyncKeyState(VK_ESCAPE))
    if(GetAsyncKeyState(VK_DOWN)) {
      if(sprawdzMape(pozycjaX, pozycjaY, DOL)) {
        pozycjaY++;
        czyZmiana = true;
      }
    }//if(GetAsyncKeyState(VK_DOWN))
    if(GetAsyncKeyState(VK_UP)) {
      if(sprawdzMape(pozycjaX, pozycjaY, GORA)) {
        pozycjaY--;
        czyZmiana = true;
      }
    }//if(GetAsyncKeyState(VK_UP))
    else if(GetAsyncKeyState(VK_RIGHT)) {
      if(sprawdzMape(pozycjaX, pozycjaY, PRAWO)) {
        pozycjaX++;
        czyZmiana = true;
      }
    }//if(GetAsyncKeyState(VK_RIGHT))
    if(GetAsyncKeyState(VK_LEFT)) {
      if(sprawdzMape(pozycjaX, pozycjaY, LEWO)) {
        pozycjaX--;
        czyZmiana = true;
      }
    }//if(GetAsyncKeyState(VK_LEFT))
    if(czyZmiana) {
      wypisz(pozycjaX, pozycjaY);
      czyZmiana = false;
    }//if(czyZmiana)
    Sleep(67);
  }//while(czyGra)
  return 0;
}
