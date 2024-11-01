#ifndef BAGITERATOR_H
#define BAGITERATOR_H

#include "Bag.h"

class BagIterator {
	// DO NOT CHANGE THIS PART
	friend class Bag;

private:
	const Bag& bag;
	int currentPosition; // index of the current position in the bag
	int currentFrequency; // frequency of the current element

	// Constructor
	BagIterator(const Bag& c);

public:
	// Moves the iterator to the first position in the bag
	void first();

	// Moves the iterator to the next position in the bag
	void next();

	// Returns the element at the current position of the iterator
	TElem getCurrent() const;

	// Checks if the iterator is in a valid state
	bool valid() const;
};

#endif
