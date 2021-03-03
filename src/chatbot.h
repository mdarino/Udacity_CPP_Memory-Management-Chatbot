#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation

    // Marcos Darino - 01-MAR-2021 - Rule of five

    // Rule 1 Destructor
    ~ChatBot();
    // Rule 2 Assignment operator
    ChatBot &operator=(const ChatBot &source);       // copy assignment constructor
    // Rule 3 Copy constructor
    ChatBot(const ChatBot &source);
    // Rule 4 Move constructor
    ChatBot(ChatBot &&source);
    // Rule 5 Move assignment operator
    ChatBot &operator=(ChatBot &&source);
    
    //// EOF MD changes

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */