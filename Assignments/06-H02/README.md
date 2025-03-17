# Hashing Homework - Strategies and Collision Resolution

## Part A - Conceptual Questions:
### 1. Define Hashing and Collision Resolution)
- A Hash table is a data structure which uses the hash function to derive an index in an array where certain values will be stored.
- Open hashing (chaining) is where each slot in a hash table has a pointer that points to a link list. Any elements that share
  the same index are stored in the link list to prevent collision.
- Close hashing (Open Address) finds another available slot to store the element when collision occurs.
