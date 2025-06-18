#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string title;
        int age;
};
class Student :virtual public Person{
    public:
        string name;
        int rollno;
};

class Teacher : virtual public Person{
    public:
        string subject;
        double salary;
};

class TA : public Student, public Teacher{

};



class Something {
    public:
         string name;
    Something(){
        cout << "non-paremeterixed" << endl;
    }
    Something(int val){
        name = val;
         cout << "paremeterixed" << endl;
    }

};

class Print {
    public:
        void show(int x){
            cout << "int : " << x << endl;
        }
        void show(char ch){
            cout <<"ch :" << ch << endl;
        }
};

class A {
    public:
        void getInfo(){
            cout << "parent class A" << endl;
        }
    virtual void hello(){
        cout << "Hlelo from a" << endl;
    }
};

class B : public A {
    public:
        void getInfo(){
            cout << "child class B" << endl;
        } 
        void hello(){
        cout << "Hlelo from B" << endl; // Called during runtime
    }
};

class Shape {
    virtual void draw() = 0; //pure virtual function
};
class Circle : public Shape {
    public:
        void draw(){
            cout << "Draw circle" << endl;
        }
};

void fun(){
    static int x = 0;
    cout <<"x :" << x << endl;
    x++;
}

class AA {
    public :
       static int x ;
    void incX(){
        x = x+1;
    }
};
int main(){
    // TA t1;
    // t1.title ="Iron man";
    // t1.name ="Tony";
    // t1.subject = "engineering";
    // cout << t1.name << endl;
    // cout << t1.subject << endl;

    // Print p1;
    // p1.show(1);
    // p1.show('&');
    // B c1;
    // c1.getInfo();
    // c1.hello();
    // Circle s1;
    // s1.draw();
    // fun();
    //   fun();
    //     fun();
   AA obj;
    AA obj2;

    obj.x = 0;  // or AA::x = 0;
    cout << obj.x << endl;  // Output: 0

    obj.incX();  // x = 1
    obj2.incX(); // x = 2

    cout << obj.x << endl;  // Output: 2 (shared across all objects)
    return 0;
}