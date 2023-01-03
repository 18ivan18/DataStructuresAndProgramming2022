# Задачи за дървета

## Задача 1
### Invert Binary Tree
По даден корен на двоично дърво, обърнете дървото и върнете корена.

 

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)
```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)
```c++
Input: root = [2,1,3]
Output: [2,3,1]
```
**Example 3:**
```c++
Input: root = []
Output: []
 ```

**Constraints:**

The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Задача 2

Допълнете класът BST с итератор.

За целта имплемнтирайте методите 
- `begin()` връща итератор към началото на дървото
- `end()` връща итератор към края на дървото

Променете методът `get` така че да връща итератор.