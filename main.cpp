#include <iostream>
#include <locale>
#include "SocialGraph.h"

using namespace std;

int main() {
    
    setlocale(LC_ALL, "Russian");

    SocialGraph graph;

    cout << "=== Создание графа социальных связей ===\n";

    
    graph.addFriendship("Олег", "Никита");
    graph.addFriendship("Никита", "Настя");
    graph.addFriendship("Настя", "Ваня");
    graph.addFriendship("Ваня", "Женя");

    // Выводим информацию о графе
    graph.printGraphInfo();

    // Находим все пары с расстоянием <= 3
    graph.findAllPairsWithDistance(3);

    // Дополнительный пример с более сложным графом
    cout << "\n\n=== Пример с более сложным графом ===\n";

    SocialGraph graph2;

    // Создаём более сложную сеть
    graph2.addFriendship("Анна", "Борис");
    graph2.addFriendship("Анна", "Виктор");
    graph2.addFriendship("Борис", "Галина");
    graph2.addFriendship("Виктор", "Галина");
    graph2.addFriendship("Галина", "Дмитрий");
    graph2.addFriendship("Дмитрий", "Елена");
    graph2.addFriendship("Елена", "Жанна");

    graph2.printGraphInfo();
    graph2.findAllPairsWithDistance(3);

    // Интерактивный режим
    cout << "\n\n=== Интерактивный режим ===\n";
    cout << "Хотите добавить свои связи? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        SocialGraph userGraph;
        int numConnections;

        cout << "Введите количество связей: ";
        cin >> numConnections;
        cin.ignore(); // Очистка буфера

        for (int i = 0; i < numConnections; i++) {
            string person1, person2;
            cout << "Связь " << (i + 1) << ":\n";
            cout << "  Человек 1: ";
            getline(cin, person1);
            cout << "  Человек 2: ";
            getline(cin, person2);

            userGraph.addFriendship(person1, person2);
        }

        userGraph.printGraphInfo();
        userGraph.findAllPairsWithDistance(3);
    }

    system("pause");
    return 0;
}