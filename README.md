# EECS 230 Homework 7

Due **Sunday**, February 28, at 11:59 PM

## Purpose

The primary goal of this assignment is to learn to program with linked data structures and `std::shared_ptr`.

## Preliminaries

This homework is to be completed by pair programming with your chosen partner. After you register with your chosen partner at `http://goo.gl/forms/GlqlXdU9Pr`, you will be given access to a private GitHub repository for this homework assignment, located at `https://github.com/eecs230/`<var>NETID</var>`-`<var>NETID</var>`-hw7`, where one <var>NETID</var> is your six-character Northwestern NetID, and the other is your partner’s. (They’re in alphabetical order). For example, if your NetID were `xyz789` and your partner’s were `abc123` then your HW7 repo would be at `https://github.com/eecs230/abc123-xyz789-hw7`.

Because we’ve already forked your repository for you, you *must not* fork it on GitHub, as this would make your homework publicly readable. (Also, you will be submitting your homework via the repo we made for you.)

To start working, you need to clone a local copy of your HW7 repo. Choose *Checkout from Version Control* from the *VCS* menu or the “Welcome to CLion” window, and enter your repository URL.

### Background

The linked list, which we saw in class, is a simple yet versatile data structure. It is represented as a pointer to a node (that is, the address of a node) that contains two member variables: the list element stored in the node, and either a pointer to another node, or the special value `nullptr` to terminate the list.

One possible use for a linked list is to represent a set of elements,
where each element goes in one node in the list. To compute with sets in
C++, we could make a set class that uses a linked to store the set’s
elements, and that provides the following operations:

  - `bool is_empty() const`, to determine whether the set is empty;

  - `size_t size() const`, to return the number of elements (cardinality) of the set;

  - `bool contains(const element_t&) const`, to determine if some value is an element of the set;

  - `void insert(element_t)`, to add an element to the set; and

  - `void remove(const element_t&)`, to remove an element from the set.

## Your task

For this assignment, your job is to implement a class `List_set`, which uses a linked list to represent a set of `std::string`s. You’ve been provided with three C++ source files:

  - `src/List_set.h`—**which you should not change in any way**—contains a definition of the `List_set` class with declarations of its member functions. It also forward-declares a `struct Node` and defines one member variable, `link_`, to be a `std::shared_ptr<Node>`.

  - `src/List_set.cpp` is where you will implement the `List_set` class. One constructor, which takes an `initialization_list`, has been defined for you. It is up to you to define the `Node` class, the default constructor, and the five member functions listed above, in this file.

  - `test/List_set_tests.cpp` is where you will add tests for your `List_set` class.

In short: Your job is to implement the set interface from `src/List_set.h` in `src/List_set.cpp`, including providing a complete definition of `Node`, and to test it thoroughly in `test/List_set_tests.cpp`. You must not modify the file `src/List_set.h`.

### Example test

Here is an example usage of the class, which you may use as a test (but you will need many more, smaller tests as well):

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

## Reference

### Shared pointers

Type `std::shared_ptr<Node>` implements a *reference-counted* pointer to a `Node`. This means that it counts how many references to the `Node` there are and frees it when the last reference goes away—which means you don’t have to worry about it.

You can use a `std::shared_ptr<Node>` just like an ordinary pointer (address). If `p` is a `std::shared_ptr<Node>` then `*p` is the `Node` that it points to. If `Node` has a member variable `next` then you can get the `next` member of `p` by writing `(*p).next` or `p->next`.

In order to create a `std::shared_ptr<Node>`, use `std::make_shared<Node>`, which can be passed the same arguments that a `Node` constructor takes and allocates a fresh `Node` on the free store. You should not need to use the `new` and `delete` operators, since `std::make_shared<Node>` and `std::shared_ptr<Node>` handle both allocation and deallocation for you.

### Iterating over a list

If `p` is a `std::shared_ptr<Node>` and `Node` has a `next` member variable, then you can iterate through the nodes in order with

    for (auto current = p; current != nullptr; current = current->next)

Then `current` will be a shared pointer to each node in turn in the body of the loop.

### The dummy node trick

You may find that removal of elements involves some tricky corner cases, because to remove a node you need access to the precessor node. But the first node in the list doesn’t have a predecessor node, which makes it a special case.

Alternatively, you can maintain a *dummy node*—an extra node at the beginning (or end) of the list that doesn’t carry any meaningful data but makes sure that every real, non-dummy node has a predecessor (or successor). (The dummy node would probably store the empty string, but that doesn’t mean the empty string is always in your set—the dummy node’s element isn’t considered part of the set.) This makes it easier to treat the first node uniformly, since you can now do removal by finding the node whose successor contains the element to be removed, and then remove the successor node.

Of course, to iterate through all the real nodes, it’s necessary to skip the initial dummy node:

    for (auto current = p->next; current != nullptr; current = current->next)

You can also, of course, iterate over all but the last node (*i.e.,* iterate over the predecessors of the non-dummy nodes):

    for (auto current = p; current->next != nullptr; current = current->next)

## Grading

For this assignment, you will be graded on whether your code implements the specification (functional correctness).

## Submission

See [the submission instructions](http://users.eecs.northwestern.edu/~jesse/course/eecs230/homework). Note that either partner can submit to GitHub. There is no need to tag your code, but beware that I will grade the most recent version on GitHub at the time of grading. Note also that the time of your push to GitHub will count as your submission time.

