#include "List_set.h"

namespace list_set {

struct List_set::Node
{
    // YOU NEED TO COMPLETE THIS DEFINITION
};

// Constructs a `List_set` from an initializer list by creating an empty set
// and then inserting each element of the initializer list. For example:
//
//     List_set abc{"a", "b", "c"};
//
List_set::List_set(const std::initializer_list<element_t>& elements)
        : List_set{}
{
    for (const auto& element : elements)
        insert(element);
}

// Provide your definitions of the default constructor and five member
// functions (is_empty, size, member, insert, remove) here.


} // end namespace list_set

