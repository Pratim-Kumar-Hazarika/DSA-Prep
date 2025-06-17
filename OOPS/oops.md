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
