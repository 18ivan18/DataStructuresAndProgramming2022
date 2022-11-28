# Задачи за едносвързан списък
## Задача 1
Да се напише функция, която обръща всяка група от k елемента в свързан списък.

Ако k не е делител на броя на елементите в списъка, последната група от елементи да остане непроменена. 

Не трябва да променяте стойностите на елементите, можете да работите само с указатели.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)
```c++
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)
```c++
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```
**Example 3:**
```c++
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
```
**Example 4:**
```c++
Input: head = [1], k = 1
Output: [1]
 ```

**Constraints:**

- The number of nodes in the list is in the range sz.
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`
 

**Follow-up:** Can you solve the problem in O(1) extra memory space?

## Задача 2
### Palindrome Linked List
Да се напише функция, която проверява дали свързан списък е палиндром.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)
```c++
Input: head = [1,2,2,1]
Output: true
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)
```c++
Input: head = [1,2]
Output: false
 ```

**Constraints:**

- The number of nodes in the list is in the range [1, 105].
- 0 <= Node.val <= 9
 

**Follow up:** Could you do it in O(n) time and O(1) space?

## Задача 3
### Remove Zero Sum Consecutive Nodes from Linked List

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

**Example 1:**
```c++
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
```
**Example 2:**
```c++
Input: head = [1,2,3,-3,4]
Output: [1,2,4]
```
**Example 3:**
```c++
Input: head = [1,2,3,-3,-2]
Output: [1]
 ```

**Constraints:**

- The given linked list will contain between `1` and `1000` nodes.
- Each node in the linked list has `-1000 <= node.val <= 1000`.

## Задача 4
### Reorder List
Напишете функция, която пренарежда свързан списък по зададен начин в линейно време.

Представяме листа като:

`L0 → L1 → … → Ln - 1 → Ln`

Пренареждаме елементите му по следния начин:

`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)
```c++
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg)
```c++
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 ```

**Constraints:**

- The number of nodes in the list is in the range [1, 5 * 10<sup>4</sup>].
- 1 <= Node.val <= 1000

## Задача 5
### Insert into a Cyclic Sorted List

По даден произволен елемент от цикличен свързан списък, сортиран възходящо, напишете функция, която добавя елемент в списъка така че той да остане сортиран. 

Ако има няколко подходящи места вие изберете къде да вмъкнете новия елемент.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/01/19/example_1_before_65p.jpg)

```c++
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.
```
![](https://assets.leetcode.com/uploads/2019/01/19/example_1_after_65p.jpg)

**Constraints:**

- 0 <= Number of Nodes <= 5 * 10<sup>4
- 10^<sup>6</sup> <= Node.val <= 10<sup>6</sup>
- 10^<sup>6</sup> <= insertVal <= 10<sup>6</sup>



## Задача 6
### Odd Even Linked List

Даден е едносвързан списък. Пренаредете листа така че всички елементи с нечетни индекси да са първи, последвани от елементите с четни индекси и върнете пренаредения лист. 

За да е по-интересно първия елемент се смята за елемент с нечетен индекс, втория - четен и тн.

Използвайте `O(1)` място и `O(n)` време.

**Example 1:**

```c++
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```
**Example 2:**

```c++
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 ```

**Constraints:**

- n == number of nodes in the linked list
- 0 <= n <= 10<sup>4</sup>
- -10<sup>6</sup> <= Node.val <= 10<sup>6</sup>


## Задача 7
### Partition List

Даден е едносвързан списък и число х. Пренаредете листа така, че всички елементи със стойност по-малка от х да са преди елементите със стойност по-голяма от х. Трябва да се запази относителния ред на елементите в двете половини.

**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)
```c++
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```
**Example 2:**

```c++
Input: head = [2,1], x = 2
Output: [1,2]
 ```

**Constraints:**

- The number of nodes in the list is in the range `[0, 200]`.
- `-100 <= Node.val <= 100`
- `-200 <= x <= 200`


## По-трудни задачи
### Задача 1 (от контролно):
Даден е списък **l** с n елемента.  
Да се дефинира функция *shuffle()*, която получава адреса на първия елемент на списъка. Функцията да пренарежда възлите на списъка така, че *елементите от втората половина на списъка да се преместят в началото на списъка, но в обратен ред* (при списъци с нечетен брой елементи считаме средния елемент за принадлежащ към първата половина на списъка).  

*Пример:*
*L1 → L2 → L3 → L4 → L5 се преобразува до L5 → L4 → L1 → L2 → L3*  

### Задача 2 (от контролно)
Даден е списък **l** с елементи стекове.  
Да се дефинира функция *equalize(l)*, която размества елементите на стековете така, че *да няма два стека в l с разлика в броя на елементите, по-голяма от 1*.  

*Пример:*  
*Вход:* &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Изход:*
```c++
5 -> 4 -> 3 -> 2 -> 1         5 -> 4 -> 3
|                             |
v                             v
7 -> 6                        7 -> 6 -> 1
|                             |
v                             v
11 -> 10 -> 9 -> 8            11 -> 10 -> 9
|                             |
v                             v
12                            12 -> 2 -> 8
```
