#include "std_lib_facilities.h"

struct Point {
    Point();
    Point(int x1, int y1) {x = x1; y = y1;}
    int x;
    int y;
};

Point::Point() {
    x = 0; y = 0;
}

ostream& operator << (ostream& os, const Point p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator >> (istream& is, Point& p)
{
    char ch1,ch2,ch3;
    int x, y;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }
    p = Point{x, y};
    return is;
}

int main() {
    cout << "Please enter 7 (x,y) pairs in the form x y:\n";
    int x,y;
    vector<Point> original_points;
    for (int i = 0; i < 7; ++i) {
        cin >> x >> y;
        Point p = Point{x,y};
        original_points.push_back(p);
    }

    ofstream ost {"mydata.txt"};
    if (!ost) error("Can't open output file");
    for (int i = 0; i < original_points.size(); ++i) {
        ost << original_points[i] << endl;
    }

    ifstream ist {"mydata.txt"};
    if (!ist) error("Can't open input file");
    vector<Point> new_points;
    for (Point p; ist >> p; ) {
        new_points.push_back(p); 
    }
    
    cout << "New points vector!:\n";
    for (int i = 0; i < new_points.size(); ++i) {
        cout << new_points[i] << endl;
    }
}

