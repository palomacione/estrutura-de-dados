// "Copyright 2018, Paloma Cione"
#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! ldkfmd
class LinkedStack {
 public:
    //! aaaa
    LinkedStack();  // construtor
    //! aaa
    ~LinkedStack();  // deconstrutor
    //! aaa
    void clear();  //! limpa pilha
    //! aaa
    void push(const T& data);  // empilha
    //! aaa
    T pop();  // desempilha
    //! aaa
    T& top() const;  // dado no topo
    //! aaa
    bool empty() const;  // pilha vazia
    //! aaa
    std::size_t size() const;  // tamanho da pilha

 private:
    class Node {
     public:
        explicit Node(const T& data) {
            data_ = data;
        }

        Node(const T& data, Node* next) {
            data_ = data;
            next_ = next;
        }

        T& data() {
            return data_;
        }  // getter: info

        const T& data() const {
            return data_;
        }  // getter-constante: info

        Node* next() {
            return next_;
        }  // getter: próximo

        const Node* next() const {
            return next_;
        }  // getter-constante: próximo

        void next(Node* next) {
            next_ = next;
        }  // setter: próximo

     private:
     T data_;
     Node* next_;
    };

    Node* top_;  // nodo-topo
    std::size_t size_;  // tamanho
};
template <typename T>structures::LinkedStack<T>::LinkedStack() {
    size_ = 0;
    top_ = nullptr;
}
template <typename T>structures::LinkedStack<T>::~LinkedStack() {
    LinkedStack::clear();
}
template <typename T>void structures::LinkedStack<T>::clear() {
    Node* atual =  top_;
    Node* anterior;
    if (!empty()) {
        while (atual!= nullptr) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
        }
    }
    size_ = 0;
    top_ = nullptr;
}
template <typename T>bool structures::LinkedStack<T>::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}
template <typename T>std::size_t structures::LinkedStack<T>::size() const {
    return size_;
}
template <typename T>T& structures::LinkedStack<T>::top() const {
    if (!empty())
        return top_->data();
    else
        throw std::out_of_range("Pilha vazia");
}
template <typename T>void structures::LinkedStack<T>::push(const T& data) {
    Node* novo = new Node(data);
    if (novo == nullptr) {
        throw std::out_of_range("Pilha cheia");
    } else {
        novo->next(top_);
        top_ = novo;
        size_++;
    }
}
template <typename T>T structures::LinkedStack<T>::pop() {
    T data;
    Node* aux;
    if (empty()) {
        throw std::out_of_range("Pilha vazia");
    } else {
        aux = top_;
        data = top_->data();
        size_--;
        top_ = top_->next();
        delete aux;
}
    return data;
}
}  // namespace structures
