#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

using namespace std;

/// MediaItem class definition
class MediaItem {
protected:
    string title;
    string creator;
    int yearReleased;
    double rating;
    int length;
    vector<string> genres;
    vector<string> tags;
    int timesAccessed;
    string dateAdded;

public:
    MediaItem(string t, string c, int year, double r, int len,
              vector<string> g, vector<string> tg, string date)
        : title(t), creator(c), yearReleased(year), rating(r), length(len),
          genres(g), tags(tg), timesAccessed(0), dateAdded(date) {}

    virtual ~MediaItem() {}

    string getTitle() const { return title; }
    string getCreator() const { return creator; }
    int getYearReleased() const { return yearReleased; }
    double getRating() const { return rating; }
    int getLength() const { return length; }
    vector<string> getGenres() const { return genres; }
    vector<string> getTags() const { return tags; }
    int getTimesAccessed() const { return timesAccessed; }
    string getDateAdded() const { return dateAdded; }

    void access() { ++timesAccessed; }
    void setRating(double r) { rating = r; }

    virtual void display() const {
        cout << "Title: " << title << "\n"
             << "Creator: " << creator << "\n"
             << "Year Released: " << yearReleased << "\n"
             << "Rating: " << rating << "\n"
             << "Length: " << length << "\n"
             << "Genres: ";
        for (const auto& g : genres) cout << g << " ";
        cout << "\nTags: ";
        for (const auto& t : tags) cout << t << " ";
        cout << "\nTimes Accessed: " << timesAccessed << "\n"
             << "Date Added: " << dateAdded << "\n";
    }
};

/// Movie class
class Movie : public MediaItem {
private:
    string director;
    int runtime;
    string studio;

public:
    Movie(string t, string c, int year, double r, int len,
          vector<string> g, vector<string> tg, string date,
          string dir, int run, string studio)
        : MediaItem(t, c, year, r, len, g, tg, date),
          director(dir), runtime(run), studio(studio) {}

    void display() const override {
        MediaItem::display();
        cout << "Director: " << director << "\n"
             << "Runtime: " << runtime << " minutes\n"
             << "Studio: " << studio << "\n";
    }
};

/// Song class
class Song : public MediaItem {
private:
    string album;
    int duration;
    int playCount;

public:
    Song(string t, string c, int year, double r, int len,
         vector<string> g, vector<string> tg, string date,
         string alb, int dur, int plays)
        : MediaItem(t, c, year, r, len, g, tg, date),
          album(alb), duration(dur), playCount(plays) {}

    void play() { ++playCount; }

    void display() const override {
        MediaItem::display();
        cout << "Album: " << album << "\n"
             << "Duration: " << duration << " seconds\n"
             << "Play Count: " << playCount << "\n";
    }
};

/// Book class
class Book : public MediaItem {
private:
    string publisher;
    double readingProgress;

public:
    Book(string t, string c, int year, double r, int len,
         vector<string> g, vector<string> tg, string date,
         string pub, double progress)
        : MediaItem(t, c, year, r, len, g, tg, date),
          publisher(pub), readingProgress(progress) {}

    void updateProgress(double progress) {
        if (progress >= 0.0 && progress <= 100.0)
            readingProgress = progress;
    }

    void display() const override {
        MediaItem::display();
        cout << "Publisher: " << publisher << "\n"
             << "Reading Progress: " << readingProgress << "%\n";
    }
};

/// MediaCollection class
class MediaCollection {
private:
    vector<shared_ptr<MediaItem>> items;

public:
    void addItem(shared_ptr<MediaItem> item) {
        items.push_back(item);
    }

    void removeIf(function<bool(const shared_ptr<MediaItem>&)> condition) {
        items.erase(remove_if(items.begin(), items.end(), condition), items.end());
    }

    vector<shared_ptr<MediaItem>> findIf(function<bool(const shared_ptr<MediaItem>&)> condition) const {
        vector<shared_ptr<MediaItem>> results;
        for (const auto& item : items) {
            if (condition(item)) {
                results.push_back(item);
            }
        }
        return results;
    }

    void sortBy(function<bool(const shared_ptr<MediaItem>&, const shared_ptr<MediaItem>&)> comparator) {
        sort(items.begin(), items.end(), comparator);
    }

    void displayAll() const {
        for (const auto& item : items) {
            item->display();
            cout << "----------------------\n";
        }
    }

    void accessAll() {
        for (auto& item : items) {
            item->access();
        }
    }

    // Sorting Methods
    void sortByTitle() {
        sortBy([](const auto& return a->getTitle() < b->getTitle();
        });
    }

    void sortByCreatorThenTitle() {
        sortBy( {
            return (a->getCreator() == b->getCreator()) ?
                   (a->getTitle() < b->getTitle()) :
                   (a->getCreator() < b->getCreator());
        });
    }

    void sortByRatingDescending() {
        sortBy([](const       return a->getRating() > b->getRating();
        });
    }

    void sortByYearDescending() {
        sortBy([](const auto& a, const auto&earReleased() > b->getYearReleased();
        });
    }

    void sortByAccessCountDescending() {
        sortBy([](const auto& a,turn a->getTimesAccessed() > b->getTimesAccessed();
        });
    }

    // Filtering and Searching
    vector<shared_ptr<MediaItem>> filterByYearRange(int startYear, int endYear) const {
        return findIf(= {
            return item->getYearReleased() >= startYear && item->getYearReleased() <= endYear;
        });
    }

    vector<shared_ptr<MediaItem>> filterByMinRating(double minRating) const {
        return findIf(= {
            return item->getRating() >= minRating;
        });
    }

    vector<shared_ptr<MediaItem>> findByPartialTitleOrCreator(const string& keyword) const {
        return findIf(= {
            return item->getTitle().find(keyword) != string::npos ||
                   item->getCreator().find(keyword) != string::npos;
        });
    }

    vector<shared_ptr<MediaItem>> findByGenre(const string& genre) const {
        return findIf(= {
            const auto& genres = item->getGenres();
            return find(genres.begin(), genres.end(), genre) != genres.end();
        });
    }

    vector<shared_ptr<MediaItem>> findByType(const string& type) const {
        return findIf(= {
            if (type == "Movie" && dynamic_pointer_cast<Movie>(item)) return true;
            if (type == "Song" && dynamic_pointer_cast<Song>(item)) return true;
            if (type == "Book" && dynamic_pointer_cast<Book>(item)) return true;
            return false;
        });
    }
};
