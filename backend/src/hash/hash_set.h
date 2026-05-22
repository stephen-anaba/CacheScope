// hash_set.h
#ifndef HASHSET_H
#define HASHSET_H

#include <vector>
#include <cstdint>
#include "Entry.h"

/*
 * HashSet using Robin Hood hashing (open addressing).
 *
 * Key Features:
 * - Uniform probe distribution (Robin Hood strategy)
 * - 64-bit hashing with 7-bit fingerprint optimization
 * - Dynamic resizing (rehashing)
 * - Tombstone-based deletion
 */
class HashSet {
private: 
    std::vector<Entry> table_; // underlying storage
    size_t size_;              // total capacity
    size_t used_;              // number of valid elements
    size_t tombstones_;        // number of deleted slots
    // Evaluate MAX_LOAD at compile time. constexpr = constant expression
    static constexpr float MAX_LOAD = 0.7f;

    // Hash utilities
    uint64_t Hash(int key) const;
    uint8_t Fingerprint(uint64_t hash) const;

    // Internal helpers
    void Rehash(size_t new_size);
    size_t ProbeIndex(size_t home, size_t i) const;

public:
    // Non-default constructor
    explicit HashSet(size_t size = 10); // no implicit conversions
    
    // Member functions
    bool Add(int key); // adds a new element
    bool Remove(int key); // removes an existing element
    bool Contains(int key) const; // checks for existence

    void Clear(); // clears the entire element set
    void Display() const; // displays all elements
};

#endif
