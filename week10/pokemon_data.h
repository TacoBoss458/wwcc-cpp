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

    Pokemon(string n, string t, int h, int a, int d)
        : name(n), type(t), hp(h), attack(a), defense(d) {}
};

vector<Pokemon> getStarterPokemon() {
    return {
        // Generation 1 - Kanto
        Pokemon("Bulbasaur", "Grass", 45, 49, 49),
        Pokemon("Ivysaur", "Grass", 60, 62, 63),
        Pokemon("Venusaur", "Grass", 80, 82, 83),

        Pokemon("Charmander", "Fire", 39, 52, 43),
        Pokemon("Charmeleon", "Fire", 58, 64, 58),
        Pokemon("Charizard", "Fire/Flying", 78, 84, 78),

        Pokemon("Squirtle", "Water", 44, 48, 65),
        Pokemon("Wartortle", "Water", 59, 63, 80),
        Pokemon("Blastoise", "Water", 79, 83, 100),

        // Generation 2 - Johto
        Pokemon("Chikorita", "Grass", 45, 49, 65),
        Pokemon("Bayleef", "Grass", 60, 62, 80),
        Pokemon("Meganium", "Grass", 80, 82, 100),

        Pokemon("Cyndaquil", "Fire", 39, 52, 43),
        Pokemon("Quilava", "Fire", 58, 64, 58),
        Pokemon("Typhlosion", "Fire", 78, 84, 78),

        Pokemon("Totodile", "Water", 50, 65, 64),
        Pokemon("Croconaw", "Water", 65, 80, 80),
        Pokemon("Feraligatr", "Water", 85, 105, 100),

        // Generation 3 - Hoenn
        Pokemon("Treecko", "Grass", 40, 45, 35),
        Pokemon("Grovyle", "Grass", 50, 65, 45),
        Pokemon("Sceptile", "Grass", 70, 85, 65),

        Pokemon("Torchic", "Fire", 45, 60, 40),
        Pokemon("Combusken", "Fire/Fighting", 60, 85, 60),
        Pokemon("Blaziken", "Fire/Fighting", 80, 120, 70),

        Pokemon("Mudkip", "Water", 50, 70, 50),
        Pokemon("Marshtomp", "Water/Ground", 70, 85, 70),
        Pokemon("Swampert", "Water/Ground", 100, 110, 90),

        // Generation 4 - Sinnoh
        Pokemon("Turtwig", "Grass", 55, 68, 64),
        Pokemon("Grotle", "Grass", 75, 89, 85),
        Pokemon("Torterra", "Grass/Ground", 95, 109, 105),

        Pokemon("Chimchar", "Fire", 44, 58, 44),
        Pokemon("Monferno", "Fire/Fighting", 64, 78, 52),
        Pokemon("Infernape", "Fire/Fighting", 76, 104, 71),

        Pokemon("Piplup", "Water", 53, 51, 53),
        Pokemon("Prinplup", "Water", 64, 66, 68),
        Pokemon("Empoleon", "Water/Steel", 84, 86, 88),

        // Generation 5 - Unova
        Pokemon("Snivy", "Grass", 45, 45, 55),
        Pokemon("Servine", "Grass", 60, 60, 75),
        Pokemon("Serperior", "Grass", 75, 75, 95),

        Pokemon("Tepig", "Fire", 65, 63, 45),
        Pokemon("Pignite", "Fire/Fighting", 90, 93, 55),
        Pokemon("Emboar", "Fire/Fighting", 110, 123, 65),

        Pokemon("Oshawott", "Water", 55, 55, 45),
        Pokemon("Dewott", "Water", 75, 75, 60),
        Pokemon("Samurott", "Water", 95, 100, 85),

        // Generation 6 - Kalos
        Pokemon("Chespin", "Grass", 56, 61, 65),
        Pokemon("Quilladin", "Grass", 61, 78, 95),
        Pokemon("Chesnaught", "Grass/Fighting", 88, 107, 122),

        Pokemon("Fennekin", "Fire", 40, 45, 40),
        Pokemon("Braixen", "Fire", 59, 59, 58),
        Pokemon("Delphox", "Fire/Psychic", 75, 69, 72),

        Pokemon("Froakie", "Water", 41, 56, 40),
        Pokemon("Frogadier", "Water", 54, 63, 52),
        Pokemon("Greninja", "Water/Dark", 72, 95, 67),

        // Generation 7 - Alola
        Pokemon("Rowlet", "Grass/Flying", 68, 55, 55),
        Pokemon("Dartrix", "Grass/Flying", 78, 75, 75),
        Pokemon("Decidueye", "Grass/Ghost", 78, 107, 75),

        Pokemon("Litten", "Fire", 45, 65, 40),
        Pokemon("Torracat", "Fire", 65, 85, 50),
        Pokemon("Incineroar", "Fire/Dark", 95, 115, 90),

        Pokemon("Popplio", "Water", 50, 54, 54),
        Pokemon("Brionne", "Water", 60, 69, 69),
        Pokemon("Primarina", "Water/Fairy", 80, 74, 74),

        // Generation 8 - Galar
        Pokemon("Grookey", "Grass", 50, 65, 50),
        Pokemon("Thwackey", "Grass", 70, 85, 70),
        Pokemon("Rillaboom", "Grass", 100, 125, 90),

        Pokemon("Scorbunny", "Fire", 50, 71, 40),
        Pokemon("Raboot", "Fire", 65, 86, 60),
        Pokemon("Cinderace", "Fire", 80, 116, 75),

        Pokemon("Sobble", "Water", 60, 40, 40),
        Pokemon("Drizzile", "Water", 65, 60, 55),
        Pokemon("Inteleon", "Water", 70, 85, 65),

        // Generation 9 - Paldea
        Pokemon("Sprigatito", "Grass", 40, 61, 54),
        Pokemon("Floragato", "Grass", 61, 80, 63),
        Pokemon("Meowscarada", "Grass/Dark", 76, 110, 70),

        Pokemon("Fuecoco", "Fire", 67, 45, 59),
        Pokemon("Crocalor", "Fire", 81, 55, 78),
        Pokemon("Skeledirge", "Fire/Ghost", 104, 75, 100),

        Pokemon("Quaxly", "Water", 55, 65, 45),
        Pokemon("Quaxwell", "Water", 70, 85, 65),
        Pokemon("Quaquaval", "Water/Fighting", 85, 120, 80)
    };
}

#endif // POKEMON_DATA_H
