#include "List_set.h"

namespace list_set {

struct List_set::Node
{
    element_t element;
    link_t    next;

    Node(element_t e, link_t n) : element{e}, next{n} { }
};

List_set::List_set()
        : link_{ std::make_shared<Node>(element_t{}, nullptr) }
{ }

List_set::List_set(std::initializer_list<element_t> elements)
        : List_set{}
{
    for (const auto& element : elements)
        insert(element);
}

bool List_set::is_empty() const
{
    return link_->next == nullptr;
}

size_t List_set::size() const
{
    size_t result = 0;

    for (auto ptr = link_->next; ptr != nullptr; ptr = ptr->next)
        ++result;

    return result;
}

bool List_set::contains(const element_t& element) const
{
    for (auto ptr = link_->next; ptr != nullptr; ptr = ptr->next)
        if (element == ptr->element) return true;

    return false;
}

void List_set::insert(element_t element)
{
    if (contains(element)) return;
    link_->next = std::make_shared<Node>(element, link_->next);
}

void List_set::remove(const element_t& element)
{
    for (auto ptr = link_; ptr->next != nullptr; ptr = ptr->next) {
        if (ptr->next->element == element) {
            ptr->next = ptr->next->next;
            return;
        }
    }
}

} // end namespace list_set

