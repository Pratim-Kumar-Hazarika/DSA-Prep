Classes & Objects

objects are entities in the real world

class is like a blueprint of these entities

--Students in a class
------students are objects
------class is blueprint

Access Modifieres

1. private
   data & methods accesible inside class
   byDefault its private
2. public
   data & methods accesible outside class
3. protected
   data & methods accessible inside class & to its derived class

Pillars of OOPS

1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphism

What is Encapsulation ?
Imagine a capsule with (data/properties + memeber functions) = class.
Wrapping up data & member functions in a single unit called class
Helps in data hiding also. By using private;

class Account {
--private:
------double balance;
------string password;
---public:
-----string accountId;
-----string userName;
}

Constructor
Sepcial method called during object creation and can be used for initialization.
Memory allocation happens when constructor is called.

class Teacher {

---int x;
----Teacher(){ // non-parameterised constructor
----------x = 1; // allocates memory
------cout << "Constructor called" << endl;
-----}

----Teacher(int val){ // parameterised constructor
----------x = val; // allocates memory
-----}

---void getInfo(){
-------cout << x << endl;
----}

}

Teacher T1(10) // Can be called like this
T1.getInfo()/// prints 10

Constructor overloading is a example of polymorphism.

this is a special pointer in c++ that points to the current object;

Copy Constructor
Teacher t1("Pratim","Cs","ML");

Teacher t2(t1); // default copy constructor -invoke

Shallow Copy & deep Copy
A shallow copy of an object copies all the memeber values from one object to another

Destructor opp of constructor
It deallcoates the memory ( dynamic memory created with new keyword)

Inheritance
ClassA -> passing properties to -> Class B
ClassA ( Parent, Base)
Class B ( Child , Derived)
Base class constructor called first then child class constructor called

Polymorphism
Poly means multiple
morph means forms
multiple-forms

1. Compile Time Polymorphism ex :
   1. Constructor Overloading
   2. Function Overloading
      a. When we are defining two functions within the same class with same name but different params
      `class Print {
    public:
        void show(int x){
            cout << "int : " << x << endl;
        }
        void show(char ch){
            cout <<"ch :" << ch << endl;
        }
};`
2. Run time Polymorphism
   1. Function Overriding ( Inheritance)
      a. Parent & child both contain the same function with diff implementation. The parent class function is said to be overriden.

````
class A {
    public:
        void getInfo(){
            cout << "parent class A" << endl;
        }
};

class B : public A {
    public:
        void getInfo(){
            cout << "child class B" << endl;
        }
};```
````

2. Virtual Functions : A virtual function is a member fn that you except to be redefiend in derived class

Abstraction : Hiding all unncesaary details & showing only the imp parts
private , protected , public. It is like a template for derived classes

``class Shape {
draw()
}
class Circle : public Shape {
draw(){
///
}
}

Static Keyword

````void fun(){
    static int x = 0; // it will create memory once
    cout <<"x :" << x << endl;
    x++;
}```
````
