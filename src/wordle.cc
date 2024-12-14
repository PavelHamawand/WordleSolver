#include "wordle.h"
#include <algorithm>
#include <unordered_set>
#include <cctype>
#include "utils.h"  // För hjälpfunktionerna
#include <iostream>

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


// Constructor initializes functors with the given arguments
exclude_word::exclude_word(const std::string& wrong,
                           const letters_and_indices& correct,
                           const letters_and_indices& misplaced)
    : wrong(wrong), correct(correct), misplaced(misplaced) {}

// Function call operator combines the logic of wrong, correct, and misplaced functors
bool exclude_word::operator()(const std::string& w) const {
    return wrong(w) || !correct(w) || !misplaced(w);
}

// Filters candidates using exclude_word functor
void filter_candidates(std::vector<std::string>& candidates,
                       const std::string& wrong,
                       const letters_and_indices& correct,
                       const letters_and_indices& misplaced) {
    // Create an instance of the exclude_word functor
    exclude_word predicate(wrong, correct, misplaced);

    // Use std::remove_if with the predicate to filter the candidates
    candidates.erase(std::remove_if(candidates.begin(), candidates.end(), predicate),
                     candidates.end());
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

std::tuple<std::string, letters_and_indices, letters_and_indices> prompt() {
    std::string wrong;
    std::cout << "Enter wrong letters (e.g., xyz): ";
    std::getline(std::cin, wrong);

    std::string correct_input;
    std::cout << "Enter correct letters (letter index pairs, e.g., a 0 b 1): ";
    std::getline(std::cin, correct_input);
    auto correct = build_list(correct_input);

    std::string misplaced_input;
    std::cout << "Enter misplaced letters (letter index pairs, e.g., a 0 b 1): ";
    std::getline(std::cin, misplaced_input);
    auto misplaced = build_list(misplaced_input);

    return {wrong, correct, misplaced};
}

// Filters candidates based on the provided constraints
void do_filter(std::vector<std::string>& c,
               const std::string& wrong,
               const letters_and_indices& green,
               const letters_and_indices& yellow) {
    // Create functors for grey, green, and yellow constraints
    wrong_fn wrong_letters(wrong);
    correct_fn green_letters(green);
    misplaced_fn yellow_letters(yellow);

    // Remove candidates that fail any of the constraints
    c.erase(std::remove_if(c.begin(), c.end(), [&](const std::string& word) {
        return wrong_letters(word) || !green_letters(word) || !yellow_letters(word);
    }), c.end());
}