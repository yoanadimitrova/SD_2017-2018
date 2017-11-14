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


