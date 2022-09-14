#include <iostream>
#include <cmath>

struct Point
{
    double x;
    double y;
    double lenToCenter;
    double lenBetweenPonts;

    
};
Point inputCoordinates();
Point inputCoordinates()
{   
    Point p;
    std::cout<<"Input x and y: ";
    std::cin>>p.x>>p.y;
    return p;
}
void outputCoordinates(Point p)
{
    std::cout<<"x: "<< p.x<<" and y: "<<p.y<<std::endl;
}

double lenghtToCenter(double x, double y)
{
    return sqrt((pow(x,2)+pow(y,2)));
}

double lenghtBetweenPoints(double x1, double y1, double x2, double y2)
{
     return sqrt(pow((abs(x1)+abs(x2)),2) + pow((abs(y1)+abs(y2)),2));
}
int main()
{
    struct Point p1;
    struct Point p2;

    p1 = inputCoordinates();
    p2 = inputCoordinates();

    outputCoordinates(p1);
    outputCoordinates(p2);

    p1.lenToCenter = lenghtToCenter(p1.x, p1.y);
    p2.lenToCenter = lenghtToCenter(p2.x, p2.y);

    p1.lenBetweenPonts = lenghtBetweenPoints(p1.x, p1.y,p2.x, p2.y);

    std::cout<<"Len to center p1: "<<p1.lenToCenter<<" Len to center p2: "<<p2.lenToCenter<<" Len between points: "<<p1.lenBetweenPonts<<std::endl;
    return 0;

}