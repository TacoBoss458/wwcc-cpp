#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Recipe {
public:
    string name;
    vector<string> ingredients;
    vector<string> steps;

    Recipe(string name) {
        this->name = name;
    }

    void addIngredient(const string& ingredient) {
        ingredients.push_back(ingredient);
    }

    void addStep(const string& step) {
        steps.push_back(step);
    }

    void display() const {
        cout << "\nRecipe: " << name << endl;
        cout << "Ingredients:\n";
        for (const auto& ing : ingredients) {
            cout << "  - " << ing << endl;
        }
        cout << "Steps:\n";
        for (const auto& st : steps) {
            cout << "  - " << st << endl;
        }
    }
};

class RecipeManager {
private:
    vector<Recipe> recipes;

public:
    void addRecipe(const Recipe& recipe) {
        recipes.push_back(recipe);
    }

    void displayAllRecipes() const {
        if (recipes.empty()) {
            cout << "No recipes available.\n";
            return;
        }
        for (const auto& recipe : recipes) {
            recipe.display();
        }
    }

    void searchByName(const string& keyword) const {
        bool found = false;
        for (const auto& recipe : recipes) {
            if (recipe.name.find(keyword) != string::npos) {
                recipe.display();
                found = true;
            }
        }
        if (!found) cout << "No recipe found with that name.\n";
    }

    void searchByIngredient(const string& keyword) const {
        bool found = false;
        for (const auto& recipe : recipes) {
            for (const auto& ing : recipe.ingredients) {
                if (ing.find(keyword) != string::npos) {
                    recipe.display();
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << "No recipe found with that ingredient.\n";
    }

    void removeRecipe(const string& name) {
        bool found = false;
        for (auto it = recipes.begin(); it != recipes.end(); ++it) {
            if (it->name == name) {
                recipes.erase(it);
                cout << "Recipe removed.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Recipe not found.\n";
        }
    }

    void displayStatistics() const {
        int total = recipes.size();
        if (total == 0) {
            cout << "No recipes to calculate statistics.\n";
            return;
        }

        int totalIngredients = 0, totalSteps = 0;
        for (const auto& r : recipes) {
            totalIngredients += r.ingredients.size();
            totalSteps += r.steps.size();
        }

        cout << "Total recipes: " << total << endl;
        cout << "Average ingredients per recipe: " << (totalIngredients / total) << endl;
        cout << "Average steps per recipe: " << (totalSteps / total) << endl;
    }
};

int main() {
    RecipeManager manager;
    int choice;
    string name, input;

    do {
        cout << "\n--- Recipe Manager ---\n";
        cout << "1. Add Recipe\n";
        cout << "2. Display All Recipes\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by Ingredient\n";
        cout << "5. Remove Recipe\n";
        cout << "6. Show Statistics\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter recipe name: ";
                getline(cin, name);
                if (name.empty()) {
                    cout << "Name cannot be empty.\n";
                    break;
                }
                Recipe recipe(name);

                cout << "Enter ingredients (type 'done' to finish):\n";
                while (true) {
                    getline(cin, input);
                    if (input == "done") break;
                    if (!input.empty()) recipe.addIngredient(input);
                }

                cout << "Enter steps (type 'done' to finish):\n";
                while (true) {
                    getline(cin, input);
                    if (input == "done") break;
                    if (!input.empty()) recipe.addStep(input);
                }

                manager.addRecipe(recipe);
                break;
            }
            case 2:
                manager.displayAllRecipes();
                break;
            case 3:
                cout << "Enter name to search: ";
                getline(cin, name);
                manager.searchByName(name);
                break;
            case 4:
                cout << "Enter ingredient to search: ";
                getline(cin, name);
                manager.searchByIngredient(name);
                break;
            case 5:
                cout << "Enter recipe name to remove: ";
                getline(cin, name);
                manager.removeRecipe(name);
                break;
            case 6:
                manager.displayStatistics();
                break;
            case 7:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
