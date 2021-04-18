#ifndef LAB3_LINKEDLIST_H
#define LAB3_LINKEDLIST_H

#include <string>
#include <cstddef>

class LinkedList {
private:
    struct Node {
        std::string value{};
        Node* next{};
    };

    Node* head{};
    Node* tail{};
    std::size_t length{};

    // insert value after pos
    void insert(Node* pos, const std::string& value);

public:
    LinkedList() = default;

    void push_back(const std::string& value);
    void push_front(const std::string& value);
    void push_in_order(const std::string& value);
    void pop_front();
    std::size_t size() const;
    bool empty() const;
    void print() const;
    Node* begin();
    const Node* begin() const;
    Node* end();
    const Node* end() const;

    ~LinkedList();
};

#endif //LAB3_LINKEDLIST_H
