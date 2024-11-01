#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include "Bag.h"
using namespace std;

// Constructor:
//   Best: Theta(1)
//   Worst: Theta(1)
//   Final: O(1) -CONSTANT TIME OPERATION

Bag::Bag() : capacity(10), elementCount(0) {
    elements = new std::pair<TElem, int>[capacity];
}
// Destructor:
//   Best: Theta(1)
//   Worst: Theta(1) 
//   Final: O(1)-CONSTANT TIME OPERATION

Bag::~Bag() {
    delete[] elements;
}
// Resize :
//   Best: Theta(n) - Doubling the capacity and copying elements requires iterating through each element=>linear.
//   Worst: Theta(n) - all elements need to be copied to the resized array, making it linear.
//   Final: O(n)

void Bag::resize() {
    capacity *= 2;
    std::pair<TElem, int>* newElements = new std::pair<TElem, int>[capacity];
    for (int i = 0; i < pairCount; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}
// Find Element:
//   Best: Theta(1) - Finding an element at the beginning of the array is constant time.
//   Worst: Theta(n) - the element might be at the end of the array, requiring linear search.
//   Final: O(n) - The average time complexity for finding an element in an unsorted array is linear.
int Bag::findElement(TElem elem) const {
    for (int i = 0; i < pairCount; i++) {
        if (elements[i].first == elem) {
            return i;
        }
    }
    return -1;
}
// Add:
//   Best: Theta(1) - Adding an element when the bag is not full is a constant-time operation.
//   Worst: Theta(n) - If resizing is required, it takes linear time due to copying elements.
//   Final: O(n)
void Bag::add(TElem elem) {
    int index = findElement(elem);
    if (index != -1) {
        //cout<<"incrementing fequency a index"<<index<<endl;
        elements[index].second++;
    }
    else {
        if (pairCount == capacity) {
            resize();
        }
        elements[pairCount++] = std::make_pair(elem, 1);
    }
    elementCount++;
}
// Remove:
//   Best: Theta(1) - Removing an element when it's the last one of its kind in the bag is a constant-time operation.
//   Worst: Theta(n) - If the element to remove is at the end of the array, shifting elements takes linear time.
//   Final: O(n) 
bool Bag::remove(TElem elem) {
    int index = findElement(elem);
    if (index != -1) {
        elements[index].second--;
        if (elements[index].second == 0) {
            elements[index] = elements[pairCount - 1];
            pairCount--;
        }
        elementCount--;
        return true;

    }
    
    return false;
}

// Search:
//   Best: Theta(1) - If the element is found at the beginning, it's a constant-time operation.
//   Worst: Theta(n) - In the worst case, the element is at the end of the array, requiring linear search.
//   Final: O(n)
bool Bag::search(TElem elem) const {
    return findElement(elem) != -1;
}

// Number of Occurrences::
//   Best: Theta(1) - If the element is found at the beginning, it's a constant-time operation.
//   Worst: Theta(n) - In the worst case, the element is at the end of the array, requiring linear search.
//   Final: O(n) - The average time complexity for counting occurrences involves linear search in an unsorted array.

int Bag::nrOccurrences(TElem elem) const {
    int index = findElement(elem);
    if (index != -1) {
        return elements[index].second;
    }
    return 0;
}

// Size :
//   Best: Theta(1) - Returning the number of elements in the bag takes constant time.
//   Worst: Theta(1)
//   Final: O(1)

int Bag::size() const {
    return elementCount;
}
// Is Empty:
//   Best: Theta(1) - Checking if the bag is empty is a constant-time operation.
//   Worst: Theta(1)
//   Final: O(1)

bool Bag::isEmpty() const {
    return pairCount == 0;
}
// Iterator :
//   Best: Theta(1) - Returning an iterator to the bag's beginning is a constant-time operation.
//   Worst: Theta(1) 
//   Final: O(1) 
BagIterator Bag::iterator() const {
    return BagIterator(*this);
}
