#include <iostream>
using namespace std;

class sensor_output {
    private:
        float distance;
    public:
    void readData() {
        float in_distance;
        while (true) {
            cout << "enter distance in cm:" << endl;
            cin >> in_distance;
            if (!cin.fail() && in_distance >= 0) {
                distance = in_distance;
                break;
            }
            else {
                cout << "Invalid input. Please enter valid distance." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
    }
    public:
    float getDistance() {
        return distance;
    }
};

class RaONE_Brain {
    public: void data_process() {
        sensor_output values;
        values.readData();
        float distance = values.getDistance();
        if (distance < 20) {
            cout << "Obstacle detected! Stopping the robot." << endl;
        }
        else if (distance >= 20 && distance < 50) {
            cout << "Obstacle detected! Slowing down the robot." << endl;
        }
        else {
            cout << "No obstacles detected. Robot is moving at normal speed." << endl;
        }

        cout << "----------------" << endl;

        }
};

int main() {
    RaONE_Brain brain;

    while (true) {
        brain.data_process();
    }
}
