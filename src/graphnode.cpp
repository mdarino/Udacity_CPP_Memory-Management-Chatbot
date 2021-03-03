#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode() { /*Empty*/}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}
// Marcos Darino - 01-MAR-2021 - Task 4
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

// Marcos Darino - 01-MAR-2021 - Task 5
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
//// EOF MD changes

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    // Marcos Darino - 01-MAR-2021 - Task 4
    return _childEdges[index].get();
    //// EOF MD changes
}