// Updated to support expanded Pokemon data from Gen 1 to Gen 9
#include "pokemon_data.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "pokemon_data.h"

using namespace std;

// -------------------- Battle Function --------------------
bool battle(Pokemon& player, Pokemon boss) {
    cout << "\nBattle Start: " << player.name << " vs " << boss.name << "!\n";

    while (player.hp > 0 && boss.hp > 0) {
        // Player attacks
        int playerDamage = max(1, player.attack - boss.defense / 2);
        boss.hp -= playerDamage;
        cout << player.name << " attacks " << boss.name << " for " << playerDamage << " damage!\n";

        if (boss.hp <= 0) {
            cout << boss.name << " fainted! You win this battle!\n";
            return true;
        }

        // Boss attacks
        int bossDamage = max(1, boss.attack - player.defense / 2);
        player.hp -= bossDamage;
        cout << boss.name << " attacks " << player.name << " for " << bossDamage << " damage!\n";

        if (player.hp <= 0) {
            cout << player.name << " fainted! You lost this battle.\n";
            return false;
        }
    }

    return false;
}

// -------------------- Boss Pokémon --------------------
vector<Pokemon> getBosses() {
    return {
        Pokemon("Mewtwo", "Psychic", 106, 110, 90),
        Pokemon("Giratina", "Ghost/Dragon", 150, 100, 120),
        Pokemon("Palkia", "Water/Dragon", 90, 120, 100),
        Pokemon("Dialga", "Steel/Dragon", 100, 120, 120) // Final Boss
    };
}

// -------------------- Main Function --------------------
int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to the Pokémon Text Adventure!\n";
    cout << "Choose your starter Pokémon:\n";

    vector<Pokemon> starters = getStarterPokemon();
    for (size_t i = 0; i < starters.size(); ++i) {
        cout << i + 1 << ". " << starters[i].name << " (" << starters[i].type << ")\n";
    }

    int choice;
    cin >> choice;

    if (choice < 1 || choice > starters.size()) {
        cout << "Invalid choice. Exiting game.\n";
        return 1;
    }

    Pokemon player = starters[choice - 1];
    cout << "You chose " << player.name << "!\n";

    vector<Pokemon> bosses = getBosses();
    for (size_t i = 0; i < bosses.size(); ++i) {
        cout << "\nA wild " << bosses[i].name << " appears!\n";
        bool won = battle(player, bosses[i]);

        if (!won) {
            cout << "Game Over. Better luck next time!\n";
            return 0;
        } else {
            cout << "You defeated " << bosses[i].name << "!\n";
        }
    }

    cout << "\nCongratulations! You defeated all the bosses!\n";
    return 0;
}
