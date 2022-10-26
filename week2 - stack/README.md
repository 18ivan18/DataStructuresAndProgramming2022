# Структури от данни

## Какво са структурите от данни?  
- В компютърните науки, *структура от данни* е фундаментална концепция, която е от ключово значение за създаването на алгоритми.  
- Тя е начин да организираме информация по начин, по който да можем да я използваме *ефикасно*.  

## Видове структури от данни:
### Линейни (списъчни) структури от данни (Linear Data Structures)
Това са структури, които имат **наредба** на елементите в тях.  
Можем да си ги представяме като "хартиен" списък, в който имаме някакво изброяване (1., 2., 3., ..). Точно както в хартиения списък, така и в списъчните структури, елементите ни са *подредени* по определен начин (имаме първи, след него втори, трети и т.н. до последния).

![alt text](https://i.ibb.co/QJYhwJ4/List.jpg)

#### Какви функционалности бихме очаквали да има една списъчна структура?
1. Добавяне на елемент на произволна позиция (в частност, в началото и в края)  
2. Премахване на елемент от произволна позиция (в частност, от началото и от края)  
3. "Преглед" на произволен елемент (в частност, в началото и в края)  

### Абстрактни структури от данни (Abstract Data Type, ADT)
Абстрактният тип данни (АТД) **дава определена дефиниция (абстракция) на конкретната структура**, т.е. определя допустимите опера­ции и свойства, без да се интересува от конкретната реализация.  
Това позволява една абстрактна структура от данни да има различни реализации и респективно различна ефикасност.  
**Контейнер** се нарича структурата, с която сме реализирали такъв *абстрактен тип данни*.  

![alt text](https://i.ibb.co/z6C7ysm/Data-structures.png)

# Динамичен масив (вектор)
 
 ### Сложност на операциите му:  
 - Добавяне на елемент на произволна позиция -> **O(n)**.  
В частност, добавяне на елемент в края -> **O(1) амортизирано** (константно амортизирано).  
-  Премахване на елемент от произволна позиция -> **O(n)**.  
В частност, премахване на елемент от края -> **O(1) амортизирано** (константно амортизирано).  
- "Преглед" на произволен елемент (в частност, в началото и в края)  -> **O(1)**.  

# Стек
Абстрактен тип данни, базиран на принципа **"Last In First Out (LIFO)"**.  
Обектите могат да се добавят/премахват и преглеждат единствено от горната страна на стека.  
Стекът има три операции:  
-  **push** – добавя нов елемент  най - отгоре  
-  **pop** – премахва най - горния елемент  
- **top** – показва най-горния елемент от стека, без да го премахва   

![alt text](https://i.ibb.co/tpwtT2p/Stack.png)

## Какво беше това стек?

Линейна динамична структура от данни. Крайна редица от хомогенни елементи. Операции за включване и изключване на елементи от вида LIFO (last in first out). 

![](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)

![](https://cdn.programiz.com/sites/tutorial2program/files/stack-operations.png)



## Как сега го имплементирах този стек?

Две физически представяния - последователно и свързано. Последователното има ограничен капацитет. При свързаното парчетата памет са разпръснати из оперативната памет и връзката между отделните елементи става чрез указатели.

![](https://lh3.googleusercontent.com/proxy/B8FTgbSgpUvyHXAL-Hl21PXCrkxQfKwI9k14bxypgoi9koCiKMlA80lypSFDBTtVAGcgJxJIz3ruQ53MjWyVbtRzAzfPy9e1WS8yC22aX7ZXZDyHOLNA1MR0hcaPDzXpZ3U2vymPf7DhOGtfX-XyipAmJmuMmm1e4dOU)

## Добре де, ама ако не искам да си го пиша сам, нали хората вече са го измислили?

Ползвай stl реализацията в c++.

```c++
#include <stack>
// ...
std::stack<int> st;
st.push(5);
st.push(-42);
st.push(69);
st.push(77);

while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
}
```

## Като го ползвам на готово как да разбера то как е имплементирано?
Стандартно структурите използват други струкури за имплементацията си. Ние можем и сами да избирами кои точно. В [конкретния случай](https://en.cppreference.com/w/cpp/container/stack):

```c++
std::stack
    // Defined in header <stack>
    template<
    class T,
    class Container = std::deque<T>
    > class stack;
```
> The std::stack class is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.

> The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.

## И кога каза, че го ползвам това чудо?

- Expression evaluation and syntax parsing
- Backtracking  
- Compile time memory management
- Efficient algorithms

# Задача 1
## Reverse text without reversing individual words
Имаме даден текст. Обрънете реда на думите в него.

**Example 1:**
```c++
Input: s = "Technical Interview Preparation"
Output: "Preparation Interview Technical"
```
# Задача 2
## Валидни скоби

Даден е низ `s` съдържащ символите `'(', ')'`, `'{', '}'`, `'['` и `']'`, опредеете дали входът е валиден.

Входният низ е валиед, ако:

1. Отварящите скоби се затварят от същия вид скоби.
2. Отварящите скоби са затворени в правилния ред.
 

**Example 1:**
```c++
Input: s = "()"
Output: true
```
**Example 2:**
```c++
Input: s = "()[]{}"
Output: true
```
**Example 3:**
```c++
Input: s = "(]"
Output: false
```
**Example 4:**
```c++
Input: s = "([)]"
Output: false
```
**Example 5:**
```c++
Input: s = "{[]}"
Output: true
```

**Constraints:**

* 1 <= s.length <= 10<sup>4
* `s` consists of parentheses only `'()[]{}'`.
# Задача 3
## Минимален стек

Напишете структура стек, която поддържа операциите `push`, `pop`, `top` и извеждане на минимален елемент в константно време.

Имплементирайте класа `MinStack`:

- `MinStack()` инициализира обекта стек.
- `void push(val)` поставя елемента `val` на върха на стека.
- `void pop()` премахва най-горния елемент от върха на стека.
- `int top()` връща стойността на елемента, който се намира на върха на стека.
- `int getMin()` взима минималния елемент в стека.
 

**Example 1:**
```c++
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

**Constraints:**

- -2<sup>31</sup> <= val <= 2<sup>31</sup> - 1
- Methods `pop`, `top` and `getMin` operations will always be - called on **non-empty** stacks.
- At most 3 * 10<sup>4</sup> calls will be made to `push`, `pop`, `top`, and `getMin`.

# Задача 4
## Пресметнете стойносттна на аритметичен израз записан в обратен полски запис (Reverse Polish Notation)

![](https://media.cheggcdn.com/media%2Fb3d%2Fb3d2eb31-5784-49be-895c-aef23651f0b2%2Fimage.png)

Валидни оператори са `+`, `-`, `*`, and `/`. Всеки операнд може да е число или друг валиден израз.

Използвайте floor division. 

Гарантираме, че даденият израз в обратен полски запис е винаги правилен. Той винаги се свежда до резултат и няма да има деление на нула.
 

**Example 1:**
```c++
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**Example 2:**
```c++
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```
**Example 3:**
```c++
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

**Constraints:**

- 1 <= tokens.length <= 10<sup>4
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200].`

# Задача 5
## Опростяване на път
Даден ни е низ - абсолютен път (започващ с '/') към файл или директория в Unix файлова система. Ние трябва да го опростим и да го превърнем в **каноничен път**.

В Unix файлова система точката '.' означава текуща директория, двете последователни точки '..' означават родителска директория, а много последователни наклонени черти '//' се третират като една '/'. Всички останали низове се третираткато имена на файлове/директории.

Каноничния път трябва да има следния формат:
- Пътят започва с една наклонена черта '/'.
- Две директории се разделят от една наклонена черта '/'.
- Пътят не завършва с наклонена черта '/'.
- Пътят съдържа само директории от основната директория до файла/крайната директория (не се позволяват '.', '..').

Върнете пътя.

**Example 1:**
```c++
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
```

**Example 2:**
```c++

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
```
**Example 3:**
```c++

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 ```

**Constraints:**

- `1 <= path.length <= 3000`
- `path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`.
- `path` is a valid absolute Unix path.

# Задача 6
## Простичък калкулатор
Даден ни е низ `s` представляващ правилен алгебричен израз. Напишете калкулатор, който да пресметне стойността му и да я върне като резултат.
 

**Example 1:**
```c++
Input: s = "1 + 1"
Output: 2
```
**Example 2:**
```c++
Input: s = " 2-1 + 2 "
Output: 3
```
**Example 3:**
```c++
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 ```

**Constraints:**

- 1 <= s.length <= 3 * 10<sup>5
- `s` consists of digits, `'+'`, `'-'`, `'('`, `')'`, and `' '`.
- `s` represents a valid expression.
- `'+'` is not used as a unary operation.
- `'-'` could be used as a unary operation and in this case, it will not be used directly after a +ve or -ve signs (will be inside parentheses).
- There will be no two consecutive operators in the input.
- Every number and running calculation will fit in a signed 32-bit integer.

# Задача 7
## Калкулатор
Даден ни е низ `s` представляващ правилен алгебричен израз. Напишете обикновен калкулатор, който да пресметне стойността му и да я върне като резултат.
 
При деление на цели числа използвайте floor division.

Можем да предположим, че изразите са винаги верни.

**Example 1:**
```c++
Input: s = "3+2*2"
Output: 7
```
**Example 2:**
```c++
Input: s = " 3/2 "
Output: 1
```
**Example 3:**
```c++
Input: s = " 3+5 / 2 "
Output: 5
 ```

**Constraints:**

- 1 <= s.length <= 3 * 10<sup>5
- `s` consists of integers and operators (`'+'`, `'-'`, `'*'`, `'/'`) separated by some number of spaces.
- `s` represents **a valid expression**.
- All the integers in the expression are non-negative integers in the range [0, 2<sup>31</sup> - 1].
- The answer is **guaranteed** to fit in a **32-bit integer**.

# Задача 8
## Отровни цветя

В една градина има `n` на брой цветя. Всяко цвете е третирано с определено количество
пестициди. В края на всеки ден, ако някое цвете е било третирано с повече пестициди от
съседното му вляво, то умира.
В началото се подава `n` - броя на цветята. На следващият ред `n` числа, разделени с
интервал - количеството пестициди, с които е третирано `i`-тото цвете. Вашата програма 
трябва да изведе броя на дните, след които никое цвете не умира (няма цветя с повече
пестициди от левия си съсед).

**Example 1:**
```c++
Input: 5
       3 6 2 7 5
Output: 2
Explanation: След първия ден умират второто и четвъртото цвете (p[1], p[3]) и остават следните - `p = [3,
2, 5]`. След втория ден третото цвете от първоначалния масив(p[2]) умира, т.е. остават `p =
[3, 2]`. Вече няма цветя с повече пестициди от левия си съсед, следователно отговора е 2.
```

**Example 2:**
```c++
Input: 7
       6 5 8 4 7 10 9
Output: 2
```

# Задача 9
## Пресичащи се интервали
Даден е вектор от интервали от време s. Всеки интервал се характеризира с начален час и краен час. Намерете всички непресичащи се интервали след като убедините всички пресичащи се.

**Example 1:**
```c++
Input:  {1, 5}, {2, 3}, {4, 6}, {7, 8}, {8, 10}, {12, 15}
Output: Intervals after merging overlapping intervals are {1, 6}, {7, 10}, {12, 15}.
```