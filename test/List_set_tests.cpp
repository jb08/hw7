#include "List_set.h"

#include <UnitTest++/UnitTest++.h>

using namespace list_set;

// These tests won't compile until you define the List_set member functions.
// Add more tests here to be sure your class works properly.

//TEST(ListConstructor)
//{
//    List_set set{"a", "b", "c"};
//}
//
//TEST(InsertRemoveContains)
//{
//    List_set set{"a", "b", "c"};
//
//    CHECK_EQUAL(true, set.contains("a"));
//    CHECK_EQUAL(true, set.contains("b"));
//    CHECK_EQUAL(true, set.contains("c"));
//    CHECK_EQUAL(false, set.contains("d"));
//    CHECK_EQUAL(3, set.size());
//
//    set.insert("d");
//    CHECK_EQUAL(true, set.contains("a"));
//    CHECK_EQUAL(true, set.contains("b"));
//    CHECK_EQUAL(true, set.contains("c"));
//    CHECK_EQUAL(true, set.contains("d"));
//    CHECK_EQUAL(4, set.size());
//
//    set.remove("b");
//    CHECK_EQUAL(true, set.contains("a"));
//    CHECK_EQUAL(false, set.contains("b"));
//    CHECK_EQUAL(true, set.contains("c"));
//    CHECK_EQUAL(true, set.contains("d"));
//    CHECK_EQUAL(3, set.size());
//
//    set.remove("b");
//    set.remove("a");
//    CHECK_EQUAL(false, set.contains("a"));
//    CHECK_EQUAL(false, set.contains("b"));
//    CHECK_EQUAL(true, set.contains("c"));
//    CHECK_EQUAL(true, set.contains("d"));
//    CHECK_EQUAL(2, set.size());
//
//    set.insert("a");
//    CHECK_EQUAL(true, set.contains("a"));
//    CHECK_EQUAL(false, set.contains("b"));
//    CHECK_EQUAL(true, set.contains("c"));
//    CHECK_EQUAL(true, set.contains("d"));
//    CHECK_EQUAL(3, set.size());
//}
