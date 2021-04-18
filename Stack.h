/*
 * since end-user doesn't need to know about implementation details,
 * and all he needs is basic knowledge about interface of data type to work with it,
 * we can have declarations and definitions in different places.
 * Compiler only needs declarations as well.
 * Separating declarations and definitions has multiple Pros!
 *
 * We implement same interface as std::stack
 * https://en.cppreference.com/w/cpp/container/stack
 * except pop function which is different and required for assignment.
 */



// header guards to prevent multiple declarations
#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <cstddef>

class Stack {
private:
    struct Node {
        char value{};
        Node* next{};
    };
    Node* head{};
    std::size_t length{};

public:
    Stack() = default;

    void push(char value);
    std::size_t size() const;
    bool empty() const;
    char& top();
    const char& top() const;
    char pop();
    void print() const;

    /*
     * we have multiple const functions to have const-friendly data type.
     */

    ~Stack();

    /*
     * We use RAII (Resource Acquisition is Initialization) technique
     * to avoid memory leak.
     */
};


#endif //LAB3_STACK_H
