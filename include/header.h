


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
	bool contains(int key);
	bool erase(int key);
};