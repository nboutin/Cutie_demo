//
// Created by dor on 02/07/2020.
//

#ifndef DATASTRUCTURES_ALGORITHMS_TREE_HPP
#define DATASTRUCTURES_ALGORITHMS_TREE_HPP

#include <memory>
#include <functional>
#include "queue.hpp"
#include "stack.hpp"

template<typename T>
class Tree {
public:
    class Node;

    class Scanner;

    class PreorderScanner;

    using NodePtr = std::shared_ptr<Node>;

    static NodePtr create(const T&);
    static void do_bfs(const NodePtr& root, const std::function<void(const T&)>&);
    static PreorderScanner preorder(const NodePtr& root);
    static void do_postorder(const NodePtr& root, const std::function<void(const T&)>&);
    static void do_inorder(const NodePtr& root, const std::function<void(const T&)>&);

public:
    Tree() = delete;
    ~Tree() = delete;
};

template<typename T>
class Tree<T>::Node {
public:
    virtual ~Node() = default;
    const NodePtr& set_left(const T&);
    const NodePtr& set_right(const T&);

private:
    friend class Tree<T>;

    explicit Node(const T&);
    static NodePtr create(const T&);

public:
    T value;

private:
    NodePtr m_left;
    NodePtr m_right;
};

template<typename T>
class Tree<T>::Scanner {
public:
    explicit Scanner(const NodePtr&);
    virtual ~Scanner() = default;

    virtual void apply(const std::function<void(const T&)>&) const = 0;
    template<typename Container>
    Container collect();

protected:
    const NodePtr& m_root;
};

template<typename T>
class Tree<T>::PreorderScanner : public Tree<T>::Scanner {
public:
    explicit PreorderScanner(const NodePtr&);
    virtual ~PreorderScanner() = default;

    virtual void apply(const std::function<void(const T&)>&) const;
};

template<typename T>
typename Tree<T>::NodePtr Tree<T>::create(const T& value) {
    return Node::create(value);
}

template<typename T>
Tree<T>::Node::Node(const T& value) : value(value), m_left(), m_right() {}

template<typename T>
Tree<T>::Scanner::Scanner(const NodePtr& root) : m_root(root) {}

template<typename T>
Tree<T>::PreorderScanner::PreorderScanner(const NodePtr& root) : Scanner(root) {}

template<typename T>
typename Tree<T>::NodePtr Tree<T>::Node::create(const T& value) {
    return std::shared_ptr<Node>(new Node(value));
}

template<typename T>
const typename Tree<T>::NodePtr& Tree<T>::Node::set_left(const T& child_value) {
    m_left = create(child_value);
    return m_left;
}

template<typename T>
const typename Tree<T>::NodePtr& Tree<T>::Node::set_right(const T& child_value) {
    m_right = create(child_value);
    return m_right;
}

template<typename T>
void Tree<T>::do_bfs(const NodePtr& root, const std::function<void(const T&)>& function) {
    Queue<NodePtr> queue;

    for (queue.enqueue(root); !queue.is_empty(); queue.dequeue()) {
        const NodePtr& node = queue.next();
        if (node == nullptr) {
            continue;
        }
        function(node->value);
        queue.enqueue(node->m_left);
        queue.enqueue(node->m_right);
    }
}

template<typename T>
typename Tree<T>::PreorderScanner Tree<T>::preorder(const NodePtr& root) {
    return PreorderScanner(root);
}

template<typename T>
void Tree<T>::PreorderScanner::apply(const std::function<void(const T&)>& function) const {
    if (this->m_root == nullptr) {
        return;
    }
    function(this->m_root->value);
    preorder(this->m_root->m_left).apply(function);
    preorder(this->m_root->m_right).apply(function);
}

template<typename T>
void Tree<T>::do_postorder(const Tree::NodePtr& root, const std::function<void(const T&)>& function) {
    if (root == nullptr) {
        return;
    }
    do_postorder(root->m_left, function);
    do_postorder(root->m_right, function);
    function(root->value);
}

template<typename T>
void Tree<T>::do_inorder(const Tree::NodePtr& root, const std::function<void(const T&)>& function) {
    if (root == nullptr) {
        return;
    }
    do_inorder(root->m_left, function);
    function(root->value);
    do_inorder(root->m_right, function);
}

template<typename T>
template<typename Container>
Container Tree<T>::Scanner::collect() {
    Container container;
    apply([&](const T& item) { container.push_back(item); });
    return container;
}

#endif //DATASTRUCTURES_ALGORITHMS_TREE_HPP
