//Nathaniel Goldammer
/**
 * \file traveling.cpp
 * \date April 27, 2022
**/
#include "middleearth.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

//Driver
int main(int argc, char** argv) 
{
    // check the number of parameters
    if (argc != 6) 
    {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> " << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    //TODO: YOUR CODE HERE

    //Sort each destination after dests[0]
    sort(dests.begin() + 1, dests.end());

    //Let mindistance = the distance of the current permutation
    float mindistance = computeDistance(me, dests[0], dests);

    //Let path = the current least costly path to every destination
    vector<string> path = dests;

    //While dests hasn't been permuted dests.size()! times
    do
    {
        //If dests's current permutation has a shorter distance than mindistance
        if(computeDistance(me, dests[0], dests) < mindistance)
        {
            //Let mindistance = the distance of dests's current permutation
            mindistance = computeDistance(me, dests[0], dests);

            //Let path = the current permutation of dests
            path = dests;
        }
        
    }while(next_permutation(dests.begin() + 1 , dests.end()) == true);

    //Display the least costly path and it's corrsponding distance
    cout << "Minimum path has distance " << mindistance << ": ";
    printRoute(dests[0], path);

    //End of main
    return 0;
}

/**
 * @brief Computes the full distance of the cycle in order
 * @param me The MiddleEarth object
 * @param start The starting city of the cycle
 * @param dests The destinations to be visited
**/
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) 
{
    //TODO: YOUR CODE HERE

    //Let distance = the full distance of the cycle
    float distance = 0.0;

    //Increment distance by the distance from the start city to the first destination
    distance = distance + me.getDistance(start, dests[0]);

    //For each destination after the first destination
    for(int i = 1; i < dests.size(); i++)
    {
        //Increment distance by the distance from the destination to the next destination
        distance = distance + me.getDistance(dests[i - 1], dests[i]);

        //If i + 1 == the number of destinations
        if(i + 1 == dests.size())
        {
            //Increment distance by the distance from the last destination to the start city
            distance = distance + me.getDistance(dests[i], start);
        } 
    }

    //Return the total distance of the cycle
    return distance;
}

/**
 * @brief Prints the entire route.
 * @param start The route's starting city
 * @param dests The destinations to be visited.
**/
void printRoute(const string& start, const vector<string>& dests) 
{
    //TODO: YOUR CODE HERE

    //For each destination in dests
    for(int i = 0; i < dests.size(); i++)
    {
        //Print the destination
        cout << dests[i] << " -> "; 
    }

    //Print the starting city
    cout << start << endl;
}