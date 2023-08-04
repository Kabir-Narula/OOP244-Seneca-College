///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
// Note: The following code is my own work. However, I have utilized code snippets provided by my professor in completing workshops and assignments.

#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

namespace sdds {
    template <typename T>
    class Collection {
        T* m_data = nullptr; // Dynamic array to store elements of type T
        int m_size = 0; // Size of the collection (number of elements)

    public:
        // Constructor with an optional initial size
        Collection(int size = 0);

        // Copy constructor
        Collection(const Collection<T>& CP);

        // Assignment operator
        Collection<T>& operator=(const Collection<T>& RO);

        // Function to get the size of the collection
        int size() const;

        // Function to resize the collection to a new size
        void resize(int newsize);

        // Index operator to access elements by index
        T& operator[](int index);

        // Function to add an element to the collection
        Collection<T>& add(const T& element);

        // Destructor to deallocate memory
        ~Collection();
    };

    template <typename T>
    Collection<T>::Collection(int size) : m_size(size) {
        // Ensure non-negative size
        if (m_size <= 0)
            m_size = 0;

        // Allocate memory for elements if size is greater than 0
        if (m_size > 0)
            m_data = new T[m_size];
    }

    template <typename T>
    Collection<T>::Collection(const Collection<T>& CP) {
        // Call assignment operator to perform deep copy
        operator=(CP);
    }

    template <typename T>
    Collection<T>& Collection<T>::operator=(const Collection<T>& RO) {
        if (this != &RO) {
            // Delete existing data
            delete[] m_data;

            // Allocate memory for new data and copy elements
            m_data = new T[m_size = RO.m_size];
            for (int i = 0; i < m_size; i++)
                m_data[i] = RO.m_data[i];
        }
        return *this;
    }

    template <typename T>
    int Collection<T>::size() const {
        return m_size;
    }

    template <typename T>
    void Collection<T>::resize(int newsize) {
        int i;
        T* temp = nullptr;
        if (newsize < 0)
            newsize = 0;

        if (newsize > 0) {
            temp = new T[newsize];
            for (i = 0; i < m_size && i < newsize; i++) {
                temp[i] = m_data[i];
            }
        }
        delete[] m_data;
        m_data = temp;
        m_size = newsize;
    }

    template <typename T>
    T& Collection<T>::operator[](int index) {
        // Resize the collection if the index is out of bounds
        if (index >= m_size)
            resize(index + 1);
        return m_data[index];
    }

    template <typename T>
    Collection<T>& Collection<T>::add(const T& element) {
        // Use the index operator to add the element to the collection
        (*this)[size()] = element;
        return *this;
    }

    template <typename T>
    Collection<T>::~Collection() {
        // Deallocate memory when the collection is destroyed
        delete[] m_data;
    }
}

#endif // !SDDS_COLLECTION_H_
