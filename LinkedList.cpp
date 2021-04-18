#include "LinkedList.h"
#include <iostream>
#include <cstddef>


void LinkedList::push_back(const std::string& value) {
    ++length;
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;
    if (!tail) head = node;
    else tail->next = node;
    tail = node;
}

void LinkedList::push_front(const std::string& value) {
    ++length;
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;
    if (head) node->next = head;
    else tail = node;
    head = node;
}

void LinkedList::insert(LinkedList::Node* pos, const std::string& value) {
    if (!length) push_back(value);
    else {
        ++length;
        Node* node = new Node;
        node->value = value;
        node->next = pos->next;
        pos->next = node;
        if (pos == tail) tail = node;
    }
}

void LinkedList::push_in_order(const std::string& value) {
    if (!length) push_back(value);
    else if (value <= head->value) push_front(value);
    else {
        Node* tmp = head;
        while (tmp->next) {
            if (value <= tmp->next->value) {
                insert(tmp, value);
                return;
            }
            tmp = tmp->next;
        }
        insert(tmp, value);
    }
}

void LinkedList::print() const {
    std::cout << "{ ";
    Node* tmp = head;
    while(tmp) {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << "}\n";
}

void LinkedList::pop_front() {
    if (length) {
        --length;
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}

std::size_t LinkedList::size() const {
    return length;
}

bool LinkedList::empty() const {
    return (!length);
}

LinkedList::Node* LinkedList::begin() {
    return head;
}

const LinkedList::Node* LinkedList::begin() const {
    return head;
}

LinkedList::Node* LinkedList::end() {
    return tail;
}

const LinkedList::Node* LinkedList::end() const {
    return tail;
}

LinkedList::~LinkedList() {
    while(head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}
