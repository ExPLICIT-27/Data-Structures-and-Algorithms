# Rules for Partition DP
### Always start with the entire portion
    - if the matrices are A, B, C and D
    then start with ABCD
                ABCD
    (A)(BCD)  (AB)(CD)   (ABC)(D)
    i j i  j  i j i  j   i  j i j 
    each breaking point will have a starting point and an ending point

### Run a loop to try all partitions

### Return the best partition