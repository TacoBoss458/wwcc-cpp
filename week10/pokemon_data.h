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
    int stage;
    string evolvesTo;

    Pokemon(string n, string t, int h, int a, int d, int s = 0, string evo = "")
        : name(n), type(t), hp(h), attack(a), defense(d), stage(s), evolvesTo(evo) {}
};

vector<Pokemon> getStarterPokemon() {
    return {
        // Generation 1
        Pokemon("Bulbasaur", "Grass", 45, 49, 49, 0, ""),
        Pokemon("Ivysaur", "Grass", 60, 62, 63, 6, "Combusken"),
        Pokemon("Venusaur", "Grass", 80, 82, 83, 35, "Blaziken"),
        Pokemon("Charmander", "Fire", 39, 52, 43, 0, ""),
        Pokemon("Charmeleon", "Fire", 58, 64, 58, 2, "Quilava"),
        Pokemon("Charizard", "Fire/Flying", 78, 84, 78, 30, "Typhlosion"),
        Pokemon("Squirtle", "Water", 44, 48, 65, 0, ""),
        Pokemon("Wartortle", "Water", 59, 63, 80, 4, "Braixen"),
        Pokemon("Blastoise", "Water", 79, 83, 100, 34, "Venusaur"),

        // Generation 2
        Pokemon("Chikorita", "Grass", 45, 49, 65, 0, ""),
        Pokemon("Bayleef", "Grass", 60, 62, 80, 0, ""),
        Pokemon("Meganium", "Grass", 80, 82, 100, 0, ""),
        Pokemon("Cyndaquil", "Fire", 39, 52, 43, 0, ""),
        Pokemon("Quilava", "Fire", 58, 64, 58, 3, "Wartortle"),
        Pokemon("Typhlosion", "Fire", 78, 84, 78, 31, "Dartrix"),
        Pokemon("Totodile", "Water", 50, 65, 64, 0, ""),
        Pokemon("Croconaw", "Water", 65, 80, 80, 14, "Torracat"),
        Pokemon("Feraligatr", "Water", 85, 105, 100, 41, "Quaquaval"),

        // Generation 3
        Pokemon("Treecko", "Grass", 40, 45, 35, 0, ""),
        Pokemon("Grovyle", "Grass", 50, 65, 45, 0, "Frogadier"),
        Pokemon("Sceptile", "Grass", 70, 85, 65, 18, "Marshtomp"),
        Pokemon("Torchic", "Fire", 45, 60, 40, 0, ""),
        Pokemon("Combusken", "Fire/Fighting", 60, 85, 60, 7, "Servine"),
        Pokemon("Blaziken", "Fire/Fighting", 80, 120, 70, 36, "Primarina"),
        Pokemon("Mudkip", "Water", 50, 70, 50, 0, ""),
        Pokemon("Marshtomp", "Water/Ground", 70, 85, 70, 19, "Thwackey"),
        Pokemon("Swampert", "Water/Ground", 100, 110, 90, 48, "Rillaboom"),

        // Generation 4
        Pokemon("Turtwig", "Grass", 55, 68, 64, 0, ""),
        Pokemon("Grotle", "Grass", 75, 89, 85, 24, "Serperior"),
        Pokemon("Torterra", "Grass/Ground", 95, 109, 105, 45, "Samurott"),
        Pokemon("Chimchar", "Fire", 44, 58, 44, 0, ""),
        Pokemon("Monferno", "Fire/Fighting", 64, 78, 52, 12, "Prinplup"),
        Pokemon("Infernape", "Fire/Fighting", 76, 104, 71, 28, "Meowscarada"),
        Pokemon("Piplup", "Water", 53, 51, 53, 0, ""),
        Pokemon("Prinplup", "Water", 64, 66, 68, 13, "Croconaw"),
        Pokemon("Empoleon", "Water/Steel", 84, 86, 88, 40, "Feraligatr"),

        // Generation 5
        Pokemon("Snivy", "Grass", 45, 45, 55, 0, ""),
        Pokemon("Servine", "Grass", 60, 60, 75, 8, "Brionne"),
        Pokemon("Serperior", "Grass", 75, 75, 95, 25, "Dewott"),
        Pokemon("Tepig", "Fire", 65, 63, 45, 0, ""),
        Pokemon("Pignite", "Fire/Fighting", 90, 93, 55, 44, "Torterra"),
        Pokemon("Emboar", "Fire/Fighting", 110, 123, 65, 51, ""),
        Pokemon("Oshawott", "Water", 55, 55, 45, 0, ""),
        Pokemon("Dewott", "Water", 75, 75, 60, 26, "Delphox"),
        Pokemon("Samurott", "Water", 95, 100, 85, 46, "Incineroar"),

        // Generation 6
        Pokemon("Chespin", "Grass", 56, 61, 65, 0, ""),
        Pokemon("Quilladin", "Grass", 61, 78, 95, 10, "Floragato"),
        Pokemon("Chesnaught", "Grass/Fighting", 88, 107, 122, 43, "Pignite"),
        Pokemon("Fennekin", "Fire", 40, 45, 40, 0, ""),
        Pokemon("Braixen", "Fire", 59, 59, 58, 5, "Ivysaur"),
        Pokemon("Delphox", "Fire/Psychic", 75, 69, 72, 27, "Infernape"),
        Pokemon("Froakie", "Water", 41, 56, 40, 0, ""),
        Pokemon("Frogadier", "Water", 54, 63, 52, 1, "Charmeleon"),
        Pokemon("Greninja", "Water/Dark", 72, 95, 67, 23, "Grotle"),

        // Generation 7
        Pokemon("Rowlet", "Grass/Flying", 68, 55, 55, 0, ""),
        Pokemon("Dartrix", "Grass/Flying", 78, 75, 75, 32, "Decidueye"),
        Pokemon("Decidueye", "Grass/Ghost", 78, 107, 75, 33, "Blastoise"),
        Pokemon("Litten", "Fire", 45, 65, 40, 0, ""),
        Pokemon("Torracat", "Fire", 65, 85, 50, 15, "Raboot"),
        Pokemon("Incineroar", "Fire/Dark", 95, 115, 90, 47, "Swampert"),
        Pokemon("Popplio", "Water", 50, 54, 54, 0, ""),
        Pokemon("Brionne", "Water", 60, 69, 69, 9, "Quilladin"),
        Pokemon("Primarina", "Water/Fairy", 80, 74, 74, 37, "Cinderace"),

        // Generation 8
        Pokemon("Grookey", "Grass", 50, 65, 50, 0, ""),
        Pokemon("Thwackey", "Grass", 70, 85, 70, 20, "Inteleon"),
        Pokemon("Rillaboom", "Grass", 100, 125, 90, 49, "Skeledirge"),
        Pokemon("Scorbunny", "Fire", 50, 71, 40, 0, ""),
        Pokemon("Raboot", "Fire", 65, 86, 60, 16, "Drizzile"),
        Pokemon("Cinderace", "Fire", 80, 116, 75, 38, "Crocalor"),
        Pokemon("Sobble", "Water", 60, 40, 40, 0, ""),
        Pokemon("Drizzile", "Water", 65, 60, 55, 17, "Sceptile"),
        Pokemon("Inteleon", "Water", 70, 85, 65, 21, "Quaxwell"),

        // Generation 9
        Pokemon("Sprigatito", "Grass", 40, 61, 54, 0, ""),
        Pokemon("Floragato", "Grass", 61, 80, 63, 11, "Monferno"),
        Pokemon("Meowscarada", "Grass/Dark", 76, 110, 70, 29, "Charizard"),
        Pokemon("Fuecoco", "Fire", 67, 45, 59, 0, ""),
        Pokemon("Crocalor", "Fire", 81, 55, 78, 39, "Empoleon"),
        Pokemon("Skeledirge", "Fire/Ghost", 104, 75, 100, 50, "Emboar"),
        Pokemon("Quaxly", "Water", 55, 65, 45, 0, ""),
        Pokemon("Quaxwell", "Water", 70, 85, 65, 22, "Greninja"),
        Pokemon("Quaquaval", "Water/Fighting", 85, 120, 80, 42, "Chesnaught"),
    };
}

#endif // POKEMON_DATA_H