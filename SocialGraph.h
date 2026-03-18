#ifndef SOCIALGRAPH_H
#define SOCIALGRAPH_H

#include <vector>
#include <map>
#include <string>

class SocialGraph {
private:
    std::vector<std::vector<int>> adjacencyList; 
    std::map<std::string, int> nameToId;         
    std::vector<std::string> idToName;          
    int vertexCount;                             

public:
   
    SocialGraph();

   
    void addPerson(const std::string& name);

   
    void addFriendship(const std::string& person1, const std::string& person2);

    
    std::vector<int> bfsWithDistance(int startVertex);

   
    void findAllPairsWithDistance(int maxDistance);


    void printGraphInfo();

   
    int getVertexCount() const;
};

#endif // SOCIALGRAPH_H
