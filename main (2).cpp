//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"

using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};

struct Node {
    Airport* data;
    Node* next;

    Node(Airport* data) {
        this->data = data;
        this->next = nullptr;
    }
};

void simpleSortTotal(Slist *s);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
double distanceAus(Airport *data) {
    return distanceEarth(data->latitude, data->longitude, 30.19449997, -97.66989899);
}

int main()
{
    //cout<<"test";
    ifstream infile;
    int i=0;
    char cNum[10] ;
    //Airport* airportArr[13500];			// Replace array with Linked List
    Slist * airportList = new Slist();

    int   airportCount;
    //Airport* a[13500];
    //cout<<"test";
    infile.open ("USAirportCodes.txt", ifstream::in);
    if (infile.is_open())
    {

        //cout<<"test";
        int   c=0;
        while (infile.good())
        {
            Airport * port = new Airport();
            infile.getline(port->code, 256, ',');
            infile.getline(cNum, 256, ',');
            port->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            port->latitude = atof(cNum);
            //Node* current = new Node();
            //current->data = port;
            //current->next = nullptr;
            //airportList->head = (current);
            airportList->insert(c,port);
            //airportList->add(port);

            //return 0;
            //cout<<"test";

            if (!(c % 1000))
                cout << (*airportList).get(c)->code << " long: " << (*airportList).get(c)->longitude << " lat: " << (*airportList).get(c)->latitude <<  endl;
                //cout << airportList->get(c) <<  endl;

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
    Airport *furthestAirport;
    for (int i = 0; i < airportList->size(); i++) {
      Airport *currentAirport = airportList->get(i);
      double maxDistance = 0.0;
      double distance = distanceAus(currentAirport);
      if (distance > maxDistance) {
        maxDistance = distance;
        furthestAirport = currentAirport;
      }
    }
    cout << "Farthest airport from Austin-Bergstorm International airport is: "
         << furthestAirport->code << "  " << distanceAus(furthestAirport)
         << " miles away" << endl;
    for (int i = 0; i < airportList->size(); i++) {
      Airport *currentAirport = airportList->get(i);
      double maxDistance = 100.0;
      double distance = distanceAus(currentAirport);
      if (distance <= maxDistance) {
        cout << currentAirport->code
             << " Distance: " << distanceAus(currentAirport) << " miles."
             << endl;
      }
    }
    
        
        /* for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << (*airportList).get(c)->code << " long: " << (*airportList).get(c)->longitude << " lat: " << (*airportList).get(c)->latitude <<  endl;
                cout << (*airportList).get(c+1)->code << " long: " << (*airportList).get(c+1)->longitude << " lat: " << (*airportList).get(c+1)->latitude <<  endl;
                cout <<"Distance between " << (*airportList).get(c)->code << " and " << (*airportList).get(c+1)->code << " is "
                  << distanceEarth((*airportList).get(c)->longitude, (*airportList).get(c)->latitude ,(*airportList).get(c+1)->longitude, (*airportList).get(c+1)->latitude) << endl;
            }
        */
        free(airportList);
    }
    else
    {
        cout << "Error opening file";
    }
 


    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/

void simpleSortTotal(Slist* airList)
{
 
}

