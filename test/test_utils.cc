#include "../src/utils.h"
#include <cassert>
#include <iostream>

/**
 * Test the `contains_any_of` function.
 */
void test_contains_any_of() {
    assert(contains_any_of("apple", "ae"));  // True: 'a' and 'e' are in "apple"
    assert(!contains_any_of("apple", "xyz"));  // False: None of 'x', 'y', or 'z' are in "apple"
    std::cout << "All tests passed for contains_any_of.\n";
}

/**
 * Test the `contains_at` function.
 */
void test_contains_at() {
    assert(contains_at("apple", 'a', 0));  // True: 'a' is at position 0
    assert(!contains_at("apple", 'p', 0));  // False: 'p' is not at position 0
    assert(contains_at("apple", 'e', 4));  // True: 'e' is at position 4
    std::cout << "All tests passed for contains_at.\n";
}

/**
 * Test the `contains_but_not_at` function.
 */
void test_contains_but_not_at() {
    assert(contains_but_not_at("apple", 'p', 0));  // True: 'p' is in "apple" but not at position 0
    assert(!contains_but_not_at("apple", 'p', 1));  // False: 'p' is at position 1
    assert(!contains_but_not_at("apple", 'z', 2));  // False: 'z' is not in "apple"
    std::cout << "All tests passed for contains_but_not_at.\n";
}

/**
 * Test the `build_list` function.
 */
void test_build_list() {
    letters_and_indices result = build_list("a 0 p 1 l 2");
    assert(result.size() == 3);
    assert(result[0] == 'a');
    assert(result[1] == 'p');
    assert(result[2] == 'l');
    std::cout << "All tests passed for build_list.\n";
}

/**
 * Test the `append` function.
 */
void test_append() {
    letters_and_indices dest = {{0, 'a'}, {1, 'b'}};
    letters_and_indices src = {{1, 'c'}, {2, 'd'}};
    append(dest, src);

    assert(dest.size() == 3);  // dest should now contain keys 0, 1, and 2
    assert(dest[0] == 'a');    // 'a' at index 0 remains unchanged
    assert(dest[1] == 'b');    // 'b' at index 1 remains unchanged
    assert(dest[2] == 'd');    // 'd' at index 2 is added
    std::cout << "All tests passed for append.\n";
}

/**
 * Main function to run all tests for utils functions.
 */
int main() {
    test_contains_any_of();
    test_contains_at();
    test_contains_but_not_at();
    test_build_list();
    test_append();
    std::cout << "All tests passed for utils!\n";
    return 0;
}