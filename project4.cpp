#include <iostream>
#include <string>
#include <cmath>


using namespace std;

class LineSegment{
private:
    double m;
    double y_intercept;
    double points[4];

public:
    double getSlope();
    double getYIntercept();
    friend double getSegmentLength(LineSegment *A);
    friend LineSegment getLongerSegment(LineSegment A, LineSegment B);
    friend string show(LineSegment A);
    LineSegment operator+(LineSegment other);

    LineSegment(double a, double b, double c, double d){
        *(points+0) = a;
        *(points+1) = b;
        *(points+2) = c;
        *(points+3) = d;

        double first = points[3] - points[1];
        double second = points[2] - points[0];
        m = first / second;

        y_intercept = points[1] - m * points[0];


    }
};
string show(LineSegment A) {
    string s = "LineSegment between points (" + to_string(A.points[0]) + "," + to_string(A.points[1]) + ")" + " and " + "(" + to_string(A.points[2]) + "," + to_string(A.points[3]) +  ").";

    return s;
}

double LineSegment::getSlope(){
    return m;
}

double LineSegment::getYIntercept(){
    return y_intercept;
}


double getSegmentLength(LineSegment *A){
    double firstsquare = pow( (*A).points[3] - (*A).points[1], 2);
    double secondsquare = pow( (*A).points[2] - (*A).points[0], 2);
    double square = sqrt(firstsquare + secondsquare);
    return square;
}


LineSegment getLongerSegment(LineSegment A, LineSegment B) {
    double m = getSegmentLength(&A);
    double n = getSegmentLength(&B);

    if (m > n) {
        return A;
    } else{
        return B;
    }



}

LineSegment LineSegment::operator+(LineSegment other) {
    LineSegment ret (points[0] + other.points[0], points[1] + other.points[1], points[2] + other.points[2], points[3] + other.points[3]);
    return ret;
}



int main(){
    LineSegment A(2,8,4,9);
    LineSegment B(3,11,6,21);
    cout << show(A) << endl;
    cout << show(B) << endl;
    cout << A.getSlope() << endl;
    cout << B.getYIntercept() << endl;
    cout << getSegmentLength(&A) << endl;
    cout << show(getLongerSegment(A, B)) << endl;
    cout << show(A+B) << endl;
    return 0;

}





