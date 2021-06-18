/*
 * Author: Yonas Adamu
 * Project: Vector Class.
 * Purpose: Write a vector class that does a very similar job like
 *          the add_entry project with vectors

 * Notes: for insert function if insert index was greater than size
 *        and or capacity, the number was pushed back to the last space

 */
#include <iostream>

#include "../../!includes/Vector/vector.h"
#include "../../!includes/Vector/vector_test.h"

using namespace std;

int main() {
    srand(time(NULL));
    // Vector<int> v1({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14});

    // cout << v1 << endl;
    // cout << v1.size() << " v size( ): " << endl;
    // cout << v1.capacity() << " v capacity( ): " << endl;

    // cout << "===============================================" << endl;

    ////===========================================
    // test_big_three();

    // const_test(v1);

    // non_const_test(v1);

    ////===========================================

    // test_at_front_back();

    // test_erase();

    // test_index_of();

    test_insert();

    // test_operator_PlusEqual();

    // test_pop_back();

    // test_push_back();

    return 0;
}
