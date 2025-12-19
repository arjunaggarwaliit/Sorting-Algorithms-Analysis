# Sorting Algorithms Analysis

A comprehensive study and implementation of classical sorting algorithms with **theoretical analysis, empirical benchmarking, and comparative insights**. This repository is designed to bridge the gap between *algorithmic theory* and *practical performance*, making it useful for students, researchers, and competitive programmers.

---

## 📌 Project Overview

Sorting algorithms are fundamental to computer science and appear extensively in **data structures, competitive programming, systems, and real-world applications**. While theoretical time complexity gives asymptotic guarantees, real-world performance often varies due to constants, memory access patterns, and input characteristics.

This project:

* Implements multiple **well-known sorting algorithms**
* Analyzes their **time and space complexities**
* Benchmarks them on different **input sizes and distributions**
* Provides **comparative observations** based on empirical data

The goal is not just to implement sorting algorithms, but to **understand how and why they behave differently in practice**.

---

## 🧠 Algorithms Covered

The repository includes implementations and analysis of the following sorting algorithms:

| Algorithm      | Type       | Stable | In-place | Time Complexity (Best / Avg / Worst) |
| -------------- | ---------- | ------ | -------- | ------------------------------------ |
| Bubble Sort    | Comparison | Yes    | Yes      | O(n) / O(n²) / O(n²)                 |
| Selection Sort | Comparison | No     | Yes      | O(n²) / O(n²) / O(n²)                |
| Insertion Sort | Comparison | Yes    | Yes      | O(n) / O(n²) / O(n²)                 |
| Merge Sort     | Comparison | Yes    | No       | O(n log n) / O(n log n) / O(n log n) |
| Quick Sort     | Comparison | No     | Yes      | O(n log n) / O(n log n) / O(n²)      |

*(Exact set may vary depending on current repository state.)*

---

## ⚙️ Implementation Details

* All algorithms are implemented in **C++** with a focus on:

  * Clean logic
  * Readability
  * Minimal STL usage (to expose algorithm internals)

* Sorting functions are written in a **modular format**, enabling easy reuse in benchmarking code.

* Care is taken to avoid unnecessary overhead during timing to ensure accurate measurement.

---

## 📊 Benchmarking Methodology

To ensure fair comparison:

* **Input Sizes:** Multiple values of `n` (small to large)

* **Input Distributions:**

  * Random
  * Already sorted
  * Reverse sorted
  * Nearly sorted

* **Timing Mechanism:**

  * `std::chrono::high_resolution_clock`
  * Multiple runs averaged to reduce noise

* **Environment:**

  * Same compiler and optimization flags
  * Single-threaded execution

---

## 📈 Key Observations

Some high-level insights obtained from experiments:

* Quadratic algorithms (Bubble, Selection, Insertion) degrade rapidly as `n` increases
* Insertion Sort performs surprisingly well on **nearly sorted inputs**
* Merge Sort provides consistent performance but incurs **extra memory overhead**
* Quick Sort is fastest on average but highly sensitive to **pivot selection**
* Heap Sort has stable performance but worse cache locality compared to Quick Sort

Detailed observations and graphs are available in the `analysis/` and `plots/` directories.

---

## 🎯 Learning Outcomes

By exploring this repository, you will:

* Strengthen intuition behind **asymptotic vs real-world performance**
* Understand trade-offs between **time, space, and stability**
* Learn how to **design fair benchmarks**
* Gain hands-on experience implementing classical algorithms from scratch

---

## 🚀 How to Run

### Compile

```bash
g++ -O2 benchmarking/benchmark.cpp -o benchmark
```

### Execute

```bash
./benchmark
```

Results will be printed to the console and/or saved in the `benchmarking/results/` directory.

---

## 🔮 Possible Extensions

* Add non-comparison sorts (Counting, Radix, Bucket)
* Compare STL `std::sort` with custom implementations
* Visualize sorting demonstrations
* Analyze cache misses and branch prediction

---

## 👤 Author

**Arjun Aggarwal**
