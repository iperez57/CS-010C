#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    void SetName(string courseName) {
        name = courseName;
    }
    void SetClassSize(int courseClassSize) {
        classSize = courseClassSize;
    }
    void Print() const {
        cout << name << ". Class size: " << classSize << endl;
    }

private:
    string name;
    int classSize;
};


int main() {
    Course favoriteCourse;

    favoriteCourse.SetName("World History");
    favoriteCourse.SetClassSize(165);

    favoriteCourse.Print();

    return 0;
}