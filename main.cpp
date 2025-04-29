#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include "funkcje.h"

using namespace std;

vector<string> talia;
vector<int> indeksy;
vector<string> potasowanatalia;
vector<string> rekagracz;
vector<string> rekakomputer;
vector<string> stosyg;
vector<string> stosyk;

int main() {
    vector<string> talia;
    generacjatalii(talia);

    vector<int> indeksy;
    vector<string> potasowanatalia;
    vector<string> rekagracz;
    vector<string> rekakomputer;
    vector<string> stosyg;
    vector<string> stosyk;

    potasowanatalia.resize(0);
    while (indeksy.size() < 52) {// hehe tasujemy talie brrrrrr lol
        int losowyint =  rand() % 52;
        bool wykryto=false;
        for (int i = 0; i < indeksy.size(); i++) {
            if (indeksy[i] == losowyint) {
                wykryto = true;
            }
        }
        if (!wykryto) {
            indeksy.push_back(losowyint);
        }
    }
    for (int i=0; i<indeksy.size(); i++) {
        potasowanatalia.push_back(talia[indeksy[i]]);
    }

    // rozdanie kart na reke gracza
    for (int i = 0; i < 7; i++) {
        rekagracz.push_back(potasowanatalia[i]);
    }
    for (int i = 0; i < 7; i++) {
        potasowanatalia.erase(potasowanatalia.begin());
    }
    // rozdanie kart na reke komputera
    for (int i = 0; i < 7; i++) {
        rekakomputer.push_back(potasowanatalia[i]);
    }
    for (int i = 0; i < 7; i++) {
        potasowanatalia.erase(potasowanatalia.begin());
    }


    //gra:
    int d = 0;
    int gra = 0;
    int stosyki = 0;
    int stosygi = 0;
    char szukanag;
    char szukanak;
    int dobrakarta;
    bool znaleziono = false;
    int tura = 0;
    while (gra==0) {
        //sprawdzanie stosów przed grą
        unordered_map<char, int> policzone;
            for (const auto& str : rekakomputer) {
                if (!str.empty()) {
                    char karta = str[0];
                    policzone[karta]++;
                }
            }

            for (const auto& entry : policzone) {
                if (entry.second >= 4) {
                stosyki++;
                    for (auto it = rekakomputer.begin(); it != rekakomputer.end();) {
                        if (it->at(0) == entry.first) {
                            stosyg.push_back(*it);
                            it = rekakomputer.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }
            policzone.clear();
            for (const auto& str : rekagracz) {
                if (!str.empty()) {
                    char karta = str[0];
                    policzone[karta]++;
                }
            }

            for (const auto& entry : policzone) {
                if (entry.second >= 4) {
                stosygi++;
                    for (auto it = rekagracz.begin(); it != rekagracz.end();) {
                        if (it->at(0) == entry.first) {
                            stosyg.push_back(*it);
                            it = rekagracz.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }
            policzone.clear();


        //tura gacza
        while(tura == 0){
            cout<< "Stosy komputera: "<<stosyki<< endl;
            cout<< "Twoje karty: ";
            for (int i = 0; i < rekagracz.size(); i++) {
                cout << rekagracz[i]<< " ";
            }
            if (stosygi >0){
                cout << " + "<<stosygi<<" stosy";
            }
            cout<<endl<<"Pytaj o: ";




            //sprawdzanie czy posiada się tą kartę na ręce
            dobrakarta = 0;
            while (dobrakarta == 0){
                cin >> szukanag;
                for (const auto& str : rekagracz) {
                    if (!str.empty() && str[0] == szukanag) {
                        dobrakarta = 1;
                    }
                }
                if (dobrakarta == -0) {
                cout << "Nie posiadzasz podanej karty! Wybierz inną:";
                }
            }


            //szukanie kart
            znaleziono = false;
            for (auto it = rekakomputer.begin(); it != rekakomputer.end(); ) {
                if (!it->empty() && it->at(0) == szukanag) {
                    cout << "Komputer przekazuje Ci: " << *it << "\n";
                    rekagracz.push_back(*it);
                    it = rekakomputer.erase(it);
                    znaleziono = true;
                } else {
                 ++it;
            }

            }
            if (!znaleziono) {
                cout << "Komputer: nie mam!"<< endl;
                tura = 1;
                rekagracz.push_back(potasowanatalia[0]);
                potasowanatalia.erase(potasowanatalia.begin());
            }
            if (potasowanatalia.empty()){
                gra=1;
            }
            cout << endl;
            //sprawdzanie stosó po turze
            unordered_map<char, int> policzone;
            for (const auto& str : rekagracz) {
                if (!str.empty()) {
                    char karta = str[0];
                    policzone[karta]++;
                }
            }

            for (const auto& entry : policzone) {
                if (entry.second >= 4) {
                stosygi++;
                    for (auto it = rekagracz.begin(); it != rekagracz.end();) {
                        if (it->at(0) == entry.first) {
                            stosyg.push_back(*it);
                            it = rekagracz.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }
            policzone.clear();

        }




        //tura komputera
        while (tura == 1){
            cout<< "Stosy komputera: "<<stosyki<< endl;
            cout<< "Twoje karty: ";
            for (int i = 0; i < rekagracz.size(); i++) {
                cout << rekagracz[i]<< " ";
            }
            if (stosygi >0){
                cout << " + "<<stosygi<<" stosy";
            }
            cout<<endl;


            //pytanie o kartę
            szukanak = rekakomputer[0+d][0];
            cout<<"Komputer pyta się o:"<<szukanak<<endl;
            znaleziono = false;
            for (auto it = rekagracz.begin(); it != rekagracz.end(); ) {
                if (!it->empty() && it->at(0) == szukanak) {
                    cout << "Komputer zabiera " << *it << "\n";
                    rekakomputer.push_back(*it);
                    it = rekagracz.erase(it);
                    znaleziono = true;
                } else {
                 ++it;
            }
            if (znaleziono== true){
                d++;
            }
            }
            if (!znaleziono) {
                cout << "Nie posiadasz tej kartyw  swojej talii!"<< endl;
                tura = 0;
                d = 0;
                rekakomputer.push_back(potasowanatalia[0]);
                potasowanatalia.erase(potasowanatalia.begin());
            }
            if (potasowanatalia.empty()){
                gra=1;
            }
            cout << endl;




            //sprawdzanie stosów
            unordered_map<char, int> policzone;
            for (const auto& str : rekakomputer) {
                if (!str.empty()) {
                    char karta = str[0];
                    policzone[karta]++;
                }
            }

            for (const auto& entry : policzone) {
                if (entry.second >= 4) {
                stosyki++;
                    for (auto it = rekakomputer.begin(); it != rekakomputer.end();) {
                        if (it->at(0) == entry.first) {
                            stosyg.push_back(*it);
                            it = rekakomputer.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }
            policzone.clear();
        }
    }
    cout<<"Talia się skończyła!";
    if (stosygi>stosyki){
        cout<< "Wygrywa Gracz!!!";
    }else if	(stosygi<stosyki){
        cout<< "Wygrywa Komputer!!!";
    }else{
        cout<<"Remis";
    }
    return 0;
}

