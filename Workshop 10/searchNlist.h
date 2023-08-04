///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
// Note: The following code is my own work. However, I have utilized code snippets provided by my professor in completing workshops and assignments.

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include "Collection.h"

namespace sdds {
    template <typename CollectionType, typename KeyType>
    bool search(Collection<CollectionType>& collection, const CollectionType* array, size_t size, const KeyType& key) {
        bool found = false;
        size_t count = 0; // A counter to track the number of cars added to the collection
        for (size_t i = 0; i < size && count < 7; i++) {
            if (array[i] == key) {
                collection.add(array[i]);
                found = true;
                count++; // Increment the count when a car is added
            }
        }
        return found;
    }


    // Function template to list elements of an array with a given title
    template <typename ElementType>
    void listArrayElements(const char* title, const ElementType* array, size_t size) {
        std::cout << title << std::endl;
        for (size_t i = 0; i < size; ++i) {
            std::cout << i + 1 << ": " << array[i] << std::endl;
        }
    }
}

#endif // SDDS_SEARCHNLIST_H_
