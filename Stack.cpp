#include "Stack.h"  // function declarations
#include <iostream> // std::cout

void Stack::push(char value) {
    ++length;
    Node* node = new Node;
    node->value = value;
    node->next = head;
    head = node;
}

std::size_t Stack::size() const {
    return length;
}

// 0      -> false
// others -> true
bool Stack::empty() const {
    return !length;
}

char& Stack::top() {
    return head->value;
}

const char& Stack::top() const {
    return head->value;
}

char Stack::pop() {
    if (length) {
        char tmpValue;
        --length;
        Node* tmp = head;
        head = head->next;
        tmpValue = tmp->value;
        delete tmp;
        return tmpValue;
    }
    return 0;
}

void Stack::print() const {
    std::cout << "{ ";
    Node* tmp = head;
    while(tmp) {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << "}\n";
}

Stack::~Stack() {
    while(head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}
