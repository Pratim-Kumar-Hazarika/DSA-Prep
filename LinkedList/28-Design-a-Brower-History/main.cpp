#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;
    Node(string url){
        data = url;
        next = nullptr;
        prev = nullptr;
    }
};

class Browser {
private:
    Node* current;
public:
    Browser(string homepage){
        current = new Node(homepage);
    }

    void visit(string url){
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps){
        while(steps > 0) {
            if(current->prev){
                current = current->prev;
            } else {
                break;
            }
            steps--;
        }
        return current->data;
    }

    string forward(int steps){
        while(steps > 0){
            if(current->next){
                current = current->next;
            } else {
                break;
            }
            steps--;
        }
        return current->data;
    }
};

int main() {
    Browser browser("leetcode.com");
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << browser.back(1) << endl;      // facebook.com
    cout << browser.back(1) << endl;      // google.com
    cout << browser.forward(1) << endl;   // facebook.com
    browser.visit("linkedin.com");        // Clear forward history
    cout << browser.forward(2) << endl;   // linkedin.com (no forward history)
    cout << browser.back(2) << endl;      // google.com
    cout << browser.back(7) << endl;      // leetcode.com

    return 0;
}
