#include "Node.h"
#include <stdexcept>

namespace matrices {

    Node::Node(double* value, int name) : arr(value), name(name), next(nullptr) {}

    Node::~Node() {
        delete[] arr; // משחרר את המערך אם נוצר עם new double[]
    }

    Node* Node::getnext()const  {
        return next;
    }

    void Node::setnext(Node* nextNode) {
        next = nextNode;
    }

    Node* Node::goTo(int index) {
        Node* current = this;
        while (current != nullptr && current->name != index) {
            current = current->next;
        }
        return current;
    }

    double* Node::get(int index) {
        Node* node = goTo(index);
        if (!node) throw std::out_of_range("Row index not found");
        return node->arr;
    }

    void Node::set(double* value) {
        arr = value;
    }

    void Node::set(int nodeindex, int arrindex, double value) {
        Node* node = goTo(nodeindex);
        if (!node) throw std::out_of_range("Node index out of range");
        node->arr[arrindex] = value;
    }

    double Node::getvalinarr(int nodeindex, int arrindex) {
        Node* node = goTo(nodeindex);
        if (!node) throw std::out_of_range("Node index out of range");
        return node->arr[arrindex];
    }

    int Node::getname()const  {
        return name;
    }

    double* Node::getarr()const  {
        return arr;
    }

    void Node::setarr(double* value) {
        arr = value;
    }

}
// namespace matrices