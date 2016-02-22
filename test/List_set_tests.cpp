#include "List_set.h"

#include <UnitTest++/UnitTest++.h>

using namespace list_set;

TEST(DefaultConstructor)
{
    List_set set;
}

TEST(ListConstructor)
{
    List_set set{"a", "b", "c"};
}

TEST(IsEmpty)
{
    List_set set1;
    List_set set2{"a", "b", "c"};

    CHECK_EQUAL(true, set1.is_empty());
    CHECK_EQUAL(false, set2.is_empty());
}

TEST(Size)
{
    List_set set1;
    List_set set2{"a", "b", "c"};

    CHECK_EQUAL(0, set1.size());
    CHECK_EQUAL(3, set2.size());
}

TEST(Contains)
{
    List_set set1;
    List_set set2{"a", "b", "c"};

    CHECK_EQUAL(false, set1.contains("a"));
    CHECK_EQUAL(false, set1.contains("b"));
    CHECK_EQUAL(false, set1.contains("c"));
    CHECK_EQUAL(false, set1.contains("d"));

    CHECK_EQUAL(true, set2.contains("a"));
    CHECK_EQUAL(true, set2.contains("b"));
    CHECK_EQUAL(true, set2.contains("c"));
    CHECK_EQUAL(false, set2.contains("d"));
}

TEST(Insert)
{
    List_set set;

    set.insert("these");
    set.insert("are");
    set.insert("set");
    set.insert("elements");
    CHECK_EQUAL(4, set.size());

    set.insert("these");
    set.insert("set");
    set.insert("elements");
    CHECK_EQUAL(4, set.size());

    set.insert("These");
    CHECK_EQUAL(5, set.size());

    set.insert("These");
    CHECK_EQUAL(5, set.size());
}

TEST(Remove)
{
    List_set set{"a", "b", "c"};

    CHECK_EQUAL(3, set.size());

    set.remove("a");
    CHECK_EQUAL(2, set.size());
    set.remove("a");
    CHECK_EQUAL(2, set.size());

    set.remove("b");
    CHECK_EQUAL(1, set.size());

    set.remove("a");
    CHECK_EQUAL(1, set.size());

    set.remove("c");
    CHECK_EQUAL(0, set.size());

    set.remove("c");
    CHECK_EQUAL(0, set.size());
}

TEST(InsertRemoveContains)
{
    List_set set{"a", "b", "c"};

    CHECK_EQUAL(true, set.contains("a"));
    CHECK_EQUAL(true, set.contains("b"));
    CHECK_EQUAL(true, set.contains("c"));
    CHECK_EQUAL(false, set.contains("d"));
    CHECK_EQUAL(3, set.size());

    set.insert("d");
    CHECK_EQUAL(true, set.contains("a"));
    CHECK_EQUAL(true, set.contains("b"));
    CHECK_EQUAL(true, set.contains("c"));
    CHECK_EQUAL(true, set.contains("d"));
    CHECK_EQUAL(4, set.size());

    set.remove("b");
    CHECK_EQUAL(true, set.contains("a"));
    CHECK_EQUAL(false, set.contains("b"));
    CHECK_EQUAL(true, set.contains("c"));
    CHECK_EQUAL(true, set.contains("d"));
    CHECK_EQUAL(3, set.size());

    set.remove("b");
    set.remove("a");
    CHECK_EQUAL(false, set.contains("a"));
    CHECK_EQUAL(false, set.contains("b"));
    CHECK_EQUAL(true, set.contains("c"));
    CHECK_EQUAL(true, set.contains("d"));
    CHECK_EQUAL(2, set.size());

    set.insert("a");
    CHECK_EQUAL(true, set.contains("a"));
    CHECK_EQUAL(false, set.contains("b"));
    CHECK_EQUAL(true, set.contains("c"));
    CHECK_EQUAL(true, set.contains("d"));
    CHECK_EQUAL(3, set.size());
}
