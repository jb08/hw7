/*********************************************************
 * WARNING: DO NOT CHANGE THIS FILE.                     *
 *                                                       *
 * If you do, the grading tests are very likely to fail. *
 *********************************************************/
#pragma once

#include <string>

namespace list_set {

// ATTENTION: DO NOT CHANGE THIS FILE IN ANY WAY

class List_set
{
public:
    // Type alias: elements are strings.
    using element_t = std::string;

    // Constructs the empty set.
    List_set();

    // Constructs the set with the given elements.
    List_set(const std::initializer_list<element_t>&);

    // Returns whether this set is empty.
    bool is_empty() const;

    // Returns the count of elements in this set.
    size_t size() const;

    // Returns whether this set contains the given element.
    bool contains(const element_t&) const;

    // Adds the given element to this set.
    void insert(element_t);

    // Removes the given element from this set.
    void remove(const element_t&);

// ATTENTION: DO NOT CHANGE THIS FILE IN ANY WAY

private:
    // "Forward" declaration of Node type (to be defined in List_set.cpp).
    struct Node;

    // The type of a link to a Node on the free store.
    using link_t = std::shared_ptr<Node>;

    // The first link of the list, or nullptr if empty.
    link_t link_;
};

// ATTENTION: DO NOT CHANGE THIS FILE IN ANY WAY

} // end namespace list_set
