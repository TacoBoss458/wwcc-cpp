
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>

using namespace std;

class MediaItem {
protected:
    string title, creator, dateAdded;
    int yearReleased, length, timesAccessed;
    double rating;
    vector<string> genres, tags;

public:
    MediaItem(string t, string c, int year, double r, int len,
              vector<string> g, vector<string> tg, string date)
        : title(t), creator(c), yearReleased(year), rating(r), length(len),
          genres(g), tags(tg), timesAccessed(0), dateAdded(date) {}

    virtual ~MediaItem() {}
    virtual void display() const {
        cout << "Title: " << title << "\nCreator: " << creator
             << "\nYear: " << yearReleased << "\nRating: " << rating
             << "\nLength: " << length << "\nGenres: ";
        for (auto& g : genres) cout << g << " ";
        cout << "\nTags: ";
        for (auto& t : tags) cout << t << " ";
        cout << "\nAccessed: " << timesAccessed << "\nDate Added: " << dateAdded << "\n";
    }
    void access() { ++timesAccessed; }
    string getTitle() const { return title; }
    string getCreator() const { return creator; }
    int getYearReleased() const { return yearReleased; }
    double getRating() const { return rating; }
    int getTimesAccessed() const { return timesAccessed; }
    vector<string> getGenres() const { return genres; }
    virtual string getType() const = 0;
};

class Movie : public MediaItem {
    string director, studio;
    int runtime;
public:
    Movie(string t, string c, int y, double r, int len, vector<string> g, vector<string> tg, string d,
          string dir, int run, string s)
        : MediaItem(t, c, y, r, len, g, tg, d), director(dir), runtime(run), studio(s) {}
    void display() const override {
        MediaItem::display();
        cout << "Director: " << director << "\nRuntime: " << runtime << "\nStudio: " << studio << "\n";
    }
    string getType() const override { return "Movie"; }
};

class Song : public MediaItem {
    string album;
    int duration, playCount;
public:
    Song(string t, string c, int y, double r, int len, vector<string> g, vector<string> tg, string d,
         string alb, int dur, int plays)
        : MediaItem(t, c, y, r, len, g, tg, d), album(alb), duration(dur), playCount(plays) {}
    void display() const override {
        MediaItem::display();
        cout << "Album: " << album << "\nDuration: " << duration << "\nPlay Count: " << playCount << "\n";
    }
    string getType() const override { return "Song"; }
};

class Book : public MediaItem {
    string publisher;
    double progress;
public:
    Book(string t, string c, int y, double r, int len, vector<string> g, vector<string> tg, string d,
         string pub, double prog)
        : MediaItem(t, c, y, r, len, g, tg, d), publisher(pub), progress(prog) {}
    void display() const override {
        MediaItem::display();
        cout << "Publisher: " << publisher << "\nProgress: " << progress << "%\n";
    }
    string getType() const override { return "Book"; }
};

class MediaCollection {
    vector<shared_ptr<MediaItem>> items;

public:
    void addItem(shared_ptr<MediaItem> item) {
        items.push_back(item);
    }

    void displayAll() const {
        for (const auto& item : items) {
            item->display();
            cout << "----------------------\n";
        }
    }

    void sortByTitle() {
        sort(items.begin(), items.end(), [](auto& a, auto& b) {
            return a->getTitle() < b->getTitle();
        });
    }

    void sortByCreatorThenTitle() {
        sort(items.begin(), items.end(), [](auto& a, auto& b) {
            return a->getCreator() == b->getCreator() ?
                   a->getTitle() < b->getTitle() :
                   a->getCreator() < b->getCreator();
        });
    }

    void sortByRating() {
        sort(items.begin(), items.end(), [](auto& a, auto& b) {
            return a->getRating() > b->getRating();
        });
    }

    void sortByYear() {
        sort(items.begin(), items.end(), [](auto& a, auto& b) {
            return a->getYearReleased() > b->getYearReleased();
        });
    }

    void sortByAccessCount() {
        sort(items.begin(), items.end(), [](auto& a, auto& b) {
            return a->getTimesAccessed() > b->getTimesAccessed();
        });
    }

