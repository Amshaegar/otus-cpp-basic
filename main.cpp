#include "Vector.hpp"
#include "List.hpp"

#include <iostream>

template<typename T>
void test_container(containers::IContainer<T>* container);

int main() {
    std::cout << "Контейнер последовательного доступа" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. создание объекта контейнера для хранения объектов типа int" << std::endl;
    auto* vector = new containers::Vector<int>();
    test_container(vector);

    std::cout << std::endl;

    std::cout << "Контейнер спискового типа" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. создание объекта контейнера для хранения объектов типа int" << std::endl;
    auto* list = new containers::List<int>();
    test_container(list);

    return 0;
}


template<typename T>
void test_container(containers::IContainer<T>* container) {
    std::cout << "2. добавление в контейнер десяти элементов (0, 1 ... 9)" << std::endl;
    int num = 10;
    for (int i = 0; i < num; ++i) {
        container->push_back(i);
    }

    std::cout << "3. вывод содержимого контейнера на экран" << std::endl;
    std::cout << "ожидаемый результат:\n0, 1, 2, 3, 4, 5, 6, 7, 8, 9" << std::endl;
    std::cout << "результат:" << std::endl;
    std::cout << *container;

    std::cout << "4. вывод размера контейнера на экран" << std::endl;
    std::cout << "ожидаемый результат: 10" << std::endl;
    std:: cout << "size: " << container->size() << std::endl;

    std::cout << "5. удаление третьего (по счёту), пятого и седьмого элементов" << std::endl;
    container->erase(3);
    container->erase(4);
    container->erase(5);
    std::cout << "6. вывод содержимого контейнера на экран" << std::endl;
    std::cout << "ожидаемый результат:\n0, 1, 3, 5, 7, 8, 9" << std::endl;
    std::cout << "результат:" << std::endl;
    std::cout << *container;

    std::cout << "7. добавление элемента 10 в начало контейнера" << std::endl;
    container->insert(0, 10);

    std::cout << "8. вывод содержимого контейнера на экран" << std::endl;
    std::cout << "ожидаемый результат:\n10, 0, 1, 3, 5, 7, 8, 9" << std::endl;
    std::cout << "результат:" << std::endl;
    std::cout << *container;

    std::cout << "9. добавление элемента 20 в середину контейнера" << std::endl;
    container->insert(4, 20);

    std::cout << "10. вывод содержимого контейнера на экран" << std::endl;
    std::cout << "ожидаемый результат:\n10, 0, 1, 3, 20, 5, 7, 8, 9" << std::endl;
    std::cout << "результат:" << std::endl;
    std::cout << *container;

    std::cout << "11. добавление элемента 30 в конец контейнера" << std::endl;
    container->insert(container->size(), 30);

    std::cout << "12. вывод содержимого контейнера на экран" << std::endl;
    std::cout << "ожидаемый результат:\n10, 0, 1, 3, 20, 5, 7, 8, 9, 30" << std::endl;
    std::cout << "результат:" << std::endl;
    std::cout << *container;
}