#include <iostream>

using namespace std;
#define zadanie2

#ifdef zadanie1

void wyswietlTablice(int* tablica)
{
	int rozmiar = tablica[-1];
	cout << "Tablica: ";
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}


int* alokujTablice(const int rozmiar)
{
	int* tablica = new int[rozmiar+1];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = 0;
	}
	tablica[-1] = rozmiar ;
	return tablica;
}

int* zmianaRozmiaruTalicy(int* adresRozmiaruTablicy, int nowyRozmiar)
{
	if (nowyRozmiar == adresRozmiaruTablicy[-1])
	{
		return adresRozmiaruTablicy;
	}
	else if (nowyRozmiar <= 0)
	{
		delete[](adresRozmiaruTablicy - 1);
		adresRozmiaruTablicy = nullptr;
		return adresRozmiaruTablicy;
	}
	else
	{
		int r = (nowyRozmiar < adresRozmiaruTablicy[-1]) ? nowyRozmiar : adresRozmiaruTablicy[-1];
		int* nowa_tablica = new int[r + 1];
		for (int i = 0; i < r + 1; i++)
		{
			nowa_tablica[i] = 0;
		}
		int* temp = nowa_tablica;
		temp[0] = r;
		temp += 1;
		memcpy(temp, adresRozmiaruTablicy, r);
		delete[](adresRozmiaruTablicy + 1);
		return temp;
	}
}

int zwolnijTablice(int* tablica) 
{
	delete[] tablica;
	tablica = nullptr;
	return 0;
}



int main()
{
	
	int rozmiar;

	cout << "Podaj poczatkowy rozmiar tablicy: ";
	cin >> rozmiar;

	if (rozmiar <= 0)
	{
		cout << "Podano nieprawidlowy rozmiar tablicy." << endl;
		return 1;
	}

	int* tablica = alokujTablice(rozmiar);

	cout << "Wypelnij tablice kolejnymi liczbami naturalnymi (koniec - 0): " << endl;
	int liczba;
	cin >> liczba;
	int i = 0;
	while (liczba != 0 && i < rozmiar)
	{
		tablica[i] = liczba;
		i++;
		cin >> liczba;
	}

	wyswietlTablice(tablica);

	cout << "Podaj nowy rozmiar tablicy: ";
	cin >> rozmiar;

	if (rozmiar <= 0)
	{
		cout << "Podano nieprawidlowy rozmiar tablicy." << endl;
		zwolnijTablice(tablica);
		return 1;
	}

	tablica = zmianaRozmiaruTalicy(tablica,rozmiar);

	wyswietlTablice(tablica);

	zwolnijTablice(tablica);

	return 0;

}
#endif

#ifdef zadanie2

int** alokacjaCiagła(int** tab, int stareWiersze, int stareKolumny, int noweWiersze, int noweKolumny) {

	if (noweWiersze == 0) {
		for (int i = 0; i < stareKolumny; i++) {
			delete[] tab[i];
		}
		delete[] tab;
		return nullptr;
	}

	int** tablica = new int* [noweWiersze];
	for (int i = 0; i < noweWiersze; i++) {
		tablica[i] = new int[noweKolumny];
	}


	for (int i = 0; i < min(stareWiersze, noweWiersze); i++) {
		for (int j = 0; j < min(stareKolumny, noweKolumny); j++) {
			tablica[i][j] = tab[i][j];
		}
	}

	if (noweWiersze > stareKolumny) {
		for (int i = 0; i < min(stareWiersze, noweWiersze); i++) {
			for (int j = stareKolumny; j < noweKolumny; j++) {
				tablica[i][j] = 0;
			}
		}
	}

	if (noweWiersze > stareWiersze) {
		for (int i = stareWiersze; i < noweWiersze; i++) {
			for (int j = 0; j < noweKolumny; j++) {
				tablica[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < stareWiersze; i++) {
		delete[] tab[i];
	}
	delete[] tab;

	return tablica;
}


int main(){

	const int wiersze = 3;
	const int kolumny = 5;
	int tab[wiersze][kolumny] = {};

	for (size_t i = 0; i < wiersze; i++)
	{
		for (size_t j= 0; j < kolumny; j++)
		{
			tab[i][j] = i + j;
		}
	}


	for (size_t i = 0; i < wiersze; i++)
	{
		for (size_t j = 0; j < kolumny; j++)
		{
			cout << tab[i][j]<<" ";
		}
		cout << endl;
	}

	alokacjaCiagła(tab, wiersze, kolumny, 3, 3);

	for (size_t i = 0; i < wiersze; i++)
	{
		for (size_t j = 0; j < kolumny; j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}



}



#endif 

