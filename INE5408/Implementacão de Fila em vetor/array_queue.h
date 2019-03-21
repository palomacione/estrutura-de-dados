/* Copyright [2018] <Copyright Paloma Cione>
 */
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>   // std::size_t
#include <stdexcept>   // C++ Exceptions

namespace structures {

template<typename T>
//! benis
class ArrayQueue {
 public:
    ArrayQueue();  //! Construtor sem paramêtro;

    explicit ArrayQueue(std::size_t);  //! Construtor com paramêtro;

    ~ArrayQueue();  //! Deconstrutor;

    void enqueue(const T& data);  //! Enfileira;

    T dequeue();  //! Desenfileira;

    T& back();  //! Retorna o último;

    void clear();  //! Limpa a fila;

    std::size_t size();  //! Retorna o tamanho atual;

    std::size_t max_size();  //! Retorna o tamanho máximo;

    bool empty();  //! Fila vazia;

    bool full();  //! Fila cheia;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};
template <typename T>structures::ArrayQueue<T>::ArrayQueue() {
    contents = new T[DEFAULT_SIZE];
    size_ = 0;
    max_size_ = DEFAULT_SIZE;
}
template <typename T>structures::ArrayQueue<T>::ArrayQueue(std::size_t max) {
    contents = new T[max];
    size_ = 0;
    max_size_ = max;
}
template <typename T>structures::ArrayQueue<T>::~ArrayQueue() {
    delete[] contents;
}
template <typename T> void structures::ArrayQueue<T>::clear() {
    size_ = 0;
}
template <typename T>std::size_t structures::ArrayQueue<T>::size() {
    return size_;
}
template <typename T>std::size_t structures::ArrayQueue<T>::max_size() {
    return max_size_;
}
template <typename T> bool structures::ArrayQueue<T>::full() {
    if (size_ == max_size_)
        return true;
    else
        return false;
}
template <typename T> bool structures::ArrayQueue<T>::empty() {
    if (size_ == 0)
        return true;
    else
        return false;
}
template <typename T> void structures::ArrayQueue<T>::enqueue(const T& data) {
    if (full()) {
        throw std::out_of_range("The Queue is full.");
    } else {
        contents[size_] = data;
         size_++;
    }
}
template <typename T> T structures::ArrayQueue<T>::dequeue() {
    T data;
    if (empty()) {
        throw std::out_of_range("The Queue is empty.");
    } else {
        data = contents[0];
        for (int i= 0; i< size_ -1; i++)
            contents[i] = contents[i+1];
        size_--;
    }
    return data;
}
template <typename T> T& structures::ArrayQueue<T>::back() {
    if (empty())
     throw std::out_of_range("The Queue is empty.");
    else
    return contents[size_ -1];
}
}    // namespace structures
#endif
