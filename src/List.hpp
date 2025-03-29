#pragma once

#include "IContainer.hpp"

namespace containers {

template<typename T>
class List : public IContainer<T> {
public:

    List() : IContainer<T>() {}

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

    void insert(size_t pos, T value) {
        if (pos > m_size) {
            throw std::out_of_range("Position out of container");
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
    }

    void erase(size_t pos) {
        if (pos >= m_size) {
            throw std::out_of_range("Position out of container");
        }

        Node* nodeToDelete = nullptr;

        if (pos == 0) {
            nodeToDelete = m_first;
            m_first = m_first->next;
        } else {
            nodeToDelete = getElement(pos);
            getElement(pos-1)->next = getElement(pos+1);
        }

        delete nodeToDelete;
        --m_size;
    }

    size_t size() const {
        return m_size;
    }

    const T& operator[](size_t pos) const {
        return getElement(pos)->data;
    }

private:

struct Node {
    Node* next{nullptr};
    T data;
};

    Node* getElement(size_t pos) const {
        Node* iter = m_first;
        for (size_t i = 0; i < pos; ++i) {
            iter = iter->next;
        }
        return iter;
    }

    size_t m_size{0};
    Node* m_first{nullptr};
    Node* m_last{nullptr};
};

} // containers
