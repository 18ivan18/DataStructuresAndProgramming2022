# FAQ

## Какво е свързаният списък като структура от данни?
Крайна редица от хомогенни елементи. Операциите за включване и излючване са допустими на произволни места в редицата. Възможен е и достъп до всеки елемент в редицата. 

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)

## Да си го напишем сами?
Има две основни физически представяния. Свързано с една връзка и свързано с две връзки. Връзката между отделните елементи се осъществява чрез указател към следващия елемент. За поддържане на структурата е достатъчен указател към началото на списъка.

## А да го ползваме на готово?
Макар и да го имаме в slt не го използваме самоцелно поради лоши сложности при добавяне и триене.
Повечето задачи използват тънкости при работата с отделните елементчета на списъка.

```c++
#include <list>
// ...
std::list<int> l;
```


# Задача 1
## Обръщане на свръзан списък
По даден указател към `head` - началото на свързан списък с една връзка, върнете *обърнатия списък*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)
```c++
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```
**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)
```c++
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**
```c++
Input: head = []
Output: []
 ```

Constraints:

- The number of nodes in the list is the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`
 

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

# Задача 2
## Цикличен свързан списъл
По дадено начало към свързан списък определете дали той има цикъл в себе си.

Свързан списък има цикъл ако съществува негов елемент, който може да се достъпи повече от веднъж следвайки `next` указателя след като сме тръгнали от началото. Функцията да връща true/false.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)
```c++
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)
```c++
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```
**Example 3:**

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)
```c++
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 ```

**Constraints:**

- The number of the nodes in the list is in the range `[0, 10`<sup>`4`</sup>`]`.
- `-10`<sup>`5`</sup>` <= Node.val <= 10`<sup>`5`</sup>
- `pos` is `-1` or a **valid index** in the linked-list.
 

**Follow up:** Can you solve it using `O(1)` (i.e. constant) memory?


# Задача 3
## Сливане на два сортирани списъка
Слейте два сортирани свързани списъка в нов **сортиран** лист. Той трябва да бъде построен от вече съществуващите елементи на двата подадени списъка.


**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```c++
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
```
**Example 2:**
```c++
Input: l1 = [], l2 = []
Output: []
```
**Example 3:**
```c++
Input: l1 = [], l2 = [0]
Output: [0]
 ```

**Constraints:**

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `l1` and `l2` are sorted in **non-decreasing** order.

# Задача 4
## Сортиране на свързан списък
По дадено началото на свързан списък с една връзка върнете листа след като го сортирате във възходящ ред.
 

**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg)

```c++
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg)

```c++
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```
**Example 3:**
```c++
Input: head = []
Output: []
 ```

**Constraints:**

- The number of nodes in the list is in the range [0, 5 * 10<sup>4</sup>].
- -10<sup>5</sup> <= Node.val <= 10<sup>5</sup>
 

**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

# Задача 5
## Сбор на числа
Дадени са два не-празни свързани списъка представящи две неотрицателни цели числа. Техните цифри са записани в обратен ред и всеки възел съдържа една цифра. Съберете двете числа и върнете резултата като свързан списък.

Можем да предполагаме, че числата не започват с `0` освен самото число 0.

 

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)
```c++
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```c++
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```c++
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 ```

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100].`
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.


# Задача 6
## Премахване на елемент от свързан списък
Напишете функция, която изтрива елемент на свързан списък с една връзка. Като аргумент на функцията обаче няма да бъде подадено началото на свързания списък, ами самият елемент, който трябва да изтрием.

Гарантирано е, че подаденият елемент за триене не е краят на списъка.

**Example 1**:

![](https://assets.leetcode.com/uploads/2020/09/01/node1.jpg)


```c++
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
```
**Example 2**:

![](https://assets.leetcode.com/uploads/2020/09/01/node2.jpg)

```c++
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
```

**Example 3**:
```c++
Input: head = [1,2,3,4], node = 3
Output: [1,2,4]
```

**Example 4**:
```c++
Input: head = [0,1], node = 0
Output: [1]
```

**Example 5**:
```c++
Input: head = [-3,5,-99], node = -3
Output: [5,-99]
 ```

**Constraints:**

- The number of the nodes in the given list is in the range **[2, 1000]**.
- `-1000 <= Node.val <= 1000`
- The value of each node in the list is unique.
- The node to be deleted is in the list and is not a tail node

# Задача 7
## Изтриване на n-ти елемент от края на листа
По дадено началото на свързан списък и число n, премахнете n-тия елемент от края на списъка и върнете началото.  

**Example 1:**

![image](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)
```c++
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```
**Example 2:**
```c++
Input: head = [1], n = 1
Output: []
```
**Example 3:**
```c++
Input: head = [1,2], n = 1
Output: [1]
 ```

**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

**Follow up:** Could you do this in one pass?

# Задача 8
## Flatten a Linked List

Преобразувайте даден свързан списък от свързани списъци до сортиран свързан списък. 
**Example 1:**

![](https://www.techiedelight.com/wp-content/uploads/Flatten-linked-list.png)
```c++
Input: head = [[1, 4, 6, 8], [2, 3, 7], [5, 9], [10, 11, 12]]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
```

