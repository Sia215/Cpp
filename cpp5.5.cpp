/*
A team of developers is tasked with building a temperature conversion system for a weather
application. To achieve this, the team creates two classes: Celsius and Fahrenheit. These classes
handle the conversion between temperature units, with the ability to convert from Celsius to
Fahrenheit and vice versa using type conversion. The team utilizes operator overloading to define the
conversion operators for both classes, enabling seamless conversions between the two units.
The system also requires the ability to compare two temperature objects to check if they are equal.
This is achieved by overloading the equality operator ==, which compares the values of the
temperatures in their respective units.
To ensure smooth processing of temperature conversions, the team needs to manage and store
multiple converted temperature objects. Two approaches are considered for handling this task. The
first approach involves using a dynamic data structure, a queue, to process the conversions in a first
in-first-out (FIFO) manner. Alternatively, a basic array is used to store the converted objects in a static
manner.
*/

#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    double tempC;

public:
    // Constructor
    Celsius(double t = 0.0) : tempC(t) {}

    // Type conversion to Fahrenheit
    operator Fahrenheit();

    // Overload == to compare two Celsius objects
    bool operator==(const Celsius& other) const {
        return tempC == other.tempC;
    }

    // Accessor
    double getTemp() const { return tempC; }

    void print() const {
        cout << tempC << "°C";
    }
};

class Fahrenheit {
private:
    double tempF;

public:
    // Constructor
    Fahrenheit(double t = 32.0) : tempF(t) {}

    // Type conversion to Celsius
    operator Celsius() {
        return Celsius((tempF - 32) * 5.0 / 9.0);
    }

    // Overload == to compare two Fahrenheit objects
    bool operator==(const Fahrenheit& other) const {
        return tempF == other.tempF;
    }

    // Accessor
    double getTemp() const { return tempF; }

    void print() const {
        cout << tempF << "°F";
    }
};

// Define conversion from Celsius to Fahrenheit
Celsius::operator Fahrenheit() {
    return Fahrenheit(tempC * 9.0 / 5.0 + 32);
}

int main() {
    // Example temperatures
    Celsius c1(0.0), c2(100.0);
    Fahrenheit f1(32.0), f2(212.0);

    // Convert Celsius to Fahrenheit
    Fahrenheit f_from_c1 = c1;
    Fahrenheit f_from_c2 = c2;

    // Convert Fahrenheit to Celsius
    Celsius c_from_f1 = f1;
    Celsius c_from_f2 = f2;

    cout << "Conversions:\n";
    cout << "0°C -> "; f_from_c1.print() << endl;
    cout << "100°C -> "; f_from_c2.print()<< endl;
    cout << "32°F -> "; c_from_f1.print()<< endl;
    cout << "212°F -> "; c_from_f2.print() << endl;

    // Compare temperatures
    cout << "\nComparisons:\n";
    cout << "Is 0°C equal to 32°F? ";
    cout << (c1 == (Celsius)f1 ? "Yes" : "No") << endl;

    cout << "Is 100°C equal to 212°F? ";
    cout << (c2 == (Celsius)f2 ? "Yes" : "No") << endl;

    // Using a queue to process conversions
    queue<Fahrenheit> tempQueue;
    tempQueue.push(f_from_c1);
    tempQueue.push(f_from_c2);
    tempQueue.push(f1);
    tempQueue.push(f2);

    cout << "\nProcessing temperatures from the queue:\n";
    while (!tempQueue.empty()) {
        Fahrenheit temp = tempQueue.front();
        tempQueue.pop();
        temp.print();
        cout << endl;
    }

    return 0;
}
