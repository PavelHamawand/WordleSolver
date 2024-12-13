#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * Checks if the string `s` contains any of the characters in `cs`.
 * @param s The string to check.
 * @param cs A string containing characters to look for in `s`.
 * @return True if any character in `cs` is found in `s`, otherwise false.
 */
bool contains_any_of(const std::string& s, const std::string& cs);

/**
 * Checks if the string `s` has the character `c` at the specified position.
 * @param s The string to check.
 * @param c The character to look for.
 * @param pos The position in the string to check.
 * @return True if `s[pos]` is equal to `c`, otherwise false.
 */
bool contains_at(const std::string& s, char c, size_t pos);

/**
 * Checks if the string `s` contains the character `c` but not at the specified position.
 * @param s The string to check.
 * @param c The character to look for.
 * @param pos The position where `c` must not occur.
 * @return True if `c` is found in `s` but not at `pos`, otherwise false.
 */
bool contains_but_not_at(const std::string& s, char c, size_t pos);

#endif // UTILS_H