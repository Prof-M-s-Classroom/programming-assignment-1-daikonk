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
  SpaceRoute();  // Constructor
  ~SpaceRoute(); // Destructor

  void addWaypointAtBeginning(T &data) {
    Node newNode = Node(data);
    Node temp = head->next;
    head->next = newNode;
    newNode->prev = head;
    newNode->next = temp;
    temp->prev = newNode;
  };
  void addWaypointAtEnd(T &data) {
    Node newNode = Node(data);
    Node temp = tail->prev;
    tail->prev = newNode;
    newNode->next = tail;
    newNode->prev = temp;
    temp->next = newNode;
  };
  void addWaypointAtIndex(int index, T &data) {
    Node curr = head->next;
    if (index == 0) {
      addWaypointAtBeginning(data);
    } else if (index < 0) {
      cout << "Index out of bounds." << endl;
    } else {
      for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (!curr->next) {
          cout << "Index out of bounds." << endl;
          return;
        }
      }
      Node newNode = Node(data);
      Node temp = curr->next;
      curr->next = newNode;
      newNode->prev = curr;
      newNode->next = temp;
      temp->prev = newNode;
    }
  };
  void removeWaypointAtBeginning() {
    Node temp = head->next->next;
    head->next = temp;
    temp->prev = head;
  };
  void removeWaypointAtEnd() {
    Node temp = tail->prev->prev;
    tail->prev = temp;
    temp->next = tail;
  };
  void removeWaypointAtIndex(int index) {
    Node curr = head->next;
    if (index == 0) {
      removeWaypointAtBeginning();
    } else if (index < 0) {
      cout << "Index out of bounds." << endl;
    } else {
      for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (!curr->next) {
          cout << "Index out of bounds." << endl;
          return;
        }
      }
      Node temp = curr->next->next;
      curr->next = temp;
      temp->prev = curr;
    }
  };
  void traverseForward() {
    Node curr = head;
    while (curr->next) {
      cout << "Waypoint data: " << curr->data << endl;
      curr = curr->next;
    }
  };
  void traverseBackward() {
    Node curr = tail;
    while (curr->prev) {
      cout << "Waypoint data: " << curr->data << endl;
      curr = curr->prev;
    }
  };
  Node<T> *getWaypoint(int index) {
    Node curr = head->next;
    if (index < 0) {
      cout << "Index out of bounds." << endl;
      return NULL;
    } else {
      for (int i = 0; i < index; i++) {
        curr = curr->next;
        if (!curr->next) {
          cout << "Index out of bounds." << endl;
          return NULL;
        }
      }
      return curr;
    }
  };
  void setWaypoint(int index, T &data) {
    Node curr = head->next;
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

    Node<T> *current = head;
    while (current) {
      current->print();
      current = current->next;
    }
    cout << endl;
  }
};
