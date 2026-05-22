# Editorial: Royal Trade Logistics

### Topics involved: 
DYNAMIC PROGRAMMING  
BINARY SEARCH   
CONSTRUCTIVE ALGORITHMS

---

## Method Explanation

We need to find a sequence of choices from three parallel arrays $A, B,$ and $C$ of length $N$ such that the minimum element in our chosen sequence is maximized, while keeping the total transition cost at most $K$. 

We cannot simply choose the maximum element of the three arrays at each index because the total transition cost between the arrays during the process can exceed the maximum allowed transition cost.

### Binary Search
The solution becomes intuitive when we ask ourselves the following question- *"Is it possible to achieve a minimum daily profit of at least $X$ with total transition cost at most $K$?"* 

This is where the first idea involved comes into play- **Binary Search**.
If a minimum profit of $X$ is achievable, any profit $X' < X$ is also achievable by using the exact same path. This monotonic property allows us to use **Binary Search on the Answer** for the optimal value of $X$.

### 2-Dimensional DP
For a fixed target profit threshold $X$, an element at day $i$ is considered valid if and only if its profit is $\ge X$. We can define the validity of each sector on day $i$ as a binary state where a finite value means that the sector is valid on day $i$ and infinite value means that it is not.

Let $DP[i][j]$ define the minimum total transition cost incurred while traversing from day $1$ to day $i$, given that the sector chosen on day $i$ is $j$ (where $j = 0$ for Sector A, $j = 1$ for Sector B, and $j = 2$ for Sector C).

Let $W[k][j]$ denote the transition cost of moving from sector $k$ on day $i-1$ to sector $j$ on day $i$.

#### Base Case (Day 1):
For $j \in \{0, 1, 2\}$:
$$
DP[1][j] = 
\begin{cases} 
0 & \text{if } \text{Profit}(1, j) \ge X \\ 
\infty & \text{otherwise} 
\end{cases}
$$

#### State Transitions (Day $i > 1$):
To compute $DP[i][j]$ for a sector $j \in \{0, 1, 2\}$, we look at the choices made on the previous day $k \in \{0, 1, 2\}$:
$$
DP[i][j] = \min_{0 \le k \le 2} \left( DP[i-1][k] + W[k][j] \right)
$$

If the profit of the sector $j$ on day $i$ is strictly less than $X$, then $DP[i][j] = \infty$ because that state is invalid.

### Feasibility Check & Construction
The threshold $X$ is feasible if:
$$
\min_{0 \le j \le 2} \left( DP[N][j] \right) \le K
$$

Since our feasibility check requires the total transition cost to be lesser than or equal to $K$, we can define infinity as any number greater than $K$ as it will be considered invalid. In our solution, we shall be using $K+1$.

To construct the required array R, we maintain another matrix $Current Parent[i][j]$, which records the optimal value of $k$ that minimized the transition cost for $DP[i][j]$. Whenever we find a value of $X$ which can be obtained as the minimum, we copy the constructed matrix to $AnsParent[i][j]$. Once the maximum feasible $X$ is found by the binary search loop, we backtrack from day $N$ down to day $1$ using the stored values to reconstruct the exact string path ('A', 'B', or 'C').

---

## Complexity Analysis

### Time Complexity
1. **Binary Search:** The profit values lie within the range $[0, \max(A_i, B_i, C_i)]$. Let $V = \max(A_i, B_i, C_i) \le 10^9$. The binary search takes $\mathcal{O}(\log V)$ steps.
2. **DP Check:** For each step of the binary search, we iterate through $N$ days. On each day, we perform a nested evaluation of the $3$ current states against the $3$ previous states, which takes $3 \times 3 = 9$ operations. Thus, the verification function runs in $\mathcal{O}(9N) = \mathcal{O}(N)$ time.
3. **Construction:** In the worst case we would have to construct the $AnsParent$ matrix at each step of the binary search which is done in $\mathcal{O}(N)$ time. The final string construction based on the matrix also takes $\mathcal{O}(N)$ time. 

The total time complexity per testcase is:
$$\mathcal{O}(N \log V)$$
With $\sum N \le 2 \cdot 10^5$, this comfortably runs well within the 2.0-second time limit.

### Space Complexity
The space complexity is dominated by the storage allocation for the three arrays, the transition cost matrix, and our DP state-tracking table. 
The transition cost matrix requires $3 \times 3$ units. The DP table requires $N \times 3$ matrix units, the current parent history tracking uses $N \times 3$ entries and the parent history tracking corresponding to the answer uses another $N \times 3$ entries. The constructed string also has a length $N$.

Thus, the overall space complexity is:
$$\mathcal{O}(N)$$
This easily complies with the 256 megabyte allocation limit.