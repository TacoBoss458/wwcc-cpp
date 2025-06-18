#ifndef POKEMON_DATA_H
#define POKEMON_DATA_H

#include <string>
#include <vector>

using namespace std;

class Pokemon {
public:
    string name;
    string type;
    int hp;
    int attack;
    int defense;
    int stage; // 0 = base, 1 = first evo, 2 = second evo
    string evolvesTo;
    bool canEvolveFlag = true;

    Pokemon() = default;

    Pokemon(string n, string t, int h, int a, int d, int s = 0, string evo = "")
        : name(n), type(t), hp(h), attack(a), defense(d), stage(s), evolvesTo(evo), canEvolveFlag(true) {}
};

vector<Pokemon> getAllPokemon() {
    return {
        // Gen 1
        Pokemon("Bulbasaur", "Grass/Poison", 45, 49, 49, 0, "Ivysaur"),
        Pokemon("Ivysaur", "Grass/Poison", 60, 62, 63, 1, "Venusaur"),
        Pokemon("Venusaur", "Grass/Poison", 80, 82, 83, 2, ""),

        Pokemon("Charmander", "Fire", 39, 52, 43, 0, "Charmeleon"),
        Pokemon("Charmeleon", "Fire", 58, 64, 58, 1, "Charizard"),
        Pokemon("Charizard", "Fire/Flying", 78, 84, 78, 2, ""),

        Pokemon("Squirtle", "Water", 44, 48, 65, 0, "Wartortle"),
        Pokemon("Wartortle", "Water", 59, 63, 80, 1, "Blastoise"),
        Pokemon("Blastoise", "Water", 79, 83, 100, 2, ""),

        // Gen 2
        Pokemon("Chikorita", "Grass", 45, 49, 65, 0, "Bayleef"),
        Pokemon("Bayleef", "Grass", 60, 62, 80, 1, "Meganium"),
        Pokemon("Meganium", "Grass", 80, 82, 100, 2, ""),

        Pokemon("Cyndaquil", "Fire", 39, 52, 43, 0, "Quilava"),
        Pokemon("Quilava", "Fire", 58, 64, 58, 1, "Typhlosion"),
        Pokemon("Typhlosion", "Fire", 78, 84, 78, 2, ""),

        Pokemon("Totodile", "Water", 50, 65, 64, 0, "Croconaw"),
        Pokemon("Croconaw", "Water", 65, 80, 80, 1, "Feraligatr"),
        Pokemon("Feraligatr", "Water", 85, 105, 100, 2, ""),

        // Gen 3
        Pokemon("Treecko", "Grass", 40, 45, 35, 0, "Grovyle"),
        Pokemon("Grovyle", "Grass", 50, 65, 45, 1, "Sceptile"),
        Pokemon("Sceptile", "Grass", 70, 85, 65, 2, ""),

        Pokemon("Torchic", "Fire", 45, 60, 40, 0, "Combusken"),
        Pokemon("Combusken", "Fire/Fighting", 60, 85, 60, 1, "Blaziken"),
        Pokemon("Blaziken", "Fire/Fighting", 80, 120, 70, 2, ""),

        Pokemon("Mudkip", "Water", 50, 70, 50, 0, "Marshtomp"),
        Pokemon("Marshtomp", "Water/Ground", 70, 85, 70, 1, "Swampert"),
        Pokemon("Swampert", "Water/Ground", 100, 110, 90, 2, ""),

        // Gen 4
        Pokemon("Turtwig", "Grass", 55, 68, 64, 0, "Grotle"),
        Pokemon("Grotle", "Grass", 75, 89, 85, 1, "Torterra"),
        Pokemon("Torterra", "Grass/Ground", 95, 109, 105, 2, ""),

        Pokemon("Chimchar", "Fire", 44, 58, 44, 0, "Monferno"),
        Pokemon("Monferno", "Fire/Fighting", 64, 78, 52, 1, "Infernape"),
        Pokemon("Infernape", "Fire/Fighting", 76, 104, 71, 2, ""),

        Pokemon("Piplup", "Water", 53, 51, 53, 0, "Prinplup"),
        Pokemon("Prinplup", "Water", 64, 66, 68, 1, "Empoleon"),
        Pokemon("Empoleon", "Water/Steel", 84, 86, 88, 2, ""),

        // Gen 5
        Pokemon("Snivy", "Grass", 45, 45, 55, 0, "Servine"),
        Pokemon("Servine", "Grass", 60, 60, 75, 1, "Serperior"),
        Pokemon("Serperior", "Grass", 75, 75, 95, 2, ""),

        Pokemon("Tepig", "Fire", 65, 63, 45, 0, "Pignite"),
        Pokemon("Pignite", "Fire/Fighting", 90, 93, 55, 1, "Emboar"),
        Pokemon("Emboar", "Fire/Fighting", 110, 123, 65, 2, ""),

        Pokemon("Oshawott", "Water", 55, 55, 45, 0, "Dewott"),
        Pokemon("Dewott", "Water", 75, 75, 60, 1, "Samurott"),
        Pokemon("Samurott", "Water", 95, 100, 85, 2, ""),

        // Gen 6
        Pokemon("Chespin", "Grass", 56, 61, 65, 0, "Quilladin"),
        Pokemon("Quilladin", "Grass", 61, 78, 95, 1, "Chesnaught"),
        Pokemon("Chesnaught", "Grass/Fighting", 88, 107, 122, 2, ""),

        Pokemon("Fennekin", "Fire", 40, 62, 60, 0, "Braixen"),
        Pokemon("Braixen", "Fire", 59, 74, 72, 1, "Delphox"),
        Pokemon("Delphox", "Fire/Psychic", 75, 88, 90, 2, ""),

        Pokemon("Froakie", "Water", 41, 56, 40, 0, "Frogadier"),
        Pokemon("Frogadier", "Water", 54, 63, 52, 1, "Greninja"),
        Pokemon("Greninja", "Water/Dark", 72, 95, 67, 2, ""),

        // Gen 7
        Pokemon("Rowlet", "Grass/Flying", 68, 55, 55, 0, "Dartrix"),
        Pokemon("Dartrix", "Grass/Flying", 78, 75, 75, 1, "Decidueye"),
        Pokemon("Decidueye", "Grass/Ghost", 88, 107, 75, 2, ""),

        Pokemon("Litten", "Fire", 45, 65, 40, 0, "Torracat"),
        Pokemon("Torracat", "Fire", 65, 85, 50, 1, "Infernape"),
        Pokemon("Infernape", "Fire/Fighting", 78, 112, 64, 2, ""),

        Pokemon("Popplio", "Water", 50, 54, 54, 0, "Brionne"),
        Pokemon("Brionne", "Water", 60, 69, 69, 1, "Primarina"),
        Pokemon("Primarina", "Water/Fairy", 80, 74, 74, 2, ""),

        // Gen 8
        Pokemon("Grookey", "Grass", 50, 65, 50, 0, "Thwackey"),
        Pokemon("Thwackey", "Grass", 70, 85, 70, 1, "Rillaboom"),
        Pokemon("Rillaboom", "Grass", 100, 125, 90, 2, ""),

        Pokemon("Scorbunny", "Fire", 50, 71, 40, 0, "Raboot"),
        Pokemon("Raboot", "Fire", 65, 86, 60, 1, "Cinderace"),
        Pokemon("Cinderace", "Fire", 80, 116, 75, 2, ""),

        Pokemon("Sobble", "Water", 50, 40, 40, 0, "Drizzile"),
        Pokemon("Drizzile", "Water", 65, 60, 55, 1, "Inteleon"),
        Pokemon("Inteleon", "Water", 70, 85, 65, 2, ""),

        // Gen 9
        Pokemon("Sprigatito", "Grass", 40, 61, 54, 0, "Floragato"),
        Pokemon("Floragato", "Grass", 70, 81, 74, 1, "Meowscarada"),
        Pokemon("Meowscarada", "Grass/Dark", 76, 110, 70, 2, ""),

        Pokemon("Fuecoco", "Fire", 55, 70, 40, 0, "Crocalor"),
        Pokemon("Crocalor", "Fire", 80, 112, 65, 1, "Skeledirge"),
        Pokemon("Skeledirge", "Fire/Ghost", 120, 136, 80, 2, ""),

        Pokemon("Quaxly", "Water", 55, 65, 50, 0, "Quaxwell"),
        Pokemon("Quaxwell", "Water", 70, 85, 70, 1, "Quaquaval"),
        Pokemon("Quaquaval", "Water/Fighting", 110, 132, 75, 2, ""),

        // Legendary Bosses (stage 0, no evolutions)
        Pokemon("Mewtwo", "Psychic", 60, 50, 25, 0, ""), // Heavilly altered due to the lore.
        Pokemon("Giratina", "Ghost/Dragon", 188, 125, 150, 0, ""),  // 1x
        Pokemon("Palkia", "Water/Dragon", 131, 174, 145, 0, ""),    // 1.25x
        Pokemon("Dialga", "Steel/Dragon", 170, 204, 204, 0, ""),    // 1.5x
    };
}

#endif