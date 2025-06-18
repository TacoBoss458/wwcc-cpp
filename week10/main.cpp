/*
 * Interactive Story Game - PokeCode!
 * Author: Isaiah Rusch
 * Date: 6/17/2025
 *
 * ==== Project Features ====
 * Variables (3+ types): Lines 16-18 in pokemon_data.h
 * If/else statements: Lines 110, 149(attack_data.h), 29(utilities.h)
 * Switch statement: Line _______
 * For Loop: Line 96
 * While Loop: Line 117
 * Function w/ return: Line 70
 * Void function: Line 49
 * Function w/ params: Line 49
 * Vector usage: Lines 64, 65, 78 and many more
 * Struct/Class: Lines 59-66
 * Enum: Lines 40-43
 * File Reading: Lines 105-120
 * File Writing: Lines 169-181
 * Modern Feature (auto): Lines 85, 92
 * Modern Feature (range-for): Line 150
 * ==========================
 */
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
    int numChosen = 0;
    int totalDamageDealt = 0;
    int totalDamageReceived = 0;
    chrono::system_clock::time_point startTime;
    chrono::system_clock::time_point endTime;
    int numFainted = 0;
    vector<string> bossesDefeated;
    vector<string> finalTeam;
};



int main() {
    AdventureLog log;
    srand(static_cast<unsigned>(time(nullptr))); // Seed RNG

    while (true) {
        cout << "\n=== PokeCode Adventure Menu ===\n";
        cout << "1. Start New Adventure\n";
        cout << "2. View Past Logs\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int menuChoice;
        if (!(cin >> menuChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        if (!(cin >> menuChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }


        switch (menuChoice) {
            case 1: {
                log.startTime = chrono::system_clock::now();
                int totalFaints = 0;
                int totalAttacks = 0;
                vector<Pokemon> allPokemon = getAllPokemon();
                AttackDatabase attackDB;

                cout << "Select your team of 5 starter Pokemon from the list below:\n";
                vector<Pokemon> playerTeam = selectInitialTeam(allPokemon);
                log.numChosen = playerTeam.size();

                cout << "\nYour selected team:\n";
                for (const auto& p : playerTeam) {
                    cout << " - " << p.name << " (" << p.type << ") HP: " << p.hp
                         << " Atk: " << p.attack << " Def: " << p.defense << "\n";
                }

                vector<Gym> gyms = getGyms();
                bool defeated = false;

                for (const auto& gym : gyms) {
                    cout << "\n=== " << gym.name << " ===\n";
                    cout << "Boss: " << gym.bossName << "\n";
                    cout << "Restricted types: ";
                    for (const auto& t : gym.restrictedTypes) cout << t << " ";
                    cout << "\n";

                    vector<Pokemon> filteredTeam = filterTeamForGym(playerTeam, gym);
                    if (filteredTeam.empty()) {
                        cout << "All your Pokemon were filtered out by the gym restrictions. You lose.\n";
                        defeated = true;
                        break;
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

                    printBattleBanner(gym.name + " BATTLE START!");
                    BattleResult result = battle(selectedTeam, bossTeam, attackDB, totalFaints, totalAttacks, log.totalDamageDealt, log.totalDamageReceived);

                    if (result == BattleResult::Defeat) {
                        cout << "You were defeated in the " << gym.name << "!\n";
                        log.endTime = chrono::system_clock::now();
                        log.numFainted = totalFaints;
                        for (const auto& p : playerTeam) log.finalTeam.push_back(p.name);

                        ofstream out("Adventures.txt", ios::app);
                        time_t start = chrono::system_clock::to_time_t(log.startTime);
                        time_t end = chrono::system_clock::to_time_t(log.endTime);
                        out << "\n=== LOSS LOG ===\n";
                        out << "Gym: " << gym.name << "\n";
                        out << "Start Time: " << ctime(&start);
                        out << "End Time: " << ctime(&end);
                        out << "Final Team: ";
                        for (const auto& name : log.finalTeam) out << name << " ";
                        out << "\n=================\n";
                        out.close();
                        defeated = true;
                        break;
                    }

                    evolveTeam(playerTeam, allPokemon);
                }

                if (!defeated) {
                    cout << "\nYOU WIN!\nThanks for playing!\n";
                    log.endTime = chrono::system_clock::now();
                    for (const auto& p : playerTeam) log.finalTeam.push_back(p.name);
                    log.numFainted = totalFaints;

                    ofstream out("Adventures.txt", ios::app);
                    time_t start = chrono::system_clock::to_time_t(log.startTime);
                    time_t end = chrono::system_clock::to_time_t(log.endTime);
                    out << "\n=== Pokemon Adventure Log ===\n";
                    out << "Start Time: " << ctime(&start);
                    out << "End Time: " << ctime(&end);
                    out << "Number of Pokemon Chosen: " << log.numChosen << "\n";
                    out << "Number of Pokemon Fainted: " << log.numFainted << "\n";
                    out << "Final Team Lineup: ";
                    for (const auto& name : log.finalTeam) out << name << " ";
                    out << "\n=============================\n";
                    out.close();
                }
                break;
            }

            case 2: {
                ifstream in("Adventures.txt");
                if (!in.is_open()) {
                    cout << "\nError: Could not open Adventures.txt.\n";
                } else {
                    in.seekg(0, ios::end);
                    if (in.tellg() == 0) {
                        cout << "\nAdventures.txt is empty.\n";
                    } else {
                        in.seekg(0); // Reset to beginning
                        cout << "\n=== Adventure Logs ===\n";
                        string line;
                        while (getline(in, line)) {
                            cout << line << "\n";
                        }
                        cout << "=======================\n";
                    }
                    in.close();
                }
                break;
            }



            case 3:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
