#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}
    
    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }
    
    // Sobrecarga del operador []
    T operator[](int pos){
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        
        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    // Sobrecarga del operador << como función friend
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        out << "[";
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr) {
                out << ", ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }
    
    // Implementación de métodos heredados de List<T>
    
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida");
        }
        
        if (pos == 0) {
            // Insertar al principio
            first = new Node<T>(e, first);
        } else {
            // Insertar en otra posición
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }
    
    void append(T e) override {
        insert(n, e);
    }
    
    void prepend(T e) override {
        insert(0, e);
    }
    
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        
        T data;
        if (pos == 0) {
            // Eliminar el primero
            Node<T>* aux = first;
            data = aux->data;
            first = first->next;
            delete aux;
        } else {
            // Eliminar en otra posición
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            Node<T>* aux = prev->next;
            data = aux->data;
            prev->next = aux->next;
            delete aux;
        }
        n--;
        return data;
    }
    
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        
        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    int search(T e) override {
        Node<T>* current = first;
        int pos = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1;
    }
    
    bool empty() override {
        return n == 0;
    }
    
    int size() override {
        return n;
    }
};

#endif
