#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
};

void addNode(Student** head, string name, int score) {
    Student* newNode = new Student{ name, score, nullptr };
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Student* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int getMax(Student* head) {
    int mx = 0;
    Student* temp = head;
    while (temp) {
        if (temp->score > mx) mx = temp->score;
        temp = temp->next;
    }
    return mx;
}

void radixSort(Student** head) {
    int maxScore = getMax(*head);
    int exp = 1;

    while (maxScore / exp > 0) {
        Student* buckets[10] = { nullptr };
        Student* tails[10] = { nullptr };
        Student* temp = *head;

        while (temp) {
            int digit = (temp->score / exp) % 10;
            Student* nextNode = temp->next;
            temp->next = nullptr;

            if (!buckets[digit]) {
                buckets[digit] = tails[digit] = temp;
            } else {
                tails[digit]->next = temp;
                tails[digit] = temp;
            }

            temp = nextNode;
        }

        Student* newHead = nullptr;
        Student* last = nullptr;
        for (int i = 0; i < 10; i++) {
            if (buckets[i]) {
                if (!newHead) {
                    newHead = buckets[i];
                    last = tails[i];
                } else {
                    last->next = buckets[i];
                    last = tails[i];
                }
            }
        }
        *head = newHead;
        exp *= 10;
    }
}

int getLength(Student* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

void linkedListToArray(Student* head, Student** arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = head;
        head = head->next;
    }
}

int binarySearch(Student** arr, int n, string name, int score) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid]->score == score && arr[mid]->name == name) return mid;
        else if (arr[mid]->score < score || (arr[mid]->score == score && arr[mid]->name < name))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void deleteNode(Student** head, Student* target) {
    if (!head || !*head || !target) return;
    if (*head == target) {
        *head = (*head)->next;
        delete target;
        return;
    }
    Student* temp = *head;
    while (temp->next && temp->next != target) temp = temp->next;
    if (temp->next) {
        temp->next = target->next;
        delete target;
    }
}

void display(Student* head) {
    while (head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int main() {
    Student* head = nullptr;

    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);

    radixSort(&head);

    cout << "Sorted list:\n";
    display(head);

    string searchName;
    int searchScore;
    cout << "\nEnter name and score to delete: ";
    cin >> searchName >> searchScore;

    int n = getLength(head);
    Student* arr[10000];
    linkedListToArray(head, arr, n);

    int index = binarySearch(arr, n, searchName, searchScore);
    if (index != -1) {
        deleteNode(&head, arr[index]);
        cout << "\nRecord deleted. Updated list:\n";
        display(head);
    } else {
        cout << "\nRecord not found. List remains:\n";
        display(head);
    }

    return 0;
}