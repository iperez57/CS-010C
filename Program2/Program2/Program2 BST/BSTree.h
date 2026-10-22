#include "Node.h"

#ifndef BSTREE_H
#define BSTREE_H

class BSTree {

private:
	Node* root;

private:
	void preOrder(Node*) const;
	void inOrder(Node*) const;
	void postOrder(Node*) const;

	bool search(Node*, const std::string&) const;
	bool remove(Node*, Node*, const string&);

	int height(Node*) const;

public:
	BSTree();
	void insert(const std::string& data);
	bool search(const std::string& data) const;
	void inOrder() const;
	void postOrder() const;
	void preOrder() const;
	std::string largest() const;
	std::string smallest() const;
	int height(const std::string&) const;
	void remove(const std::string&);
};

#endif