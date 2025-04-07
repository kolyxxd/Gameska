#include <iostream>
#include <string>

using namespace std;

struct Player {      //delam prakticky novej int ketrej ma v sobe vsechny ostatni
    string className;
    int maxHP;
    int currentHP;
    int maxMana;
    int currentMana;
    int attack;
    int gold;
    int level;
    int exp;
    int bullets;  // Náboje pro pistolníka
};

int main() {
    Player hrac;  // Promìnná hráèe

    int choice;
    bool confirmed = false;

    while (confirmed == false) {
        cout << "Vyber si classu:" << endl;
        cout << "1) Mag" << endl;
        cout << "2) Assassin" << endl;
        cout << "3) Warrior" << endl;
        cout << "4) Pistolnik" << endl;
        cout << "5) Gambler" << endl;
        cout << "Zadej cislo classy: ";
        cin >> choice;

        if (choice == 1) {
            hrac.className = "Mag";
            hrac.maxHP = 3;
            hrac.maxMana = 10;
            hrac.attack = 2;
            hrac.bullets = 0;
        } else if (choice == 2) {
            hrac.className = "Assassin";
            hrac.maxHP = 5;
            hrac.maxMana = 5;
            hrac.attack = 3;
            hrac.bullets = 0;
        } else if (choice == 3) {
            hrac.className = "Warrior";
            hrac.maxHP = 8;
            hrac.maxMana = 3;
            hrac.attack = 2;
            hrac.bullets = 0;
        } else if (choice == 4) {
            hrac.className = "Pistolnik";
            hrac.maxHP = 5;
            hrac.maxMana = 5;
            hrac.attack = 2;
            hrac.bullets = 6;
        } else if (choice == 5) {
            hrac.className = "Gambler";
            hrac.maxHP = 4;
            hrac.maxMana = 6;
            hrac.attack = 2;
            hrac.bullets = 0;
        } else {
            cout << "Neplatna volba, zkuste to znova." << endl;
            continue;  // Pokud volba není platná, pokraèujeme v cyklu
        }

        hrac.currentHP = hrac.maxHP;
        hrac.currentMana = hrac.maxMana;
        hrac.gold = 3;
        hrac.level = 1;
        hrac.exp = 0;

        cout << "Zvolena classa: " << hrac.className << endl;
        if (hrac.className == "Mag") {
            cout << "Zivoty: 3/3, Mana: 10/10, Utok: 2" << endl;
            cout << "Schopnosti: Fireball - 5 dmg, Ledove kouzlo - 3 dmg + zpomaleni" << endl;
        } else if (hrac.className == "Assassin") {
            cout << "Zivoty: 5/5, Mana: 5/5, Utok: 3" << endl;
            cout << "Schopnosti: Kriticky uder (2x dmg), Uhni! (50% sance na vyhnuti)" << endl;
        } else if (hrac.className == "Warrior") {
            cout << "Zivoty: 8/8, Mana: 3/3, Utok: 2" << endl;
            cout << "Schopnosti: Silovy utok - 4 dmg, Nahod si stit" << endl;
        } else if (hrac.className == "Pistolnik") {
            cout << "Zivoty: 5/5, Naboje: 6/6, Utok: 2" << endl;
            cout << "Schopnosti: Zamireni (3x dmg na dalsi utok), Vystrel - 4 dmg" << endl;
        } else if (hrac.className == "Gambler") {
            cout << "Zivoty: 4/4, Mana: 6/6, Utok: 2" << endl;
            cout << "Schopnosti: Hod kostkou (1 - 6 dmg nebo samoskoda), Sazka" << endl;
        }

        char confirm;
        cout << "Chces tuto classu? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            confirmed = true;  // Hráè potvrdil volbu
        } else {
            cout << "Vyber jinou classu." << endl;
        }
    }

    cout << "Hra zacina..." << endl;
    // TODO: Pøidat souboje, mapu,boss,vesnice.shop,buffy debuffy, a ty vole kolik toho je  atd.

    return 0;
}
