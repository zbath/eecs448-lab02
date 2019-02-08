/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	if(m_front == nullptr)
	{
		return(false);
	}

	while(temp->getNext() != nullptr)
	{
		if(temp->getValue() == value)
		{
			break;
		}
		else
		{
			temp = temp->getNext();
		}
	}

	if(temp->getValue() != value)
	{
		isFound = false;
	}
	else
	{
		isFound = true;
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack() //I created this
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	if(m_size == 0) //0 nodes
	{
		return(false);
	}
	else if(m_size == 1) //1 node
	{
		delete m_front;
		m_front = nullptr;
		isRemoved = true;
	}
	else if(m_size == 2) //2 nodes
	{
		delete m_front->getNext();
		m_front->setNext(nullptr);
		isRemoved = true;
	}
	else //3 nodes
	{
		lastNode = m_front;
		while(lastNode->getNext()->getNext() != nullptr)
		{
			secondintoLast = lastNode;
			lastNode = lastNode->getNext();
		}
		delete lastNode->getNext();
		secondintoLast->getNext()->setNext(nullptr);
		isRemoved = true;
	}
	m_size--;
	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
		bool isRemoved = false;

		if(!isEmpty())
		{
			temp = m_front;
			m_front = temp->getNext();
			delete temp;
			m_size--;
			isRemoved = true;
		}

	return(isRemoved);
}
