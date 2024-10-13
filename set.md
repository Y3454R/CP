
# C++ STL: Set Cheat Sheet

## What is `std::set`?

A `std::set` is an associative container in C++ that stores unique elements in a sorted order. Sets automatically arrange the elements and do not allow duplicates.

---

## Basic Operations

### 1. Declaration and Initialization:
```cpp
#include <set>

std::set<int> mySet;               // Empty set
std::set<int> mySet = {1, 2, 3};   // Initialized set
```

### 2. Insert Elements:
```cpp
mySet.insert(4);  // Inserts 4 into the set
mySet.insert(2);  // Since 2 is already in the set, it won't be added again
```

### 3. Check Size:
```cpp
std::cout << mySet.size();  // Returns the number of elements in the set
```

### 4. Erase Elements:
```cpp
mySet.erase(2);  // Removes the element 2 from the set
mySet.clear();   // Removes all elements from the set
```

### 5. Check if Element Exists:
```cpp
if (mySet.find(3) != mySet.end()) {
    // Element 3 is in the set
}

if (mySet.count(3) > 0) {
    // Element 3 is in the set
}
```

---

## Iterating over a `std::set`

### 1. Using an Iterator:
```cpp
for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
    std::cout << *it << " ";
}
```

### 2. Using a Range-Based For Loop (C++11 and later):
```cpp
for (const int &element : mySet) {
    std::cout << element << " ";
}
```

### 3. Using Constant Iterator:
```cpp
for (std::set<int>::const_iterator it = mySet.cbegin(); it != mySet.cend(); ++it) {
    std::cout << *it << " ";
}
```

---

## Common Methods

- `insert()`: Adds an element to the set.
  ```cpp
  mySet.insert(10);
  ```
  
- `erase()`: Removes a specific element or elements in a range.
  ```cpp
  mySet.erase(5);  // Remove element 5
  mySet.erase(mySet.begin(), mySet.end());  // Remove all elements
  ```
  
- `find()`: Returns an iterator to the element or `end()` if the element is not found.
  ```cpp
  auto it = mySet.find(3);  // Find element 3
  ```
  
- `count()`: Returns the number of elements with a given value (either 0 or 1).
  ```cpp
  if (mySet.count(2)) {
      // Element exists
  }
  ```

- `size()`: Returns the number of elements in the set.
  ```cpp
  std::cout << mySet.size();
  ```

- `clear()`: Removes all elements from the set.
  ```cpp
  mySet.clear();
  ```

- `empty()`: Checks if the set is empty.
  ```cpp
  if (mySet.empty()) {
      // The set is empty
  }
  ```

- `begin()` and `end()`: Return iterators to the beginning and the end of the set.
  ```cpp
  auto it = mySet.begin();   // Iterator to the first element
  auto itEnd = mySet.end();  // Iterator to one-past-the-last element
  ```

---

## Notes
- `std::set` is usually implemented as a balanced binary search tree, which provides logarithmic time complexity for insertions, deletions, and lookups.
- Elements in a `std::set` are automatically sorted in ascending order.
- The elements in a `std::set` are immutable, i.e., you cannot change the value of an element after it is added.

---

## Example Code:
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1, 2, 3, 4, 5};

    // Insert an element
    mySet.insert(6);

    // Iterate over the set
    for (const int &element : mySet) {
        std::cout << element << " ";
    }

    // Check if an element exists
    if (mySet.count(3)) {
        std::cout << "\nElement 3 exists";
    }

    return 0;
}
```

```
Output:
1 2 3 4 5 6 
Element 3 exists
```
