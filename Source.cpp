#include"Header.h"

int main() {

	
	std::cout << "give a  size\n";
	std::size_t size;
	std::cin >> size;
	std::vector <std::vector<double>>a(size);
	std::vector<double>b{};
	std::cout << "elements for A\n";
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < a.size(); j++) {
			double element;
		    std::cin >> element;
			a[i].push_back(element);

		}
	}
	std::cout << "elements for b\n";
	for (size_t i = 0; i < a.size(); i++) {
            double element;
			std::cin >> element;
			b.push_back(element);
	}

	for (size_t k = 0; k < a.size()-1; k++) {
		if (a[k][k] == 0) {
			std::cout << "error\n";
			std::exit(EXIT_FAILURE);
		}
		for (size_t i = k + 1; i < a.size(); i++) {
					
				
			double kati = a[i][k] / a[k][k];
					
			for (size_t j = k; j < a.size(); j++) {
						
				a[i][j] =a[i][j]- kati * a[k][j];
						
			}
			b[i] = b[i] - kati * b[k];
		}

	}
	printmatrix(a, b);//after forward substitution
	if (a[a.size() - 1][a.size() - 1]) {
		std::cout << "erro\n";
		std::exit(EXIT_FAILURE);
	}
	std::vector <double>x(size);
	//backwards substitution:
	for (size_t k = a.size()-1; k > 0; k--) {
		if (k == 1) {
			x[k] = b[k];
			for (size_t j = k + 1; j < a.size(); j++) {
				x[k] = (x[k] - a[k][j] * x[j]);
			}
			x[k] = x[k] / a[k][k];

			x[0] = b[0];
			for (size_t j = 0 + 1; j < a.size(); j++) {
				x[0] = (x[0] - a[0][j] * x[j]);
			}
			x[0] = x[0] / a[0][0];
			break;
		}
	}
	printsolution(x);



}