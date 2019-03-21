// "Copyright 2018, Paloma Cione"
#include <cstdint>
#include <stdexcept>

namespace structures {


template<typename T>
//! ...
class LinkedQueue {
 public:
    LinkedQueue();

    ~LinkedQueue();
    //! ...
    void clear();  // limpar
    //! ...
    void enqueue(const T& data);  // enfilerar
    //! ...
    T dequeue();  // desenfilerar
    //! ...
    T& front() const;  // primeiro dado
    //! ...
    T& back() const;  // último dado
    //! ...
    bool empty() const;  // fila vazia
    //! ...
    std::size_t size() const;  // tamanho

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

    Node* head;  // nodo-cabeça
    Node* tail;  // nodo-fim
    std::size_t size_;  // tamanho
};
template <typename T>structures::LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}	 	  	 	      	      	    	   	  	  	       	 	
template <typename T>structures::LinkedQueue<T>::~LinkedQueue() {
    LinkedQueue::clear();
}
template <typename T>void structures::LinkedQueue<T>::enqueue(const T& data) {
    Node* novo = new Node(data);
    if (novo == nullptr) {
        throw std::out_of_range("Fila cheia");
    } else if (empty()) {
        head = novo;
        tail = novo;
        novo->next(nullptr);
        size_++;
    } else {
        novo->next(nullptr);
        tail->next(novo);
        tail = novo;
        size_++;
    }
    }
template <typename T>T structures::LinkedQueue<T>::dequeue() {
    if (empty())
        throw std::out_of_range("Fila vazia");
    Node* aux;
    T data;
    if (size_ == 1) {
        data = head->data();
        aux = head;
        delete aux;
        head = nullptr;
        tail = nullptr;
        size_--;
    } else {
        aux = head;
        data = head->data();
        head = head->next();
        delete aux;
        size_--;
    }	 	  	 	      	      	    	   	  	  	       	 	
    return data;
}
template <typename T>bool structures::LinkedQueue<T>::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}
template <typename T>std::size_t structures::LinkedQueue<T>::size() const {
    return size_;
}
template <typename T>T& structures::LinkedQueue<T>::front() const {
    if (empty())
        throw std::out_of_range("Fila vazia");
    return head->data();
}
template <typename T>T& structures::LinkedQueue<T>::back() const {
    if (empty())
        throw std::out_of_range("Fila vazia");
    return tail->data();
}
template <typename T>void structures::LinkedQueue<T>::clear() {
    if (!empty()) {
        Node* atual = head;
        Node* anterior;
        while (atual != nullptr) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
        }
    size_ = 0u;
    head = nullptr;
    tail = nullptr;
    }
}
}  // namespace structures
	 	  	 	      	      	    	   	  	  	       	 	
