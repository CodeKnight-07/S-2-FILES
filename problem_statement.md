King Aditya and King Suvan jointly coordinate a critical trade route between their kingdoms spanning $N$ consecutive days. On each day $i$ ($1 \le i \le N$), they must select exactly one sector to prioritize for trading. There are three available sectors:
\begin{itemize}
 \item  Sector A: Agriculture
 \item  Sector B: Banking
 \item  Sector C: Commerce
\end{itemize}
Market forecasts indicate that \textbf{on day $i$, prioritizing Sector A yields a profit of $A_i$, Sector B yields $B_i$, and Sector C yields $C_i$}.

Shifting focus from one sector on day $i-1$ to a different sector on day $i$ causes logistic friction. \textbf{A transition penalty is incurred if the chosen sector on day $i$ is different from the chosen sector on day $i-1$}. 

If sector $x$ is chosen on day $i-1$ and sector $y$ is chosen on day $i$, then \textbf{the transition cost is $W(x,y)$}. Due to administrative constraints, the kings can tolerate \textbf{a total transition cost of at most $K$ over the $N$ days}. There is no penalty for the choice made on the first day.

To maintain economic stability, King Aditya and King Suvan want to \textbf{maximize the minimum profit earned on any single day}. Help them determine this maximum guaranteed daily profit and construct an optimal sequence of daily sector choices.

INPUT-

The first line contains a single integer $t$ ($1 \le t \le 10^4$) -- the number of test cases.

The first line of each test case contains two integers $N$ and $K$ ($1 \le N \le 10^5$, $0 \le K \le 10^ {18} $) --- the number of days and the maximum allowed transition cost.

The second line contains $N$ integers $A_1, A_2, \dots, A_N$ ($1 \le A_i \le 10^9$) --- the profits for Sector A.

The third line contains $N$ integers $B_1, B_2, \dots, B_N$ ($1 \le B_i \le 10^9$) --- the profits for Sector B.

The fourth line contains $N$ integers $C_1, C_2, \dots, C_N$ ($1 \le C_i \le 10^9$) --- the profits for Sector C.

The next three lines each contain three integers.

The $y$-th integer on the $x$-th of these lines represents $W(x,y)$ ($0 \le W(x,y) \le 10^9$), the cost of switching from sector $x$ to sector $y$.

Sectors are ordered as:

$
1 = A, 2 = B, 3 = C
$

It is guaranteed that:

$
W(1,1) = W(2,2) = W(3,3) = 0
$


It is guaranteed that the sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.

OUTPUT- 

For each test case, output two lines:


 * The first line should contain a single integer --- the maximum possible value of the minimum profit achieved on a single day.
 * The second line should contain a string of length $N$ consisting of characters 'A', 'B', and 'C', representing the optimal sector choice for each day. If multiple sequences achieve this maximum, output any one of them.

