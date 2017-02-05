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