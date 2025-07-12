# Great Graph Problem

The Great Graph Problem is a combinatorial graph theory challenge that asks you to count the number of valid graphs satisfying specific structural constraints.

---

## Workflow

<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/b641c48f-41a1-43c7-9198-608ff4306439" />

---

## Problem Statement

You are given three integers **N**, **M**, and **L**.

A *great graph* is defined as any graph that satisfies the following conditions:

- It has exactly **N** nodes
- It has exactly **M** edges
- It has a maximum connected component of size **L**
- The degree of every node is at most 2
- There must be no self-loops in the graph

**Task:**  
Find the total number of great graphs possible. Since the answer can be large, return it modulo \(10^9 + 7\).

---

### Input Format

- First line: integer **N** (number of nodes)
- Second line: integer **M** (number of edges)
- Third line: integer **L** (maximum size of connected component)

#### Constraints

- \(2 \leq N \leq 300\)
- \(1 \leq M \leq N\)
- \(1 \leq L \leq N\)

---

### Notes

A connected component in a graph is a maximal set of nodes such that:

- Every pair of nodes in this set is reachable from each other through some path
- No node in this set is connected to any node outside this set
- The size of a connected component is the number of nodes it contains

---

## Problem Analysis

This is a complex graph theory problem that requires understanding several key concepts:

- **Degree Constraint:** Each node can have at most 2 edges, meaning the graph can only contain:
  - Paths (linear chains)
  - Cycles (rings)
  - Isolated nodes

- **Component Structure:** With degree ≤ 2, components can only be:
  - Isolated nodes
  - Paths
  - Cycles

- **Critical Insight:** The maximum connected component size must be *exactly* L, not "at most L".

---

## Solution Approach

The solution uses a brute-force approach with optimizations:

1. Generate all possible edges between N nodes (no self-loops).
2. Try all combinations of M edges from possible edges.
3. Validate each combination by checking:
   - No node exceeds degree 2
   - No self-loops
   - The maximum connected component size is exactly L
4. Count valid configurations.

---

## Complete Solution

### Test Cases

#### Sample Test Cases

| Input (N, M, L) | Output | Explanation |
|-----------------|--------|-------------|
| (3, 2, 3)       | 3      | Three ways to connect 3 nodes with 2 edges forming max component of size 3 |
| (3, 1, 3)       | 0      | Single edge creates max component size 2, not 3 |
| (2, 1, 2)       | 1      | One edge connects both nodes, forming component of size 2 |

#### Additional Test Cases

| Input (N, M, L) | Output | Explanation |
|-----------------|--------|-------------|
| (4, 0, 1)       | 1      | All isolated nodes |
| (4, 1, 2)       | 6      | One edge, others isolated |
| (4, 2, 2)       | 3      | Two disjoint edges |
| (3, 3, 3)       | 1      | Triangle formation |
| (4, 3, 4)       | 4      | Path connecting all nodes |

---

## Key Implementation Details

- **Edge Generation:** Creates all possible edges between nodes (no self-loops)
- **Combination Generation:** Uses backtracking to try all \(C(\text{total\_edges}, M)\) combinations
- **Degree Validation:** Ensures no node exceeds degree 2
- **Component Analysis:** Uses DFS to find connected components and their sizes
- **Exact Matching:** Validates that maximum component size equals exactly L

---

## Time Complexity

- **Worst Case:** \(O(C(N(N-1)/2, M) \times N)\)
- **Space Complexity:** \(O(N^2)\)

The solution is efficient enough for the given constraints (\(N \leq 300\)) due to the degree-2 limitation which significantly reduces the search space.

---

## Common Pitfalls

- **Misunderstanding L:** L is the exact maximum component size, not "at most L"
- **Self-loops:** Remember to avoid self-loops when generating edges
- **Degree constraint:** Must validate that no node has degree > 2
- **Component calculation:** Use proper DFS/BFS to find all connected components

This solution provides a robust approach to solving the great graph counting problem with proper validation and edge case handling.

---
