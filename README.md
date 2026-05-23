# CacheScope

CacheScope is a modular cache simulation and visualization platform built with C++ and TypeScript for exploring CPU cache behavior, memory-access patterns, and replacement-policy performance.

The project combines systems programming, data-structure engineering, and interactive visualization to make cache architecture easier to understand and analyze.

---

# Features

## Core Cache Simulation
- Configurable cache size
- Configurable associativity
- Configurable block size
- Configurable replacement policies
- Real-time memory-access simulation

## Address Mapping
- Hexadecimal memory-address input
- Tag/index/offset decomposition
- Binary address visualization

## Cache Resolution
- Cache hit detection
- Cache miss detection
- Set-associative lookup simulation
- Cache-line replacement handling

## Replacement Policies
- LRU (Least Recently Used)
- FIFO (First-In First-Out)
- Extensible replacement-policy architecture

## Visualization
- Interactive cache-grid rendering
- Hit/miss highlighting
- Eviction visualization
- Simulation event logging

## Analytics
- Real-time hit-rate metrics
- Real-time miss-rate metrics
- Simulation performance statistics

---

# Architecture

CacheScope follows a layered modular-monolith architecture with strong subsystem separation.

```text
Frontend (Presentation Layer)
        ↓
Backend API Layer
        ↓
Simulation/Application Layer
        ↓
Cache Domain Layer
        ↓
Infrastructure/Data Structure Layer
```

The architecture emphasizes:
- high cohesion
- low coupling
- modularity
- extensibility
- systems-oriented design

---

# Tech Stack

## Backend
- C++
- CMake
- Custom HashSet implementation
- REST API architecture

## Frontend
- TypeScript
- Vite
- Web Components
- CSS

---

# Project Structure

```text
cache-scope/
│
├── frontend/
│   ├── src/
│   │   ├── components/
│   │   ├── services/
│   │   ├── styles/
│   │   ├── types/
│   │   └── utils/
│
├── backend/
│   ├── src/
│   │   ├── api/
│   │   ├── cache/
│   │   ├── hash/
│   │   ├── simulation/
│   │   ├── visualization/
│   │   └── utils/
│
├── docs/
│
└── README.md
```

---

# Systems Engineering Concepts

CacheScope demonstrates several systems and software-engineering concepts:

- cache architecture simulation
- address translation
- set-associative caches
- replacement policies
- modular layered architecture
- reusable data structures
- performance-oriented design
- Agile incremental development
- GRASP principles
- domain-oriented decomposition

---

# Custom HashSet

CacheScope includes a reusable custom HashSet implementation designed to support fast cache-tag lookup operations.

This enables:
- scalable cache-set access
- reduced lookup overhead
- cleaner simulation-domain separation
- reusable infrastructure components

---

# Example Simulation Flow

```text
User Input
    ↓
Address Translation
    ↓
Cache Set Lookup
    ↓
Hit/Miss Resolution
    ↓
Replacement Policy
    ↓
Visualization Update
    ↓
Metrics Update
```

---

# Getting Started

## Backend

```bash
cd backend

mkdir build
cd build

cmake ..
make

./cache_scope
```

## Frontend

```bash
cd frontend

npm install
npm run dev
```

---

# Roadmap

## Current
- Core cache simulation
- Address mapping
- LRU/FIFO support
- Visualization system
- Metrics engine

## Planned
- LFU and Random replacement policies
- Multi-level cache simulation
- Benchmark trace imports
- Performance profiling
- Advanced analytics
- Exportable simulation reports

---

# Why This Project?

CacheScope was designed to bridge low-level systems concepts with interactive visualization.

The goal is to create a platform that demonstrates:
- practical systems programming
- scalable software architecture
- data-structure engineering
- frontend/backend integration
- performance-focused application design

---

# License

MIT License
