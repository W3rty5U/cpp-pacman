#include <iostream>
#include <fstream>
#include <istream>

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
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
    {MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,WOLNE,MUR,MUR},
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

void wypisz() {
    for(int i=0; i<MAX_ROZMIAR_MAPY; i++) {
        for(int j=0; j<MAX_ROZMIAR_MAPY; j++) {
            cout << (char)mapa[i][j];
        }
        cout << "\n";
    }
}

int main() {
    zapisz("mapa.txt");
    wczytaj("mapa.txt");
    wypisz();
    return 0;
}
