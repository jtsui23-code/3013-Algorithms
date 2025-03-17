# Hashing Homework - Strategies and Collision Resolution

## Part A - Conceptual Questions:
### 1. Define Hashing and Collision Resolution)
- A Hash table is a data structure which uses the hash function to derive an index in an array where certain values will be stored.
- Open hashing (chaining) is where each hash table slot has a pointer pointing to a link list. Any elements that share
  the same index are stored in the link list to prevent collision.
- Close hashing (Open Address) finds another available slot to store the element when collision occurs.

### 2. Collision Resolution Techniques:
- Linear probing checks if the next slot is empty and continues until there is an avaible slot for the element.
  Pros: Simple implementation
  Cons: Clustering and performance suffers when the table becomes full.

- Quadratic Probing uses quadratic function to determine next slot.
  Pros: Reduces clustering and better performance compared to linear probing.
  Cons: More complex to implement

- Chaining is a collision resolution that can handle more values than table slots because of the use of link list in each slot.
- Chaining has a worst case of O(n).
- Linear probing has a worst case of O(n).
- Quadratic probing has a worst case of O(n)
- Double Hashing has a worst case of O(n).
