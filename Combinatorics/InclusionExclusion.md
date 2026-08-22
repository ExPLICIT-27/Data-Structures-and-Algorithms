# Inclusion-Exclusion Principle (IEP)
The Inclusion-Exclusion Principle (IEP) computes the exact size of overlapping sets by alternating between adding and subtracting subset intersections. In competitive programming, bitmasking generates these subsets efficiently, but it is strictly limited to small arrays (N <= 25, approx)

## The Core Concept
If you just add the sizes of all individual sets to find the total unique elements, you double-count the elements that belong to more than one set. IEP corrects this overcounting through an alternating sequence:

*   **Add** the sizes of all individual sets.
*   **Subtract** the sizes of all pairwise intersections (to fix double-counting).
*   **Add** the sizes of all triplet intersections (because Step 2 subtracted them too many times).
*   **Continue** alternating signs for larger subset combinations.

## The Generalized Formula

For $n$ finite sets $A_1, A_2, \dots, A_n$, the Inclusion-Exclusion Principle is:

$$
\left|\bigcup_{i=1}^{n} A_i\right|
=
\sum_{i=1}^{n} |A_i|
-
\sum_{1 \le i < j \le n} |A_i \cap A_j|
+
\sum_{1 \le i < j < k \le n} |A_i \cap A_j \cap A_k|
-
\cdots
+
(-1)^{n-1}
\left|A_1 \cap A_2 \cap \cdots \cap A_n\right|
$$

## Bitmask Algorithm for IEP
To translate this mathematical formula into code, treat the input array of size $N$ as a set. Use the bits of an integer to generate all possible combinations (subsets) of those elements.

*   **The Mask:** A loop runs a variable `mask` from $1$ up to $2^N - 1$. The binary representation of `mask` acts as a blueprint. If the $j$-th bit is $1$, the $j$-th array element is included in the current subset.
*   **Subset Evaluation:** For each `mask`, compute the intersection value of the included elements (e.g., finding their LCM).
*   **Parity Check:** Count the number of set bits. If the count is **odd**, add the subset's value to the global answer. If the count is **even**, subtract it.

