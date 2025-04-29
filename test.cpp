#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "funkcje.h" // Dołączamy plik nagłówkowy z funkcją generującą talię

using namespace std;

bool sprawdz_talie(const vector<string>& talia) {
    // Sprawdzenie czy talia ma 52 karty
    if (talia.size() != 52) {
        cout << "Błąd: Talia powinna mieć 52 karty, a ma " << talia.size() << endl;
        return false;
    }

    // Mapy do zliczania kart i kolorów
    unordered_map<char, int> kolory; // T, k, K, P
    unordered_map<string, int> wszystkie_karty;

    // Sprawdzenie każdej karty w talii
    for (const auto& karta : talia) {
        if (karta.length() < 2) {
            cout << "Błąd: Nieprawidłowy format karty: " << karta << endl;
            return false;
        }

        // Sprawdzenie koloru
        char kolor = karta.back();
        kolory[kolor]++;

        // Sprawdzenie wartości
        string wartosc = karta.substr(0, karta.length() - 1);
        wszystkie_karty[karta]++;
    }

    // Sprawdzenie czy są 4 kolory po 13 kart każdy
    const vector<char> oczekiwane_kolory = {'T', 'k', 'K', 'P'};
    for (const auto& kolor : oczekiwane_kolory) {
        if (kolory[kolor] != 13) {
            cout << "Błąd: Kolor " << kolor << " ma " << kolory[kolor] << " kart zamiast 13" << endl;
            return false;
        }
    }

    // Sprawdzenie czy każda karta występuje dokładnie raz
    for (const auto& [karta, ilosc] : wszystkie_karty) {
        if (ilosc != 1) {
            cout << "Błąd: Karta " << karta << " występuje " << ilosc << " razy" << endl;
            return false;
        }
    }

    cout << "Talia została poprawnie wygenerowana!" << endl;
    return true;
}

int main() {
    vector<string> talia;
    generacjatalii(talia); // Generujemy talię

    // Testujemy wygenerowaną talię
    if (!sprawdz_talie(talia)) {
        cerr << "TEST NIEUDANY: Talia niepoprawna!" << endl;
        return 1;
    }

    cout << "TEST UDANY: Talia poprawna!" << endl;
    return 0;
}