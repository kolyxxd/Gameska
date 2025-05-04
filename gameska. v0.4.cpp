#include <iostream>
#include <string>

using namespace std;

// struckt pro hrace
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

//  pauza :3
void waitForEnter() {
    cout << "Pokracuj stiskem klavesy..." << endl;
    cin.ignore();
    cin.get();
}
// Placeholder pro predmety
void useItem(Player &player) {
    cout << "(Pouziti predmetu zatim nedostupne)" << endl;
}

// Fight se dvema bandity
void fightTwoBandits(Player &player) {
    int bandit1HP = 6;
    int bandit2HP = 6;
    int banditDMG = 3;

    while (player.currentHP > 0 && (bandit1HP > 0 || bandit2HP > 0)) {
        cout << "Bandita 1: " << bandit1HP << " HP, Bandita 2: " << bandit2HP << " HP" << endl;
        cout << "Vyber cil (1/2): ";
        int target;
        cin >> target;

        if (target == 1 && bandit1HP > 0) {
            bandit1HP -= player.attack;
            cout << "Zasahujes Banditu 1 za " << player.attack << " DMG." << endl;
        } else if (target == 2 && bandit2HP > 0) {
            bandit2HP -= player.attack;
            cout << "Zasahujes Banditu 2 za " << player.attack << " DMG." << endl;
        } else {
            cout << "Neplatny cil!" << endl;
            continue;
        }

        if (bandit1HP > 0) {
            player.currentHP -= banditDMG;
            player.gold = max(0, player.gold - 1);
            cout << "Bandita 1 te zasahuje za " << banditDMG << " DMG a krade 1 zlato!" << endl;
        }
        if (bandit2HP > 0) {
            player.currentHP -= banditDMG;
            player.gold = max(0, player.gold - 1);
            cout << "Bandita 2 te zasahuje za " << banditDMG << " DMG a krade 1 zlato!" << endl;
        }

        cout << "Tvoje HP: " << player.currentHP << ", Zlato: " << player.gold << endl;
        waitForEnter();
    }

    if (player.currentHP <= 0) {
        cout << "Byl jsi porazen!" << endl;
        exit(0);
    } else {
        cout << "Vyhral jsi nad obema bandity!" << endl;
    }
}

// Fight s harpii
void fightHarpy(Player &player) {
    int harpyHP = 10;
    int harpyDMG = 3;

    while (player.currentHP > 0 && harpyHP > 0) {
        cout << "Harpie: " << harpyHP << " HP" << endl;

        int damage = player.attack / 2;
        cout << "Zasahujes harpii za " << damage << " DMG." << endl;
        harpyHP -= damage;

        if (harpyHP > 0) {
            player.currentHP -= harpyDMG;
            cout << "Harpie te zasahuje za " << harpyDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << player.currentHP << endl;
        waitForEnter();
    }

    if (player.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi harpii!" << endl;
    }
}

// Fight rytir + healer
void fightKnightAndHealer(Player &player) {
    int knightHP = 15;
    int healerHP = 8;
    int knightDMG = 5;
    int healerDMG = 2;
    int round = 1;

    while (player.currentHP > 0 && (knightHP > 0 || healerHP > 0)) {
        cout << "Rytir: " << knightHP << " HP, Healer: " << healerHP << " HP" << endl;
        cout << "Vyber cil (1 = Rytir, 2 = Healer): ";
        int target;
        cin >> target;

        if (target == 1 && knightHP > 0) {
            knightHP -= player.attack;
            cout << "Zasahujes Rytire za " << player.attack << " DMG." << endl;
        } else if (target == 2 && healerHP > 0) {
            healerHP -= player.attack;
            cout << "Zasahujes Healera za " << player.attack << " DMG." << endl;
        } else {
            cout << "Neplatny cil!" << endl;
            continue;
        }

        if (healerHP > 0 && (round % 3 == 0) && knightHP > 0) {
            knightHP += 3;
            cout << "Healer leci Rytire za 3 HP!" << endl;
        }

        if (knightHP > 0) {
            player.currentHP -= knightDMG;
            cout << "Rytir te zasahuje za " << knightDMG << " DMG." << endl;
        }
        if (healerHP > 0) {
            player.currentHP -= healerDMG;
            cout << "Healer te zasahuje za " << healerDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << player.currentHP << endl;
        waitForEnter();
        round++;
    }

    if (player.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi nepratele!" << endl;
    }
}

// Fight miniboss
void fightMiniBoss(Player &player) {
    int bossHP = 12;
    int bossDMG = 4;

    cout << "MiniBoss ti zablokoval schopnosti!" << endl;

    while (player.currentHP > 0 && bossHP > 0) {
        cout << "MiniBoss: " << bossHP << " HP" << endl;
        bossHP -= player.attack;
        cout << "Zasahujes MiniBosse za " << player.attack << " DMG." << endl;

        if (bossHP > 0) {
            player.currentHP -= bossDMG;
            cout << "MiniBoss te zasahuje za " << bossDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << player.currentHP << endl;
        waitForEnter();
    }

    if (player.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi MiniBosse!" << endl;
    }
}


//  mapa a pohyb
void travel(Player &hrac) {
    const int totalLocations = 17;  //Celkovy pocet lokaci
    for (int location = 1; location <= totalLocations; ++location) {
        cout << endl << "Lokace " << location << ": ";

        // vesnice
        if (location == 1 || location == 4 || location == 7 || location == 11 || location == 14 || location == 16) {
            cout << "Vesnice " << ((location + 2) / 3) << endl;
            cout << "Odpocivas ve vesnici. Zdravi, mana a naboje doplneny." << endl;

            hrac.currentHP = hrac.maxHP;
            hrac.currentMana = hrac.maxMana;
            hrac.bullets = (hrac.className == "Pistolnik") ? 6 : hrac.bullets;
        }
        // Fighty
        else {
            if (location == 5 || location == 10 || location == 15) {
                cout << "Souboj se dvema enemaky!" << endl;
            }
            else if (location == 6 || location == 12) {
                cout << "MiniBoss Fight!" << endl;
            }
            else if (location == 17) {
                cout << "Finalni boss fight!" << endl;
            }
            else {
                cout << "Souboj s nepritelem." << endl;
            }

            // Placeholder = budouci scrypt pro fight
            cout << "(placeholder pro souboj)" << endl;
        }

        waitForEnter();
    }
}

// Funkce pro vypis schopnosti podle classy
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

// Main - zacatek hry, vyber classy, start mapy
int main() {
    Player hrac;  //  Promenna hrace

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

        // Nastaveni classy
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

        // dalsi hodnoty
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

        vypisSchopnosti(hrac);  //Vypis schopnosti

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
    travel(hrac);  // Spusteni cesty mapou

    return 0;
}
