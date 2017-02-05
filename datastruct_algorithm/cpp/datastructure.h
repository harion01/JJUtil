template <class T>
class Node
{
public:
	T data = NULL;
	Node* prev = NULL;
	Node* next = NULL;
};

template <class T>
class Stack
{
private:
	Node<T>* bottom;
	Node<T>* top;
	int size;
public:
	Stack()
	{
		this->bottom = new Node<T>;
		this->top = new Node<T>;

		this->bottom->next = this->top;
		this->top->prev = this->bottom;

		this->size = 0;
	}

	void push(T data)
	{
		Node<T>* temp = new Node<T>;

		temp->next = this->top;
		temp->prev = this->top->prev;
		temp->data = data;

		this->top->prev = temp;
		this->top->prev->next = temp;

		this->size++;
	}

	template <typename T>
	T pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			Node<T>* temp = this->top->prev;
			T ret = temp->data;

			temp->prev->next = this->top;
			this->top->prev = temp->prev;

			delete temp;
			temp = NULL;

			this->size--;

			return ret;
		}
	}

	template <typename T>
	T getTop()
	{
		if (isEmpty())
			return NULL;
		else
			return this->top->prev->data;
	}

	bool isEmpty()
	{
		if (this->size <= 0)
			return true;
		else
			return false;
	}

	int getSize()
	{
		return this->size;
	}

};

template <class T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;
	int size;

public:
	Queue()
	{
		this->front = new Node<T>;
		this->rear = new Node<T>;

		this->front->next = this->rear;
		this->rear->prev = this->front;

		this->size = 0;
	}

	void enqueue(T data)
	{
		Node<T>* temp = new Node<T>;

		temp->prev = this->front;
		temp->next = this->front->next;
		temp->data = data;

		this->front->next->prev = temp;
		this->front->next = temp;

		this->size++;
	}

	template <typename T>
	T dequeue()
	{
		if (isEmpty())
			return NULL;
		else
		{
			Node<T>* temp = this->rear->prev;
			T ret = temp->data;

			temp->prev->next = this->rear;
			this->rear->prev = temp->prev;

			delete temp;
			temp = NULL;

			this->size--;

			return ret;
		}
	}

	bool isEmpty()
	{
		if (this->size <= 0)
			return true;
		else
			return false;
	}

	int getSize()
	{
		return this->size;
	}


};