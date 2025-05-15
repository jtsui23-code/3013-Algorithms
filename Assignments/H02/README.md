# (H02) Hashing Homework - Strategies and Collision Resolution

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
  The link list can grow to accommodate for the collision due to there being more values than table slots. 
- Chaining has a worst case of O(n).
- Linear probing has a worst case of O(n).
- Quadratic probing has a worst case of O(n)
- Double Hashing has a worst case of O(n).

### 3. Impact of Hash Table Size:
- Larger table sizes reduce likelihood of collision.
- Smaller talbe size is memory efficient but increases probablity of collision.
- If the hash function produces values that share common factors with the table size, certain slots may never be used.
- Some hash functions use power of 2 so a hash table size that is a power of 2 will result in certain bits in the hash table to be ignored.
- A hash table with a round number will have many factors which leads to poor distribution and cause more collision.
- Prime numbers are the best values for table sizes because they distribute the values more evenly.

## Part B: Simulation and Diagram Exercises:
### Exercise 1: Open Hashing (Separate Chaining)
- Keys: 5,22,17,18,35,101,16,0, 8
- Table size: 10
- Hash Function: h(k) = k mod 10
  
  ![Chaining](https://github.com/user-attachments/assets/bff6e548-2ca3-488f-908a-251870f4a4c4)

### Exercise 2: Closed Hashing (Open Addressing) - Linear Probing:
- Keys: 5,22,17,18,35,101,16,0, 8
- Table size: 10
- Hash Function: h(k) = k mod 10
  
![linear probing](https://github.com/user-attachments/assets/9f5eb126-cb2a-46c3-9a29-1162e0cdd12f)

### Exercise 3: Impact of Poor Table Sizes using chaining:
- Keys: 5, 10, 15, 20, 25, 30, 35, 40
- Table size 10 and Table size of 11
- Hash Function: h(k) = k mod 10 and h(k) = k mod 11
  
![Poor Table Size](https://github.com/user-attachments/assets/2a4bf1d0-9565-4b77-989b-d61d456f5357)







