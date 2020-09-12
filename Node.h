/*
#ifndef POLT_NODE_H
#define POLT_NODE_H















template<typename T>
class Node {
private:
	T value;
	Node* left;
	Node* right;
public:
	Node();
	Node(const T);
	~Node();
	void set_left(Node* left_param) {
		left = left_param;
	}
	void set_right(Node* right_param) {
		right = right_param;
	}
	void set_value(T value_param) {
		value = value_param;
	}

	Node* get_left() { return left; }
	Node* get_right() { return right; }
	T get_value() { return value; }
};

template<typename T>
Node<T>::Node()
{
	value = NULL;
	left = nullptr;
	right = nullptr;
}

template<typename T>
Node<T>::Node(const T value_param)
{
	value = value_param;
	left = nullptr;
	right = nullptr;
}


template<typename T>
Node<T>::~Node()
{
	delete left;
	delete right;
}

#endif //POLT_NODE_H
*/
