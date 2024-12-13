#include "wordle.h"
#include <algorithm>
#include <unordered_set>
#include <cctype>

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
