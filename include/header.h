


struct Node
{
	int _data;
	Node* _left;
	Node* _rigth;
public:
	Node() : _data(0), _left(nullptr), _rigth(nullptr) {};
	Node(const int data) : _data(data), _left(nullptr), _rigth(nullptr) {};
	int get_key() const;
	Node** get_left_tree() const;
	Node** get_rigth_tree() const;
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
	bool contains(int key);
	bool erase(int key);
	void copyTree(Node* newNode, const Node* otherNode);
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