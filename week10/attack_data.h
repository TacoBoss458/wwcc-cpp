#ifndef ATTACK_DATA_H
#define ATTACK_DATA_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Attack {
    string name;
    int damage;
    Attack(string n, int d) : name(n), damage(d) {}
};

class AttackDatabase {
public:
    unordered_map<string, vector<Attack>> attackMap;

    AttackDatabase() {
        attackMap = {
            {"Bayleef", {
            Attack("Bayleef Strike", 20),
            Attack("Bayleef Blast", 25),
            Attack("Bayleef Fury", 30)
        }},
            {"Blastoise", {
            Attack("Blastoise Strike", 20),
            Attack("Blastoise Blast", 25),
            Attack("Blastoise Fury", 30)
        }},
            {"Blaziken", {
            Attack("Blaziken Strike", 20),
            Attack("Blaziken Blast", 25),
            Attack("Blaziken Fury", 30)
        }},
            {"Braixen", {
            Attack("Braixen Strike", 20),
            Attack("Braixen Blast", 25),
            Attack("Braixen Fury", 30)
        }},
            {"Brionne", {
            Attack("Brionne Strike", 20),
            Attack("Brionne Blast", 25),
            Attack("Brionne Fury", 30)
        }},
            {"Bulbasaur", {
            Attack("Bulbasaur Strike", 20),
            Attack("Bulbasaur Blast", 25),
            Attack("Bulbasaur Fury", 30)
        }},
            {"Charizard", {
            Attack("Charizard Strike", 20),
            Attack("Charizard Blast", 25),
            Attack("Charizard Fury", 30)
        }},
            {"Charmander", {
            Attack("Charmander Strike", 20),
            Attack("Charmander Blast", 25),
            Attack("Charmander Fury", 30)
        }},
            {"Charmeleon", {
            Attack("Charmeleon Strike", 20),
            Attack("Charmeleon Blast", 25),
            Attack("Charmeleon Fury", 30)
        }},
            {"Chesnaught", {
            Attack("Chesnaught Strike", 20),
            Attack("Chesnaught Blast", 25),
            Attack("Chesnaught Fury", 30)
        }},
            {"Chespin", {
            Attack("Chespin Strike", 20),
            Attack("Chespin Blast", 25),
            Attack("Chespin Fury", 30)
        }},
            {"Chikorita", {
            Attack("Chikorita Strike", 20),
            Attack("Chikorita Blast", 25),
            Attack("Chikorita Fury", 30)
        }},
            {"Chimchar", {
            Attack("Chimchar Strike", 20),
            Attack("Chimchar Blast", 25),
            Attack("Chimchar Fury", 30)
        }},
            {"Cinderace", {
            Attack("Cinderace Strike", 20),
            Attack("Cinderace Blast", 25),
            Attack("Cinderace Fury", 30)
        }},
            {"Combusken", {
            Attack("Combusken Strike", 20),
            Attack("Combusken Blast", 25),
            Attack("Combusken Fury", 30)
        }},
            {"Crocalor", {
            Attack("Crocalor Strike", 20),
            Attack("Crocalor Blast", 25),
            Attack("Crocalor Fury", 30)
        }},
            {"Croconaw", {
            Attack("Croconaw Strike", 20),
            Attack("Croconaw Blast", 25),
            Attack("Croconaw Fury", 30)
        }},
            {"Cyndaquil", {
            Attack("Cyndaquil Strike", 20),
            Attack("Cyndaquil Blast", 25),
            Attack("Cyndaquil Fury", 30)
        }},
            {"Dartrix", {
            Attack("Dartrix Strike", 20),
            Attack("Dartrix Blast", 25),
            Attack("Dartrix Fury", 30)
        }},
            {"Decidueye", {
            Attack("Decidueye Strike", 20),
            Attack("Decidueye Blast", 25),
            Attack("Decidueye Fury", 30)
        }},
            {"Delphox", {
            Attack("Delphox Strike", 20),
            Attack("Delphox Blast", 25),
            Attack("Delphox Fury", 30)
        }},
            {"Dewott", {
            Attack("Dewott Strike", 20),
            Attack("Dewott Blast", 25),
            Attack("Dewott Fury", 30)
        }},
            {"Drizzile", {
            Attack("Drizzile Strike", 20),
            Attack("Drizzile Blast", 25),
            Attack("Drizzile Fury", 30)
        }},
            {"Emboar", {
            Attack("Emboar Strike", 20),
            Attack("Emboar Blast", 25),
            Attack("Emboar Fury", 30)
        }},
            {"Empoleon", {
            Attack("Empoleon Strike", 20),
            Attack("Empoleon Blast", 25),
            Attack("Empoleon Fury", 30)
        }},
            {"Fennekin", {
            Attack("Fennekin Strike", 20),
            Attack("Fennekin Blast", 25),
            Attack("Fennekin Fury", 30)
        }},
            {"Feraligatr", {
            Attack("Feraligatr Strike", 20),
            Attack("Feraligatr Blast", 25),
            Attack("Feraligatr Fury", 30)
        }},
            {"Floragato", {
            Attack("Floragato Strike", 20),
            Attack("Floragato Blast", 25),
            Attack("Floragato Fury", 30)
        }},
            {"Froakie", {
            Attack("Froakie Strike", 20),
            Attack("Froakie Blast", 25),
            Attack("Froakie Fury", 30)
        }},
            {"Frogadier", {
            Attack("Frogadier Strike", 20),
            Attack("Frogadier Blast", 25),
            Attack("Frogadier Fury", 30)
        }},
            {"Fuecoco", {
            Attack("Fuecoco Strike", 20),
            Attack("Fuecoco Blast", 25),
            Attack("Fuecoco Fury", 30)
        }},
            {"Greninja", {
            Attack("Greninja Strike", 20),
            Attack("Greninja Blast", 25),
            Attack("Greninja Fury", 30)
        }},
            {"Grookey", {
            Attack("Grookey Strike", 20),
            Attack("Grookey Blast", 25),
            Attack("Grookey Fury", 30)
        }},
            {"Grotle", {
            Attack("Grotle Strike", 20),
            Attack("Grotle Blast", 25),
            Attack("Grotle Fury", 30)
        }},
            {"Grovyle", {
            Attack("Grovyle Strike", 20),
            Attack("Grovyle Blast", 25),
            Attack("Grovyle Fury", 30)
        }},
            {"Incineroar", {
            Attack("Incineroar Strike", 20),
            Attack("Incineroar Blast", 25),
            Attack("Incineroar Fury", 30)
        }},
            {"Infernape", {
            Attack("Infernape Strike", 20),
            Attack("Infernape Blast", 25),
            Attack("Infernape Fury", 30)
        }},
            {"Inteleon", {
            Attack("Inteleon Strike", 20),
            Attack("Inteleon Blast", 25),
            Attack("Inteleon Fury", 30)
        }},
            {"Ivysaur", {
            Attack("Ivysaur Strike", 20),
            Attack("Ivysaur Blast", 25),
            Attack("Ivysaur Fury", 30)
        }},
            {"Litten", {
            Attack("Litten Strike", 20),
            Attack("Litten Blast", 25),
            Attack("Litten Fury", 30)
        }},
            {"Marshtomp", {
            Attack("Marshtomp Strike", 20),
            Attack("Marshtomp Blast", 25),
            Attack("Marshtomp Fury", 30)
        }},
            {"Meganium", {
            Attack("Meganium Strike", 20),
            Attack("Meganium Blast", 25),
            Attack("Meganium Fury", 30)
        }},
            {"Meowscarada", {
            Attack("Meowscarada Strike", 20),
            Attack("Meowscarada Blast", 25),
            Attack("Meowscarada Fury", 30)
        }},
            {"Monferno", {
            Attack("Monferno Strike", 20),
            Attack("Monferno Blast", 25),
            Attack("Monferno Fury", 30)
        }},
            {"Mudkip", {
            Attack("Mudkip Strike", 20),
            Attack("Mudkip Blast", 25),
            Attack("Mudkip Fury", 30)
        }},
            {"Oshawott", {
            Attack("Oshawott Strike", 20),
            Attack("Oshawott Blast", 25),
            Attack("Oshawott Fury", 30)
        }},
            {"Pignite", {
            Attack("Pignite Strike", 20),
            Attack("Pignite Blast", 25),
            Attack("Pignite Fury", 30)
        }},
            {"Piplup", {
            Attack("Piplup Strike", 20),
            Attack("Piplup Blast", 25),
            Attack("Piplup Fury", 30)
        }},
            {"Popplio", {
            Attack("Popplio Strike", 20),
            Attack("Popplio Blast", 25),
            Attack("Popplio Fury", 30)
        }},
            {"Primarina", {
            Attack("Primarina Strike", 20),
            Attack("Primarina Blast", 25),
            Attack("Primarina Fury", 30)
        }},
            {"Prinplup", {
            Attack("Prinplup Strike", 20),
            Attack("Prinplup Blast", 25),
            Attack("Prinplup Fury", 30)
        }},
            {"Quaquaval", {
            Attack("Quaquaval Strike", 20),
            Attack("Quaquaval Blast", 25),
            Attack("Quaquaval Fury", 30)
        }},
            {"Quaxly", {
            Attack("Quaxly Strike", 20),
            Attack("Quaxly Blast", 25),
            Attack("Quaxly Fury", 30)
        }},
            {"Quaxwell", {
            Attack("Quaxwell Strike", 20),
            Attack("Quaxwell Blast", 25),
            Attack("Quaxwell Fury", 30)
        }},
            {"Quilava", {
            Attack("Quilava Strike", 20),
            Attack("Quilava Blast", 25),
            Attack("Quilava Fury", 30)
        }},
            {"Quilladin", {
            Attack("Quilladin Strike", 20),
            Attack("Quilladin Blast", 25),
            Attack("Quilladin Fury", 30)
        }},
            {"Raboot", {
            Attack("Raboot Strike", 20),
            Attack("Raboot Blast", 25),
            Attack("Raboot Fury", 30)
        }},
            {"Rillaboom", {
            Attack("Rillaboom Strike", 20),
            Attack("Rillaboom Blast", 25),
            Attack("Rillaboom Fury", 30)
        }},
            {"Rowlet", {
            Attack("Rowlet Strike", 20),
            Attack("Rowlet Blast", 25),
            Attack("Rowlet Fury", 30)
        }},
            {"Samurott", {
            Attack("Samurott Strike", 20),
            Attack("Samurott Blast", 25),
            Attack("Samurott Fury", 30)
        }},
            {"Sceptile", {
            Attack("Sceptile Strike", 20),
            Attack("Sceptile Blast", 25),
            Attack("Sceptile Fury", 30)
        }},
            {"Scorbunny", {
            Attack("Scorbunny Strike", 20),
            Attack("Scorbunny Blast", 25),
            Attack("Scorbunny Fury", 30)
        }},
            {"Serperior", {
            Attack("Serperior Strike", 20),
            Attack("Serperior Blast", 25),
            Attack("Serperior Fury", 30)
        }},
            {"Servine", {
            Attack("Servine Strike", 20),
            Attack("Servine Blast", 25),
            Attack("Servine Fury", 30)
        }},
            {"Skeledirge", {
            Attack("Skeledirge Strike", 20),
            Attack("Skeledirge Blast", 25),
            Attack("Skeledirge Fury", 30)
        }},
            {"Snivy", {
            Attack("Snivy Strike", 20),
            Attack("Snivy Blast", 25),
            Attack("Snivy Fury", 30)
        }},
            {"Sobble", {
            Attack("Sobble Strike", 20),
            Attack("Sobble Blast", 25),
            Attack("Sobble Fury", 30)
        }},
            {"Sprigatito", {
            Attack("Sprigatito Strike", 20),
            Attack("Sprigatito Blast", 25),
            Attack("Sprigatito Fury", 30)
        }},
            {"Squirtle", {
            Attack("Squirtle Strike", 20),
            Attack("Squirtle Blast", 25),
            Attack("Squirtle Fury", 30)
        }},
            {"Swampert", {
            Attack("Swampert Strike", 20),
            Attack("Swampert Blast", 25),
            Attack("Swampert Fury", 30)
        }},
            {"Tepig", {
            Attack("Tepig Strike", 20),
            Attack("Tepig Blast", 25),
            Attack("Tepig Fury", 30)
        }},
            {"Thwackey", {
            Attack("Thwackey Strike", 20),
            Attack("Thwackey Blast", 25),
            Attack("Thwackey Fury", 30)
        }},
            {"Torchic", {
            Attack("Torchic Strike", 20),
            Attack("Torchic Blast", 25),
            Attack("Torchic Fury", 30)
        }},
            {"Torracat", {
            Attack("Torracat Strike", 20),
            Attack("Torracat Blast", 25),
            Attack("Torracat Fury", 30)
        }},
            {"Torterra", {
            Attack("Torterra Strike", 20),
            Attack("Torterra Blast", 25),
            Attack("Torterra Fury", 30)
        }},
            {"Totodile", {
            Attack("Totodile Strike", 20),
            Attack("Totodile Blast", 25),
            Attack("Totodile Fury", 30)
        }},
            {"Treecko", {
            Attack("Treecko Strike", 20),
            Attack("Treecko Blast", 25),
            Attack("Treecko Fury", 30)
        }},
            {"Turtwig", {
            Attack("Turtwig Strike", 20),
            Attack("Turtwig Blast", 25),
            Attack("Turtwig Fury", 30)
        }},
            {"Typhlosion", {
            Attack("Typhlosion Strike", 20),
            Attack("Typhlosion Blast", 25),
            Attack("Typhlosion Fury", 30)
        }},
            {"Venusaur", {
            Attack("Venusaur Strike", 20),
            Attack("Venusaur Blast", 25),
            Attack("Venusaur Fury", 30)
        }},
            {"Wartortle", {
            Attack("Wartortle Strike", 20),
            Attack("Wartortle Blast", 25),
            Attack("Wartortle Fury", 30)
        }}
        };
    }

    vector<Attack> getAttacks(const string& pokemonName) {
        if (attackMap.find(pokemonName) != attackMap.end()) {
            return attackMap[pokemonName];
        }
        return {};
    }
};

#endif // ATTACK_DATA_H
