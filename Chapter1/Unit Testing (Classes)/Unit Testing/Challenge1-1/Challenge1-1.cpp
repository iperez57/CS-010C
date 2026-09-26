#include <iostream>
using namespace std;

class Rectangle {
public:
    void SetSize(int heightVal, int widthVal) {
        height = heightVal;
        width = widthVal;
    }
    int GetArea() const;
    int GetPerimeter() const;

private:
    int height;
    int width;
};

int Rectangle::GetArea() const {
    return height * width;
}

int Rectangle::GetPerimeter() const {
    return (height * 2) * (width * 2);
}

int main() {
    Rectangle myRectangle;

    myRectangle.SetSize(1, 1);
    if (myRectangle.GetArea() != 1) {
        cout << "FAILED GetArea() for 1, 1" << endl;
    }
    if (myRectangle.GetPerimeter() != 4) {
        cout << "FAILED GetPerimeter() for 1, 1" << endl;
    }

    myRectangle.SetSize(2, 3);
    if (myRectangle.GetArea() != 6) {
        cout << "FAILED GetArea() for 2, 3" << endl;
    }
    if (myRectangle.GetPerimeter() != 10) {
        cout << "FAILED GetPerimeter() for 2, 3" << endl;
    }

    return 0;
}