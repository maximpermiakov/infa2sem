#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    Node *prev = nullptr;
    Node *next = nullptr;
    int key    = 0;
};

struct List
{
    Node *HEAD  = nullptr;
    Node *TAIL  = nullptr;
    Node *NIL   = nullptr;
    size_t size = 0;
};

List *create_empty_list() {
    List *list = new List;
    Node *NIL  = new Node;
    list->NIL  = NIL;
    list->HEAD = NIL;
    list->TAIL = NIL;
    return list;
}

List *push_front(List *list_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    if (list_ptr->HEAD == list_ptr->NIL) {
        Node *new_node = new Node;
        new_node->key  = new_key;
        new_node->prev = list_ptr->NIL;
        new_node->next = list_ptr->NIL;
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = new_node;
        list_ptr->size++;
        return list_ptr;
    }
    Node *second_node    = list_ptr->HEAD;
    Node *new_node       = new Node;
    list_ptr->HEAD       = new_node;
    list_ptr->HEAD->next = second_node;
    list_ptr->HEAD->prev = list_ptr->NIL;
    second_node->prev    = list_ptr->HEAD;
    list_ptr->HEAD->key  = new_key;
    list_ptr->size++;
    return list_ptr;
}

List *push_back(List *list_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    if (list_ptr->HEAD == list_ptr->NIL) {
        Node *new_node = new Node;
        new_node->key  = new_key;
        new_node->prev = list_ptr->NIL;
        new_node->next = list_ptr->NIL;
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = new_node;
        list_ptr->size++;
        return list_ptr;
    }
    Node *secondlast     = list_ptr->TAIL;
    Node *new_node       = new Node;
    list_ptr->TAIL       = new_node;
    list_ptr->TAIL->next = list_ptr->NIL;
    list_ptr->TAIL->prev = secondlast;
    secondlast->next     = list_ptr->TAIL;
    list_ptr->TAIL->key  = new_key;
    list_ptr->size++;
    return list_ptr;
}

List *insert_after(List *list_ptr, Node *prev_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    if (prev_ptr == list_ptr->NIL) return list_ptr;
    Node *new_node = new Node;
    new_node->next = prev_ptr->next;
    new_node->prev = prev_ptr;
    prev_ptr->next = new_node;
    new_node->key  = new_key;
    if (new_node->next != list_ptr->NIL) {
        new_node->next->prev = new_node;
    } else {
        list_ptr->TAIL = new_node;
    }
    list_ptr->size++;
    return list_ptr;
}

void print_list(const List *list_ptr) {
    if (list_ptr == nullptr or list_ptr->HEAD == list_ptr->NIL) return;
    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << current->key << std::endl;
    return;
}

void clear_list(List *list_ptr) {
    if (list_ptr == nullptr or list_ptr->HEAD == list_ptr->NIL) return;
    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        current = current->next;
        delete current->prev;
    }
    delete current;
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    list_ptr->size = 0;
    return;
}

void destroy_list(List *list_ptr) {
    if (list_ptr == nullptr) return;
    if (list_ptr->HEAD == list_ptr->NIL) {
        delete list_ptr->NIL;
        delete list_ptr;
        return;
    }
    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        current = current->next;
        delete current->prev;
    }
    delete current;
    delete list_ptr->NIL;
    delete list_ptr;
    return;
}

Node *find_key(List *list_ptr, int key) {
    if (list_ptr == nullptr) return nullptr;
    if (list_ptr->HEAD == list_ptr->NIL) return list_ptr->NIL;
    Node *current = list_ptr->HEAD;
    while (current != nullptr and current->key != key) {
        current = current->next;
    }
    return current;
}

void remove_key(List *list_ptr, int key) {
    if (list_ptr == nullptr or list_ptr->HEAD == list_ptr->NIL) return;
    Node *current = list_ptr->HEAD;
    while (current != nullptr and current->key != key) {
        current = current->next;
    }
    if (current != list_ptr->NIL) {
        if (current != list_ptr->HEAD) {
            current->prev->next = current->next;
        } else {
            current->next->prev = list_ptr->NIL;
            list_ptr->HEAD      = current->next;
        }
        if (current != list_ptr->TAIL) {
            current->prev->next = current->next;
        } else {
            current->prev->next = list_ptr->NIL;
            list_ptr->TAIL      = current->prev;
        }
    }
    delete current;
    return;
}