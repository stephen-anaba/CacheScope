// hash_set.cpp
#include "HashSet.h"
#include <iostream>
#include <functional>


// Constructor initializes table with given size.
HashSet::HashSet(size_t size)
    : size_(size), used_(0), tombstones_(0) {
    table_.resize(size_);
}

// Computes 64-bit hash using std::hash.
uint64_t HashSet::Hash(int key) const {
    return std::hash<int>{}(key);
}


// Extracts a 7-bit fingerprint from the hash  
// Purpose: 
// Fast pre-check before full key comparison
// - Reduces expensive equality checks
uint8_t HashSet::Fingerprint(uint64_t hash) const {
    return (hash >> 57) & 0x7F;
}

// Computes probing index using linear probing.
size_t HashSet::ProbeIndex(size_t home, size_t i) const {
    return (home + i) % size_;
}

// Rehashes all elements into a new table.
// Triggered when load factor exceeds threshold.
void HashSet::Rehash(size_t new_size) {
    std::vector<Entry> old_table = table_;

    table_.clear();
    table_.resize(new_size);

    size_ = new_size;
    used_ = 0;
    tombstones_ = 0;

    // Reinsert valid entries
    for (const auto& entry : old_table) {
        if (entry.state == State::OCCUPIED) {
            Add(entry.key);
        }
    }
}

// Inserts a key using Robin Hood hashing.
bool HashSet::Add(int key) {
    // Resize if load factor too high
    if ((float)used_ / size_ > MAX_LOAD) {
        Rehash(size_ * 2);
    }

    uint64_t hash = Hash(key);
    uint8_t fp = Fingerprint(hash);
    size_t home = hash % size_;

    // Incoming entry
    Entry incoming;
    incoming.key = key;
    incoming.fingerprint = fp;
    incoming.probe_count = 0;
    incoming.state = State::OCCUPIED;

    // Probe sequence
    for (size_t i = 0; i < size_; i++) {
        size_t idx = ProbeIndex(home, i);
        Entry& current = table_[idx];

        // Case 1: Empty or deleted slot → insert
        if (current.state == State::EMPTY || current.state == State::DELETED) {
            table_[idx] = incoming;
            used_++;
            return true;
        }

        // Case 2: Key already exists
        if (current.fingerprint == fp && current.key == key) {
            return false;
        }

        // Case 3: Robin Hood swap
        // If incoming has traveled farther, steal position
        if (current.probe_count < incoming.probe_count) {
            std::swap(current, incoming);
        }

        // Continue probing
        incoming.probe_count++;
    }

    return false;
}

// Checks if a key exists in the set.
bool HashSet::Contains(int key) const {
    uint64_t hash = Hash(key);
    uint8_t fp = Fingerprint(hash);
    size_t home = hash % size_;

    for (size_t i = 0; i < size_; i++) {
        size_t idx = ProbeIndex(home, i);
        const Entry& entry = table_[idx];

        // Stop early if empty slot encountered
        if (entry.state == State::EMPTY) return false;

        if (entry.fingerprint == fp && entry.key == key) {
            return true;
        }
    }

    return false;
}

// Removes a key by marking it as DELETED (tombstone).
bool HashSet::Remove(int key) {
    uint64_t hash = Hash(key);
    uint8_t fp = Fingerprint(hash);
    size_t home = hash % size_;

    for (size_t i = 0; i < size_; i++) {
        size_t idx = ProbeIndex(home, i);
        Entry& entry = table_[idx];

        if (entry.state == State::EMPTY) return false;

        if (entry.fingerprint == fp && entry.key == key) {
            entry.state = State::DELETED;
            used_--;
            tombstones_++;
            return true;
        }
    }

    return false;
}

// Clears the entire hash table.
void HashSet::Clear() {
    table_.assign(size_, Entry{});
    used_ = 0;
    tombstones_ = 0;
}

// Displays table contents for debugging/visualization.
void HashSet::Display() const {
    std::cout << "Table: ";
    for (const auto& entry : table_) {
        if (entry.state == State::EMPTY) {
            std::cout << "e ";
        } else if (entry.state == State::DELETED) {
            std::cout << "d ";
        } else {
            std::cout << entry.key << "(" << entry.probe_count << ") ";
        }
    }
    std::cout << "\nSize: " << size_
              << " | Used: " << used_
              << " | Load Factor: " << (float)used_ / size_
              << "\n";
}
