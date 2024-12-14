#include "utils.h"

/**
 *  returns true if the string s contains any of the characters in cs
 */
bool contains_any_of(const std::string& s, const std::string& cs) {
    for (char c : cs) {
        if (s.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

/**
 *  returns true if the string s has the character c at position pos
 */
bool contains_at(const std::string& s, char c, size_t pos) {
    return pos < s.size() && s[pos] == c;
}

/**
 * returns true if the string s contains c but at any other position than pos
 */
bool contains_but_not_at(const std::string& s, char c, size_t pos) {
    return s.find(c) != std::string::npos && s[pos] != c;
}

#include <sstream> // Ensure this header is included
#include "utils.h"

letters_and_indices build_list(const std::string& line) {
    letters_and_indices result;
    std::istringstream iss(line); // This should now work correctly
    char letter;
    std::size_t index;

    while (iss >> letter >> index) {
        result[index] = letter;
    }

    return result;
}

/**
 * Merges `src` into `dest`. If there are conflicting keys, `dest`'s values remain unchanged.
 */
void append(letters_and_indices& dest, const letters_and_indices& src) {
    for (const auto& [index, letter] : src) {
        dest.try_emplace(index, letter);  // Only add if `index` is not already in `dest`
    }
}