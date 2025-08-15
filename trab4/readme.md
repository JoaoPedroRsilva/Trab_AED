# João Pedro Rocha da Silva - M1

## 148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

## Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

## Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

## Example 3:

Input: head = []
Output: []

## Complexity:
### Time:
The recursion call divides the linked list into two halves until the stopping condition is achieved, after that the elements need to be sorted for the merging of the sublists, so they get compared with each other on each step of the merging. So the time complexity is N * log(N), log(N) for the division of the recursion, and N for the comparison on the merging process.

### Space:
The space complexity is O(log N) for function calls on the stack.

