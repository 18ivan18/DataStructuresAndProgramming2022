# F.A.Q.
## Анализ на алгоритми
Да бъде **анализиран** даден алгоритъм означава да бъде доказано, че той е **коректен**, и ако е коректен, да бъде  
изчислено колко **ресурси ползва** - за всеки възможен вход - като ресурсите са основно **време** и **памет**.  

В този курс ще разглеждаме само втората част от анализа на алгоритми - **сложността**.  

**“Сложност на алгоритъм”** е мярка за това **колко ресурси полза този алгоритъм.** За какви ресурси става дума?  
1. **Време.** Искаме алгоритмите ни да работят бързо.   
В този смисъл, “качествен алгоритъм” е алгоритъм, който работи бързо върху *всички* входове.  
2. **Памет.** Искаме алгоритмите ни да ползват малко памет.  
В този смисъл, “качествен алгоритъм” е алгоритъм, който ползва малко памет върху *всички* входове.  

**Сложността по време** е мярка, която ни казва как нараства времето за изпълнение на даден алгоритъм, когато  големината на входа му клони към *безкрайност*.  
**Сложността по памет** е мярка, която ни казва как нараства паметта, която даден алгоритъм ползва, когато големината на входа му клони към *безкрайност*.  

Когато разглеждаме сложността по време на алгоритми, разглеждаме *три* случая:  

 - Най-добър случай (**Best case**)  
 - Среден случай (**Average case**)  
 - Най-лош случай (**Worst case**)  
 
 Коя е най-ценната величина от трите?  
**Средният случай!** ..*Но:*  
 -   Средното време за работа обикновено се определя трудно.  
 -   Ще се фокусираме върху времето за работа **в най-лошия случай**.  


## Какво беше това сложност?

Θ(g(n)) = { f(n) | ∃c<sub>1</sub>, c<sub>2</sub> > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ c<sub>1</sub>.g(n) ≤ f(n) ≤ c<sub>2</sub>.g(n) }
	
f(n) ≈ g(n) ⇔ f(n) = Θ(g(n)) 

### Нестрога горна граница

O(g(n)) = { f(n) | ∃c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ f(n) ≤ c.g(n) }

f(n) <= g(n) ⇔ f(n) = O(g(n)) 
	
### Нестрога долна граница
Ω(g(n)) = { f(n) | ∃c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ c.g(n) ≤ f(n) }

f(n) ≺ g(n) ⇔ f(n) = o(g(n)) 
	

### Строга горна граница

o(g(n)) = { f(n) | ∀c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ f(n) < c.g(n) }

f(n) >= g(n) ⇔ f(n) = Ω(g(n)) 
	
### Строга долна граница

ω(g(n)) = { f(n) | ∀c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ c.g(n) < f(n) }
	
f(n) ≻ g(n) ⇔ f(n) = ω(g(n)) 

## Кои бяха основните сложности с примери?

Big O Notation | Name | Example(s)
------------ | ------------- | ---------
O(1) | Constant | **Odd or Even number** <br>**Look-up table (on average)**
O(log n) | Logarithmic | **Finding element on sorted array with binary search**
O(n) | Linear | **Find max element in unsorted array**
O(n log n) | Linearithmic | **Sorting elements in array with merge sort**
O($n^2$) | Quadratic | **Duplicate elements in array (naïve)**
O($n^3$) |	Cubic | **3 variables equation solver**
O($2^n$) |	Exponential	| **Find all subsets**
O(n!) | Factorial | **Find all permutations of a given set/string**

## Защо ме вълнува сложнстта?

