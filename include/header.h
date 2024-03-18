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
public:
	Tree();
	Tree(const Tree& other);
	~Tree();
	void print();
	void printTree(const Node* root, int level);
	Tree& operator=(const Tree& other);
	bool insert(int key);
	bool insertKey(Node*& root, int key);
	bool contains(int key);
	bool erase(int key);
	void copyTree(Node* newNode, const Node* otherNode);
	void deleteTree(Node*& root);
};

Tree::Tree() : _root(nullptr) {}

Tree::Tree(const Tree& other)
{
	_root = nullptr;
	copyTree(_root, other._root);
}

void Tree::copyTree(Node* newNode, const Node* otherNode)
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

