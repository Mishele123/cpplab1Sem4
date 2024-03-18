#include <iostream>


struct Node
{
	int _data;
	Node* _left;
	Node* _rigth;
public:
	Node() : _data(0), _left(nullptr), _rigth(nullptr) {};
	Node(const int data) : _data(data), _left(nullptr), _rigth(nullptr) {};
	Node*& getLeftTree();
	Node*& getRigthTree();
	int getData() const;
};

class Tree
{
	Node* _root;
	bool insertKey(Node*& root, int key);
	bool containData(Node*& root, int key);
	void copyTree(Node*& newNode, const Node* otherNode);
	void printTree(const Node* root);
	void deleteTree(Node*& root);
	bool deleteKey(Node*& root, int key);

public:
	Tree();
	Tree(const Tree& other);
	~Tree();
	void print();
	Tree& operator=(const Tree& other);
	bool insert(int key);
	bool contains(int key);
	bool erase(int key);
};

Tree::Tree() : _root(nullptr) {}

Tree::Tree(const Tree& other)
{
	_root = nullptr;
	copyTree(_root, other._root);
}

void Tree::copyTree(Node*& newNode, const Node* otherNode)
{
	if (otherNode == nullptr)
	{
		newNode = nullptr;
		return;
	}

	newNode = new Node(otherNode->_data);
	copyTree(newNode->_rigth, otherNode->_rigth);
	copyTree(newNode->_left, otherNode->_left);
}

Tree::~Tree()
{
	deleteTree(_root);
	_root = nullptr;
}


void Tree::deleteTree(Node*& root)
{
	if (root == nullptr) return;

	if (root->_left != nullptr || root->_rigth != nullptr)
	{
		deleteTree(root->_left);
		deleteTree(root->_rigth);
	}
	delete root;
	root = nullptr;
}


Tree& Tree::operator=(const Tree& other)
{
	if (this != &other)
	{
		deleteTree(_root);
		copyTree(_root, other._root);
	}
	return *this;
}

Node*& Node::getLeftTree() { return _left; }
Node*& Node::getRigthTree() { return _rigth; }

int Node::getData() const
{
	return _data;
}

bool Tree::insert(int key)
{
	return insertKey(_root, key);
}

bool Tree::insertKey(Node*& root, int key)
{
	if (root == nullptr)
	{
		root = new Node(key);
		return true;
	}

	if (key <= root->getData())
		return insertKey(root->getLeftTree(), key);
	else if (key > root->getData())
		return insertKey(root->getRigthTree(), key);
	return false; 
}

void Tree::print() 
{
	printTree(_root);
}

void Tree::printTree(const Node* root) 
{
	if (root == nullptr) return;
	std::cout << root->getData() << " ";
	printTree(root->_left);
	printTree(root->_rigth);
}



bool Tree::contains(int key)
{
	return containData(_root, key);
}



bool Tree::containData(Node*& root, int key)
{
	if (root == nullptr) return false;

	if (root->getData() == key) return true;

	if (key < root->getData()) return containData(root->getLeftTree(), key);
	else return containData(root->getRigthTree(), key);
}


bool Tree::erase(int key)
{
	return deleteKey(_root, key);
}

bool Tree::deleteKey(Node*& root, int key)
{
	if (root == nullptr) return false;
	if (key < root->getData())
		return deleteKey(root->getLeftTree(), key);
	else if (key > root->getData())
		return deleteKey(root->getRigthTree(), key);
	else
	{
		if (root->_left != nullptr && root->_rigth != nullptr)
		{
			delete root;
			root = nullptr;
			return true;
		}
		else if (root->_left == nullptr)
		{
			Node* tmp = root;
			root = root->_rigth;
			delete tmp;
			return true;
		}
		else if (root->_right == nullptr)
		{
			Node* tmp = root;
			root = root->_left;
			delete tmp;
			return true;
		}
		else
		{
			Node* tmp = root->_rigth;

			while (tmp->_left != nullptr)
				tmp = tmp->_left;
			root->_data = tmp->getData();
			return deleteKey(root->getRigthTree(), tmp->getData());
		}
	}
}