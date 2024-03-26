#include <iostream>


struct Node
{
	int _data;
	
public:
	Node* _left;
	Node* _right;
	Node() : _data(0), _left(nullptr), _right(nullptr) {};
	Node(const int data) : _data(data), _left(nullptr), _right(nullptr) {};
	Node*& getLeftTree();
	Node*& getRigthTree();
	int getData() const;
};

class Tree
{
	bool insertKey(Node*& root, int key);
	bool containData(Node*& root, int key);
	void copyTree(Node*& newNode, const Node* otherNode);
	void printTree(const Node* root);
	void deleteTree(Node*& root);
	bool deleteKey(Node*& root, int key);

public:
	Node* _root;

	Tree();
	Tree(const Tree& other);
	~Tree();
	void print();
	Tree& operator=(const Tree& other);
	bool insert(int key);
	bool contains(int key);
	bool erase(int key);
	double measureFillTime(size_t num_elements);
	double measureSearchTime(size_t num_elements);
	double measureInsertEraseTime(size_t num_elements);
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
	copyTree(newNode->_right, otherNode->_right);
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

	if (root->_left != nullptr || root->_right != nullptr)
	{
		deleteTree(root->_left);
		deleteTree(root->_right);
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
Node*& Node::getRigthTree() { return _right; }

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
	printTree(root->_left);
	std::cout << root->getData() << " ";
	printTree(root->_right);
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
		if (root->_left == nullptr && root->_right == nullptr)
		{
			delete root;
			root = nullptr;
			return true;
		}
		else if (root->_left == nullptr)
		{
			Node* tmp = root;
			root = root->_right;
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
			Node* tmp = root->_right;

			while (tmp->_left != nullptr)
				tmp = tmp->_left;
			root->_data = tmp->getData();
			return deleteKey(root->getRigthTree(), tmp->getData());
		}
	}
}

size_t lcg()
{
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

double Tree::measureFillTime(size_t num_elements)
{
	double total_time = 0.0;
	for (int attempt = 0; attempt < 100; attempt++)
	{
		clock_t start_time = clock();
		for (size_t i = 0; i < num_elements; i++)
		{
			insert(lcg());
		}
		clock_t end_time = clock();
		total_time += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
		deleteTree(_root);
		_root = nullptr;
	}
	return total_time / 100.0;
}

double Tree::measureSearchTime(size_t num_elements)
{
	for (size_t i = 0; i < num_elements; i++)
	{
		insert(lcg());
	}
	double total_time = 0.0;
	for (int attempt = 0; attempt < 1000; attempt++) 
	{
		int key_to_find = lcg();
		clock_t start_time = clock();
		contains(key_to_find);
		clock_t end_time = clock();
		total_time += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	}
	return total_time / 1000.0;
}

double Tree::measureInsertEraseTime(size_t num_elements) {
	for (size_t i = 0; i < num_elements; ++i) {
		insert(lcg());
	}
	double total_time_add = 0.0;
	double total_time_remove = 0.0;
	for (int attempt = 0; attempt < 1000; ++attempt) {
		int key_to_add = lcg();
		clock_t start_time_add = clock();
		insert(key_to_add);
		clock_t end_time_add = clock();
		total_time_add += static_cast<double>(end_time_add - start_time_add) / CLOCKS_PER_SEC;
		int key_to_remove = lcg();
		clock_t start_time_remove = clock();
		erase(key_to_remove);
		clock_t end_time_remove = clock();
		total_time_remove += static_cast<double>(end_time_remove - start_time_remove) / CLOCKS_PER_SEC;
	}
	double avg_time_add = total_time_add / 1000.0;
	double avg_time_remove = total_time_remove / 1000.0;
	return (avg_time_add + avg_time_remove) / 2.0;
}