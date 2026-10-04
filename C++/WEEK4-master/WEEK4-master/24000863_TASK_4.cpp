#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL; 
    }

    ~LinkedList() {
        Node* current = head;
        Node* nextNode = NULL; 
        while (current != NULL) { 
            nextNode = current->next; 
            delete current;           
            current = nextNode;       
        }
        head = NULL; 
    }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) { 
             temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int val) {
        if (pos <= 1) {
            insertAtStart(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) { 
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position " << pos << " is out of range. Inserting at the end.\n";
            delete newNode; 
            insertAtEnd(val); 
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void detectAndRemoveLoop() {
        if (!head || !head->next) {
             cout << "No loop found (list too short).\n";
             return;
        }

        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) { 
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout << "Loop detected!\n";
                removeLoop(slow); 
                return;
            }
        }
        cout << "No loop found.\n";
    }

    void removeLoop(Node* loopNode) {
        Node* ptr1 = head;
        Node* ptr2 = NULL; 
        while (1) {
            ptr2 = loopNode;
            while (ptr2->next != loopNode && ptr2->next != ptr1) {
                ptr2 = ptr2->next;
            }
            if (ptr2->next == ptr1) {
                break; 
            }
            ptr1 = ptr1->next;
        }
        ptr2->next = NULL; 
        cout << "Loop removed.\n";
    }

    void findNthFromEnd(int n) {
        if (n <= 0) {
            cout << "Invalid value of n. Must be greater than 0.\n";
            return;
        }
        if (!head) {
             cout << "List is empty.\n";
             return;
        }

        Node* mainPtr = head;
        Node* refPtr = head;

        for (int count = 0; count < n; count++) {
            if (refPtr == NULL) { 
                cout << "List is shorter than " << n << " nodes.\n";
                return;
            }
            refPtr = refPtr->next;
        }

        while (refPtr != NULL) { 
            mainPtr = mainPtr->next;
            refPtr = refPtr->next;
        }

        if (mainPtr) 
             cout << "The " << n << "th node from end is: " << mainPtr->data << "\n";
    }

    Node* reverseInGroups(Node* node, int k) {
        if (!node) return NULL; 

        Node* prev = NULL; 
        Node* curr = node;
        Node* next = NULL; 
        int count = 0;

        while (curr != NULL && count < k) { 
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL) { 
            node->next = reverseInGroups(next, k);
        }

        return prev; 
    }

    void reverseGroups(int k) {
        if (k <= 1 || !head) {
             if (k <= 0) cout << "Invalid group size.\n";
            return;
        }
        head = reverseInGroups(head, k);
    }

    void print() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty." << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n"; 
    }
};
int main() {
    LinkedList list;
    int choice, val, pos, k, n;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Print List\n";
        cout << "5. Find Nth Node from End\n";
        cout << "6. Reverse in Groups of K\n";
        cout << "7. Detect and Remove Loop\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtStart(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;

            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;
                list.insertAtPosition(pos, val);
                break;

            case 4:
                cout << "Current List: ";
                list.print();
                break;

            case 5:
                cout << "Enter n: ";
                cin >> n;
                list.findNthFromEnd(n);
                break;

            case 6:
                cout << "Enter group size k: ";
                cin >> k;
                list.reverseGroups(k);
                cout << "List after reversing in groups of " << k << ": ";
                list.print();
                break;

            case 7:
                list.detectAndRemoveLoop();
                cout << "List after attempting loop removal: ";
                list.print();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

