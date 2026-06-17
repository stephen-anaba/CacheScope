# Architecture Decision Record
# ADR-002: CacheScope Uses Robin Hood Hashing

Status: Accepted

## Context:
CacheScope requires efficient set membership and lookup operations
for simulation workloads.

## Decision:
Implement a custom HashSet using:
- Open addressing
- Linear probing
- Robin Hood hashing
- Fingerprints
- Tombstones
- Dynamic resizing

## Consequences:
+ O(1) average lookup
+ Improved probe distribution
+ Educational value
+ Demonstrates systems-level design

- More complex insertion logic
- Requires tombstone management
