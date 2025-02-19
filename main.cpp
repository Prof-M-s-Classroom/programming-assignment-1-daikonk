#include "SpaceRoute.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  string mars = "Mars";
  string jupiter = "Jupiter";
  string saturn = "Saturn";
  string earth = "Earth";
  string venus = "Venus";
  string arrakis = "Arrakis";

  SpaceRoute<string> voyagerRoute;

  voyagerRoute.addWaypointAtEnd(mars);
  voyagerRoute.addWaypointAtEnd(jupiter);
  voyagerRoute.addWaypointAtEnd(saturn);
  voyagerRoute.addWaypointAtBeginning(earth);
  voyagerRoute.addWaypointAtIndex(2, venus);

  cout << "Voyager Route (Forward):\n";
  voyagerRoute.traverseForward();

  cout << "\nVoyager Route (Backward):\n";
  voyagerRoute.traverseBackward();

  cout << "\nPrinting Route: \n";
  voyagerRoute.print();

  voyagerRoute.removeWaypointAtIndex(2);
  cout << "\nAfter Removing Venus: \n";
  voyagerRoute.print();

  cout << "\nRemoving at 4, -1, Adding at 5, -1\n";
  voyagerRoute.removeWaypointAtIndex(4);
  voyagerRoute.removeWaypointAtIndex(-1);
  voyagerRoute.addWaypointAtIndex(5, mars);
  voyagerRoute.addWaypointAtIndex(-1, mars);

  cout << "\nAdding and removing at 0 and 4\n";
  voyagerRoute.addWaypointAtIndex(0, mars);
  voyagerRoute.print();
  voyagerRoute.removeWaypointAtIndex(0);
  voyagerRoute.print();
  voyagerRoute.addWaypointAtIndex(4, mars);
  voyagerRoute.print();
  voyagerRoute.removeWaypointAtIndex(4);
  voyagerRoute.print();

  cout << "\nLoop using getWaypoint" << endl;
  int i = 0;
  while (voyagerRoute.getWaypoint(i)) {
    cout << voyagerRoute.getWaypoint(i)->data << endl;
    i++;
  }

  cout << "\nLoop using setWaypoint to set all to Arrakis" << endl;
  i = 0;
  while (voyagerRoute.getWaypoint(i)) {
    voyagerRoute.setWaypoint(i, arrakis);
    i++;
  }
  voyagerRoute.traverseForward();

  return 0;
}
