#pragma once
#include "SortedSet.h"
#include <iostream>
using namespace std;
//#include "RBTree.h"

struct Node {
	int data; // holds the key
	Node* parent; // pointer to the parent
	Node* left; // pointer to left child
	Node* right; // pointer to right child
	int color; // 1 -> Red, 0 -> Black
};
typedef Node* NodePtr;

class TreeSet :
    public SortedSet<TreeSet, Node>
{
private:
	NodePtr root;
	NodePtr TNULL;
	void initializeNULLNode(NodePtr node, NodePtr parent);
	void preOrderHelper(NodePtr node);
	void inOrderHelper(NodePtr node);
	void postOrderHelper(NodePtr node);
	void getChildsHelper(NodePtr node, TreeSet& toCopy, bool const &foundMax = false);

	NodePtr searchTreeHelper(NodePtr node, int key);
	void fixDelete(NodePtr x);
	void rbTransplant(NodePtr u, NodePtr v);
	void deleteNodeHelper(NodePtr node, int key);
	void fixInsert(NodePtr k);
	void preorder();
	void inorder();
	void postorder();

	NodePtr minimum(NodePtr node);
	NodePtr maximum(NodePtr node);
	NodePtr successor(NodePtr x);
	NodePtr predecessor(NodePtr x);
	void leftRotate(NodePtr x);

	void printHelper(NodePtr root, string indent, bool last) {
		// print the tree structure on the screen
		if (root != TNULL) {
			cout << indent;
			if (last) {
				cout << "R----";
				indent += "     ";
			}
			else {
				cout << "L----";
				indent += "|    ";
			}

			string sColor = root->color ? "RED" : "BLACK";
			cout << root->data << "(" << sColor << ")" << endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
		// cout<<root->left->data<<endl;
	}
	
public:
	TreeSet();
	void rightRotate(NodePtr x);
	void add(int e);
	void addAll(TreeSet c) const;
	void clear();
	bool contains(int e);
	void containsAll(TreeSet c);
	void remove(int e);
	void removeAll(TreeSet c);
	bool isEmpty();
	int max();
	int size();
	int first();
	TreeSet headSet(int toElement);
	int last();
	void getSubsetHelper(NodePtr node, TreeSet& toCopy, int const& min, int const& max);
	TreeSet subSet(int fromElement, int toElement);
	TreeSet tailSet(int fromElement);

	NodePtr getRoot() {
		return this->root;
	}

	void prettyPrint() {
		if (root) {
			printHelper(this->root, "", true);
		}
	}
};

NodePtr searchTreeHelper(NodePtr node, int key);