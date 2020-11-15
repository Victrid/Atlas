#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

typedef unsigned short int Chromosome;

const double crossover_probability = 0.7;
const double mutation_probability  = 0.9;
const double selection_probability = 0.4;
const double parental_rate         = 0.1;

const int population_capacity = 100;
const int maximum_generations = 2000;

double target_function(double x) { return x * sin(x); }
double xsome_to_double(Chromosome val) { return val / 4096.0 - 1; }
double fitness(Chromosome val) {
    return tan((15.0 - target_function(xsome_to_double(val))) / 27 * M_PI / 2);
}
Chromosome generate_random() { return rand() % 65536; }
Chromosome crossover(Chromosome base, Chromosome crossover_parent) {
    double probability      = 1;
    Chromosome return_value = 0;
    for (int i = 0; i <= 16; i++) {
        probability *= crossover_probability;
        if ((rand() % 1000) / 1000.0 < probability)
            return_value |= (crossover_parent & (1 << i));
        else
            return_value |= (base & (1 << i));
    }
    return return_value;
}

Chromosome mutation(Chromosome mutation) {
    double probability = 1;
    for (int i = 0; i <= 16; i++) {
        probability *= mutation_probability;
        if ((rand() % 1000) / 1000.0 < probability)
            mutation ^= (1 << i);
    }
    return mutation;
}

pair<Chromosome, vector<Chromosome>> selection(vector<Chromosome>& lastroll) {
    vector<double> fitness_list;
    for (auto i = lastroll.begin(); i != lastroll.end(); i++) {

        fitness_list.push_back(fitness(*i));
    }
    double sum = std::accumulate(fitness_list.begin(), fitness_list.end(), 0.0);
    for (auto i = fitness_list.begin(); i != fitness_list.end(); i++)
        (*i) /= sum;
    vector<Chromosome> newroll;
    auto getone = [&] {
        double roulette = rand() / (double)RAND_MAX;
        auto i          = fitness_list.begin();
        for (; i != fitness_list.end(); roulette -= (*i), i++)
            if ((*i) > roulette)
                break;
        return lastroll[i - fitness_list.begin()];
    };
    while (newroll.size() <= population_capacity * parental_rate)
        newroll.push_back(getone());
    for (auto i = lastroll.begin(); i != lastroll.end(); i++)
        (*i) = mutation(*i);
    while (newroll.size() <= population_capacity) {
        auto i = getone(), j = getone();
        newroll.push_back(crossover(i, j));
    }
    double best_result = 0;
    Chromosome best_chromosome;
    for (auto i = newroll.begin(); i != newroll.end(); i++) {
        if (fitness(*i) > best_result) {
            best_result     = fitness(*i);
            best_chromosome = *i;
        }
    }
    return pair<double, vector<Chromosome>>(best_chromosome, newroll);
}

vector<Chromosome> init() {
    vector<Chromosome> newroll;
    while (newroll.size() <= population_capacity)
        newroll.push_back(generate_random());
    return newroll;
}

int main() {
    auto current_result = pair<Chromosome, vector<Chromosome>>(0, init());
    int rounds          = 1;
    for (; rounds <= maximum_generations / 10; rounds++) {
        current_result = selection(current_result.second);
        cout << "generation: " << rounds << "\tvalue: " << std::setw(8)
             << xsome_to_double(current_result.first)
             << "\tanswer: " << std::setw(8)
             << target_function(xsome_to_double(current_result.first)) << endl;
    }
    vector<double> answerset;
    double average = 0;
    double metbar  = 0;
    double stddev  = 0;
    int bar        = 0;
    for (; rounds <= maximum_generations; rounds++) {
        current_result = selection(current_result.second);
        cout << "generation: " << rounds << "\tvalue: " << std::setw(8)
             << xsome_to_double(current_result.first)
             << "\tanswer: " << std::setw(8)
             << target_function(xsome_to_double(current_result.first)) << endl;
        answerset.push_back(xsome_to_double(current_result.first));
        average = (average * (answerset.size() - 1) +
                   xsome_to_double(current_result.first)) /
                  answerset.size();
        metbar = (metbar * (answerset.size() - 1) +
                  pow(xsome_to_double(current_result.first), 2)) /
                 answerset.size();
        stddev = sqrt(metbar - pow(average, 2));
        if (xsome_to_double(current_result.first) > average + 3 * stddev ||
            xsome_to_double(current_result.first) < average - 3 * stddev) {
            bar     = 0;
            average = 0;
            metbar  = 0;
            answerset.clear();
        } else {
            bar++;
            if (bar >= 20) {
                cout << "Final result = " << average << endl
                     << "with stddev = " << stddev
                     << " in last 20 generations." << endl;
                break;
            }
        }
    }
    return 0;
}