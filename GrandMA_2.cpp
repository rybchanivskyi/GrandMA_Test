#include<iostream>
#include<stdalign.h>
#include<time.h>
using namespace std;

int main() {
    int frame_width, frame_height, pic_width, pic_height, pic_x, pic_y, temp;
    cout << "Enter the height of the frame : ";
    cin >> frame_height;
    cout << "\nEnter the width of the frame : ";
    cin >> frame_width;
    cout << "\nEnter the height of the picture : ";
    cin >> pic_height;
    cout << "\nEnter the width of the picture: ";
    cin >> pic_width;
    cout << "\nEnter x of the picture: ";
    cin >> pic_x;
    cout << "\nEnter y of the picture: ";
    cin >> pic_y;

    srand(time(NULL));
    if ((pic_x < 0 || pic_y < 0) || (pic_x >= frame_width || pic_y >= frame_height)
        || (pic_width + pic_x > frame_width || pic_height + pic_y > frame_height)) {
        cout << "\nError data!!!";
        return 0;
    }
    int matrix[frame_height][frame_width];
    cout<<"\nInitial matrix:\n";
    for (int i = 0; i < frame_height; ++i) {
        for (int j = 0; j < frame_width; ++j) {
            matrix[i][j] = rand();
            cout<<matrix[i][j]<< ' ';
        }
        cout<<'\n';
    }
    for (int i = 0; i < pic_height; ++i) {
        for (int j = 0; j < pic_width; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i + pic_y][j + pic_x];
            matrix[i + pic_y][j + pic_x] = temp;
        }
    }
    cout << "\nFinal matrix : \n";
    for (int i = 0; i < frame_height; ++i) {
        for (int j = 0; j < frame_width; ++j) {
            cout<<matrix[i][j]<< ' ';
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}
