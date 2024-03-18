


struct Node
{
	int _data;
	Node* _left;
	Node* _rigth;
public:
	Node() : _data(0), _left(nullptr), _rigth(nullptr) {};
	Node(const int data) : _data(data), _left(nullptr), _rigth(nullptr) {};
};

class Tree
{
	Node* _root;
public:
	Tree();
	Tree(const Tree& other);
	~Tree();
	void print();
	Tree& operator=(const Tree& other);
	bool insert(int key);
	bool insertKey(Node* root, int key);
	bool contains(int key);
	bool erase(int key);
	void copyTree(Node* newNode, const Node* otherNode);
	void deleteTree(Node* root);
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


void Tree::deleteTree(Node* root)
{
	if (root == nullptr) return;

	if (root->_left != nullptr || root->_rigth != nullptr)
	{
		deleteTree(_root->_left);
		deleteTree(_root->_rigth);
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

bool Tree::insert(int key)
{
	return insertKey(_root, key);
}

bool Tree::insertKey(Node* root, int key)
{
	if (root == nullptr)
	{
		root = new Node(key);
		return true;
	}

	if (key <= root->_data)
		return insertKey(root->_left, key);
	else if (key > root->_data)
		return insertKey(root->_rigth, key);
	return false;
}