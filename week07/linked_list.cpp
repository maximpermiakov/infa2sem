#include <iostream>

struct Node
{
    Node *next = nullptr;
    int key    = 0;
};

void push_front(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->key = new_key;
        return;
    }
    Node *new_node = new Node;
    new_node->key  = new_key;
    new_node->next = head_ref;
    head_ref       = new_node;
}

void push_back(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->key = new_key;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    Node *new_node = new Node;
    new_node->key  = new_key;
    current->next  = new_node;
}

void insert_after(Node *&prev_ref, int new_key) {
    if (prev_ref == nullptr) {
        return;
    }
    Node *new_node = new Node;
    new_node->key  = new_key;
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
    return;
}

void destroy_list(Node *&head_ref) {
    if (head_ref == nullptr) return;
    while (head_ref->next != nullptr) {
        Node *tmp = head_ref->next->next;
        delete head_ref->next;
        head_ref->next = tmp;
    }
    delete head_ref->next;
    head_ref = nullptr;
    return;
}

void print_list(Node *head_ref) {
    if (head_ref == nullptr) {
        std::cout << std::endl;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << current->key << std::endl;
    return;
}

Node *find(Node *head_ref, int key) {
    if (head_ref == nullptr) return nullptr;
    Node *current = head_ref;
    while (current != nullptr) {
        if (current->key == key) return current;
        current = current->next;
    }
    return nullptr;
}

void remove_key(Node *&head_ref, int key) {
    if (head_ref == nullptr) return;
    Node *current = head_ref;
    if (current->key == key) {
        Node *tmp = current->next;
        delete head_ref;
        head_ref = tmp;
        return;
    }
    while (current->next != nullptr) {
        if (current->next->key == key) {
            Node *tmp = current->next->next;
            delete current->next;
            current->next = tmp;
            return;
        }
        current = current->next;
    }
    return;
}