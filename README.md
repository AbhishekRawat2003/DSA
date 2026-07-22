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
| `374.cpp` | [Guess the number](https://leetcode.com/problems/guess-number-higher-or-lower/) | Binary Search | Easy |

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
|`986.cpp`| [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | Two Pointer | Medium |
|`948.cpp`|[Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/)|Two Pointer + Greedy| Medium|
|`1768.cpp`|[Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/)|Two pointer + String| Easy |
|`3867.cpp`|[Sum of GCD of Formed Pairs](https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/)|Simulation + Math| Medium |

---

### 📦 Prefix (`Prefix/`)
| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
|`1732.cpp`|[Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)|Prefix Sum| Hard |
|`3756.cpp`|[Concatenate Non-Zero Digits and Multiply by Sum II](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/)|Prefix Sum + String + Math| Medium |

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
|`3737.cpp`|[Count Subarrays With Majority Element I](https://leetcode.com/problems/count-subarrays-with-majority-element-i/)| Segment Tree + Merge Sort + Counting + Prefix Sum|Medium|
|`3739.cpp`|[Count Subarrays With Majority Element II](https://leetcode.com/problems/count-subarrays-with-majority-element-ii/)| Segment Tree + Merge Sort + Counting + Prefix Sum|Hard|
|`3020.cpp`|[. Find the Maximum Number of Elements in Subset](https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/)|Array+ Hash Table + Enumeration| Medium |
|`1431.cpp`|[Kids with greatest Number of candies](https://leetcode.com/problems/kids-with-greatest-number-of-candies/)|Array|Easy|
|`1331.cpp`|[Rank transform of an array](https://leetcode.com/problems/rank-transform-of-an-array/)|Array + Hash table| Easy |
|`3312.cpp`|[ Sorted GCD Pair Queries](https://leetcode.com/problems/sorted-gcd-pair-queries/)|
Hash Table + Binary Search + Combinatorics + Counting + Number Theory + Prefix Sum| Hard |

---

### 📦 Linked List (`Linked-List/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
|`2095.cpp`|[Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/)|Two Pointer + lazy and fast Pointer| Medium |

---

### 🔤 Strings (`Strings/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `1910.cpp` | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/) | String find + erase | Medium |
| `StringPalindrome.cpp` | Check String Palindrome | Two pointers | Easy |
| `3612.cpp` | [Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/) | String + simulation | Medium |
| `3614.cpp` | [Process String with Special Operations II](https://leetcode.com/problems/process-string-with-special-operations-ii/) | String + simulation | Hard |
|`1189.cpp`|[Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/)|Hash Table + counting| Easy |
|`1071.cpp`|[greatest common divisor of strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)|string|Easy|
|`1967.cpp`|[Number of strings that appear as substrings in word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)|  string | Easy |
|`151.cpp`|[Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)|Two Pointer| Medium |
|`1081.cpp`|[Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)|Stack + Greedy + Monotonic Stack| Medium |
|`3499.cpp`|[Maximize Active Section with Trade I](https://leetcode.com/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21)| Enumeration | Medium |
|`3501.cpp`|[Maximize Active Section with Trade II](https://leetcode.com/problems/maximize-active-section-with-trade-ii/)|Segmented tree + Binary Search + prefix Sum| Hard |

---

### Maths {Formula based} (`Math/`)
| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `371.cpp`| [Sum of Two Integer](https://leetcode.com/problems/sum-of-two-integers/) | Bit Manupilation | Medium |
|`1840.cpp`| [Maximum Building Height](https://leetcode.com/problems/maximum-building-height/)|Array + sorting|Hard|
|`1291.cpp`|[Sequential Digits](https://leetcode.com/problems/sequential-digits/)| Enumeration | Medium |
|`3658.cpp`|[GCD of Odd and Even Sums](https://leetcode.com/problems/gcd-of-odd-and-even-sums/)|Math|Easy|
---

### Greedy (`Greedy/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `1833.cpp`| [Maximum ice cream bars](https://leetcode.com/problems/maximum-ice-cream-bars/) | Greedy | Medium |
|`605.cpp`|[Can place flowers](https://leetcode.com/problems/can-place-flowers/)|Greedy + Array| Easy|


---

### 🏔️ Heap & Sorting (`heap/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
| `1046.cpp` | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) | Max Heap | Easy |
| `Median.cpp` | Median of Array | Sort + middle index | Easy |
| `QuickSelect.cpp` | Kth Smallest (QuickSelect) | Lomuto partition | Medium |

---

### Recursion (`Recursion/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
|`factorial.cpp`|[]()|Recursin-> memoization||
|`power.cpp`|[]()|Recursin-> memoization| Easy |
|`reverseString.cpp`|[]()|Recursin-> memoization| Easy |
|`sum.cpp`|[]()|Recursin-> memoization| Easy |
<!-- |``|[]()|Recursin-> memoization| Easy | -->

---

### ⚡ Dynamic Programmming (`Dynamic Programming/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
|`Fibonnnacci.cpp`|Fibonnacci Series| DP + Recursion 🔄 + Memoization| Easy|
|`Fibonnnacci_1.cpp`|Fibonnacci Series| DP + Memoization -> Tabulation | Easy|
|`70.cpp`|[Climb Stairs](https:/leetcode.com/problems/climb-stairs/)|DP + Memoization -> Tabulation|Easy|
|`403.cpp`|[Frog jump](https://leetcode.com/problems/frog-jump/)|Recursion -> DP + Memoization -> Tabulation|Hard|
|`frog-jump`|[Frog Jump with height](https://www.naukri.com/code360/problems/frog-jump_3621012)|Recursion -> DP + Memoization -> Tabulation | Medium |
|`uniquePath.cpp`|[Unique Path](https://www.naukri.com/code360/problems/unique-paths_1081470)|Recursion -> Memoization -> Tabulation |
|`198.cpp`|[House Robber](https://www.leetcode.com/problems/house-robbers/)|DP| Medium |
|`3336.cpp`|[Find the Number of Subsequences With Equal GCD](https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/)| DP + GCD + Array | Hard |
|`42.cpp`|[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)|Array
Two Pointers + Stack + Monotonic Stack| Hard |
---
### ⚡ Graph (`Graph/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
|`3532.cpp`|[Path Existence Queries in a Graph I ](https://leetcode.com/problems/path-existence-queries-in-a-graph-i/)|Array+ Prefix Sum| Medium |
|`3534.cpp`|[Path Existence Queries in a Graph II](https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/)|Array + Prefix Sum| Hard |
|`2685.cpp`|[Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/)| DFS | Medium |


### Matrix (`Matrix/`)

| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
|`1260.cpp`|[Shift 2D grid](https://leetcode.com/problems/shift-2d-grid/)|Array + Simulation |Easy|

### Tree (`Tree/`)
| File | Problem | Approach | Difficulty |
|------|---------|----------|------------|
|`3501.cpp`|[Maximize Active Section with Trade II](https://leetcode.com/problems/maximize-active-section-with-trade-ii/)|Segmented tree + Binary Search + prefix Sum| Hard |


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
- [x] Dynamic Programming 
- [x] Graphs
- [ ] Trees *(coming soon)*

---

## 👤 Author

**Abhishek Rawat** — Backend Developer | Python & Django | C++ DSA  
📧 abhirawathdr@gmail.com  
🔗 [LinkedIn](https://linkedin.com/in/Abhishekrawat2003)

> *"Consistency beats intensity when building skills."*
