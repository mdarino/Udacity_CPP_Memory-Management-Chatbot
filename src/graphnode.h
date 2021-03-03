#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    // Marcos Darino 1-MAR-2021 - Task 4 (owned(->To smart pointer)
    // data handles 
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;// edges to subsequent nodes
    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    // Marcos Darino 1-MAR-2021 - Task 5
    ChatBot _chatBot;
    //// EOF MD changes
    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    // Marcos Darino - 01-MAR-2021 - Task 4
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);
    // Marcos Darino 1-MAR-2021 - Task 5
    void MoveChatbotHere(ChatBot chatbot);
    //// EOF MD changes

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */