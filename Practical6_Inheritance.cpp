#include <iostream>
#include <string>
using namespace std;

// 1. SINGLE INHERITANCE
class Person {
protected:
    string name;
public:
    void setPersonName(string n) {
        name = n;
    }
};

class Student : public Person {
private:
    int rollNo;
public:
    void setStudentDetails(string n, int r) {
        setPersonName(n);
        rollNo = r;
    }

    void displayStudent() {
        cout << "Name    : " << name << endl;
        cout << "Roll No : " << rollNo << endl;
    }
};

// 2. MULTILEVEL INHERITANCE
class Grandparent {
public:
    void showGrandparent() {
        cout << "Grandparent class method" << endl;
    }
};

class Parent : public Grandparent {
public:
    void showParent() {
        cout << "Parent class method" << endl;
    }
};

class Child : public Parent {
public:
    void showChild() {
        cout << "Child class method" << endl;
    }
};

// 3. MULTIPLE INHERITANCE
class Academic {
protected:
    int marks;
public:
    void setMarks(int m) {
        marks = m;
    }
};

class Sports {
protected:
    int sportsScore;
public:
    void setSportsScore(int s) {
        sportsScore = s;
    }
};

class Result : public Academic, public Sports {
public:
    void displayResult() {
        cout << "Academic marks : " << marks << endl;
        cout << "Sports score   : " << sportsScore << endl;
        cout << "Total score    : " << marks + sportsScore << endl;
    }
};

// 4. HIERARCHICAL INHERITANCE
class Shape {
protected:
    double value;
public:
    void setValue(double v) {
        value = v;
    }
};

class Circle : public Shape {
public:
    void displayArea() {
        cout << "Area of circle : " << 3.14159 * value * value << endl;
    }
};

class Square : public Shape {
public:
    void displayArea() {
        cout << "Area of square : " << value * value << endl;
    }
};

// 5. HYBRID INHERITANCE
// Virtual inheritance prevents two copies of StudentInfo in TeachingAssistant.
class StudentInfo {
protected:
    int studentId;
public:
    void setStudentId(int id) {
        studentId = id;
    }
};

class Test : virtual public StudentInfo {
protected:
    int testMarks;
public:
    void setTestMarks(int m) {
        testMarks = m;
    }
};

class SportsActivity : virtual public StudentInfo {
protected:
    int activityScore;
public:
    void setActivityScore(int s) {
        activityScore = s;
    }
};

class TeachingAssistant : public Test, public SportsActivity {
public:
    void displayDetails() {
        cout << "Student ID        : " << studentId << endl;
        cout << "Test marks        : " << testMarks << endl;
        cout << "Activity score    : " << activityScore << endl;
        cout << "Combined score    : " << testMarks + activityScore << endl;
    }
};

int main() {
    cout << "========== PRACTICAL 6: TYPES OF INHERITANCE ==========" << endl;

    cout << "\n1. SINGLE INHERITANCE" << endl;
    Student s;
    s.setStudentDetails("Aarav", 101);
    s.displayStudent();

    cout << "\n2. MULTILEVEL INHERITANCE" << endl;
    Child c;
    c.showGrandparent();
    c.showParent();
    c.showChild();

    cout << "\n3. MULTIPLE INHERITANCE" << endl;
    Result r;
    r.setMarks(85);
    r.setSportsScore(10);
    r.displayResult();

    cout << "\n4. HIERARCHICAL INHERITANCE" << endl;
    Circle circle;
    circle.setValue(5);
    circle.displayArea();

    Square square;
    square.setValue(4);
    square.displayArea();

    cout << "\n5. HYBRID INHERITANCE" << endl;
    TeachingAssistant ta;
    ta.setStudentId(202);
    ta.setTestMarks(90);
    ta.setActivityScore(8);
    ta.displayDetails();

    cout << "\n========== END OF PROGRAM ==========" << endl;
    return 0;
}
