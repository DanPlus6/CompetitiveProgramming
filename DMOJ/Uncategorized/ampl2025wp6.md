# Problem Description

You are given an integer `maxExponent`.
Compute the number of positive integers that are less than `10^{maxExponent}` that are divisible by 67 that only contain 6's and 7's.

## Constraints

 `1 < maxExponent < 6767676767676767`

## Subtask 1 [1 point]

`maxExponent < 7`

## Subtask 2 [1 point]

 `maxExponent < 6767`

## Subtask 3 [1 point]: No additional constraints

## Input Specification

The first and only line contains a single integer, `maxExponent`.

## Output Specification

Let `numIntegers` be the number of integers that fit the given constraints. Output the remainder when `numIntegers` is divided by 67676767.

## Sample Input 1

2

## Sample Output 1

1

## Sample Explanation 1

The only such integer that is less than `10^2` is 67.

## Sample Input 2

67

## Sample Output 2

43880417

## Sample Explanation 2

We can show that the number of valid integers is 4405192614617206356. The remainder when 4405192614617206356 is divided by 67676767 is 43880417.