| n | O(1) | O(log n) | O(n) | O(n log n) | O($n^2$) | O($2^n$) | O(n!)
| - | - | - | - | - | - | - | - 
| 1	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| < 1 sec	            | < 1 sec
| 10	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| < 1 sec	            | 4 sec
| 100	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| 40170 trillion years	| > vigintillion years
| 1,000	    | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| > vigintillion years	| > centillion years
| 10,000	    | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| 2 min	    | > centillion years	| > centillion years
| 100,000	    | < 1 sec |	< 1 sec |	< 1 sec	| 1 sec	    | 3 hours	| > centillion years	| > centillion years
| 1,000,000	| < 1 sec |	< 1 sec |	1 sec	| 20 sec	| 12 days	| > centillion years	| > centillion years

## Указатели. Указатели към указатели. Референция към указатели.
Указател е променлива, която приема за стойност адрес в паметта. Указателите имат фиксирана големина. Тъй като те също са променливи заделени на стека те също имат адрес. Затова можем да декларираме указател към указател, т.е. указател, който сочи към адреса на променлива от тип указател. 

```c++
int foo = 5;
int *pFoo = &foo; // & operator takes the address of a variable
int **ppFoo = &pFoo;
```

Можем да дерефенцираме указател (т.е. да достъпим стойността на променливата, към която сочи) с оператора *.

```c++
int *pFoo = *ppFoo;
int foo = *pFoo;
int bar = **ppFoo;
```

Указателите са основата на динамичното заделяне на памет. Когато използваме оператор `new` ние получаваме адрес към новозаделената памет. Наша работа е да се погрижим за тази памет като я запазим в променлива.

```c++
int *i = new int();
int *i = new int(5);
int *i = new int{5};
int *i = new int[5];
```

Едно място в паметта може да се достъпва чрез няколко указателя.

```c++
int *i = new int(), *i1 = i;
```

Това е и причината да се използват указатели за предаване на променливи като аргументи на функции.

```c++
void swap(int first, int second) {
    int firstCopy = first;
    first = second;
    second = firstCopy;
}
```

Горният фрагмент код не работи правилно, защото аргументите на функцията са подадени по стойност. Това означава, че се създават две локални за фунцкията променливи с имена first и second, които приемат подадените им стойности. Разменяме тегните стойности и след изпълнение на фунцкията стойностите на подадените аргументите остават същите. Това лесно може да се промени, ако ги подадем чрез указатели.

## Функции от по-висок ред. (High order functions)
Функциите от по-висок ред са функции, които приемат функции като аргумент или връщат функции като резултат. Използват се във функционални езици за програмиране (какъвто C++ не е, но след C++ поддържа доста от функционалностите, например ламбда функции и ‘std::function’).

### Как?
С нещото наречено указател към функция.
```c++
void myIntFunc(int x)
{
    std::cout << x << std::endl;
}
 
int main()
{
    void (*foo)(int);
    /* the ampersand is actually optional */
    foo = &my_int_func;

    /* call myIntFunc (note that you do not need to write (*foo)(2) ) */
    foo(2);
    /* but if you want to, you may */
    (*foo)(2);
}
```

### А как ги подавам на други функции като праметър?
```c++
int resultOfCalculation(int (*op)(int, int),
                        int x, int y)
{
    return (*op)(x, y);
}

int add(int a, int b)
{
    return a + b;
}

int mult(int a, int b)
{
    return a * b;
}

int main()
{
    int (*addPtr)(int, int);
    addPtr = &add;

    int sum = resultOfCalculation(addPtr, 1, 2) 
    int prod = resultOfCalculation(mult, 1, 2)
}
```

Можем да използваме името на някоя фунцкия като указател към нея.

