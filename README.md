# University-laboratory-work-on-C++
#include <iostream>

#include <string>

#include <sstream>

template<typename T>

class LinkedList {

private:

    struct Node {

        T data;

        Node* next;

        Node(const T& newData) : data(newData), next(nullptr) {}

    };

    Node* head;

    void initialize(const T& data) {

        if (head == nullptr) {

            head = new Node(data);

        }

    }

public:

    LinkedList() : head(nullptr) {}

    LinkedList(const T& data) {

        initialize(data);

    }

    LinkedList(const LinkedList& other) {

        if (other.head == nullptr) {

            head = nullptr;

        }

        else {

            head = new Node(other.head->data);

            Node* currentNode = head;

            Node* currentOtherNode = other.head->next;

            while (currentOtherNode != nullptr) {

                currentNode->next = new Node(currentOtherNode->data);

                currentNode = currentNode->next;

                currentOtherNode = currentOtherNode->next;

            }

        }

    }

    ~LinkedList() {

        Node* currentNode = head;

        while (currentNode != nullptr) {

            Node* nextNode = currentNode->next;

            delete currentNode;

            currentNode = nextNode;

        }

    }

    void add(const T& data) {

        if (head == nullptr) {

            head = new Node(data);

        }

        else {

            Node* currentNode = head;

            while (currentNode->next != nullptr) {

                currentNode = currentNode->next;

            }

            currentNode->next = new Node(data);

        }

    }

    void remove(const T& data) {

        if (head == nullptr) {

            return;

        }

        if (head->data == data) {

            Node* temp = head;

            head = head->next;

            delete temp;

            return;

        }

        Node* currentNode = head;

        while (currentNode->next != nullptr) {

            if (currentNode->next->data == data) {

                Node* temp = currentNode->next;

                currentNode->next = currentNode->next->next;

                delete temp;

                return;

            }

            currentNode = currentNode->next;

        }

    }

    Node* find(const T& data) {

        Node* currentNode = head;

        while (currentNode != nullptr) {

            if (currentNode->data == data) {

                return currentNode;

            }

            currentNode = currentNode->next;

        }

        return nullptr;

    }

    void print() {

        Node* currentNode = head;

        while (currentNode != nullptr) {

            std::cout << currentNode->data << " ";

            currentNode = currentNode->next;

        }

        std::cout << std::endl;

    }

    void clear() {

        Node* currentNode = head;

        while (currentNode != nullptr) {

            Node* nextNode = currentNode->next;

            delete currentNode;

            currentNode = nextNode;

        }

        head = nullptr;

    }

    friend int main();

};

int main() {

    std::string inputString;

    int wordLength;

    std::cout << "Enter a sentence: ";

    std::getline(std::cin, inputString);

    std::cout << "Enter the word length: ";

    std::cin >> wordLength;

    LinkedList<std::string> wordList;

    std::istringstream iss(inputString);

    std::string word;

    while (iss >> word) {

        if (word.length() == wordLength) {

            wordList.add(word);

        }

    }

    std::string resultString1;

    LinkedList<std::string>::Node* currentNode1 = wordList.head;

    while (currentNode1 != nullptr) {

        resultString1 += currentNode1->data + " ";

        currentNode1 = currentNode1->next;

    }

    std::string resultString2;

    LinkedList<std::string>::Node* currentNode2 = wordList.head;

    while (currentNode2 != nullptr) {

        resultString2 += currentNode2->data[0];

        currentNode2 = currentNode2->next;

    }

    std::cout << "Result_1: " << resultString1 << std::endl;

    std::cout << "Result_2: " << resultString2 << std::endl;

    return 0;

}
