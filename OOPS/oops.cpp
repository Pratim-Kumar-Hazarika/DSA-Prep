#include <iostream>
#include <string>
using namespace std;

class Teacher {
    private:
          double salary;
    public:
      
    //properties / attributes
    string name;
    string dept;
    string subject;
  
    // Teacher(){
    //     cout << "Constructor called" << endl;
    
    // }

    Teacher(string name, string dept, string subject){
          this->name = name;
          this->dept = dept;
          (*this).subject = subject;
    }

    //copy constructor
    Teacher(Teacher &originalObj){
        cout << "I am custom copy constructor" << endl;
        this->name = originalObj.name;
        this->dept = originalObj.dept;
        this->subject = originalObj.subject;
    }
    //methods / member functions
    void changeDept(string newDpt){
        dept = newDpt;
    }
    void setSalary(int s){
        salary = s;
    };
    int getSalary(int s){
       return salary;
    }
    void getInfo(){
        cout << this->name << endl;
        cout << this->dept << endl;
    }
};

class Student {
    public:
        string name;
        double cgpa;
        double* cgpaPtr;
    Student(string name ,double cgpa){
        this->name = name;
        this->cgpa = cgpa;
        cgpaPtr = new double; // First it points to a new memory in heap . It will have a memory address
        *cgpaPtr = cgpa;    /// deference and store the value at that memory address
    }
    Student(Student &obj){
       this->name = obj.name;
       this->cgpa = obj.cgpa;
       cgpaPtr = new double;
       *cgpaPtr = *obj.cgpaPtr;
    }
    void getInfo(){
        cout << "name : " << name << endl;
        // cout << "cgpa : " << cgpa << endl;
        cout << "cgpaPtr : " << *cgpaPtr << endl;
    }

    //destructor
    ~Student(){
        //Deletes dynamically allocated memoery ex : new double
        cout << "Hi, I delete everything" << endl;
        delete cgpaPtr;
    }
};
//Inheritance
class Person {
    public:
        string name;
        int age ;
    Person(string name, int age){
        this->name = name;
        this->age  = age;
    };
};

class Student1 : public Person {
public:
    int rollno;

    // Correct constructor syntax
    Student1(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
        cout << "Child constructor called" << endl;
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
    }
};
class Student2 : public Student1 {
    public:
        int research;
};



int main(){
    // Teacher t1("Pratim","Cs","ML"); 

    // Teacher t2(t1); // default copy constructor -invoke
    // t2.getInfo();
    
    // Student s1 ("Pratim kumar", 8.9);
    //    s1.getInfo();
    // Student s2(s1);

    // s1.getInfo();
    // *(s2.cgpaPtr) = 9.2;
    // s1.getInfo();
    // s2.name ="Priya";
    // s2.getInfo();
    Student1 s1("pratim",21,1234);
    s1.getInfo();
    cout << s1.name << endl;
    return 0;
}