## std::function от functional 
Пример от [cppreference](https://en.cppreference.com/w/cpp/utility/functional/function)
```c++
#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
 
    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();
 
    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();
 
    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);
 
    // store a call to a data member accessor
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
 
    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);
 
    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
 
    auto factorial = [](int n) {
        // store a lambda object to emulate "recursive lambda"; aware of extra overhead
        std::function<int(int)> fac = [&](int n){ return (n < 2) ? 1 : n*fac(n-1); };
        // note that "auto fac = [&](int n){...};" does not work in recursive calls
        return fac(n);
    };
    for (int i{5}; i != 8; ++i) { std::cout << i << "! = " << factorial(i) << ";  "; }
}
```

## Кои са някои от основните функции от по-висок ред, които правят живота ни по-лесен?

### map
Фунцкия, която приема вектор и едномерна функция и връща нов вектор, чиито елементи се получават от елементите на стария чрез прилагане на едномерната фунцкия подадена като аргумент.

**Example 1:**
```
Input:  [1,2,3] square      
Output: [1,4,9]
```

### filter
Фунцкия, която приема вектор и едномерен предикат и връща нов вектор, чиито елементи се получават чрез филтриране на стария чрез прилагане на предиката подаден като аргумент.

**Example 1:**
```
Input:  [1,2,3] isEven      
Output: [2]
```

### reduce (foldl)
Фунцкия, която приема вектор, двумерна функция и начална стойност. Двумерната фунцкия се изпълнява върху всеки елемент от вектора заедно с резултата като накрая се акумулира една стойност.

**Example 1:**
```
Input:  [1,2,3] + 0      
Output: (((0 + 1) + 2) + 3) 
```

**Example 1:**
```
Input:  [1,2,3] append ""      
Output: ((("" + "1") + "2") + "3") 
```

# Задачи:
## Задача 1

Да се напише функция, която приема като аргумент масив от цели числа, броя на 
елементите и друга функция – `next(i)` (тя приема едно число и връща числото, което е с 3 по-
голямо от подаденото) и връща сумата на елементите, които се намират на индекси, които се получават чрез прилагане на `next` върху предишните индекси (в примера кратни 
на `3`, индексите започват от `0`). 

Реализирайте сами функцията next и я използвайте в другата функция!

$\sum_{i=0, next(i)}^{n} arr[i]$
## Задача 2
Да се напише функция, която приема като аргумент масив от цели числа, броя на 
числата и двуаргументна булева функция `isDivisble(x, y)` (`isDivisible` проверява дали `x` се дели 
на `y` без остатък) и връща броя на всички двойки числа от масива, отговарящи на това 
условие.

Реализирайте сами функцията `isDivisble` и я използвайте в другата функция!

## Задача 3
Да се напише функция `map`, която приема като аргументи масив от цели числа, неговата 
размерност и едноаргументна функция operation,
и прилага функцията operation върху всеки един елемент на масива.

Да се реализира и втори път като функция, която връща нов масив, вместо да променя елементите на стария.

## Задача 4
Да се напише функция `filter`, която приема като аргументи масив от цели числа, неговата 
размерност и едноаргументен предикат, и връща нов масив с елементите от масива, отговарящи на предиката.

Да се измисли механизъм за връщане на големината на филтрирания масив.

## Задача 5
Да се напише функция `compose`, която приема като аргументи едноаргументна функция 
от тип `double` и цяло число `n`, и връща композицията на функцията `n` пъти.

## Задача 6
Да се напише функция, която приема масив от низове, броя на низовете и булева 
двуместна функция, която има за аргументи два низа. Функцията да изкарва на екрана 
низовете, подредени според наредбата зададена от двуместната функция.

**Example 1:**
```
Input:   4     
         i     
         love  
         eating
         pizza
Output:  eating
         i
         love
         pizza
```


## Задача 7
Ако `f` и `g` са числови функции и n е естествено число, да се дефинира функция от по-висок 
ред `switchsum(n x f g)`, която връща като резултат функция, чиято стойност в дадена точка x е 
равна на `f(x)+g(f(x))+f(g(f(x)))+ ...` (сумата включва n събираеми).

**Example 1:**
```
f(x) = x + 1
g(x) = x * 2
 
switchsum(1, 2, f, g) → 3 
switchsum(2, 2, f, g) → 9 
switchsum(3, 2, f, g) → 16 
switchsum(4, 2, f, g) → 30
```