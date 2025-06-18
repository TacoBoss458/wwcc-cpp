# PokeCode!

## How to Play

Once you run the code, you'll be given the prompt to select 5 Pokemon to create a team. 
This team will fight 3 mini bosses and one final boss while evolving into stronger Pokemon along the way.
The rooms will get harder and harder with variables limiting Pokemon and stat multipliers making bosses harder. 
The goal is to kill all the bosses. 

## Story Synopsis
The backstory behind this starts long ago when an elite squad of 4 Pokemon took power over all other Pokemon.
These 4 soldiers were Mewtwo, Giratina, Palkia, and the leader of them all, Dialga.
Their athority would soon be questioned by the Pokemon on whether they were strong enough to remain in power.
So, they sent in their strongest, smartest warrior to battle the Pokemon leaders... you!
Your job is to go into the Legendary Gyms and take out those pokemon!

Boss Lore:
Mewtwo is the weakest of the elite. Mewtwo is very old and doesnt have the strength like they once had. 
Giratina is about as strong as shes ever been. She fights daily, holding matches and illegal cagefighting. 
Palkia commands the seas and is stronger than any given stage 2 pokemon. 
They'res verry little known about Dialga. Mostly 2 things stand out. They construct their work in silence and behind the scenes, and they may or may not be a god. Only Palkia has seen Dialga in the past 300 centuries. 

## Controls

- Enter numbers to make choices

## Features Implemented

- Variables (Multiple Types)
  int, string, vector, bool, chrono::system_clock::time_point
- Control Structure
  if, else, switch, case, while, for, break, continue
- Functions
  With return values: main(), getGyms(), getAllPokemon(), etc.
  With parameters: battle(...), filterTeamForGym(...), etc.
  Void functions: printBattleBanner(...), evolveTeam(...)
- Loops
  Traditional for loops (e.g., Pokémon selection)
  while loops (e.g., menu loop, input validation)
  Range-based for loops (modern C++ feature)
- Enums
  Enum class BattleResult { Victory, Defeat };
- Structs and Classes
  struct AdventureLog
  class Pokemon, class AttackDatabase
- File I/O
  Reading: ifstream in("Adventures.txt");
  Writing: ofstream out("Adventures.txt", ios::app);
- Error Handling
  cin.fail() and cin.clear() for input validation
- Time Handling
  chrono::system_clock::now()
  ctime() for formatting time

## File Structure

- final.cpp: Main game logic
- attack_data.h
- battle_system.h
- Adventures.txt
- pokemon_data.h
- utilities.h

## Challenges Faced

-The overall battle system and the idea of how I wanted to set up the fights. Probably went through 7 different systems before I got one I actually liked.
-Making a story
-Researching how to code ceartian spots

## Future Improvements

- Create a better story
- Add more statistics
- Add the entire pokemon library(my initial idea)
- Change damage calculator
- More variables to the rooms and bosses like adding abilities and stat mults for the user or debufs and items. 
- The ability to change Pokemon when they faint after beating a boss
- Final boss 5v1 would've been cool
- Eliminating potential missed bloatcode that isnt being used
