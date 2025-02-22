#pragma once

#include "IContainer.hpp"

namespace containers {

template<typename T>
class List : public IContainer<T> {
public:

    List()
        : IContainer<T>()
        , m_size{0}
        , m_first{nullptr}
        , m_last(nullptr)
    {}

    ~List() {
        Node* iter = m_first;
        for(size_t i = 0; i < m_size; ++i) {
            Node* current = iter;
            iter = iter->next;
            delete current;
        }
    }

    void push_back(T value) {
        Node* new_node = new Node{};
        new_node->data = value;

        if (!m_first) {
            m_first = m_last = new_node;
        } else if (m_last) {
            m_last->next = new_node;
            m_last = new_node;

        }
        
        ++m_size;
    }

    bool insert(size_t pos, T value) {
        if (pos > m_size) {
            return false;
        }

        Node* new_node = new Node{};
        new_node->data = value;

        if(pos==0) {
            new_node->next = m_first;
            m_first = new_node;
        } else {
            new_node->next=getElement(pos);
            getElement(pos-1)->next = new_node;
        }
        
        ++m_size;

        return true;
    }

    bool erase(size_t pos) {
        if (pos > m_size) {
            return false;
        }

        Node* nodeToDelete = getElement(pos-1);
        getElement(pos-2)->next = getElement(pos);
        delete nodeToDelete;

        --m_size;

        return true;
    }

    size_t size() const {
        return m_size;
    }

    T& operator[](size_t pos) const {
        Node* iter = m_first;
        for (size_t i = 0; i < pos; ++i) {
            iter = iter->next;
        }
        return iter->data;
    }

private:

struct Node {
    Node()
        : next(nullptr)
    {}

    Node* next;
    T data;
};

    Node* getElement(size_t pos) const {
        Node* iter = m_first;
        for (size_t i = 0; i < pos; ++i) {
            iter = iter->next;
        }
        return iter;
    }

    size_t m_size;
    Node* m_first;
    Node* m_last;
};

} // containers
