# assignment4
this is the code that i used as reference for the insert function but this one failed to link the nodes together
struct Node {
    int id;
    std::string name;
    double score;
    Node* next;

    Node(int _id, std::string _name, double _score) {
        id = _id;
        name = _name;
        score = _score;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int id, std::string name, double score) {
        Node* newNode = new Node(id, name, score);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            Node* prev = nullptr;
            while (current != nullptr && current->id < id) {
                prev = current;
                current = current->next;
            }
            if (prev == nullptr) {
                head = newNode;
            } else {
                // insert the new node between prev and current
            }
        }
    }
};
