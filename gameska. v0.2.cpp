#include <iostream>
#include <string>

using namespace std;

// Struktura hráče - drží všechny statistiky a info
struct Player {
    string className;
    int maxHP;
    int currentHP;
    int maxMana;
    int currentMana;
    int attack;
    int gold;
    int level;
    int exp;
    int bullets;
};

//  Funkce pro pauzu - čeká na ENTER, než se pokračuje dál
void waitForEnter() {
    cout << "Pokračuj stiskem klávesy..." << endl;
    cin.ignore();
    cin.get();
}

//  Hlavní funkce pro pohyb po mapě
void travel(Player &hrac) {
    const int totalLocations = 17;  //Celkový počet lokací
    for (int location = 1; location <= totalLocations; ++location) {
        cout << endl << "Lokace " << location << ": ";

        // vesnice
        if (location == 1 || location == 4 || location == 7 || location == 11 || location == 14 || location == 16) {
            cout << "Vesnice " << ((location + 2) / 3) << endl;
            cout << "Odpočíváš ve vesnici. Zdraví, mana a náboje doplněny." << endl;

            hrac.currentHP = hrac.maxHP;
            hrac.currentMana = hrac.maxMana;
            hrac.bullets = (hrac.className == "Pistolnik") ? 6 : hrac.bullets;
        }
        // Fighty
        else {
            if (location == 5 || location == 10 || location == 15) {
                cout << "Souboj se dvěma enemáky!" << endl;
            }
            else if (location == 6 || location == 12) {
                cout << "MiniBoss Fight!" << endl;
            }
            else if (location == 17) {
                cout << "Finální boss fight!" << endl;
            }
            else {
                cout << "Souboj s nepřítelem." << endl;
            }

            // Placeholder =budouci scryptpro fight
            cout << "(placeholder pro souboj)" << endl;
        }

        waitForEnter();
    }
}

// Funkce pro výpis schopností podle classy
void vypisSchopnosti(const Player &hrac) {
    if (hrac.className == "Mag") {
        cout << "Schopnosti: Fireball - 5 dmg, Ledove kouzlo - 3 dmg + zpomaleni" << endl;
    } else if (hrac.className == "Assassin") {
        cout << "Schopnosti: Kriticky uder (2x dmg), Uhni! (50% sance na vyhnuti)" << endl;
    } else if (hrac.className == "Warrior") {
        cout << "Schopnosti: Silovy utok - 4 dmg, Nahod si stit" << endl;
    } else if (hrac.className == "Pistolnik") {
        cout << "Schopnosti: Zamireni (3x dmg na dalsi utok), Vystrel - 4 dmg" << endl;
    } else if (hrac.className == "Gambler") {
        cout << "Schopnosti: Hod kostkou (1 - 6 dmg nebo samoskoda), Sazka" << endl;
    }
}

// Main - začátek hry, výběr classy, start mapy
int main() {
    Player hrac;  //  Proměnná hráče

    int choice;
    bool confirmed = false;

    while (!confirmed) {
        cout << "Vyber si classu:" << endl;
        cout << "1) Mag" << endl;
        cout << "2) Assassin" << endl;
        cout << "3) Warrior" << endl;
        cout << "4) Pistolnik" << endl;
        cout << "5) Gambler" << endl;
        cout << "Zadej cislo classy: ";
        cin >> choice;

        // Nastavení classy
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
            cout << "Neplatna volba, zkus to znovu." << endl;
            continue;
        }

        //  dalsi
        hrac.currentHP = hrac.maxHP;
        hrac.currentMana = hrac.maxMana;
        hrac.gold = 3;
        hrac.level = 1;
        hrac.exp = 0;

        cout << "Zvolena classa: " << hrac.className << endl;
        cout << "Staty: " << hrac.maxHP << " HP, " << hrac.maxMana << " Mana, " << hrac.attack << " Utok" << endl;
        if (hrac.className == "Pistolnik") {
            cout << "Naboje: " << hrac.bullets << endl;
        }

        vypisSchopnosti(hrac);  //Výpis schopností

        char confirm;
        cout << "Chces tuto classu? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            confirmed = true;
        } else {
            cout << "OK, vyber jinou classu." << endl;
        }
    }

    cout << endl << "Hra zacina..." << endl;
    travel(hrac);  // Spuštění cesty mapou

    return 0;
}
