#include <iostream>
#include <iomanip>

#include "max.h"
#include "mean.h"
#include "min.h"
#include "stddeviation.h"

int main() {

    const size_t statistics_count = 4;
    IStatistics *statistics[statistics_count] = { new Min{}, new Max{}, new Mean{}, new StdDeviation{} };

	double val = 0;
	while (std::cin >> val) {
        std::cout << "val: " << val << '\n';
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << std::setprecision(8) << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}
