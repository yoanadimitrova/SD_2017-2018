#pragma once

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


template<typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    T pop(); // Returns the data at the beginning
    T top() const;
    void push(const T& newElem);
    size_t len() const;
    bool isEmpty() const;


private:
    Element<T>* topElem; // Pointer to the top element of the stack
    size_t size;
    void reversedElemCopy(const Stack& stackElem); // Copies the stack but the elements in it are reversed
    void copy(const Stack& other);
    void init();
    void destroy();
};

// Creates an empty stack
template<typename T>
Stack<T>::Stack()
{
    this -> init();
}

// Copy constructor
template<typename T>
Stack<T>::Stack(const Stack& other)
{
    this -> init();
    this -> copy(other);
}

// Operator =
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
    if(this != &other)
    {
        this -> destroy(); // First we free the currently allocated memory
        this -> init();
        this -> copy(other); // Then we copy

    }
    return *this;
}

// Destructor
template<typename T>
Stack<T>::~Stack()
{
    this -> destroy();
}

// Removes and returns the element on top of the stack
template<typename T>
T Stack<T>::pop()
{
    if(!isEmpty())
    {
        Element<T>* temp = topElem; // We keep the value of topElem in temp
        T data = temp -> data;
        topElem = topElem -> nextElem; // Points the next element; If the stack is empty there will be an error if we haven't check if the stack is !isEmpty
        delete temp; // Delete the previous element so we prevent from memory leak
        this -> size--;
        return data; // We return the new value
    }
    else
        return 0; // If the stack is empty
}

// Accesses the next element and returns a reference to the top element (the last element inserted) in the stack
template<typename T>
T Stack<T>::top() const
{
    if(!isEmpty())
    {
        return topElem -> data;
    }
    return nullptr;
}

// Adds an element on the top if the stack
template<typename T>
void Stack<T>::push(const T& newElem) // newElement is the value to which the inserted element is initialized
{
    // One line solution:
    // topElem = new Element(newElem, topElem);

    Element<T>* addElem; // Pointer to Element
    addElem -> data = newElem;
    addElem -> nextElem = this -> topElem;

    if(addElem)
    {
        this -> topElem = addElem;
        this -> size++;
    }
}

// Returns the number of elements currently stored in the stack
template<typename T>
size_t Stack<T>::len() const
{
    return this -> size;
}

// Checks if the stack is empty
template<typename T>
bool Stack<T>::isEmpty() const
{
    return this -> topElem == nullptr;
}

// Copies the stack but the elements in it are reversed
template<typename T>
void Stack<T>::reversedElemCopy(const Stack& stackElem)
{
    Element<T>* temp = stackElem -> topElem; // temp point at the first element
    for(size_t i = 0; i < stackElem.len(); i++)
    {
        this -> push(temp -> data);
        temp = temp -> next;
    }
}

// Makes the current object a copy of another one
template<typename T>
void Stack<T>::copy(Stack const& other)
{
    Stack<T> reversedStack; // Empty stack to save the Stack' elements in the right order
    reversedStack.reversedElemCopy(other); // We save the 'wrong' reversed elements from other to reversedStack
    this -> reversedElemCopy(reversedStack); // This is the stack with the right order of elements
}

// Assigning initial values for the data-members of the object
// The values are proper for an empty stack
template<typename T>
void Stack<T>::init()
{
    this -> topElem = nullptr;
    this -> size = 0;
}

// Empties the stack and frees the allocated memory
template<typename T>
void Stack<T>::destroy()
{
    for(size_t i = 0; i <= this -> counter; i++)
        this -> pop();
}
