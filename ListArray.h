#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
    private:
        T* arr;                           // Puntero al array dinámico
        int max;                          // Tamaño actual del array
        int n;                            // Número de elementos en la lista
        static const int MINSIZE = 2;     // Tamaño mínimo del array

        // Método privado para redimensionar el array
        void resize(int new_size) {
            // Crear nuevo array con el nuevo tamaño
            T* new_arr = new T[new_size];
            
            // Copiar elementos del array anterior al nuevo
            for (int i = 0; i < n; i++) {
                new_arr[i] = arr[i];
            }
            
            // Liberar memoria del array anterior
            delete[] arr;
            
            // Actualizar puntero y tamaño máximo
            arr = new_arr;
            max = new_size;
        }

    public:
        // Constructor
        ListArray() {
            arr = new T[MINSIZE];
            max = MINSIZE;
            n = 0;
        }

        // Destructor
        ~ListArray() {
            delete[] arr;
        }

        // Sobrecarga del operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }
            return arr[pos];
        }

        // Sobrecarga global del operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
            out << "List => [";
            for (int i = 0; i < list.n; i++) {
                out << list.arr[i];
                if (i < list.n - 1) {
                    out << ", ";
                }
            }
            out << "]";
            return out;
        }

        // Implementación de métodos heredados de List<T>
        
        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición de inserción inválida");
            }
            
            // Si el array está lleno, redimensionar
            if (n == max) {
                resize(max * 2);  // Duplicar el tamaño
            }
            
            // Desplazar elementos a la derecha desde la posición pos
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            
            // Insertar el nuevo elemento
            arr[pos] = e;
            n++;
        }

        void append(T e) override {
            insert(n, e);  // Reutilizar insert para añadir al final
        }

        void prepend(T e) override {
            insert(0, e);  // Reutilizar insert para añadir al principio
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición de eliminación inválida");
            }
            
            // Guardar el elemento a eliminar
            T elemento = arr[pos];
            
            // Desplazar elementos a la izquierda desde pos+1
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            
            n--;
            
            // Si el array está muy vacío (menos del 25% de ocupación), reducir tamaño
            if (n > 0 && n <= max / 4 && max > MINSIZE) {
                resize(max / 2);
            }
            
            return elemento;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }
            return arr[pos];
        }

        int search(T e) override {
            for (int i = 0; i < n; i++) {
                if (arr[i] == e) {
                    return i;
                }
            }
            return -1;  // No encontrado
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }
};

#endif
