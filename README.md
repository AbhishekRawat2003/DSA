# DSA Practice — Abhishek Rawat

A structured collection of Data Structures & Algorithms solutions in **C++**, organized by topic. Problems are primarily from LeetCode and GFG.

![Problems Solved](https://img.shields.io/badge/Problems%20Solved-31-blue?style=flat-square)
![Topics](https://img.shields.io/badge/Topics-7-green?style=flat-square)
![Language](https://img.shields.io/badge/Language-C%2B%2B17-orange?style=flat-square)

---

## 📁 Repository Structure

```
dsa/
├── sliding-window/     # Fixed & variable window problems
├── binary-search/      # Classic BS + BS on answer problems
├── two-pointers/       # Two pointer technique
├── arrays/             # Array manipulation, hashing, sorting
├── Strings/            # String problems
└── heap/               # Priority queue & QuickSelect
```

---

## 📊 Problems Solved

### 🪟 Sliding Window (`sliding-window/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `3.cpp` | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Variable window + HashSet | Medium |
| `76.cpp` | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | Variable window + 2 HashMaps | Hard |
| `239.cpp` | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | Monotonic Deque | Hard |
| `643.cpp` | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) | Fixed window | Easy |
| `904.cpp` | [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/) | Variable window + HashMap | Medium |
| `1343.cpp` | [Number of Sub-arrays of Size K and Average ≥ Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/) | Fixed window | Medium |
| `1358.cpp` | [Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) | Variable window | Medium |
| `1456.cpp` | [Max Vowels in Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | Fixed window | Medium |

---

### 🔍 Binary Search (`binary-search/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `33.cpp` | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | Modified binary search | Medium |
| `540.cpp` | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/) | Binary search on parity | Medium |
| `852.cpp` | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/) | Binary search | Medium |
| `410.cpp` | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | Binary search on answer | Hard |
| `AggressiveCow.cpp` | [Aggressive Cows (GFG)](https://www.geeksforgeeks.org/aggressive-cows-problem/) | Binary search on answer | Hard |
| `allocateMinimum.cpp` | [Allocate Minimum Pages (GFG)](https://www.geeksforgeeks.org/allocate-minimum-number-pages/) | Binary search on answer | Hard |
| `painterPartition.cpp` | [Painter's Partition Problem (GFG)](https://www.geeksforgeeks.org/painters-partition-problem/) | Binary search on answer | Hard |
| `binaryExponential.cpp` | Binary Exponentiation (Fast Power) | Recursive divide & conquer | Medium |

---

### 👉 Two Pointers (`two-pointers/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `15.cpp` | [3 Sum](https://leetcode.com/problems/3sum/) | Sorting + Two Pointers | Medium |
| `18.cpp` | [4 Sum](https://leetcode.com/problems/4sum/) | Two Pointers | Medium |
| `88.cpp` | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | Two pointers from back | Easy |
| `167.cpp` | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Two pointers | Medium |
| `189.cpp` | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | Two Pointers | Easy |
| `283.cpp` | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | Two Pointers | Easy |
| `881.cpp` | [Boats to Save People](https://leetcode.com/problems/boats-to-save-people/) | Two Pointers + Greedy | Medium |
| `waterContainer.cpp` | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Two pointers | Medium |
| `pairSum.cpp` | Pair Sum in Sorted Array | Two pointers | Easy |
| `buy_Sell.cpp` | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Track min price | Easy |
| `nextPermutation.cpp` | [Next Permutation](https://leetcode.com/problems/next-permutation/) | Find pivot + reverse | Medium |
| `allPermutation.cpp` | All Permutations | Backtracking | Medium |

---

### 📦 Arrays (`arrays/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `215.cpp` | [Kth Largest Element](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Max Heap | Medium |
| `238.cpp` | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Prefix × Suffix | Medium |
| `347.cpp` | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | HashMap + Heap | Medium |
| `36.cpp` | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | HashSet per row/col/box | Medium |
| `973.cpp` | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | Max Heap of size k | Medium |
| `majorityElement.cpp` | [Majority Element](https://leetcode.com/problems/majority-element/) | Boyer-Moore Voting | Easy |
| `findDisappearedNumber.cpp` | [Find Disappeared Numbers](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | Index marking | Easy |
| `longestConsecutiveNumber.cpp` | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | HashSet | Medium |
| `sortArray.cpp` | [Sort Colors](https://leetcode.com/problems/sort-colors/) | Dutch National Flag | Medium |

---

### 🔤 Strings (`Strings/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `1910.cpp` | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/) | String find + erase | Medium |
| `StringPalindrome.cpp` | Check String Palindrome | Two pointers | Easy |
| `3612.cpp` | [Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/) | String + simulation | Medium |
| `3614.cpp` | [Process String with Special Operations II](https://leetcode.com/problems/process-string-with-special-operations-ii/) | String + simulation | Hard |

---

### 🏔️ Heap & Sorting (`heap/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `1046.cpp` | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) | Max Heap | Easy |
| `Median.cpp` | Median of Array | Sort + middle index | Easy |
| `QuickSelect.cpp` | Kth Smallest (QuickSelect) | Lomuto partition | Medium |

---

## 🛠️ How to Run

```bash
# Compile any file
g++ -std=c++17 -o out sliding-window/76.cpp && ./out

# Or with optimization flag
g++ -O2 -std=c++17 -o out binary-search/410.cpp && ./out
```

---

## 📈 Topics Covered

- [x] Sliding Window (Fixed & Variable)
- [x] Binary Search (Classic + BS on Answer)
- [x] Two Pointers
- [x] Hashing (HashMap / HashSet)
- [x] Heap / Priority Queue
- [x] Sorting (Dutch National Flag, Merge Sort concepts)
- [x] Backtracking (Permutations)
- [x] Greedy
- [ ] Dynamic Programming *(coming soon)*
- [ ] Graphs *(coming soon)*
- [ ] Trees *(coming soon)*

---

## 👤 Author

**Abhishek Rawat** — Backend Developer | Python & Django | C++ DSA  
📧 abhirawathdr@gmail.com  
🔗 [LinkedIn](https://linkedin.com/in/Abhishekrawat2003)

> *"Consistency beats intensity when building skills."*