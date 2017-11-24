#pragma once

template<typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& newData, Node<T>* newNext = nullptr)
        : data(newData), next(newNext) {}
};

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

    size_t lenght() const;
    bool isEmpty() const;

private:
    Node<T>* topElement;
    size_t size;

    void ReversedCopyElem(const Stack& stackElem);
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
    if(this != other)
    {
        this -> destroy();
        this -> init();
        this -> copy(other);
    }
    return *this;
}

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
        Node<T>* temp = topElement;
        T data = topElement -> data;

        topElement = topElement -> next;
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
        return topElement -> data;
    }
    return nullptr;
}

template<typename T>
void Stack<T>::push(const T& newElem)
{
    Node<T>* addElem = new Node<T>(newElem);

    addElem -> data = newElem;
    addElem -> next = this -> topElement;

    if(addElem)
    {
        this -> topElement = addElem;
        this -> size++;
    }
}

template<typename T>
size_t Stack<T>::lenght() const
{
    return this -> size;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return this -> topElement == nullptr;
}

template<typename T>
void Stack<T>::ReversedCopyElem(const Stack& stackElem)
{
    Node<T>* temp = stackElem -> topElement;

    for(size_t i = 0; i < stackElem.lenght(); i++)
    {
        this -> push(temp -> data);
        temp = temp -> next;
    }
}

template<typename T>
void Stack<T>::copy(const Stack& other)
{
    Stack<T> reversedStack(other);
    reversedStack.ReversedCopyElem(other);
    this -> ReversedCopyElem(reversedStack);
}

template<typename T>
void Stack<T>::init()
{
    this -> topElement = nullptr;
    this -> size = 0;
}

template<typename T>
void Stack<T>::destroy()
{
    // for(size_t i = 0; i <= this -> size; i++)
    while(isEmpty() == false)
    {
        this -> pop();
    }
}

/*
int main()
{
    Stack<char> myStack;

    fstream file("test.txt", ios::out);
    if(file.is_open())
    {
        while(!file.eof())
        {
            file.seekg(0, ios::end);
            file.clear();
            size_t len = file.tellg();
            file.seekg (0, ios::beg);

            size_t MAX_SIZE = len + 1;
            char* chars = new char[MAX_SIZE];
            file.getline(chars, MAX_SIZE);

            char temp;
            temp = file.peek();
            if(temp != ';')
            {
                char read;

                do
                {
                    file.get(read);
                }
                while(read != '\0' && !file.eof());
            }


            for(size_t i = 0; i < MAX_SIZE; i++)
            {
                if(chars[i] != '*')
                {
                    myStack.push(chars[i]);
                }
                else
                    cout << myStack.pop();
            }
        }
        file.close();
    }
    else
        cout << "Can't open file." << endl;
}
*/
