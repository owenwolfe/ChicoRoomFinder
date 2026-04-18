#include <iostream>
#include <fstream>
#include "json.hpp"
#include <vector>
#include <string>
#include <queue>

using json = nlohmann::json;

// forward declaration so we can use it in node
struct edge
{
  float distance;
  int destination; // may change from int to some other indentifier
};

// graph vertices; can be a classroom, bathroom, elevator, stairs, water fountain, etc.
                            // anything inside the building that is a point of interest
struct node
{
  int roomNumber;
  std::string name;
  std::string type;
  int id;
  float x;
  float y;
  bool accessible;
  bool publicAccess;
  int floorNumber;
  std::vector<edge> neighbors;
};

// each floor has a graph; a vector of nodes
struct floorPlan
{
  int number;
  std::vector<node> rooms;
};

// each building has a vector of floors
struct building
{
  std::string name;
  std::vector<floorPlan> floors;
};

// the campus has a vector of buildings
struct campus
{
  std::vector<building> buildings;
}; 

// load nodes on desired floor in desired building from json file generated from web scraper
floorPlan loadFloor(const std::string& fileName, const std::string& buildingName)
{
  std::ifstream file(fileName); //example json load
  if(!file)
  {
    std::cerr << "No file found";
    std::exit(-1);
  }

  json data;
  file >> data;

  node poi;

  floorPlan floor;

  floor.rooms.push_back(poi);

  return floor;
}

// load all files, put into vector, and send to loadFloor per building
campus loadCampus(const std::vector<std::string>& files)
{
  campus campusMap;
  // _campus.buildings.push_back(files[1]);

  return campusMap;
}

// djikstras; generate shortest path to desired POI
void findPath(const building& desiredBuilding, const node& startPoint)
{

}

// overload of djikstras in case student is already inside the building
void findPath(const floorPlan& floor, const node& startPoint)
{

}





// May not use these functions
//
// // after creating node, add that node to respective floor
// void addNodeToFloor(const node& poi, const floorPlan& floor);
//
// // after creating floor plan, add that floor to respective building
// void addFloorToBuilding(const floorPlan& floorPlan, const std::string& building); // use switch?
//
// // after adding all floors to a building, add building to campus
// void addBuildingToCampus(const building& building);
//





int main()
{

  return 0;
}
