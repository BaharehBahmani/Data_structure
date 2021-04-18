/*
 * since end-user doesn't need to know about implementation details,
 * and all he needs is basic knowledge about interface of data type to work with it,
 * we can have declarations and definitions in different places.
 * Compiler only needs declarations as well.
 * Separating declarations and definitions has multiple Pros!
 *
 * We implement same interface as std::queue
 * https://en.cppreference.com/w/cpp/container/queue
 * except pop function which is different and required for assignment
 */


// header guards to prevent multiple declarations
#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H

#include <cstddef>  // std::size_t

class Queue {
private:
    struct Node {
        char value{};
        Node* next{};
    };
    Node* head{};
    Node* tail{};
    std::size_t length{};

public:
    Queue() = default;

    void push(char value);
    char pop();
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    bool empty() const;
    std::size_t size() const;
    void print() const;

    /*
     * we have multiple const functions to have const-friendly data type.
     */

    ~Queue();

    /*
     * We use RAII (Resource Acquisition is Initialization) technique
     * to avoid memory leak.
     */
};

#endif //LAB3_QUEUE_H
