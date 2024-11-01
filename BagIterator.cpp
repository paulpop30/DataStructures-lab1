
#include "BagIterator.h"
#include <stdexcept> 


// Constructor
// Best : Theta(1)-initializing the iterator with the given bag and calling the 'first()' method takes constant time
// Worst: Theta(n)-the bag contains 'n' elements, initializing the iterator requires traversing the entire bag once to set up the initial state of the iterator=>the final time complexity for the constructor is  ?(n)
// Final: O(n)

BagIterator::BagIterator(const Bag& c) : bag(c), currentPosition(0), currentFrequency(0) {
    this->first();
}


// Moves the iterator to the first position in the bag
// Best: Theta(1)-The 'first()' method resets the iterator's position to the beginning of the bag. This operation takes constant time regardless of the size of the bag.
// Worst:Theta(1)
// Final Time Complexity: O(1)
// 

void BagIterator::first() {
    currentPosition = 0;
    if (currentPosition < bag.pairCount) {
        currentFrequency = bag.elements[currentPosition].second;
    }
    else {
        currentFrequency = 0;
    }
}

// Moves the iterator to the next position in the bag
// Best : Theta(1)- This operation takes constant time regardless of the size of the bag.
// Worst : Theta(1)
// Final : O(1)

void BagIterator::next() {
    if (!valid()) {
        throw std::exception("Invalid iterator state");
    }
    if (currentFrequency > 1) {
        currentFrequency--;
    }
    else {
        currentPosition++;
        if (currentPosition < bag.pairCount) {
            currentFrequency = bag.elements[currentPosition].second;
        }
        else {
            currentFrequency = 0;
        }
    }
}


// Returns the element at the current position of the iterator
// Best: Theta(1)-This operation takes constant time regardless of the size of the bag.
// Worst: Theta(1)
// Final: O(1)

TElem BagIterator::getCurrent() const {
    if (!valid()) {
        throw std::exception("Invalid iterator state");
    }
    return bag.elements[currentPosition].first;
}

// Checks if the iterator is in a valid state
// Best : Theta(1)
// Worst : Theta(1)
// Final: O(1)

bool BagIterator::valid() const {
    return currentPosition< bag.pairCount;
}
