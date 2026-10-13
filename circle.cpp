#include<iostream>
using namespace std;

class Circle
{
    protected:
    float x , y , r , area;

    public:
    Circle(float a , float b , float rad): x(a) , y(b) , r(rad) , area(0){}

    virtual void show_data()
    {
        get_area();
        cout<<"Coordinates: ("<<x<<","<<y<<")\nRadius: "<<r<<"\nArea: "<<area<<endl;
    }

    virtual float get_area()
    {
        area = 3.14*r*r;
        return area;
    }

};

class Cylinder: public Circle
{
    float h;

    public:
    Cylinder(float a , float b , float rad , float hight): Circle(a , b , rad) , h(hight){}

    void show_data() override
    {
        Circle::show_data();
        cout<<"Hight: "<<h<<endl;
    }

    float get_area() override
    {
        area = (2*3.14*r*r) + (2*3.14*r*h);
        return area;
    }

};

int main()
{
    Circle *c[5];
    float x , y , rad , h;
    char ch;
    for(int i=0 ; i<5 ; i++)
    {

       while(true)
       {
        cout<<"Enter 'A' for Circle or 'B' for Cylinder: "; cin>>ch;
        if(ch >= 'a' && ch <= 'z') ch -= 32;

        if(ch == 'A')
        {
        cout<<"Enter x: "; cin>>x;
        cout<<"Enter y: "; cin>>y;
        cout<<"Enter radius: "; cin>>rad; 
        c[i] = new Circle(x , y , rad);
        break;
        }
        else if(ch == 'B')
        {
        cout<<"Enter x: "; cin>>x;
        cout<<"Enter y: "; cin>>y;
        cout<<"Enter Radius: "; cin>>rad; 
        cout<<"Enter Hight: "; cin>>h;
        c[i] = new Cylinder(x , y , rad , h);
        break;
        }
        else cout<<"Enter 'A' or 'B' only!!\n";
        }
    }
    for(int i=0 ; i<5 ; i++)
    {
        c[i]->show_data();
        cout<<"--------------\n";
    }
   
}