#include "funkcje.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void generacjatalii(vector<string>& talia) {
    srand(std::time(0));
    vector<int> trefl;
    vector<int> karo;
    vector<int> kier;
    vector<int> pik;
    while (trefl.size() < 13) {//trefl
        int losowyint = 2 + rand() % 13;
        bool wykryto=false;
        for (int i = 0; i < trefl.size(); i++) {
            if (trefl[i] == losowyint) {
                wykryto = true;
            }
        }
        if (!wykryto) {
            trefl.push_back(losowyint);
        }
    }
    while (karo.size() < 13) {//karo
        int losowyint = 2 + rand() % 13;
        bool wykryto=false;
        for (int i = 0; i < karo.size(); i++) {
            if (karo[i] == losowyint) {
                wykryto = true;
            }
        }
        if (!wykryto) {
            karo.push_back(losowyint);
        }
    }
    while (kier.size() < 13) {//kier
        int losowyint = 2 + rand() % 13;
        bool wykryto=false;
        for (int i = 0; i < kier.size(); i++) {
            if (kier[i] == losowyint) {
                wykryto = true;
            }
        }
        if (!wykryto) {
            kier.push_back(losowyint);
        }
    }
    while (pik.size() < 13) {//pik
        int losowyint = 2 + rand() % 13;
        bool wykryto=false;
        for (int i = 0; i < pik.size(); i++) {
            if (pik[i] == losowyint) {
                wykryto = true;
            }
        }
        if (!wykryto) {
            pik.push_back(losowyint);
        }
    }
    for (int i = 0; i < trefl.size(); i++) {
        //trefl do talii
        if (trefl[i] == 11) {
            talia.push_back("JT");
        }
        if (trefl[i] == 12) {
            talia.push_back("DT");
        }
        if (trefl[i] == 13) {
            talia.push_back("KT");
        }
        if (trefl[i] == 14) {
            talia.push_back("AT");
        }
        if (trefl[i]>1 && trefl[i]<11){
            talia.push_back(to_string(trefl[i])+"T");
        }
    }
    for (int i = 0; i < karo.size(); i++) {//karo do talii
        if (karo[i] == 11) {
            talia.push_back("Jk");
        }
        if (karo[i] == 12) {
            talia.push_back("Dk");
        }
        if (karo[i] == 13) {
            talia.push_back("Kk");
        }
        if (karo[i] == 14) {
            talia.push_back("Ak");
        }
        if (karo[i]>1 && karo[i]<11){
            talia.push_back(to_string(karo[i])+"k");
        }
    }
    for (int i = 0; i < kier.size(); i++) {//kier do talii
        if (kier[i] == 11) {
            talia.push_back("JK");
        }
        if (kier[i] == 12) {
            talia.push_back("DK");
        }
        if (kier[i] == 13) {
            talia.push_back("KK");
        }
        if (kier[i] == 14) {
            talia.push_back("AK");
        }
        if (kier[i]>1 && kier[i]<11){
            talia.push_back(to_string(kier[i])+"K");
        }
    }
    for (int i = 0; i < pik.size(); i++) {//pik do talii
        if (pik[i] == 11) {
            talia.push_back("JP");
        }
        if (pik[i] == 12) {
            talia.push_back("DP");
        }
        if (pik[i] == 13) {
            talia.push_back("KP");
        }
        if (pik[i] == 14) {
            talia.push_back("AP");
        }
        if (pik[i]>1 && pik[i]<11){
            talia.push_back(to_string(pik[i])+"P");
        }
    }
}