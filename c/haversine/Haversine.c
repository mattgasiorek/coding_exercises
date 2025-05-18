/*
 * Project Name: Haversine Formula Visualizer
 * Author: Matthew Gasiorek
 * Created On: 2025-05-09
 * Last Modified: 2025-05-18
 * Description: I want this to be a fun, introductory project where I can learn the basics of C and a cool math concept that I learned.
 * The Haversine Formula determines the great-cicle distance between two points on a sphere given their longitudes and latitudes.
 * This is especially important in navigation, where one might want to know the approximate distance between two points on Earth.
 * Version: 1.1
 * Contact: matthew.gasiorek.coding@gmail.com
 */

/*
The Haversine Formula is as follows:
(need to get this put in here for reference)
*/

#include <stdio.h> //included for input, output operations like printing
#include <math.h> //included for math operations, specifically trigonometry functions like sin, cos, asin, sqrt

#define PI 3.14159265358979323846 //defining pi
#define EARTH_RADIUS_KM 6371.0 //defining the radius of the Earth in KM.

/*
Converting degrees to radians function. 
We do this because radians relate directly to the length of an arc on a circle.
We can also use radians with sin(x) and cos(x) easier, which we will need for the Haversine formula 
*/
double degreesToRadians(double degrees)
{
    return degrees * PI / 180.0;
}



int main() 
{

//Step 1: Store the latitude and longitude of 2 coordinates from user input

    //We declare 4 variables for latitude and longitude of each coordinate.
    double lat1_deg, lon1_deg, lat2_deg, lon2_deg; 
    
    //printf displays the text in quotes in the console
    //scanf reads data, interprets it according to format and stores the results into given locations
    //in this instance, "%lf" means double data type, then it's storing the result in the memory location of variable, lat1_deg
    do
    {
        printf("Enter the latitude of the first point in degrees:");
        scanf("%lf", &lat1_deg);
            //check if the latitude falls between -90 and 90 degrees
            if(lat1_deg < -90.0 || lat1_deg > 90.0)
            {
                printf("Latitude must be between -90 and 90 degrees.\n");
            }
    } while (lat1_deg < -90.0 || lat1_deg > 90.0);

    do
    {
        printf("Enter the longitude of the first point in degrees:");
        scanf("%lf", &lon1_deg);
            //check if the longitude falls between -180 and 180 degrees
            if(lon1_deg < -180.0 || lon1_deg > 180.0)
            {
                printf("Longitude must be between -180 and 180 degrees.\n");
            }
    } while (lon1_deg < -180.0 || lon1_deg > 180.0);

    do
    {
        printf("Enter the latitude of the second point in degrees:");
        scanf("%lf", &lat2_deg);
            
            if(lat2_deg < -90.0 || lat2_deg > 90.0)
            {
                printf("Latitude must be between -90 and 90 degrees.\n");
            }
    } while (lat2_deg < -90.0 || lat2_deg > 90.0);
    
    do
    {
        printf("Enter the latitude of the second point in degrees:");
        scanf("%lf", &lon2_deg);
            
            if(lon2_deg < -180.0 || lon2_deg > 180.0)
            {
                printf("Longitude must be between -180 and 180 degrees.\n");
            }
    } while (lon2_deg < -180.0 || lon2_deg > 180.0);
        
        
    //Step 2: Convert the latitude and longitude of both coordinates to radians

    //We declare 4 new variables for our radians of the 2 coordinates latitude and longitude and then we use our degreesToRadians function to convert our degree variables
    double lat1_rad = degreesToRadians(lat1_deg);
    double lon1_rad = degreesToRadians(lon1_deg);
    double lat2_rad = degreesToRadians(lat2_deg);
    double lon2_rad = degreesToRadians(lon2_deg);

//Step 3: Now that we have the radians of the coordinates, we need to ipmlement the Haversine Formula.
    
    //We start with finding the difference (or delta) in latitudes and longitudes in radians and declaring two more variables to store them. 
    double diff_lat = lat2_rad - lat1_rad;
    double diff_lon = lon2_rad - lon1_rad;


    double a = pow(sin(diff_lat / 2.0), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(diff_lon / 2.0), 2);
    double c = 2 * asin(sqrt(a));
    double distance = EARTH_RADIUS_KM * c;

    //this printf function is printing out the string "The great-circle distance...is:", 
    //%.2f means floating point number with 2 decimal places, 
    //"km" is more text, \n is a new line, then "distance" is the variable to put in the position of %.2f
    printf("For the two coordinates, (%f,%f) and (%f,%f),\nthe great-circle distance between the two points is: %.2f km\n", lat1_deg, lon1_deg, lat2_deg, lon2_deg, distance);

    return 0;
}