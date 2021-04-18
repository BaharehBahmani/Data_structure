#include "Queue.h"  // function declarations
#include <cstddef>  // std::size_t
#include <iostream> // std::cout


void Queue::push(char value) {
    ++length;
    Node *node = new Node;
    node->value = value;
    node->next = nullptr;
    if (tail) tail->next = node;
    else head = node;
    tail = node;
}

char Queue::pop() {
    if (length) {
        char tmpValue;
        --length;
        Node* tmp = head;
        head = head->next;
        if (!head) tail = nullptr;
        tmpValue = tmp->value;
        delete tmp;
        return tmpValue;
    }
    return 0;
}

char& Queue::front() {
    return head->value;
}

const char& Queue::front() const {
    return head->value;
}

char& Queue::back() {
    return tail->value;
}

const char& Queue::back() const {
    return tail->value;
}

// 0      -> false
// others -> true
bool Queue::empty() const {
    return !length;
}

std::size_t Queue::size() const {
    return length;
}

void Queue::print() const {
    std::cout << "{ ";
    Node* tmp = head;
    while(tmp) {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << "}\n";
}

Queue::~Queue() {
    while(head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}