#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <stdexcept>

namespace container {

    template<typename T>
    class Container {
    public:
        // Constructors
        Container();
        Container(std::vector<T> items);
        Container(T items[]);
        Container(T item);
        Container(Container&& other);

        // Destructor
        ~Container();

        // Member functions
        void push_back(T item);
        T& operator[](unsigned int index);
        T* begin();
        T* end();
        unsigned int size() const;
        void clear();

    private:
        T* m_data;
        unsigned int m_size;
        unsigned int m_capacity;
    };

} // namespace container

#include "container.cpp"

#endif // CONTAINER_H
