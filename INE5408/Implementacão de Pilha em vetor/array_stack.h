/* Copyright [2018] <Copyright Paloma Cione>
*/
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  //  std::size_t
#include <stdexcept>  //   C++ exceptions

namespace structures {

template<typename T>
/**
 * Template
 */
class ArrayStack {
 private:
    int tam;
    T* contents;
    int top_;
    std::size_t max_size_;
    static const auto DEFAULT_SIZE = 10u;

 public:
        //! Construtor sem paramêtro
        ArrayStack();
        //! Construtor com paramêtro
        explicit ArrayStack(std::size_t max);
        //! Deconstrutor
        ~ArrayStack();
        //! Empilha
        void push(const T& data);
        //! Desempilha
        T pop();
        //! Retorna o top
        T& top();
        //! Limpa a pilha
        void clear();
        //! Retorna o tamanho
        std::size_t size();
        //! Retorna o tamanho máximo
        std::size_t max_size();
        //! Retorna se pilha está vazia
        bool empty();
        //! Retorna se pilha está cheia
        bool full();
};
template <typename T>structures::ArrayStack<T>::ArrayStack() {
         contents = new T[DEFAULT_SIZE];
         max_size_ = DEFAULT_SIZE;
        tam = 0;
        top_ = -1;
     }
template <typename T>structures::ArrayStack<T>::ArrayStack(std::size_t max) {
        contents = new T[max];
        top_ = -1;
        tam =0;
        max_size_ = max;
    }

template <typename T>structures::ArrayStack<T>::~ArrayStack() {
        delete []contents;
    }

template <typename T> bool structures::ArrayStack<T>::empty() {
        if (top_ == -1)
        return true;
        else
        return false;
    }  // vazia

template <typename T> bool structures::ArrayStack<T>::full() {
        if (tam == max_size_)
        return true;
        else
        return false;
    }  // cheia
template <typename T> void structures::ArrayStack<T>:: push(const T& data) {
        if (full()) {
        throw std::out_of_range("The Stack is full.");
        } else {
            top_++;
            tam++;
            contents[top_] = data;
    }  // empilha
  }
template <typename T> T structures::ArrayStack<T>::pop() {
        if (empty()) {
        throw std::out_of_range("The Stack is empty.");
    } else {
            top_--;
            tam--;
            return contents[top_ +1];
        }
    }  // desempilha

template <typename T> T& structures::ArrayStack<T>::top() {
        if (empty())
        throw std::out_of_range("The Stack is empty.");
        else
        return contents[top_];
    }
template <typename T> void structures::ArrayStack<T>::clear() {
        top_ = -1;
        tam = 0;
    }  //  limpa

template <typename T>std::size_t structures::ArrayStack<T>::size() {
        return tam;
    }  //  tamanho

template <typename T>std::size_t structures::ArrayStack<T>::max_size() {
        return max_size_;
    }
}   // namespace structures
#endif
