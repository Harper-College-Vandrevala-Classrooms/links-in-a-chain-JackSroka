#include <iostream>
#include <string>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node {
public:
    ChainLink* link;
    Node* next;

    Node(ChainLink* link) : link(link), next(nullptr) {}
};

class Chain {
private:
    Node* head;

public:
    Chain() : head(nullptr) {}

    void append(ChainLink* newLink) {
        Node* newNode = new Node(newLink);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void view(int index) {
        if (index < 0) {
            cout << "Index must be non-negative." << endl;
            return;
        }
        Node* temp = head;
        int currentIndex = 0;
        while (temp != nullptr) {
            if (currentIndex == index) {
                cout << "Index color " << index << ": " << temp->link->get_color() << endl;
                return;
            }
            temp = temp->next;
            currentIndex++;
        }
        cout << "Index color " << index << " is out of bounds." << endl;
    }

    ~Chain() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp->link;
            delete temp;
        }
    }
};

// Main function to demonstrate functionality
int main() {
    Chain myChain;

    myChain.append(new ChainLink("Red"));
    myChain.append(new ChainLink("Blue"));
    myChain.append(new ChainLink("Green"));
    myChain.append(new ChainLink("cyan"));
    myChain.append(new ChainLink("yellow"));
    myChain.append(new ChainLink("mangenta"));

    myChain.view(0); 
    myChain.view(1); 
    myChain.view(2); 
    myChain.view(3);    
    myChain.view(4);    
    myChain.view(5);
    myChain.view(6);

    return 0;
}