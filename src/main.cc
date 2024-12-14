#include "wordle.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>

/**
 * Main program to solve Wordle interactively.
 */
int main() {
    // Example word list (replace with actual word list file reading if needed)
    std::vector<std::string> candidates = {"apple", "baker", "cider", "alert", "alley", "libel", "piney"};

    // Grey, green, and yellow letter sets
    std::string grey_letters;
    letters_and_indices green_letters;
    letters_and_indices yellow_letters;

    while (candidates.size() > 1) {
        std::cout << "Remaining candidates: " << candidates.size() << "\n";

        // Display current sets
        std::cout << "Grey letters: " << grey_letters << "\n";
        std::cout << "Green letters: ";
        for (const auto& [index, letter] : green_letters) {
            std::cout << letter << "@" << index << " ";
        }
        std::cout << "\nYellow letters: ";
        for (const auto& [index, letter] : yellow_letters) {
            std::cout << letter << "@" << index << " ";
        }
        std::cout << "\n";

        // Get user input for grey letters
        std::cout << "Enter wrong (grey) letters: ";
        std::string new_grey;
        std::getline(std::cin, new_grey);

        // Get user input for green letters
        std::cout << "Enter correct (green) letters (letter index pairs, e.g., a 0 b 1): ";
        std::string green_input;
        std::getline(std::cin, green_input);
        auto new_green = build_list(green_input);

        // Get user input for yellow letters
        std::cout << "Enter misplaced (yellow) letters (letter index pairs, e.g., a 0 b 1): ";
        std::string yellow_input;
        std::getline(std::cin, yellow_input);
        auto new_yellow = build_list(yellow_input);

        // Ensure no conflicts between sets
        for (const auto& [index, letter] : new_green) {
            new_grey.erase(std::remove(new_grey.begin(), new_grey.end(), letter), new_grey.end());
        }
        for (const auto& [index, letter] : new_yellow) {
            new_grey.erase(std::remove(new_grey.begin(), new_grey.end(), letter), new_grey.end());
        }

        // Update sets
        grey_letters += new_grey;
        append(green_letters, new_green);
        append(yellow_letters, new_yellow);

        // Filter candidates
        do_filter(candidates, grey_letters, green_letters, yellow_letters);
    }

    // Final result
    if (candidates.size() == 1) {
        std::cout << "The solution is: " << candidates[0] << "\n";
    } else {
        std::cout << "No solution found or not enough data.\n";
    }

    return 0;
}