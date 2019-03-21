/* Copyright [2018] <Copyright Paloma Cione>
 */
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>   // C++ Exceptions

namespace structures {

template<typename T>
//! Classe Lista
class ArrayList {
 public:
    ArrayList();  //! Cosntrutor sem paramêtro
    explicit ArrayList(std::size_t max_size);  //! Construtor com paramêtro
    ~ArrayList();  //! Deconstrutor

    void clear();  //! Limpa lista
    void push_back(const T& data);   //! Adiciona no final
    void push_front(const T& data);  //! Adiciona no ínicio
    void insert(const T& data, std::size_t index);  //! Adiciona na posição
    void insert_sorted(const T& data);  //! Adiciona em ordem
    T pop(std::size_t index);  //! Retira da posição
    T pop_back();   //! Retira do final
    T pop_front();  //! Retira do ínicio
    void remove(const T& data);  //! Remove dado especifico
    bool full() const;  //! Verifica lista cheia
    bool empty() const;  //! Verifica lista vazia
    bool contains(const T& data) const;  //! Verifica se contém dado
    std::size_t find(const T& data) const;  //! Encontra dado na lista
    std::size_t size() const;  //! Tamanho da lista
    std::size_t max_size() const;  //! Tamanho máximo da lista
    T& at(std::size_t index);  //! Retorna dado na posicao
    T& operator[](std::size_t index);  //! Retorna dado na posicao
    const T& at(std::size_t index) const;  //! Retorna dado na posicao
    const T& operator[](std::size_t index) const;  //! Retorna dado na posicao

 private:
    T* contents;
    int ultimo;
    std::size_t size_;
    std::size_t max_size_;
    static const auto DEFAULT_MAX = 10u;
};
template <typename T>structures::ArrayList<T>::ArrayList() {
        contents = new T[DEFAULT_MAX];
        size_ = 0u;
        max_size_ = DEFAULT_MAX;
}
template <typename T>structures::ArrayList<T>::ArrayList(std::size_t max_size) {
        max_size_= max_size;
        contents = new T[max_size];
        size_ = 0u;
}
template <typename T>structures::ArrayList<T>::~ArrayList() {
        delete[] contents;
}
template <typename T>void structures::ArrayList<T>::clear() {
        size_ = 0u;
}
template <typename T>void structures::ArrayList<T>::push_front(const T& data) {
    insert(data, 0);
}
template <typename T>void structures::ArrayList<T>::push_back(const T& data) {
  insert(data, size_);
}
template <typename T>bool structures::ArrayList<T>::full() const {
    if (size_== max_size_)
        return true;
    else
        return false;
}
template <typename T>bool structures::ArrayList<T>::empty() const {
    if (size_== 0)
        return true;
    else
        return false;
}
template <typename T>std::size_t structures::ArrayList<T>::size() const {
    return size_;
}
template <typename T>std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}
template <typename T>
void structures :: ArrayList < T > :: insert(const T& data, std::size_t index) {
        int atual;
        if (full()) {
            throw std :: out_of_range("Erro Lista Cheia");
        } else {
            if (index < 0 || index > size_)
                throw std :: out_of_range("Erro Posição");
            atual = size_;
            while (atual > index) {
                contents[atual] = contents[atual - 1];
                atual = atual - 1;
            }
            size_ = size_ + 1;
            contents[index] = data;
        }
    }
template <typename T>T structures::ArrayList<T>::pop(std::size_t index) {
    T dado;
    std::size_t aux;
    if (empty()) {
         throw std::out_of_range("The List is empty.");
    } else if (index >= size_ || index< 0) {
        throw std::out_of_range("Invalid index");
    } else {
        aux= index;
        dado = contents[index];
        while (aux < size_ - 1) {
            contents[aux] = contents[aux +1];
            aux++;
        }
      size_--;
    }
    return dado;
}
template <typename T>T structures::ArrayList<T>::pop_back() {
    return pop(size_ -1);
}
template <typename T>T structures::ArrayList<T>::pop_front() {
  return pop(0);
}
template <typename T>void structures::ArrayList<T>::remove(const T& data) {
        std::size_t i = find(data);
        pop(i);
}
template <typename T>bool
structures::ArrayList<T>::contains(const T& data) const {
std::size_t index = 0;
    while (index< size_ -1)
        if (contents[index] == data) {
           return true;
        } else {
            index++;
        }
    return false;
}
template <typename T>std::size_t
structures::ArrayList<T>::find(const T& data) const {
    std::size_t result = size_;
    for (int i= 0; i < size_; i++)
        if (contents[i] == data)
        result = i;
    return result;
}
template <typename T>void
structures::ArrayList<T>::insert_sorted(const T& data) {
    int aux = 0;
    if (full()) {
        throw std::out_of_range("The List is full.");
    } else {
        while (aux< size_ && data> contents[aux])
            aux++;
}
       insert(data, aux);
       }
template <typename T>T& structures::ArrayList<T>::at(std::size_t index) {
    if (index < 0 || index > max_size_)
        throw std::out_of_range("Index does not exist.");
    else
    return contents[index];
}
template <typename T>const T&
structures::ArrayList<T>::at(std::size_t index) const {
    if (index < 0 || index > max_size_)
        throw std::out_of_range("Index does not exist.");
    else
    return contents[index];
}
template <typename T> T&
structures::ArrayList<T>::operator[](std::size_t index) {
     if (index < 0 || index > max_size_)
        throw std::out_of_range("Index does not exist.");
     else
    return contents[index];
}
template <typename T>const T&
structures::ArrayList<T>::operator[](std::size_t index) const {
     if (index < 0 || index > max_size_)
        throw std::out_of_range("Index does not exist.");
     else
        return contents[index];
}
}  //! namespace structures
#endif
