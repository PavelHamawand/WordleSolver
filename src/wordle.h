#ifndef WORDLE_H
#define WORDLE_H

#include <vector>
#include <string>
#include <map>
#include <istream>

/**
 * Reads a wordlist from an input stream, filters for five-letter words,
 * converts them to lowercase, and removes duplicates.
 * @param input The input stream containing the wordlist.
 * @return A vector of unique five-letter words.
 */
std::vector<std::string> read_candidates(std::istream& input);

#endif // WORDLE_H