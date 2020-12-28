#include "TreeSet.h"

TreeSet::TreeSet()
{
	TNULL = new Node;
	TNULL->color = 0;
	TNULL->left = nullptr;
	TNULL->right = nullptr;
	root = TNULL;
}

void TreeSet::initializeNULLNode(NodePtr node, NodePtr parent) {
	node->data = 0;
	node->parent = parent;
	node->left = nullptr;
	node->right = nullptr;
	node->color = 0;
}

void TreeSet::preOrderHelper(NodePtr node) {
	if (node != TNULL) {
		cout << node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);
	}
}

void TreeSet::inOrderHelper(NodePtr node) {
	if (node != TNULL) {
		inOrderHelper(node->left);
		cout << node->data << " ";
		inOrderHelper(node->right);
	}
}

void TreeSet::postOrderHelper(NodePtr node) {
	if (node != TNULL) {
		postOrderHelper(node->left);
		postOrderHelper(node->right);
		cout << node->data << " ";
	}
}

NodePtr TreeSet::searchTreeHelper(NodePtr node, int key) {
	if (node == TNULL || key == node->data) {
		return node;
	}

	if (key < node->data) {
		return searchTreeHelper(node->left, key);
	}
	return searchTreeHelper(node->right, key);
}

// fix the rb tree modified by the delete operation
void TreeSet::fixDelete(NodePtr x) {
	NodePtr s;
	while (x != root && x->color == 0) {
		if (x == x->parent->left) {
			s = x->parent->right;
			if (s->color == 1) {
				// case 3.1
				s->color = 0;
				x->parent->color = 1;
				leftRotate(x->parent);
				s = x->parent->right;
			}

			if (s->left->color == 0 && s->right->color == 0) {
				// case 3.2
				s->color = 1;
				x = x->parent;
			}
			else {
				if (s->right->color == 0) {
					// case 3.3
					s->left->color = 0;
					s->color = 1;
					rightRotate(s);
					s = x->parent->right;
				}

				// case 3.4
				s->color = x->parent->color;
				x->parent->color = 0;
				s->right->color = 0;
				leftRotate(x->parent);
				x = root;
			}
		}
		else {
			s = x->parent->left;
			if (s->color == 1) {
				// case 3.1
				s->color = 0;
				x->parent->color = 1;
				rightRotate(x->parent);
				s = x->parent->left;
			}

			if (s->right->color == 0 && s->right->color == 0) {
				// case 3.2
				s->color = 1;
				x = x->parent;
			}
			else {
				if (s->left->color == 0) {
					// case 3.3
					s->right->color = 0;
					s->color = 1;
					leftRotate(s);
					s = x->parent->left;
				}

				// case 3.4
				s->color = x->parent->color;
				x->parent->color = 0;
				s->left->color = 0;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = 0;
}


void TreeSet::rbTransplant(NodePtr u, NodePtr v) {
	if (u->parent == nullptr) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

void TreeSet::deleteNodeHelper(NodePtr node, int key) {
	// find the node containing key
	NodePtr z = TNULL;
	NodePtr x, y;
	while (node != TNULL) {
		if (node->data == key) {
			z = node;
		}

		if (node->data <= key) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}

	if (z == TNULL) {
		cout << "Couldn't find key in the tree" << endl;
		return;
	}

	y = z;
	int y_original_color = y->color;
	if (z->left == TNULL) {
		x = z->right;
		rbTransplant(z, z->right);
	}
	else if (z->right == TNULL) {
		x = z->left;
		rbTransplant(z, z->left);
	}
	else {
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) {
			x->parent = y;
		}
		else {
			rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	if (y_original_color == 0) {
		fixDelete(x);
	}
}

// fix the red-black tree
void TreeSet::fixInsert(NodePtr k) {
	NodePtr u;
	while (k->parent->color == 1) {
		if (k->parent == k->parent->parent->right) {
			u = k->parent->parent->left; // uncle
			if (u->color == 1) {
				// case 3.1
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			}
			else {
				if (k == k->parent->left) {
					// case 3.2.2
					k = k->parent;
					rightRotate(k);
				}
				// case 3.2.1
				k->parent->color = 0;
				k->parent->parent->color = 1;
				leftRotate(k->parent->parent);
			}
		}
		else {
			u = k->parent->parent->right; // uncle

			if (u->color == 1) {
				// mirror case 3.1
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			}
			else {
				if (k == k->parent->right) {
					// mirror case 3.2.2
					k = k->parent;
					leftRotate(k);
				}
				// mirror case 3.2.1
				k->parent->color = 0;
				k->parent->parent->color = 1;
				rightRotate(k->parent->parent);
			}
		}
		if (k == root) {
			break;
		}
	}
	root->color = 0;
}

void TreeSet::preorder() {
	preOrderHelper(this->root);
}

void TreeSet::inorder() {
	inOrderHelper(this->root);
}

void TreeSet::postorder() {
	postOrderHelper(this->root);
}

// find the node with the minimum key
NodePtr TreeSet::minimum(NodePtr node) {
	while (node->left != TNULL) {
		node = node->left;
	}
	return node;
}

// find the node with the maximum key
NodePtr TreeSet::maximum(NodePtr node) {
	while (node->right != TNULL) {
		node = node->right;
	}
	return node;
}

// find the successor of a given node
NodePtr TreeSet::successor(NodePtr x) {
	// if the right subtree is not null,
	// the successor is the leftmost node in the
	// right subtree
	if (x->right != TNULL) {
		return minimum(x->right);
	}

	// else it is the lowest ancestor of x whose
	// left child is also an ancestor of x.
	NodePtr y = x->parent;
	while (y != TNULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

// find the predecessor of a given node
NodePtr TreeSet::predecessor(NodePtr x) {
	// if the left subtree is not null,
	// the predecessor is the rightmost node in the 
	// left subtree
	if (x->left != TNULL) {
		return maximum(x->left);
	}

	NodePtr y = x->parent;
	while (y != TNULL && x == y->left) {
		x = y;
		y = y->parent;
	}

	return y;
}

// rotate left at node x
void TreeSet::leftRotate(NodePtr x) {
	NodePtr y = x->right;
	x->right = y->left;
	if (y->left != TNULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

// rotate right at node x
void TreeSet::rightRotate(NodePtr x) {
	NodePtr y = x->left;
	x->left = y->right;
	if (y->right != TNULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x == x->parent->right) {
		x->parent->right = y;
	}
	else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

void TreeSet::add(int e)
{
	if (this->contains(e))
		return;

	// Ordinary Binary Search Insertion
	NodePtr node = new Node;
	node->parent = nullptr;
	node->data = e;
	node->left = TNULL;
	node->right = TNULL;
	node->color = 1; // new node must be red

	NodePtr y = nullptr;
	NodePtr x = this->root;

	while (x != TNULL) {
		y = x;
		if (node->data < x->data) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	// y is parent of x
	node->parent = y;
	if (y == nullptr) {
		root = node;
	}
	else if (node->data < y->data) {
		y->left = node;
	}
	else {
		y->right = node;
	}

	// if new node is a root node, simply return
	if (node->parent == nullptr) {
		node->color = 0;
		return;
	}

	// if the grandparent is null, simply return
	if (node->parent->parent == nullptr) {
		return;
	}

	// Fix the tree
	fixInsert(node);
}

void TreeSet::clear()
{
	this->root = TNULL;
}

bool TreeSet::contains(int e)
{
	NodePtr result = searchTreeHelper(this->root, e);
	return result == TNULL ? nullptr : result;
}

void TreeSet::remove(int e)
{
	deleteNodeHelper(this->root, e);
}

void TreeSet::removeAll(TreeSet c)
{
}


int TreeSet::first()
{
	NodePtr currNode = this->root;
	while (1) {
		if (currNode->left == TNULL)
			break;
		currNode = currNode->left;
	}
	return currNode->data;
}

void TreeSet::getChildsHelper(NodePtr node, TreeSet& toCopy, bool const &foundMax)
{
	if (node != TNULL) {
		toCopy.add(node->data);
		getChildsHelper(node->left, toCopy);
		getChildsHelper(node->right, toCopy);
	}
}

TreeSet TreeSet::headSet(int toElem)
{
	TreeSet result;

	NodePtr nodeMax = this->searchTreeHelper(this->root, toElem);
	if (nodeMax != TNULL)
		getChildsHelper(nodeMax->left, result);
	
	return result;
}

int TreeSet::last()
{
	NodePtr currNode = this->root;
	while (1) {
		if (currNode->right == TNULL)
			break;
		currNode = currNode->right;
	}
	return currNode->data;
}

void TreeSet::getSubsetHelper(NodePtr node, TreeSet& toCopy, int const& min, int const& max)
{
	if (node != TNULL) {
		if(node->data < max)
			toCopy.add(node->data);
	
		if (node->data > min)
			getSubsetHelper(node->left, toCopy, min, max);

		if(node->data < max)
			getSubsetHelper(node->right, toCopy, min, max);
	}
}

TreeSet TreeSet::subSet(int fromElem, int toElem)
{
	TreeSet result;

	NodePtr nodeMin = this->searchTreeHelper(this->root, fromElem);
	NodePtr nodeMax = this->searchTreeHelper(this->root, toElem);
	if (nodeMin != TNULL && nodeMax != TNULL) {
		result.add(fromElem);
		getSubsetHelper(this->root, result, fromElem, toElem);
	}
	return result;
}

TreeSet TreeSet::tailSet(int fromElem)
{
	TreeSet result;

	NodePtr nodeMin = this->searchTreeHelper(this->root, fromElem);
	if (nodeMin != TNULL) {
		result.add(fromElem);
		
		getChildsHelper(nodeMin->right, result);
	}
	return result;
}
