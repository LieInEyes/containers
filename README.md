
Реализация библиотеки containers.h.

В рамках данного проекта вам будет предложено написать собственную библиотеку, реализующую основные стандартные контейнерные классы языка С++: `list` (список), `map` (словарь), `queue` (очередь), `set` (множество), `stack` (стек) и `vector` (вектор). Реализации должны предоставлять весь набор стандартных методов и атрибутов для работы с элементами, проверкой заполненности контейнера и итерирования. В качестве дополнительного задания предлагается реализовать еще несколько не так часто используемых, но отличающихся деталями реализации контейнерных классов из контейнерной библиотеки C++.

Каждый вид контейнеров должен предоставить пользователю следующие методы:

- стандартные конструкторы (конструктор по умолчанию, конструктор копирования, конструктор перемещения, конструктор со списком инициализации);
- методы доступа к элементам контейнера (например, осуществление доступа к элементу с индексом i);
- методы проверки наполненности контейнера (например, количество элементов в контейнере, проверка на пустоту контейнера);
- методы изменения контейнера (удаление и добавление новых элементов, очистка контейнера);
- методы для работы с итератором контейнера.

Над итератором `iter` определены следующие операции:

- `*iter`: получение элемента, на который указывает итератор;
- `++iter`: перемещение итератора вперед для обращения к следующему элементу;
- `--iter`: перемещение итератора назад для обращения к предыдущему элементу;
- `iter1 == iter2`: два итератора равны, если они указывают на один и тот же элемент;
- `iter1 != iter2`: два итератора не равны, если они указывают на разные элементы.

Помимо особой организации объектов и предоставления необходимых методов, реализация контейнерных классов требует шаблонизации объектов. 

- Программа должна быть разработана на языке C++ стандарта C++17 с использованием компилятора gcc
- Код программы должен находиться в папке src
- При написании кода необходимо придерживаться Google Style
- Обязательно использовать итераторы
- Классы обязательно должны быть шаблонными
- Классы должны быть реализованы внутри пространства имен `my_space`
- Подготовить полное покрытие unit-тестами методов контейнерных классов c помощью библиотеки GTest
- Запрещено копирование реализации стандартной библиотеки шаблонов (STL)
- Необходимо соблюсти логику работы стандартной библиотеки шаблонов (STL) (в части проверок, работы с памятью и поведения в нештатных ситуациях)

Part 1. Реализация библиотеки containers.h

Необходимо реализовать классы библиотеки `containers.h`. \
Список классов: `list` (список), `map` (словарь), `queue` (очередь), `set` (множество), `stack` (стек), `vector` (вектор).
- Оформить решение в виде заголовочного файла `containers.h`, который включает в себя другие заголовочные файлы с реализациями необходимых контейнеров (`list.h`, `map.h` и т.д.)
- Предусмотреть Makefile для тестов написанной библиотеки (с целями clean, test)
- За основу стоит рассматривать классическую реализацию контейнеров, но конечный выбор реализаций остается свободным. За исключением списка - его необходимо реализовывать через структуру списка, а не через массив.

*Подсказка*: Вы можете выделять в базовые классы одинаковую реализацию методов контейнеров. Например, для очереди и стека или для списка и вектора. В качестве *одного из возможных примеров* иерархического построения в материалах представлена UML-диаграмма библиотеки STL. Однако ваша реализация не обязана быть строго привязана к этой UML-диаграмме.

Part 2. Дополнительно. Реализация библиотеки containersplus.h

Необходимо реализовать функции библиотеки `containersplus.h`. \
Список классов, которые нужно реализовать дополнительно: `array` (массив), `multiset` (мультимножество).
- Оформить решение в виде заголовочного файла `containersplus.h`, который включает в себя другие заголовочные файлы с реализациями необходимых контейнеров (`array.h`, `multiset.h`)
- Предусмотреть Makefile для тестов написанной библиотеки (с целями clean, test)
- За основу стоит рассматривать классическую реализацию контейнеров, но конечный выбор алгоритма остается свободным

Part 3. Дополнительно. Реализация модифицированных методов `emplace`

Необходимо дополнить классы соответствующими методами, согласно таблице:

| Modifiers      | Definition                                      | Containers |
|----------------|-------------------------------------------------| -------------------------------------------|
| `iterator emplace(const_iterator pos, Args&&... args)`          | inserts new elements into the container directly before `pos`  | List, Vector |
| `void emplace_back(Args&&... args)`          | appends new elements to the end of the container  | List, Vector, Queue |
| `void emplace_front(Args&&... args)`          | appends new elements to the top of the container  | List, Stack |
| `vector<std::pair<iterator,bool>> emplace(Args&&... args)`          | inserts new elements into the container  | Map, Set, Multiset |

Обратите внимание, что в качестве аргументов передаются уже созданные элементы, которые необходимо вставить в соответствующий контейнер.

*Подсказка 1*: обратите внимание, что каждый из этих методов использует конструкцию Args&&... args - Parameter pack. Эта конструкция позволяет передавать переменное число параметров в функцию или метод. То есть при вызове метода, определенного как `iterator emplace(const_iterator pos, Args&&... args)`, можно написать как `emplace(pos, arg1, arg2)`, так и `emplace(pos, arg1, arg2, arg3)`.

*Подсказка 2*: не забудьте протестировать методы для различных случаев, включая краевые.
