#pragma once

#include "container.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

namespace container
{

    template <typename T>
    Container<T>::Container() : m_capacity(1), m_data(new T[m_capacity]), m_size(0) {}

    template <typename T>
    Container<T>::Container(std::vector<T> items)
    {
        m_size = items.size();
        m_capacity = m_size * 2;
        m_data = new T[m_capacity];
        std::move(items, m_data);
    }
    template <typename T>
    Container<T>::Container(T items[])
    {
        m_size = sizeof(items) / sizeof(T);
        m_capacity = m_size * 2;
        m_data = new T[m_capacity];
        std::move(items, m_data);
    }
    template <typename T>
    Container<T>::Container(T item)
    {
        m_size = 1;
        m_capacity = 2 * m_size;
        m_data = new T[m_capacity];
        m_data[0] = std::move(item);
    }
    template <typename T>
    Container<T>::Container(Container &&container)
    {
        m_data = container.m_data;
        m_size = container.m_size;
        container.m_data = nullptr;
        container.m_size = 0;
    }
    template <typename T>
    Container<T>::~Container()
    {
        delete[] m_data;
    }
    template <typename T>
    void Container<T>::push_back(T item)
    {
        try
        {

            if (m_capacity == m_size)
            {
                throw std::out_of_range("Index out of range");
            }
        }
        catch (const std::out_of_range &e)
        {
            m_capacity *= 2;
            T *newData = new T[m_capacity];
            std::cout << "increasing the size" << std::endl;
            std::move(m_data, m_data + m_size, newData);
            delete[] m_data;
            m_data = newData;
        }
        m_data[m_size] = std::move(item);

        m_size++;
    }
    template <typename T>
    void Container<T>::clear()
    {
        delete[] m_data;
        m_capacity = 1;
        m_data = new T[m_capacity];
        m_size = 0;
    }
    template <typename T>
    unsigned int Container<T>::size() const
    {
        return m_size;
    }
    template <typename T>
    T &Container<T>::operator[](unsigned int index)
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }
    template <typename T>
    T *Container<T>::begin()
    {
        return &m_data[0];
    }
    template <typename T>
    T *Container<T>::end()
    {
        return &m_data[m_size];
    }

}