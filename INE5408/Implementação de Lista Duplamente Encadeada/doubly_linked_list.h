//! "Copyright 2018, Paloma Cione"
#include <cstdint>
#include <stdexcept>
namespace structures {

template<typename T>
//! classe duplamente encadeada
class DoublyLinkedList {
 public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    //! ...
    void clear();
    //! ...
    void push_back(const T& data);  // insere no fim
    //! ...
    void push_front(const T& data);  // insere no início
    //! ...
    void insert(const T& data, std::size_t index);  // insere na posição
    //! ...
    void insert_sorted(const T& data);  // insere em ordem
    //! ...
    T pop(std::size_t index);  // retira da posição
    //! ...
    T pop_back();  // retira do fim
    //! ...
    T pop_front();  // retira do início
    //! ...
    void remove(const T& data);  // retira específico
    //! ...
    bool empty() const;  // lista vazia
    //! ...
    bool contains(const T& data) const;  // contém
    //! ...
    T& at(std::size_t index);  // acesso a um elemento (checando limites)
    //! ...
    const T& at(std::size_t index) const;  // getter constante a um elemento
    //! ...
    std::size_t find(const T& data) const;  // posição de um dado
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
        Node(const T& data, Node* prev, Node* next) {
            data_ = data;
            prev_ = prev;
            next_ = next;
        }

        T& data() {
            return data_;
        }
        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }
        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    Node* head;  // primeiro da lista
    Node* tail;  // ultimo da lista
    std::size_t size_;
};
template <typename T>structures::DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size_ = 0u;
}
template <typename T>structures::DoublyLinkedList<T>::~DoublyLinkedList() {
    DoublyLinkedList::clear();
}
template <typename T>bool structures::DoublyLinkedList<T>::empty() const {
    if (size_== 0)
        return true;
    else
        return false;
}
template <typename T>std::size_t structures::DoublyLinkedList<T>::size() const {
    return size_;
}
template <typename T>void
structures::DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
    Node* novo, *anterior;
    if (index > size()) {
        throw std::out_of_range("Invalid index");
    } else if (index == 0) {
        novo = new Node(data);
        if (novo == nullptr) {
            throw std::out_of_range("Lista cheia");
        } else {
            novo->next(head);
            novo->prev(nullptr);
            head = novo;
            if (novo->next() != nullptr)
                novo->next()->prev(novo);
            else
                tail = novo;
            size_++;
        }
    } else {
        novo = new Node(data);
        if (novo == nullptr) {
            throw std::out_of_range("Lista cheia");
        } else {
            anterior = head;
            for (size_t i = 0; i< index - 1; i++)
                anterior = anterior->next();
            novo->next(anterior->next());
            if (novo->next()!= nullptr)
               novo->next()->prev(novo);
            else
                tail = novo;
            size_++;
            anterior->next(novo);
            novo->prev(anterior);
        }
}
}
template <typename T>void
structures::DoublyLinkedList<T>::push_front(const T& data) {
    insert(data, 0);
}
template <typename T>void
structures::DoublyLinkedList<T>::push_back(const T& data) {
    insert(data, size());
}
template <typename T>bool
structures::DoublyLinkedList<T>::contains(const T& data) const {
    Node* aux = head;
    for (size_t i =0; i< size_; i++)
        if (aux->data() == data)
            return true;
        else
            aux= aux->next();
    return false;
}
template <typename T>std::size_t
structures::DoublyLinkedList<T>::find(const T& data) const {
        Node* aux = head;
         for (size_t i= 0; i< size_; i++) {
            if (aux->data() == data) {
                return i;
            } else {
                aux = aux->next();
            }
    }
return size_;
}
template <typename T>T& structures::DoublyLinkedList<T>::at(std::size_t index) {
    Node* aux = head;
    if (index < 0 || index>= size()) {
        throw std::out_of_range("Erro de index");
    } else if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        for (size_t i= 0; i< index; i++)
             aux = aux->next();
    }
    return aux->data();
}
template <typename T>void
structures::DoublyLinkedList<T>::remove(const T& data) {
    pop(find(data));
}
template <typename T>T structures::DoublyLinkedList<T>::pop(size_t index) {
    Node* anterior, *eliminar;
    T data;
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else if (index >= size_) {
        throw std::out_of_range("Invalid index");
    } else if (index == 0) {
        eliminar = head;
        head = head->next();
        data = eliminar->data();
        if (eliminar->next()!= nullptr)
            eliminar->next()->prev(head);
        else
            tail = head;
        delete eliminar;
        size_--;
    } else {
        anterior = head;
        for (size_t i= 0; i< index - 1; i++)
            anterior = anterior->next();
        eliminar  = anterior->next();
        data = eliminar->data();
        anterior->next(eliminar->next());
        if (eliminar->next()!= nullptr)
            eliminar->next()->prev(anterior);
        else
            tail = anterior;
        size_--;
        delete eliminar;
        }
    return data;
}
template <typename T>T structures::DoublyLinkedList<T>::pop_front() {
    return pop(0);
}
template <typename T>T structures::DoublyLinkedList<T>::pop_back() {
    return pop(size_ -1);
}
template <typename T>void
structures::DoublyLinkedList<T>::insert_sorted(const T& data) {
    Node* atual = head;
    size_t posicao = 0;
     while (atual != nullptr && atual->data()< data) {
        atual = atual->next();
        posicao++;
    }
     insert(data, posicao);
}
template <typename T>void structures::DoublyLinkedList<T>::clear() {
    Node* atual, *anterior;
    atual = head;
        while (atual!= nullptr) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
        }
    size_ = 0;
    head = nullptr;
    tail = nullptr;
}
}  // namespace structures
