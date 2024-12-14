#include "../src/wordle.h"
#include <cassert>
#include <iostream>

/**
 * Test the do_filter function with specific grey, green, and yellow constraints.
 */
void test_do_filter() {
    // Test case 1
    std::vector<std::string> candidates1 = {"apple", "alley", "actor", "alert"};
    std::string wrong1 = "crtin";
    letters_and_indices green1 = {{0, 'a'}, {1, 'l'}, {3, 'e'}};
    letters_and_indices yellow1 = {{0, 'l'}, {1, 'e'}, {4, 'a'}};
    do_filter(candidates1, wrong1, green1, yellow1);
    assert(candidates1.size() == 1 && candidates1[0] == "alley");

    // Test case 2
    std::vector<std::string> candidates2 = {"libel", "label", "limbo", "liter"};
    std::string wrong2 = "cratdnmkd";
    letters_and_indices green2 = {{0, 'l'}, {1, 'i'}};
    letters_and_indices yellow2 = {{1, 'e'}, {3, 'i'}, {4, 'e'}};
    do_filter(candidates2, wrong2, green2, yellow2);
    assert(candidates2.size() == 1 && candidates2[0] == "libel");

    // Test case 3
    std::vector<std::string> candidates3 = {"piney", "pride", "peony", "piety"};
    std::string wrong3 = "cratbluswd";
    letters_and_indices green3 = {{3, 'e'}, {1, 'i'}};
    letters_and_indices yellow3 = {{4, 'n'}};
    do_filter(candidates3, wrong3, green3, yellow3);
    assert(candidates3.size() == 1 && candidates3[0] == "piney");

    std::cout << "All tests passed for do_filter!\n";
}

int main() {
    test_do_filter();
    return 0;
}