#include "SocialGraph.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Конструктор
SocialGraph::SocialGraph() : vertexCount(0) {}

// Добавить человека в граф
void SocialGraph::addPerson(const string& name) {
    if (nameToId.find(name) == nameToId.end()) {
        nameToId[name] = vertexCount;
        idToName.push_back(name);
        adjacencyList.push_back(vector<int>());
        vertexCount++;
    }
}

// Добавить связь (дружбу) между двумя людьми
void SocialGraph::addFriendship(const string& person1, const string& person2) {
    // Добавляем людей, если их ещё нет
    addPerson(person1);
    addPerson(person2);

    int id1 = nameToId[person1];
    int id2 = nameToId[person2];

    // Добавляем рёбра (неориентированный граф)
    adjacencyList[id1].push_back(id2);
    adjacencyList[id2].push_back(id1);
}

// BFS для поиска кратчайших расстояний от начальной вершины
vector<int> SocialGraph::bfsWithDistance(int startVertex) {
    vector<int> distances(vertexCount, -1); // -1 означает, что вершина не достижима
    queue<int> q;

    distances[startVertex] = 0;
    q.push(startVertex);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjacencyList[current]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
        }
    }

    return distances;
}

// Найти все пары с расстоянием <= maxDistance
void SocialGraph::findAllPairsWithDistance(int maxDistance) {
    cout << "\n=== Пары знакомых через " << maxDistance
        << " рукопожатия (расстояние <= " << maxDistance << ") ===\n\n";

    int pairCount = 0;

    // Для каждой вершины запускаем BFS
    for (int i = 0; i < vertexCount; i++) {
        vector<int> distances = bfsWithDistance(i);

        // Находим все вершины на расстоянии от 1 до maxDistance
        for (int j = i + 1; j < vertexCount; j++) {
            if (distances[j] != -1 && distances[j] <= maxDistance) {
                cout << idToName[i] << " - " << idToName[j]
                    << " (расстояние: " << distances[j] << ")\n";
                pairCount++;
            }
        }
    }

    cout << "\nВсего пар: " << pairCount << endl;
}

// Вывести информацию о графе
void SocialGraph::printGraphInfo() {
    cout << "\n=== Информация о графе ===\n";
    cout << "Количество людей: " << vertexCount << "\n\n";

    cout << "Список людей:\n";
    for (const auto& pair : nameToId) {
        cout << "  " << pair.first << " (ID: " << pair.second << ")\n";
    }

    cout << "\nСписок связей:\n";
    for (int i = 0; i < vertexCount; i++) {
        cout << "  " << idToName[i] << ": ";
        for (int neighbor : adjacencyList[i]) {
            cout << idToName[neighbor] << " ";
        }
        cout << "\n";
    }
}

// Получить количество вершин
int SocialGraph::getVertexCount() const {
    return vertexCount;
}