#include <random>
#include <map>
#include <fstream>
#include <functional>

using namespace std;

int main()
{
	const unsigned int Start{ 1 };
	const unsigned int End{ 99 };
	const unsigned int Iterations{ 1'000'000 };

	// Normal distributed Mersenne Twister.
	random_device seeder;
	mt19937 engine{ seeder() };
	normal_distribution<double> distribution{ 50, 10 };
	auto generator{ bind(distribution, engine) };
	map<int, int> histogram;
	for (unsigned int i{ 0 }; i < Iterations; ++i) {
		int randomNumber{ static_cast<int>(generator()) };
		// Search map for a key=randomNumber. If found, add 1 to the value associated
		// with that key. If not found, add the key to the map with value 1.
		++(histogram[randomNumber]);
	}

	// Write to a CSV file.
	ofstream of{ "res.csv" };
	for (unsigned int i{ Start }; i <= End; ++i) {
		of << i << ";" << histogram[i] << endl;
	}
}