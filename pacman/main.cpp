#include <iostream>
#include <fstream>
#include <istream>
#include <windows.h>

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

const int MAX_ROZMIAR_MAPY = 20;
const int ROZMIAR_MAPY_X = 20;
const int ROZMIAR_MAPY_Y = 20;
const int MAPA[MAX_ROZMIAR_MAPY][MAX_ROZMIAR_MAPY] = {
    {MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,WOLNE,WOLNE,MUR,WOLNE,WOLNE,WOLNE,MUR,WOLNE,WOLNE,WOLNE,MUR,WOLNE,WOLNE,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,WOLNE,WOLNE,MUR,WOLNE,WOLNE,WOLNE,MUR,WOLNE,WOLNE,WOLNE,MUR,WOLNE,WOLNE,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR,MUR}
};
int mapa[MAX_ROZMIAR_MAPY][MAX_ROZMIAR_MAPY];

void zapisz(char* nazwa_pliku) {
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

void wczytaj(char* nazwa_pliku) {
    string sData, x, y;
    ifstream plik(nazwa_pliku);
    plik >> x >> y;
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
                cout << (char)mapa[i][j];
            }
        }
        cout << endl;
    }
}


int main() {
    int pozycjaX = 1;
    int pozycjaY = 1;
    bool czyGra = true;
    bool czyZmiana = true;

    zapisz("mapa.txt");
    wczytaj("mapa.txt");
    system("color f");
    wypisz(pozycjaX, pozycjaY);

    while(czyGra) {
        if(GetAsyncKeyState(VK_ESCAPE)) {
            czyGra = false;
        }//if(GetAsyncKeyState(VK_ESCAPE))
        if(GetAsyncKeyState(VK_DOWN)) {
            if(mapa[pozycjaY+1][pozycjaX] != MUR) {
                pozycjaY++;
                czyZmiana = true;
            }
        }//if(GetAsyncKeyState(VK_DOWN))
        if(GetAsyncKeyState(VK_UP)) {
            if(mapa[pozycjaY-1][pozycjaX] != MUR) {
                pozycjaY--;
                czyZmiana = true;
            }
        }//if(GetAsyncKeyState(VK_UP))
        else if(GetAsyncKeyState(VK_RIGHT)) {
            if(mapa[pozycjaY][pozycjaX+1] != MUR) {
                pozycjaX++;
                czyZmiana = true;
            }
        }//if(GetAsyncKeyState(VK_RIGHT))
        if(GetAsyncKeyState(VK_LEFT)) {
            if(mapa[pozycjaY][pozycjaX-1] != MUR) {
                pozycjaX--;
                czyZmiana = true;
            }
        }//if(GetAsyncKeyState(VK_LEFT))
        else if(czyZmiana) {
            wypisz(pozycjaX, pozycjaY);
            czyZmiana = false;
        }//if(czyZmiana)
        Sleep(33);
    }//while(czyGra)
    return 0;
}
