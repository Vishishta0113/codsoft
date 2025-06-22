#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>  // For Windows color support

using namespace std;

// Function to convert number to string (for older C++ versions)
string numberToString(double num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Function to set console colors
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Global vector to store calculation history
vector<string> history;

void showHistory() {
    setColor(13); // Bright Magenta
    cout << "\n=== CALCULATION HISTORY ===" << endl;
    setColor(10); // Bright Green
    
    if (history.empty()) {
        cout << "No calculations yet!" << endl;
    } else {
        for (int i = 0; i < history.size(); i++) {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
    setColor(7); // Reset to white
}

void clearHistory() {
    history.clear();
    setColor(14); // Bright Yellow
    cout << "History cleared successfully!" << endl;
    setColor(7); // Reset to white
}

void calculate() {
    double num1, num2, result;
    char operation;
    string operationName;
    
    setColor(11); // Light Cyan
    cout << "Enter first number: ";
    setColor(15); // Bright White
    cin >> num1;
    
    setColor(14); // yellow 
    cout << "Choose operation (+, -, *, /): ";
    setColor(15); // Bright White
    cin >> operation;
    
    setColor(10); // Light green 
    cout << "Enter second number: ";
    setColor(15); // Bright White
    cin >> num2;
    
    string calculation = numberToString(num1) + " " + operation + " " + numberToString(num2) + " = ";
    
    switch (operation) {
        case '+':
            result = num1 + num2;
            operationName = "Addition";
            break;
        case '-':
            result = num1 - num2;
            operationName = "Subtraction";
            break;
        case '*':
            result = num1 * num2;
            operationName = "Multiplication";
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                operationName = "Division";
            } else {
                setColor(4); // Dark Red
                cout << "Error: Cannot divide by zero!" << endl;
                setColor(7);
                return;
            }
            break;
        default:
            setColor(4); // Dark Red
            cout << "Invalid operation!" << endl;
            setColor(7);
            return;
    }
    
    // Display result with colors
    setColor(14); // Bright Yellow
    cout << "\nOperation: " << operationName << " (" << operation << ")" << endl;
    setColor(10); // Bright Green
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
    
    // Add to history
    calculation += numberToString(result);
    history.push_back(calculation);
    
    setColor(7); // Reset to white
}

int main() {
    int choice;
    
    setColor(13); // Bright Magenta
    cout << "=====================================" << endl;
    cout << "     SIMPLE CALCULATOR PROGRAM      " << endl;
    cout << "=====================================" << endl;
    
    while (true) {
        setColor(9); // Light Blue
        cout << "\nMENU:" << endl;
        setColor(15);  // Bright White
        cout << "1. Calculate" << endl;
        cout << "2. Show History" << endl;
        cout << "3. Clear History" << endl;
        cout << "4. Exit" << endl;
        
        setColor(11); // Light Cyan
        cout << "Enter your choice (1-4): ";
        setColor(15); // Bright White
        cin >> choice;
        
        switch (choice) {
            case 1:
                calculate();
                break;
            case 2:
                showHistory();
                break;
            case 3:
                clearHistory();
                break;
            case 4:
                setColor(14); // Bright Yellow
                cout << "Thank you for using the calculator!" << endl;
                setColor(7);
                return 0;
            default:
                setColor(4); // Dark Red
                cout << "Invalid choice! Please try again." << endl;
                setColor(7);
        }
    }
    
    return 0;
}
