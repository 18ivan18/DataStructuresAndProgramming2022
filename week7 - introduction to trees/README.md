# Йерархични структури от данни (Hierarchical data structures)

Йерархичните структури от данни имат главна стойност, която се нарича корен (root), от която тръгват разклонения от възли, които оформят йерархична връзка на принципа parent-child. Всеки възел, от който произлизат едно или повече разклонения, се води родител или parent, а подчинените му възли са дете или child. По този начин се създава сложна разклоняваща се структура.  

#### Наредба на елементите при линейни и йерархични структури:
Нека R е релация (елементите й са от вида <x,y>) и <x,y> ∈ R <=> x е предшественик на y. Тогава:  
Множеството от елементите на йерархичните структури, заедно с релацията "предшествие" образуват ***частично наредено множество*** (не всеки два елемента могат да бъдат сравнени по критерия "предшествие").  
Множеството от елементите на линейните структури от данни, заедно с релацията "предшествие" образуват ***линейно наредено множество*** (нямаме несравними елементи по критерия "предшествие").  

## Дървета 
![alt_text](https://i.ibb.co/MZcSHQM/Binary-tree.png)

### Двоични дървета
Ще ги редставяме със следната структура  
```c++
template <typename T>
struct Node
{
	T data;

	Node* left;
	Node* right;
};
```
### N-ични дървета
Ще ги представяме със следната структура  
```c++
template <typename T>
struct NodeFull
{
	T data;

	vector<NodeFull<T>*> children;
};
```

# FAQ


## Задача 1
По даден корен на двоично дърво, върнете неговото inorder обхождане. 

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)
```c++
Input: root = [1,null,2,3]
Output: [1,3,2]
```
**Example 2:**
```c++
Input: root = []
Output: []
```
**Example 3:**
```c++
Input: root = [1]
Output: [1]
```
**Example 4:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg)
```c++
Input: root = [1,2]
Output: [2,1]
```
**Example 5:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg)
```c++
Input: root = [1,null,2]
Output: [1,2]
 ```

**Constraints:**

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100
 

**Follow up:** Рекурсивното решение е тривиално, можете ли да го решите итеративно?

Намерете и preorder и postorder обхожданията.

Ами ако дървото е n-арно?

## Задача 2
По даден корен на двоично дърво, върнете всички пътища от корен-до-листо в произволен ред.

Листо в дървото е връх без деца.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg)
```c++
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
```
**Example 2:**
```c++
Input: root = [1]
Output: ["1"]
```

## Задача 3
## Binary Tree Level Order Traversal
По даден корен на двоично дърво върнете обхождането на това дърво по нива. Например, ниво по ниво от ляво на дясно.


**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
```c++
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```
**Example 2:**
```c++
Input: root = [1]
Output: [[1]]
```
**Example 3:**
```c++
Input: root = []
Output: []
```


## Задача 4
## Binary Tree Zigzag Level Order Traversal

По даден корен на двоично дърво върнете обхождането на това дърво по нива, но този път на зиг-заг. Например, първото ниво от ляво на дясно, второто от дясно на ляво и тн.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
```c++
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```
**Example 2:**
```c++
Input: root = [1]
Output: [[1]]
```
**Example 3:**
```c++
Input: root = []
Output: []
```


## Задача 5
## Binary Tree Right Side View

По даден корен на двоично дърво си представете, че стоите от дясната му страна и върнете стойностите на върховете, които можете да видите в последователност отгоре надолу.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)
```c++
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```
**Example 2:**
```c++
Input: root = [1,null,3]
Output: [1,3]
```
**Example 3:**
```c++
Input: root = []
Output: []
```

## Задача 6
## Build Binary Expression Tree From Infix Expression

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with 2 children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

For each internal node with operator o, the infix expression that it represents is (A o B), where A is the expression the left subtree represents and B is the expression the right subtree represents.

You are given a string s, an infix expression containing operands, the operators described above, and parentheses '(' and ')'.

Return the binary expression tree, which its in-order traversal reproduce s.

Please note that order of operations applies in s. That is, expressions in parentheses are evaluated first, and multiplication and division happen before addition and subtraction.


**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/20/sample_1_1978.png)
```c++
Input: s = "2-3/(5*2)+1"
Output: [+,-,1,2,/,null,null,null,null,3,*,null,null,5,2]
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2020/09/20/sample_2_1978.png)
```c++
Input: s = "3*4-2*5"
Output: [-,*,*,3,4,2,5]
```
**Example 3:**
```c++
Input: s = "1+2+3+4+5"
Output: [+,+,5,+,4,null,null,+,3,null,null,1,2]
 ```

**Constraints:**

- 1 <= s.length <= 10<sup>5</sup>
- s consists of digits and the characters '+', '-', '*', '/', '(', and ')'.
- Operands in s are exactly 1 digit.
- It is guaranteed that s is a valid expression.


## Задача 7
Жоро е изпълнителен директор на технологичния гигант V&GCorp<sup>TM</sup>. Тъй като наближават коледните празници се налага да купи подаръци на всички свои подчинени, било то преки или косвени (подчинени на подчинени)... така, че да няма много причини да мрънкат. Проблемът е обаче, че ако той подари на даден служител подарък, а прекия му началник не му подари, то служителя ще мрънка на прекия си началник ... абе няма угодия с тия хора.

Вашата задача е по дадена йерархичната структура на компанията да прецените кой началник колко подаръка ще купи, ако знаете, че всеки началник ще купи подарък на всичките си служители.

Йерархичната структура в компанията е под формата на дърво индексирано от 0 до N като Жоро е в корена с индекс 0 като всеки връх съответства на даден човек от компанията. Ако връх с индекс х е родител на друг връх с индекс у, това значи, че човека съответстващ на върха с индекс х e пряк началник на човека съответстващ на индекс у.

Въвежда ви се броя N на служителите. След това на всеки ред се въвеждат по две числа x и y, като това значи, че човека, чийто връх в дървото е с индекс x е родител на човека с индекс в дървото y.

Извеждат се N числа разделени със празно място като i-тото число отговаря на броят подаръци, които трябва да купи човекът, който отговаря на върха с индекс  в дървото.

**Example 1:**
```
Input: n = 9
9
0 1
0 2
1 3
1 4
1 5
1 6
4 7
7 8
Output: 8 6 0 0 2 0 0 1 0
```