    void searchByKeyword(const string& keyword) const {
        auto it = find_if(items.begin(), items.end(), [&](auto& item) {
            return item->getTitle().find(keyword) != string::npos ||
                   item->getCreator().find(keyword) != string::npos;
        });
        if (it != items.end()) (*it)->display();
        else cout << "No match found.\n";
    }

    void filterByRating(double minRating) const {
        vector<shared_ptr<MediaItem>> results;
        copy_if(items.begin(), items.end(), back_inserter(results), [=](auto& item) {
            return item->getRating() >= minRating;
        });
        for (auto& item : results) item->display();
    }

    void countByType() const {
        int movies = count_if(items.begin(), items.end(), [](auto& i) {
            return i->getType() == "Movie";
        });
        int songs = count_if(items.begin(), items.end(), [](auto& i) {
            return i->getType() == "Song";
        });
        int books = count_if(items.begin(), items.end(), [](auto& i) {
            return i->getType() == "Book";
        });
        cout << "Movies: " << movies << ", Songs: " << songs << ", Books: " << books << "\n";
    }

    void averageRating() const {
        if (items.empty()) return;
        double total = accumulate(items.begin(), items.end(), 0.0, [](double sum, auto& i) {
            return sum + i->getRating();
        });
        cout << "Average Rating: " << total / items.size() << "\n";
    }

    void mostCommonGenre() const {
        map<string, int> genreCount;
        for (auto& item : items) {
            for (auto& g : item->getGenres()) {
                genreCount[g]++;
            }
        }
        string mostCommon;
        int maxCount = 0;
        for (auto& [genre, count] : genreCount) {
            if (count > maxCount) {
                maxCount = count;
                mostCommon = genre;
            }
        }
        cout << "Most Common Genre: " << mostCommon << " (" << maxCount << " times)\n";
    }

    bool binarySearchByTitle(const string& title) {
        sortByTitle();
        return binary_search(items.begin(), items.end(), title,
            [](const shared_ptr<MediaItem>& item, const string& t) {
                return item->getTitle() < t;
            });
    }
};

int main() {
    MediaCollection collection;

/*    collection.addItem(make_shared<Movie>("Inception", "Nolan", 2010, 8.8, 148, vector<string>{"Sci-Fi"}, vector<string>{"dream"}, "2023-01-01", "Nolan", 148, "WB"));
    collection.addItem(make_shared<Song>("Imagine", "Lennon", 1971, 9.2, 3, vector<string>{"Pop"}, vector<string>{"peace"}, "2023-01-02", "Imagine", 180, 100));
    collection.addItem(make_shared<Book>("1984", "Orwell", 1949, 9.0, 328, vector<string>{"Dystopia"}, vector<string>{"totalitarian"}, "2023-01-03", "Secker", 100.0));*/

    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. View Collection\n"
             << "2. Search Items\n"
             << "3. Add New Item (not implemented)\n"
             << "4. Collection Statistics\n"
             << "5. Exit\n"
             << "6. Binary Search by Title\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int sortChoice;
            cout << "Sort by: 1-Title 2-Creator 3-Rating 4-Year 5-Access\nChoice: ";
            cin >> sortChoice;
            switch (sortChoice) {
                case 1: collection.sortByTitle(); break;
                case 2: collection.sortByCreatorThenTitle(); break;
                case 3: collection.sortByRating(); break;
                case 4: collection.sortByYear(); break;
                case 5: collection.sortByAccessCount(); break;
            }
            collection.displayAll();
        } else if (choice == 2) {
            string keyword;
            cout << "Enter keyword to search: ";
            getline(cin, keyword);
            collection.searchByKeyword(keyword);
        } else if (choice == 4) {
            collection.countByType();
            collection.averageRating();
            collection.mostCommonGenre();
        } else if (choice == 6) {
            string title;
            cout << "Enter title to search for (binary search): ";
            getline(cin, title);
            bool found = collection.binarySearchByTitle(title);
            if (found)
                cout << "Item with title \"" << title << "\" found in collection.\n";
            else
                cout << "Item with title \"" << title << "\" not found.\n";
        }
    } while (choice != 5);

    return 0;
}
