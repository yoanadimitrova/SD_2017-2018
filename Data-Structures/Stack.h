#pragma once

/*
template<typename T>
struct Element
{
    T data;
    Element<T>* nextElem;
    Element(const T& other, Element<T>* _nextElem = nullptr)
    {
        data = other;
        nextElem = _nextElem;
    }
};
*/

template<typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    T pop();
    T top() const;
    void push(const T& newElem);
    size_t len() const;
    bool isEmpty() const;


private:
    template<typename T>
    struct Element
    {
    T data;
    Element<T>* nextElem;
    Element(const T& other, Element<T>* _nextElem = nullptr)
    {
        data = other;
        nextElem = _nextElem;
    }
    };

    
    Element<T>* topElem;
    size_t size;
    void reversedElemCopy(const Stack& stackElem);
    void copy(const Stack& other);
    void init();
    void destroy();
};

template<typename T>
Stack<T>::Stack()
{
    this -> init();
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
    this -> init();
    this -> copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
    if(this != &other)
    {
        this -> destroy();
        this -> init();
        this -> copy(other); 

    }
    return *this;
}

// Destructor
template<typename T>
Stack<T>::~Stack()
{
    this -> destroy();
}

template<typename T>
T Stack<T>::pop()
{
    if(!isEmpty())
    {
        Element<T>* temp = topElem;
        T data = temp -> data;
        topElem = topElem -> nextElem;
        delete temp;
        this -> size--;
        return data;
    }
    else
        return 0;
}

template<typename T>
T Stack<T>::top() const
{
    if(!isEmpty())
    {
        return topElem -> data;
    }
    return nullptr;
}

template<typename T>
void Stack<T>::push(const T& newElem)
{
        Element<T>* addElem = new Element<T>(newElem);
        addElem -> data = newElem;
        addElem -> nextElem = this -> topElem;

        if(addElem)
        {
            this -> topElem = addElem;
            this -> size++;
        }
}

template<typename T>
void Stack<T>::reversedElemCopy(const Stack& stackElem)
{
    Element<T>* temp = stackElem -> topElem;
    for(size_t i = 0; i < stackElem.len(); i++)
    {
        this -> push(temp -> data);
        temp = temp -> next;
    }
}

template<typename T>
void Stack<T>::copy(Stack const& other)
{
    Stack<T> reversedStack;
    reversedStack.reversedElemCopy(other); 
    this -> reversedElemCopy(reversedStack);
}

template<typename T>
size_t Stack<T>::len() const
{
    return this -> size;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return this -> topElem == nullptr;
}

template<typename T>
void Stack<T>::init()
{
    this -> topElem = nullptr;
    this -> size = 0;
}

template<typename T>
void Stack<T>::destroy()
{
   // for(size_t i = 0; i <= this -> size; i++)
    while(isEmpty() == false)
        this -> pop();
}
