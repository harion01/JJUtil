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