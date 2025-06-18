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
            // Gen 1 Starters
            { "Bulbasaur", { {"Vine Whip", 25}, {"Tackle", 20}, {"Razor Leaf", 30} }},
            { "Ivysaur", { {"Vine Whip", 30}, {"Razor Leaf", 35}, {"Seed Bomb", 40} }},
            { "Venusaur", { {"Solar Beam", 80}, {"Earthquake", 70}, {"Sludge Bomb", 65} }},

            { "Charmander", { {"Ember", 25}, {"Scratch", 20}, {"Flamethrower", 30} }},
            { "Charmeleon", { {"Flamethrower", 40}, {"Slash", 35}, {"Fire Fang", 35} }},
            { "Charizard", { {"Flamethrower", 80}, {"Dragon Claw", 60}, {"Blast Burn", 90} }},

            { "Squirtle", { {"Water Gun", 25}, {"Tackle", 20}, {"Bubble Beam", 30} }},
            { "Wartortle", { {"Water Gun", 30}, {"Bite", 35}, {"Rapid Spin", 40} }},
            { "Blastoise", { {"Hydro Pump", 80}, {"Skull Bash", 65}, {"Flash Cannon", 70} }},

            // Gen 2 Starters
            { "Chikorita", { {"Vine Whip", 25}, {"Tackle", 20}, {"Razor Leaf", 30} }},
            { "Bayleef", { {"Vine Whip", 30}, {"Razor Leaf", 35}, {"Body Slam", 40} }},
            { "Meganium", { {"Solar Beam", 80}, {"Earthquake", 70}, {"Sludge Bomb", 65} }},

            { "Cyndaquil", { {"Ember", 25}, {"Scratch", 20}, {"Flamethrower", 30} }},
            { "Quilava", { {"Flamethrower", 40}, {"Slash", 35}, {"Flame Wheel", 35} }},
            { "Typhlosion", { {"Flamethrower", 80}, {"Eruption", 90}, {"Solar Beam", 80} }},

            { "Totodile", { {"Water Gun", 25}, {"Scratch", 20}, {"Bite", 30} }},
            { "Croconaw", { {"Water Pulse", 35}, {"Bite", 35}, {"Ice Fang", 40} }},
            { "Feraligatr", { {"Hydro Pump", 80}, {"Crunch", 60}, {"Earthquake", 70} }},

            // Gen 3 Starters
            { "Treecko", { {"Vine Whip", 25}, {"Tackle", 20}, {"Leaf Blade", 35} }},
            { "Grovyle", { {"Leaf Blade", 40}, {"Brick Break", 35}, {"Agility", 0} }},
            { "Sceptile", { {"Leaf Blade", 80}, {"Dragon Claw", 60}, {"Earthquake", 70} }},

            { "Torchic", { {"Ember", 25}, {"Scratch", 20}, {"Double Kick", 30} }},
            { "Combusken", { {"Flamethrower", 40}, {"Brick Break", 40}, {"Quick Attack", 30} }},
            { "Blaziken", { {"Flamethrower", 80}, {"Sky Uppercut", 70}, {"Blaze Kick", 75} }},

            { "Mudkip", { {"Water Gun", 25}, {"Tackle", 20}, {"Mud Shot", 30} }},
            { "Marshtomp", { {"Mud Shot", 35}, {"Water Pulse", 40}, {"Earthquake", 70} }},
            { "Swampert", { {"Hydro Pump", 80}, {"Earthquake", 80}, {"Mud Shot", 40} }},

            // Gen 4 Starters
            { "Turtwig", { {"Tackle", 20}, {"Razor Leaf", 30}, {"Seed Bomb", 40} }},
            { "Grotle", { {"Razor Leaf", 35}, {"Crunch", 40}, {"Seed Bomb", 50} }},
            { "Torterra", { {"Earthquake", 80}, {"Wood Hammer", 75}, {"Stone Edge", 80} }},

            { "Chimchar", { {"Ember", 25}, {"Scratch", 20}, {"Fire Punch", 35} }},
            { "Monferno", { {"Fire Punch", 40}, {"Brick Break", 40}, {"Flamethrower", 50} }},
            { "Infernape", { {"Flamethrower", 80}, {"Close Combat", 75}, {"Fire Punch", 55} }},

            { "Piplup", { {"Bubble", 20}, {"Peck", 25}, {"Bide", 10} }},
            { "Prinplup", { {"Bubble Beam", 40}, {"Peck", 30}, {"Brine", 40} }},
            { "Empoleon", { {"Hydro Pump", 80}, {"Flash Cannon", 70}, {"Drill Peck", 65} }},

            // Gen 5 Starters
            { "Snivy", { {"Vine Whip", 25}, {"Tackle", 20}, {"Leaf Blade", 40} }},
            { "Servine", { {"Leaf Blade", 40}, {"Aerial Ace", 40}, {"Leech Seed", 35} }},
            { "Serperior", { {"Leaf Blade", 80}, {"Glare", 0}, {"Giga Drain", 75} }},

            { "Tepig", { {"Ember", 25}, {"Tackle", 20}, {"Flame Charge", 40} }},
            { "Pignite", { {"Flamethrower", 50}, {"Brick Break", 40}, {"Flame Charge", 50} }},
            { "Emboar", { {"Flamethrower", 80}, {"Flame Charge", 60}, {"Hammer Arm", 75} }},

            { "Oshawott", { {"Water Gun", 25}, {"Tackle", 20}, {"Razor Shell", 40} }},
            { "Dewott", { {"Razor Shell", 50}, {"Water Pulse", 35}, {"Fury Cutter", 30} }},
            { "Samurott", { {"Hydro Pump", 80}, {"Megahorn", 85}, {"Swords Dance", 0} }},

            // Gen 6 Starters
            { "Chespin", { {"Vine Whip", 25}, {"Tackle", 20}, {"Seed Bomb", 35} }},
            { "Quilladin", { {"Seed Bomb", 45}, {"Tackle", 25}, {"Rollout", 30} }},
            { "Chesnaught", { {"Wood Hammer", 75}, {"Earthquake", 80}, {"Spikes", 0} }},

            { "Fennekin", { {"Ember", 30}, {"Scratch", 20}, {"Psybeam", 50} }},
            { "Braixen", { {"Psybeam", 50}, {"Flamethrower", 60}, {"Fire Spin", 40} }},
            { "Delphox", { {"Flamethrower", 90}, {"Psychic", 90}, {"Fire Blast", 110} }},

            { "Froakie", { {"Pound", 15}, {"Water Gun", 25}, {"Quick Attack", 20} }},
            { "Frogadier", { {"Water Pulse", 40}, {"Quick Attack", 30}, {"Smokescreen", 0} }},
            { "Greninja", { {"Hydro Pump", 80}, {"Dark Pulse", 75}, {"Aerial Ace", 60} }},

            // Gen 7 Starters
            { "Rowlet", { {"Tackle", 20}, {"Leafage", 30}, {"Peck", 25} }},
            { "Dartrix", { {"Leafage", 40}, {"Brave Bird", 70}, {"Fury Attack", 25} }},
            { "Decidueye", { {"Spirit Shackle", 80}, {"Leaf Blade", 90}, {"Sucker Punch", 70} }},

            { "Litten", { {"Scratch", 20}, {"Ember", 25}, {"Bite", 35} }},
            { "Torracat", { {"Flamethrower", 50}, {"Fire Fang", 65}, {"Bite", 45} }},
            { "Infernape", { {"Flamethrower", 90}, {"Close Combat", 75}, {"Flare Blitz", 120} }},

            { "Popplio", { {"Pound", 15}, {"Water Gun", 25}, {"Bubble Beam", 40} }},
            { "Brionne", { {"Water Pulse", 35}, {"Disarming Voice", 40}, {"Aqua Jet", 40} }},
            { "Primarina", { {"Moonblast", 95}, {"Hydro Pump", 110}, {"Aqua Jet", 40} }},

            // Gen 8 Starters
            { "Grookey", { {"Scratch", 20}, {"Branch Poke", 35}, {"Razor Leaf", 30} }},
            { "Thwackey", { {"Branch Poke", 45}, {"Wood Hammer", 75}, {"Fake Out", 40} }},
            { "Rillaboom", { {"Drum Beating", 80}, {"Wood Hammer", 90}, {"Mach Punch", 40} }},

            { "Scorbunny", { {"Ember", 30}, {"Quick Attack", 20}, {"Flame Charge", 40} }},
            { "Raboot", { {"Flame Charge", 50}, {"Double Kick", 30}, {"Pyro Ball", 120} }},
            { "Cinderace", { {"Pyro Ball", 120}, {"High Jump Kick", 85}, {"Feint", 30} }},

            { "Sobble", { {"Tackle", 20}, {"Water Gun", 25}, {"Smokescreen", 0} }},
            { "Drizzile", { {"Water Pulse", 40}, {"Dark Pulse", 75}, {"Aqua Jet", 40} }},
            { "Inteleon", { {"Snipe Shot", 70}, {"Hydro Pump", 110}, {"U-Turn", 70} }},

            // Gen 9 Starters
            { "Sprigatito", { {"Tackle", 20}, {"Leafage", 25}, {"Razor Leaf", 30} }},
            { "Floragato", { {"Scratch", 30}, {"Leaf Blade", 70}, {"Bite", 60} }},
            { "Meowscarada", { {"Flower Trick", 70}, {"Knock Off", 20}, {"Leaf Blade", 90} }},

            { "Fuecoco", { {"Ember", 25}, {"Bite", 60}, {"Fire Fang", 65} }},
            { "Crocalor", { {"Fire Fang", 65}, {"Crunch", 80}, {"Flamethrower", 90} }},
            { "Skeledirge", { {"Torch Song", 80}, {"Flamethrower", 90}, {"Shadow Ball", 80} }},

            { "Quaxly", { {"Water Gun", 25}, {"Tackle", 20}, {"Peck", 35} }},
            { "Quaxwell", { {"Fury Attack", 28}, {"Water Pulse", 60}, {"Brave Bird", 70} }},
            { "Quaquaval", { {"Liquidation", 85}, {"Close Combat", 120}, {"Aqua Jet", 40} }},

            // Legendary Bosses attacks (basic)
            { "Mewtwo", { {"Psystrike", 50}, {"Shadow Ball", 60} }},
            { "Giratina", { {"Shadow Force", 50}, {"Dragon Claw", 80}, {"Aura Sphere", 60} }},
            { "Palkia", { {"Spacial Rend", 50}, {"Hydro Pump", 80}, {"Dragon Pulse", 60} }},
            { "Dialga", { {"Roar of Time", 60}, {"Flash Cannon", 85}, {"Dragon Breath", 60} }},
        };
    }

    vector<Attack> getAttacksForPokemon(const string& pokemonName) const {
        auto it = attackMap.find(pokemonName);
        if (it != attackMap.end()) {
            return it->second;
        }
        return {};
    }
};

#endif