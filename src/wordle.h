#ifndef WORDLE_H
#define WORDLE_H

#include <vector>
#include <string>
#include <map>
#include <istream>

// Funktorer för att hantera "grå", "gröna" och "gula" bokstäver
struct wrong_fn {
    std::string l;  // List of grey letters
    explicit wrong_fn(const std::string& letters);
    bool operator()(const std::string& word) const;
};

using size_type = std::string::size_type;
using letters_and_indices = std::map<size_type, char>;  // Map to store the index and correct letter

struct correct_fn {
    letters_and_indices m;  // Map of indices and green letters
    explicit correct_fn(const letters_and_indices& idxs);
    bool operator()(const std::string& word) const;
};

struct misplaced_fn {
    letters_and_indices m;  // Map of indices and yellow letters
    explicit misplaced_fn(const letters_and_indices& idxs);
    bool operator()(const std::string& word) const;
};


/**
 * Reads a wordlist from an input stream, filters for five-letter words,
 * converts them to lowercase, and removes duplicates.
 * @param input The input stream containing the wordlist.
 * @return A vector of unique five-letter words.
 */
std::vector<std::string> read_candidates(std::istream& input);

#endif // WORDLE_H