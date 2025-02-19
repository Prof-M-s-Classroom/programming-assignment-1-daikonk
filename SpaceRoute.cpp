#include <iostream>
#include <string>
using namespace std;

template <typename T> class Node {
public:
  T &data;
  Node *next;
  Node *prev;

  Node(T &d) : data(d), next(nullptr), prev(nullptr) {}
  void print() { cout << data << " "; }
};

class CelestialNode {
private:
  string name;
  double distance_from_earth;
  string mission_log;

public:
  CelestialNode(const string &n, double d, const string &log);
  const string &getName() const;
  double getDistance() const;
  const string &getMissionLog() const;
  void print() const {
    cout << name << " (" << distance_from_earth << " AU) - " << mission_log
         << endl;
  }
};

template <typename T> class SpaceRoute {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  SpaceRoute() {

    T *headData = new T();
    T *tailData = new T();

    head = new Node<T>(*headData);
    tail = new Node<T>(*tailData);

    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;

    delete headData;
    delete tailData;

  }; // Constructor
  ~SpaceRoute() {
    Node<T> *curr = head;

    while (curr) {
      Node<T> *temp = curr->next;
      delete curr;
      curr = temp;
    }
  }; // Destructor

  void addWaypointAtBeginning(T &data) {
    Node<T> *newNode = new Node(data);
    Node<T> *temp = head->next;
    head->next = newNode;
    newNode->prev = head;
    newNode->next = temp;
    temp->prev = newNode;
  };
  void addWaypointAtEnd(T &data) {
    Node<T> *newNode = new Node(data);
    Node<T> *temp = tail->prev;
    tail->prev = newNode;
    newNode->next = tail;
    newNode->prev = temp;
    temp->next = newNode;
  };
  void addWaypointAtIndex(int index, T &data) {
    Node<T> *curr = head;
    if (index < 0) {
      cout << "Index out of bounds." << endl;
      return;
    }
    for (int i = 0; i < index; i++) {
      curr = curr->next;
      if (!curr->next) {
        cout << "Index out of bounds." << endl;
        return;
      }
    }
    Node<T> *newNode = new Node(data);
    Node<T> *temp = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = temp;
    temp->prev = newNode;
  };
  void removeWaypointAtBeginning() {
    Node<T> *temp = head->next->next;
    Node<T> *toRemove = head->next;
    if (!temp) {
      cout << "List is empty" << endl;
      return;
    }
    head->next = temp;
    temp->prev = head;
    delete toRemove;
  };
  void removeWaypointAtEnd() {
    Node<T> *temp = tail->prev->prev;
    Node<T> *toRemove = tail->prev;
    if (!temp) {
      cout << "List is empty" << endl;
      return;
    }
    tail->prev = temp;
    temp->next = tail;
    delete toRemove;
  };
  void removeWaypointAtIndex(int index) {
    Node<T> *curr = head;
    if (index < 0) {
      cout << "Index out of bounds." << endl;
      return;
    }
    for (int i = 0; i < index; i++) {
      curr = curr->next;
      if (!curr->next || !curr->next->next) {
        cout << "Index out of bounds." << endl;
        return;
      }
    }
    Node<T> *temp = curr->next->next;
    Node<T> *toRemove = curr->next;
    curr->next = temp;
    temp->prev = curr;
    delete toRemove;
  };
  void traverseForward() {
    Node<T> *curr = head->next;
    while (curr->next) {
      cout << "Waypoint data: " << curr->data << endl;
      curr = curr->next;
    }
  };
  void traverseBackward() {
    Node<T> *curr = tail->prev;
    while (curr->prev) {
      cout << "Waypoint data: " << curr->data << endl;
      curr = curr->prev;
    }
  };
  Node<T> *getWaypoint(int index) {
    Node<T> *curr = head->next;
    if (index < 0) {
      return NULL;
    } else {
      for (int i = 0; i < index; i++) {
        curr = curr->next;
        if (!curr->next) {
          return NULL;
        }
      }
      return curr;
    }
  };
  void setWaypoint(int index, T &data) {
    Node<T> *curr = head->next;
    if (index < 0) {
      cout << "Index out of bounds." << endl;
    } else {
      for (int i = 0; i < index; i++) {
        curr = curr->next;
        if (!curr->next) {
          cout << "Index out of bounds." << endl;
          return;
        }
      }
      curr->data = data;
    }
  };
  void print() {

    Node<T> *curr = head->next;
    while (curr->next != nullptr) {
      curr->print();
      curr = curr->next;
    }
    cout << endl;
  }
};
