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
void fightTwoBandits(Player &hrac) {
    int bandit1HP = 6;
    int bandit2HP = 6;
    int banditDMG = 3;

    while (hrac.currentHP > 0 && (bandit1HP > 0 || bandit2HP > 0)) {
        cout << "Bandita 1: " << bandit1HP << " HP, Bandita 2: " << bandit2HP << " HP" << endl;
        cout << "Vyber cil (1/2): ";
        int target;
        cin >> target;

        if (target == 1 && bandit1HP > 0) {
            bandit1HP -= hrac.attack;
            cout << "Zasahujes Banditu 1 za " << hrac.attack << " DMG." << endl;
        } else if (target == 2 && bandit2HP > 0) {
            bandit2HP -= hrac.attack;
            cout << "Zasahujes Banditu 2 za " << hrac.attack << " DMG." << endl;
        } else {
            cout << "Neplatny cil!" << endl;
            continue;
        }

        if (bandit1HP > 0) {
            hrac.currentHP -= banditDMG;
            hrac.gold = max(0, hrac.gold - 1);
            cout << "Bandita 1 te zasahuje za " << banditDMG << " DMG a krade 1 zlato!" << endl;
        }
        if (bandit2HP > 0) {
            hrac.currentHP -= banditDMG;
            hrac.gold = max(0, hrac.gold - 1);
            cout << "Bandita 2 te zasahuje za " << banditDMG << " DMG a krade 1 zlato!" << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << ", Zlato: " << hrac.gold << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Byl jsi porazen!" << endl;
        exit(0);
    } else {
        cout << "Vyhral jsi nad obema bandity!" << endl;
    }
}

// Fight s harpii
void fightHarpy(Player &hrac) {
    int harpyHP = 10;
    int harpyDMG = 3;

    while (hrac.currentHP > 0 && harpyHP > 0) {
        cout << "Harpie: " << harpyHP << " HP" << endl;

        int damage = hrac.attack / 2;
        cout << "Zasahujes harpii za " << damage << " DMG." << endl;
        harpyHP -= damage;

        if (harpyHP > 0) {
            hrac.currentHP -= harpyDMG;
            cout << "Harpie te zasahuje za " << harpyDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi harpii!" << endl;
    }
}

// Fight rytir + healer
void fightKnightAndHealer(Player &hrac) {
    int knightHP = 15;
    int healerHP = 8;
    int knightDMG = 5;
    int healerDMG = 2;
    int round = 1;

    while (hrac.currentHP > 0 && (knightHP > 0 || healerHP > 0)) {
        cout << "Rytir: " << knightHP << " HP, Healer: " << healerHP << " HP" << endl;
        cout << "Vyber cil (1 = Rytir, 2 = Healer): ";
        int target;
        cin >> target;

        if (target == 1 && knightHP > 0) {
            knightHP -= hrac.attack;
            cout << "Zasahujes Rytire za " << hrac.attack << " DMG." << endl;
        } else if (target == 2 && healerHP > 0) {
            healerHP -= hrac.attack;
            cout << "Zasahujes Healera za " << hrac.attack << " DMG." << endl;
        } else {
            cout << "Neplatny cil!" << endl;
            continue;
        }

        if (healerHP > 0 && (round % 3 == 0) && knightHP > 0) {
            knightHP += 3;
            cout << "Healer leci Rytire za 3 HP!" << endl;
        }

        if (knightHP > 0) {
            hrac.currentHP -= knightDMG;
            cout << "Rytir te zasahuje za " << knightDMG << " DMG." << endl;
        }
        if (healerHP > 0) {
            hrac.currentHP -= healerDMG;
            cout << "Healer te zasahuje za " << healerDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
        round++;
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi nepratele!" << endl;
    }
}
void fightZombie(Player &hrac) {
    int zombieHP = 8;
    int zombieDMG = 4;

    while (hrac.currentHP > 0 && zombieHP > 0) {
        cout << "Zombik: " << zombieHP << " HP" << endl;

        int damage = hrac.attack;
        cout << "Zasahujes zombika za " << damage << " DMG." << endl;
        zombieHP -= damage;

        if (zombieHP > 0) {
            hrac.currentHP -= zombieDMG;
            cout << "Zombik te kousl za " << zombieDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi zombika!" << endl;
    }
}
void fightWolves(Player &hrac) {
    int wolvesHP = 12;
    int wolvesDMG = 5;

    while (hrac.currentHP > 0 && wolvesHP > 0) {
        cout << "Smecka vlku: " << wolvesHP << " HP" << endl;

        int damage = hrac.attack;
        cout << "Sekas vlky za " << damage << " DMG." << endl;
        wolvesHP -= damage;

        if (wolvesHP > 0) {
            hrac.currentHP -= wolvesDMG;
            cout << "Vlci te roztrhali za " << wolvesDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi smecku vlku!" << endl;
    }
}
void fightUndeadKnight(Player &hrac) {
    int knightHP = 15;
    int knightDMG = 6;
    int round = 1;

    while (hrac.currentHP > 0 && knightHP > 0) {
        cout << "Nemrtvy rytir: " << knightHP << " HP" << endl;

        if (round % 3 != 0) {
            int damage = hrac.attack;
            cout << "Zasahujes rytire za " << damage << " DMG." << endl;
            knightHP -= damage;
        } else {
            cout << "Rytir zvedl stit a zablokoval utok!" << endl;
        }

        if (knightHP > 0) {
            hrac.currentHP -= knightDMG;
            cout << "Rytir te sek za " << knightDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
        round++;
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi nemrtveho rytire!" << endl;
    }
}
void fightGhost(Player &hrac) {
    int ghostHP = 10;
    int ghostDMG = 4;

    while (hrac.currentHP > 0 && ghostHP > 0) {
        cout << "Prizrak: " << ghostHP << " HP" << endl;

        int damage = hrac.attack;
        cout << "Zasahujes prizraka za " << damage << " DMG." << endl;
        ghostHP -= damage;

        if (ghostHP > 0) {
            hrac.currentHP -= ghostDMG;
            cout << "Prizrak ti ubral " << ghostDMG << " HP." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi prizraka!" << endl;
    }
}
void fightDarkMage(Player &hrac) {
    int mageHP = 12;
    int mageDMG = 5;

    cout << "Temny mag zablokoval tve specialni schopnosti!\nMuzes pouzivat jen zakladni utok.\n";

    while (hrac.currentHP > 0 && mageHP > 0) {
        cout << "Temny mag: " << mageHP << " HP" << endl;

        int damage = hrac.attack;
        cout << "Zasahujes maga za " << damage << " DMG." << endl;
        mageHP -= damage;

        if (mageHP > 0) {
            hrac.currentHP -= mageDMG;
            cout << "Mag seslal kouzlo za " << mageDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi temneho maga!" << endl;
    }
}
void fightFallenHunter(Player &hrac) {
    int hunterHP = 11;
    int hunterDMG = 5;

    while (hrac.currentHP > 0 && hunterHP > 0) {
        cout << "Padly lovec: " << hunterHP << " HP" << endl;

        int damage = hrac.attack;
        cout << "Zasahujes lovce za " << damage << " DMG." << endl;
        hunterHP -= damage;

        if (hunterHP > 0) {
            hrac.currentHP -= hunterDMG;
            cout << "Lovec te zasahl sipem za " << hunterDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi padleho lovce!" << endl;
    }
}
void fightZombieBerserkers(Player &hrac) {
    int berserker1HP = 9;
    int berserker2HP = 9;
    int berserkerDMG = 4;

    while (hrac.currentHP > 0 && (berserker1HP > 0 || berserker2HP > 0)) {
        cout << "Zombie Berserker 1: " << berserker1HP << " HP | Zombie Berserker 2: " << berserker2HP << " HP" << endl;

        int damage = hrac.attack;

        if (berserker1HP > 0) {
            cout << "Zasahujes Berserkera 1 za " << damage << " DMG." << endl;
            berserker1HP -= damage;
        } else if (berserker2HP > 0) {
            cout << "Zasahujes Berserkera 2 za " << damage << " DMG." << endl;
            berserker2HP -= damage;
        }

        int totalDMG = berserkerDMG;
        if (berserker1HP <= 0 || berserker2HP <= 0) totalDMG += 2;

        if (berserker1HP > 0) {
            hrac.currentHP -= totalDMG;
            cout << "Berserker te trhne za " << totalDMG << " DMG." << endl;
        }

        if (berserker2HP > 0) {
            hrac.currentHP -= totalDMG;
            cout << "Druhy berserker te trhne za " << totalDMG << " DMG." << endl;
        }

        cout << "Tvoje HP: " << hrac.currentHP << endl;
        waitForEnter();
    }

    if (hrac.currentHP <= 0) {
        cout << "Padl jsi v boji!" << endl;
        exit(0);
    } else {
        cout << "Porazil jsi oba zombie berserkery!" << endl;
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
         // Souboje podle specifikace
        else if (location == 2) {
            cout << "Souboj: zombie!" << endl;
            fightZombie(hrac);
        }
        else if (location == 3) {
            cout << "Souboj: Smecka vlku!" << endl;
             fightWolves(hrac);
        }
        else if (location == 5) {
            cout << "Souboj: Banditi!" << endl;
            fightTwoBandits(hrac);
        }
        else if (location == 6) {
            cout << "Souboj: Nemrtvý rytíø!" << endl;
            fightUndeadKnight(hrac);
        }
        else if (location == 8) {
            cout << "Souboj: Harpie!" << endl;
            fightHarpy(hrac);
        }
        else if (location == 9) {
            cout << "Souboj: Pøizrak!" << endl;
            fightGhost(hrac);
        }
        else if (location == 10) {
            cout << "Souboj: Rytíø a Healer!" << endl;
            fightKnightAndHealer(hrac);
        }
        else if (location == 12) {
            cout << "Souboj: Temný mág!" << endl;
            fightDarkMage(hrac);
        }
        else if (location == 13) {
            cout << "Souboj: Pádly lovec!" << endl;
            fightFallenHunter(hrac);
        }
        else if (location == 15) {
            cout << "Souboj: Dva zombie berserkeøi!" << endl;
            fightZombieBerserkers(hrac);
        }
        else if (location == 17) {
            cout << "Finální boss fight!" << endl;
            cout << "(placeholder pro finalni boss fight)" << endl;
        }
        // Ostatní lokace
        else {
            cout << "Klidná oblast. Žádní nepøátelé." << endl;
        }

        waitForEnter();
    }
}

// Funkce pro vypis schopnosti podle classy
void vypisSchopnosti(const Player &hrac) {
    if (hrac.className == "Mag") {
        cout << "Schopnosti: Fireball - 5 dmg, Ledove kouzlo - 3 dmg"  << endl;
    } else if (hrac.className == "Assassin") {
        cout << "Schopnosti: Kriticky uder (2x dmg), Uhni! (50% sance na vyhnuti)" << endl;
    } else if (hrac.className == "Warrior") {
        cout << "Schopnosti: Silovy utok - 4 dmg, stit-blokne demage" << endl;
    } else if (hrac.className == "Pistolnik") {
        cout << "Schopnosti: Zamireni (3x dmg na dalsi utok), Vystrel - 4 dmg" << endl;
    } else if (hrac.className == "Gambler") {
        cout << "Schopnosti: Hod kostkou 50% na kri nebo samoskodu" << endl;
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
