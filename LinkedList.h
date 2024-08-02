#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<T>* cur = head;
        while (cur != NULL) {
            Node<T>* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    
    T* find(T data) const;
    void print() const;
    void del(T data);
    void add(T data);

protected:
    
    Node<T>* head;
};

template <typename T>
T* LinkedList<T>::find(T data) const {
    Node<T>* cur = head;

    while (cur != NULL && cur->data < data) {
        cur = cur->next;
    }

    if (cur != NULL && cur->data == data) {
        return &(cur->data);
    }

    return NULL;
}

template <typename T>
void LinkedList<T>::print() const {
    Node<T>* cur = head;

    while (cur != NULL) {
        cout << cur->data;
        cout << endl;
        cur = cur->next;
    }

    cout << endl;
}

template <typename T>
void LinkedList<T>::add(T data) {
    Node<T>* newNode = new Node<T>(data,NULL);
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node<T>* cur = head;
        Node<T>* prev = NULL;

        while (cur != NULL && cur->data < newNode->data) {
            prev = cur;
            cur = cur->next;
        }

        if (prev == NULL) {
            newNode->next = head;
            head = newNode;
        }
        else {
            newNode->next = cur;
            prev->next = newNode;
        }
    }
}

template <typename T>
void LinkedList<T>::del(T data) {
    Node<T>* cur = head;
    Node<T>* prev = NULL;

    while (cur != NULL && cur->data < data) {
        prev = cur;
        cur = cur->next;
    }

    if (cur != NULL && cur->data == data) {
        if (prev == NULL) {
            head = cur->next;
        }
        else {
            prev->next = cur->next;
        }

        delete cur;
    }
}

#endif
