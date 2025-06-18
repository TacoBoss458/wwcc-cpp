#include <set>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "pokemon_data.h"
#include "attack_data.h"
#include "utilities.h"
#include "battle_system.h"
#include <limits>
#include <fstream>
#include <chrono>

#ifndef BATTLE_RESULT_DEFINED
#define BATTLE_RESULT_DEFINED
enum class BattleResult {
    Victory,
    Defeat
};
#endif


#ifndef PRINT_BATTLE_BANNER_DEFINED
#define PRINT_BATTLE_BANNER_DEFINED
inline void printBattleBanner(const std::string& title) {
    cout << "==============================";
    cout << " " << title << "\n";
    cout << "==============================";
}
#endif


using namespace std;

struct AdventureLog {
    chrono::system_clock::time_point startTime;
    chrono::system_clock::time_point endTime;
    int numChosen = 0;
    int numFainted = 0;
    vector<string> bossesDefeated;
    vector<string> finalTeam;
};



int main() {
    AdventureLog log;
    log.startTime = chrono::system_clock::now();
    srand(static_cast<unsigned>(time(nullptr))); // Seed RNG

    int totalFaints = 0;
    int totalAttacks = 0;

    vector<Pokemon> allPokemon = getAllPokemon();
    AttackDatabase attackDB;

    // --- Player selects initial team ---
    cout << "Select your team of 5 starter Pokemon from the list below:\n";
    vector<Pokemon> playerTeam = selectInitialTeam(allPokemon);
    log.numChosen = playerTeam.size();

    cout << "\nYour selected team:\n";
    for (const auto& p : playerTeam) {
        cout << " - " << p.name << " (" << p.type << ") HP: " << p.hp
             << " Atk: " << p.attack << " Def: " << p.defense << "\n";
    }

    // --- Gym Battles ---
    cout << "\nNow it's time to challenge the Legendary Gyms!\n";
    vector<Gym> gyms = getGyms();

    for (const auto& gym : gyms) {
        cout << "\n=== " << gym.name << " ===\n";
        cout << "Boss: " << gym.bossName << "\n";
        cout << "Restricted types: ";
        for (const auto& t : gym.restrictedTypes) cout << t << " ";
        cout << "\n";

        vector<Pokemon> filteredTeam = filterTeamForGym(playerTeam, gym);
        if (filteredTeam.empty()) {
            cout << "All your Pokemon were filtered out by the gym restrictions. You lose.\n";
            return 0;
        }

        vector<Pokemon> selectedTeam;
        if (gym.name != "Final Boss") {
            cout << "Select 3 Pokemon from your filtered team for this gym battle:\n";
            for (int i = 0; i < filteredTeam.size(); ++i) {
                cout << i + 1 << ". " << filteredTeam[i].name << "\n";
            }

            set<int> selectedIndices;
            while (selectedTeam.size() < 3) {
                int choice;
                cout << "Enter choice #" << selectedTeam.size() + 1 << ": ";
                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number.\n";
                    continue;
                }
                if (choice >= 1 && choice <= filteredTeam.size()) {
                    if (selectedIndices.count(choice)) {
                        cout << "You already selected that Pokemon. Choose a different one.\n";
                        continue;
                    }
                    selectedIndices.insert(choice);
                    selectedTeam.push_back(filteredTeam[choice - 1]);
                } else {
                    cout << "Invalid choice. Try again.\n";
                }
            }
        } else {
            selectedTeam = playerTeam;
        }

        Pokemon boss = findPokemonByName(allPokemon, gym.bossName);
        vector<Pokemon> bossTeam = { boss };

        cout << "Filtered team:\n";
        for (const auto& p : filteredTeam) {
            cout << " - " << p.name << " (" << p.type << ") HP: " << p.hp
                 << " Atk: " << p.attack << " Def: " << p.defense << "\n";
        }

        printBattleBanner(gym.name + " BATTLE START!");
        BattleResult result = battle(selectedTeam, bossTeam, attackDB, totalFaints, totalAttacks);
        if (result == BattleResult::Defeat) {
            std::cout << "You were defeated in the " << gym.name << "!\n";
            return 0;
        }

        // Evolve team after battle
        evolveTeam(playerTeam, allPokemon);
    }

    cout << "\nYOU WIN!\n";
    cout << "Thanks for playing!\n";

    log.endTime = chrono::system_clock::now();
    for (const auto& p : playerTeam) log.finalTeam.push_back(p.name);
    log.numFainted = totalFaints;

    ofstream out("Adventures.txt");
    time_t start = chrono::system_clock::to_time_t(log.startTime);
    time_t end = chrono::system_clock::to_time_t(log.endTime);
    out << "=== Pokemon Adventure Log ===\n";
    out << "Start Time: " << ctime(&start);
    out << "End Time: " << ctime(&end);
    out << "Number of Pokemon Chosen: " << log.numChosen << "\n";
    out << "Number of Pokemon Fainted: " << log.numFainted << "\n";
    out << "Bosses Defeated: ";
    for (const auto& b : log.bossesDefeated) out << b << " ";
    out << "\nFinal Team Lineup: ";
    for (const auto& name : log.finalTeam) out << name << " ";
    out << "\n=============================\n";
    out.close();

    return 0;
}
