#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "pokemon_data.h"
#include "attack_data.h"
#include "utilities.h"
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
    std::cout << "\n==============================\n";
    std::cout << " " << title << "\n";
    std::cout << "==============================\n";
}
#endif


using namespace std;





struct BattlePokemon {
    Pokemon base;
    int currentHP;

    BattlePokemon(const Pokemon& p) : base(p), currentHP(p.hp) {}

    bool isFainted() const {
        return currentHP <= 0;
    }
};

int chooseFromList(const vector<string>& options, const string& prompt) {
    int choice = -1;
    while (true) {
        cout << prompt << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
        cout << "Enter choice (1-" << options.size() << "): ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > (int)options.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again." << endl;
        } else {
            break;
        }
    }
    return choice - 1;
}

Attack chooseAttack(const AttackDatabase& db, const Pokemon& p) {
    vector<Attack> attacks = db.getAttacksForPokemon(p.name);
    vector<string> attackNames;
    for (const auto& atk : attacks) {
        attackNames.push_back(atk.name + " (Damage: " + to_string(atk.damage) + ")");
    }
    int choice = chooseFromList(attackNames, "Choose an attack for " + p.name + ":");
    return attacks[choice];
}

int choosePokemonToAttackWith(const vector<BattlePokemon>& team) {
    vector<string> options;
    for (const auto& bp : team) {
        if (!bp.isFainted()) {
            options.push_back(bp.base.name + " (HP: " + to_string(bp.currentHP) + ")");
        } else {
            options.push_back(bp.base.name + " (Fainted)");
        }
    }
    return chooseFromList(options, "Choose a Pokemon to attack with:");
}

bool allFainted(const vector<BattlePokemon>& team) {
    for (const auto& p : team) {
        if (!p.isFainted()) return false;
    }
    return true;
}

BattleResult battle(const vector<Pokemon>& playerTeam, const vector<Pokemon>& enemyTeam, const AttackDatabase& attackDB, int& totalAttacks, int& totalFainted) {
    vector<BattlePokemon> player, enemy;
    for (const auto& p : playerTeam) player.emplace_back(p);
    for (const auto& p : enemyTeam) enemy.emplace_back(p);

    cout << "\nBattle Start!\n";

    while (!allFainted(player) && !allFainted(enemy)) {
        // Player turn
        if (!allFainted(player)) {
            int attackerIndex = choosePokemonToAttackWith(player);
            BattlePokemon& attacker = player[attackerIndex];
            if (attacker.isFainted()) {
                cout << attacker.base.name << " is fainted and cannot attack.\n";
            } else {
                Attack move = chooseAttack(attackDB, attacker.base);
                BattlePokemon& target = enemy[0];
                target.currentHP -= move.damage;
                totalAttacks++;
                cout << attacker.base.name << " used " << move.name << " on " << target.base.name << " for " << move.damage << " damage!\n";
                if (target.currentHP <= 0) {
                    cout << target.base.name << " fainted!\n";
                    totalFainted++;
                }
            }
        }

        // Enemy turn
        if (!allFainted(enemy)) {
            BattlePokemon& attacker = enemy[0];
            if (!attacker.isFainted()) {
                Attack move = attackDB.getAttacksForPokemon(attacker.base.name)[0];
                for (auto& target : player) {
                    if (!target.isFainted()) {
                        target.currentHP -= move.damage;
                        cout << attacker.base.name << " used " << move.name << " on " << target.base.name << " for " << move.damage << " damage!\n";
                        if (target.currentHP <= 0) {
                            cout << target.base.name << " fainted!\n";
                            totalFainted++;
                        }
                        break;
                    }
                }
            }
        }
    }

    cout << "Battle Over!\n";
    return allFainted(player) ? BattleResult::Defeat : BattleResult::Victory;
}