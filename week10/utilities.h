#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "pokemon_data.h"

using namespace std;

// Helper template to select unique Pokemon by index with single displayed list
template<typename T>
vector<T> selectUniquePokemon(const vector<T>& pokemonList, int count, const string& prompt) {
    vector<T> chosen;
    vector<bool> chosenFlags(pokemonList.size(), false);

    cout << "\nAvailable Pokemon:\n";
    for (size_t i = 0; i < pokemonList.size(); ++i) {
        cout << " " << (i + 1) << ". " << pokemonList[i].name << "\n";
    }
    cout << endl;

    while ((int)chosen.size() < count) {
        cout << prompt << " #" << (chosen.size() + 1) << ": ";
        int choice = 0;
        if (cin >> choice && choice > 0 && choice <= (int)pokemonList.size() && !chosenFlags[choice - 1]) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            chosenFlags[choice - 1] = true;
            chosen.push_back(pokemonList[choice - 1]);
        } else {
            cout << "Invalid choice or already selected. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return chosen;
}

// Select initial team: 5 stage-0 Pokemon (starters), excluding bosses
vector<Pokemon> selectInitialTeam(const vector<Pokemon>& allPokemon) {
    vector<Pokemon> stage0pokemon;
    vector<string> bossNames = { "Mewtwo", "Giratina", "Palkia", "Dialga" };

    for (const auto& p : allPokemon) {
        if (p.stage == 0 && find(bossNames.begin(), bossNames.end(), p.name) == bossNames.end()) {
            stage0pokemon.push_back(p);
        }
    }

    return selectUniquePokemon(stage0pokemon, 5, "Pick Pokemon");
}

// Helper function to find Pokemon by name
Pokemon findPokemonByName(const vector<Pokemon>& allPokemon, const string& name) {
    auto it = find_if(allPokemon.begin(), allPokemon.end(),
                      [&](const Pokemon& p) { return p.name == name; });
    if (it != allPokemon.end()) {
        return *it;
    }
    throw runtime_error("Pokemon " + name + " not found");
}

struct Gym {
    string name;
    string bossName;
    vector<string> restrictedTypes;
};

vector<Gym> getGyms() {
    return {
        { "Inferno Gym", "Mewtwo", { "Dark", "Ghost", "Bug" } },
        { "Phantom Gym", "Giratina", { "Ghost", "Dark", "Ice" } },
        { "Abyssal Gym", "Palkia", { "Dragon", "Fairy" } },
        { "Chrono Gym", "Dialga", { "Fighting", "Ground" } }
    };
}

vector<Pokemon> filterTeamForGym(const vector<Pokemon>& team, const Gym& gym) {
    vector<Pokemon> filtered;
    for (const auto& p : team) {
        bool restricted = false;
        for (const auto& type : gym.restrictedTypes) {
            if (p.type.find(type) != string::npos) {
                restricted = true;
                break;
            }
        }
        if (!restricted) filtered.push_back(p);
    }
    return filtered;
}

// Evolve player's team after defeating a boss if possible
void evolveTeam(vector<Pokemon>& team, const vector<Pokemon>& allPokemon) {
    for (auto& p : team) {
        if (p.canEvolveFlag && !p.evolvesTo.empty()) {
            try {
                Pokemon evolvedForm = findPokemonByName(allPokemon, p.evolvesTo);
                // Replace with evolved form
                p = evolvedForm;
                cout << p.name << " has evolved!\n";
            } catch (const runtime_error& e) {
                cout << "Evolution failed: " << e.what() << "\n";
            }
        }
    }
}
#endif
