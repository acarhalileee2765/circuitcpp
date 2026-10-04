#include <iostream>
#include <fstream>
#include <string>
int n, a, t, s;
// Function to calculate total parallel resistance
double calculateparallelresistance(std::ofstream& circuit) {
    double totalResistance = 0;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the parallel resistance value for resistor " << i + 1 << " (in ohms): ";
        std::cin >> a;

        circuit << "Resistor " << i + 1 << ": " << a << " ohms\n";
        circuit.flush(); 
        totalResistance += 1.0 / a;
    }
    return totalResistance;
}
// Function to calculate total series resistance
double calculatetotalresistance(std::ofstream& circuit ) {
	double totalseriesResistance = 0;
  
    for (int i = 0; i < t; i++) {
        std::cout << "Enter the series resistance value for resistor " << i + 1 << " (in ohms): ";
		std::cin >> s;
		circuit << "Series Resistor " << i + 1 << ": " << s << " ohms\n";
		circuit.flush(); 
		totalseriesResistance += s;
    }
    circuit.flush();
	return totalseriesResistance;
}
// calculate total current through the circuit
double calculatecurrent(double totalResistanceCombined){
	std::cout << "Enter the voltage (in volts): ";
	double voltage;
	std::cin >> voltage;
	double current = voltage / totalResistanceCombined;
	return current;


}
// Main function
int main() {
    std::ofstream circuit("circuit.txt");

    if (!circuit.is_open()) {
        std::cout << "Dosya acilamadi!" << std::endl;
        return 1;
    }
	
     

    std::cout << "Enter the number of parallel resistors: ";
    std::cin >> n;
    
    circuit << "********circuit********\n";
    circuit << "Number of resistors: " << n << "\n";
    circuit.flush(); 

    double totalResistance = calculateparallelresistance(circuit);
    circuit << "Total parallel resistance: " << totalResistance << " ohms\n";
    std::cout << "enter the series resistance number: ";
    std::cin >> t;
	double totalseriesResistance = calculatetotalresistance(circuit);
    circuit << "Total series resistance: " << totalseriesResistance << " ohms\n";
	double totalResistanceCombined = totalResistance + totalseriesResistance;
	circuit << "Total resistance of the circuit: " << totalResistanceCombined << " ohms\n";
    double current = calculatecurrent(totalResistanceCombined);
	circuit << "Total current through the circuit: " << current << " amperes\n";

    circuit.close(); 
    

    return 0;
}