#include <iostream>
#include <string>
#include <cmath>


using namespace std;


struct Vector{
    double x;
    double y;
    double z;
};

Vector generate_vector(double x, double y, double z){
    Vector h;
    h.x = x;
    h.y = y;
    h.z = z;
    return h;
}

void show(Vector v1){
    string s;
    s = "<" + to_string(v1.x) + "," + to_string(v1.y) + "," + to_string(v1.z) + ">";
    cout << s << endl;
}


void normalize(Vector v1){
    Vector i;
    double magnitude;
    magnitude = sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
    i.x = v1.x / magnitude;
    i.y = v1.y / magnitude;
    i.z = v1.z / magnitude;
    show(i);
}


void dot_product(Vector v1, Vector v2){
    double result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z + v2.z);
    cout << result << endl;
}

void const_multiply(int x,Vector *v1){
    v1->x = x*(v1->x);
    v1->y = x*(v1->y);
    v1->z = x*(v1->z);

    show(*v1);
}


void cross_product(const Vector *v1,const Vector *v2){
    Vector z;
    z.x = (v1->y * v2->z) - (v1->z * v2->y);
    z.y = (v1->z * v2->x) - (v1->x * v2->z);
    z.z = (v1->x * v2->y) - (v1->y * v2->x);

    show(z);
}

void add(const Vector *v1,const Vector *v2){
    Vector w;
    w.x = v1->x + v2->x;
    w.y = v1->y + v2->y;
    w.z  = v1->z + v2->z;

    show(w);
}


int main(){
    Vector v1;
    Vector v2;

    v1 = generate_vector(1,2,3);
    v2 = generate_vector(4,-5,8);

    show(v1);
    show(v2);
    normalize(v1);
    dot_product(v1, v2);
    const_multiply(5, &v1);
    cross_product(&v1, &v2);
    add(&v1, &v2);
    return 0;

}







