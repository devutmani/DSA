#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) {
        data = val;
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

    void add(string val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void show() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    bool isPalindrome() {
        vector<string> vals;
        Node* temp = head;

        while (temp) {
            vals.push_back(temp->data);
            temp = temp->next;
        }

        int i = 0, j = vals.size() - 1;
        while (i < j) {
            if (vals[i] != vals[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    LinkedList list1;
    list1.add("1");
    list1.add("0");
    list1.add("2");
    list1.add("0");
    list1.add("1");

    cout << "List 1:\n";
    list1.show();
    cout << (list1.isPalindrome() ? "Linked List is a Palindrome\n" : "Linked List is NOT a Palindrome\n");

    LinkedList list2;
    string word = "RACECAR";
    for (char c : word) {
        list2.add(string(1, c));
    }

    cout << "\nList 2:\n";
    list2.show();
    cout << (list2.isPalindrome() ? "Linked List is a Palindrome\n" : "Linked List is NOT a Palindrome\n");

    return 0;
}