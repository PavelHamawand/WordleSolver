#include "wordle.h"
#include <algorithm>
#include <unordered_set>
#include <cctype>
#include "utils.h"  // För hjälpfunktionerna

// wrong_fn implementation
wrong_fn::wrong_fn(const std::string& letters) : l{letters} {}

bool wrong_fn::operator()(const std::string& word) const {
    return contains_any_of(word, l);
}

// correct_fn implementation
correct_fn::correct_fn(const letters_and_indices& idxs) : m{idxs} {}

bool correct_fn::operator()(const std::string& word) const {
    return std::all_of(m.begin(), m.end(), [&](const auto& pair) {
        return word[pair.first] == pair.second;
    });
}

// misplaced_fn implementation
misplaced_fn::misplaced_fn(const letters_and_indices& idxs) : m{idxs} {}

bool misplaced_fn::operator()(const std::string& word) const {
    return std::all_of(m.begin(), m.end(), [&](const auto& pair) {
        return contains_but_not_at(word, pair.second, pair.first);
    });
}

/**
 * opens a word list from the an istream and gets all five-letter words. 
 * All words should be made lower-case and duplicates removed
 */
std::vector<std::string> read_candidates(std::istream& input) {
    std::unordered_set<std::string> unique_words;
    std::vector<std::string> candidates;
    std::string word;

    while (input >> word) {
        if (word.size() == 5) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (unique_words.insert(word).second) {
                candidates.push_back(word);
            }
        }
    }
    return candidates;
}
