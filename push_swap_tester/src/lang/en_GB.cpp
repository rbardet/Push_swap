#include "complexity.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

const string getHelp() {
	string help;

	help += "\033[1mNAME\033[0m\n";
	help += "     \033[1mcomplexity\033[0m -- starting benchmark for push_swap\n";
	help += "\n";
	help += "\033[1mSYNOPSIS\033[0m\n";
	help += "     \033[1m./complexity\033[0m [\033[1m-vh\033[0m] [\033[1m-s\033[0m \033[4mseed\033[0m] [\033[1m-o\033[0m \033[4mfile\033[0m] [\033[1m-f\033[0m \033[4mfile\033[0m] [\033[1m--seed\033[0m] \033[4mnumbers\033[0m \033[4miterations\033[0m [\033[4mgoal\033[0m] [\033[4mchecker\033[0m]\n";
	help += "\n";
	help += "\033[1mDESCRIPTION\033[0m\n";
	help += "     push_swap executable will be default searched from current and parent directory.\n";
	help += "     \n";
	help += "     Following options are available :\n";
	help += "     \n";
	help += "     \033[1m-v\033[0m, \033[1m--version\033[0m\n";
	help += "             Show version of tester.\n";
	help += "     \n";
	help += "     \033[1m-h\033[0m, \033[1m--help\033[0m\n";
	help += "             Show this help.\n";
	help += "     \n";
	help += "     \033[1m-s\033[0m \033[4mseed\033[0m, \033[1m--seed\033[0m=\033[4mseed\033[0m\n";
	help += "             Generates the numbers based on the seed.\n";
	help += "     \n";
	help += "     \033[1m-o\033[0m \033[4moutput\033[0m, \033[1m--output\033[0m=\033[4moutput\033[0m\n";
	help += "             Specifies an output file for logs.\n";
	help += "     \n";
	help += "     \033[1m-f\033[0m \033[4mpush_swap\033[0m, \033[1m--file\033[0m=\033[4mpush_swap\033[0m\n";
	help += "             Use \033[4mpush_swap\033[0m for push_swap executable.\n";
	help += "     \n";
	help += "     \033[1m--sorted\033[0m\n";
	help += "             Only pass sorted numbers to program.\n";
	return help;
}

void printStart(const program_opts& opts, const program_params& params) {
	cout << "\033[97mStarting the test : \033[95m" << params.numbers << "\033[97m elements, \033[95m" << params.iterations << "\033[97m iterations\033[0m";
	if (opts.seed.has_value())
		cout << " (seed " << opts.seed.value() << ")";
	cout << endl;
}

void print_status(const program_params& params, int done, int mean, double stddev, int best, int worst, int successful, int ok) {
	cout << "Pire = \033[31m" << (worst - worst * 0.1) << "\033[0m instructions" << endl;
	cout << "Moyenne = \033[33m" << (mean - mean * 0.1) << "\033[0m instructions" << endl;
	cout << "Meilleur = \033[36m" << (best - best * 0.1) << "\033[0m instructions" << endl;
	cout << "Écart-type = \033[93m" << setiosflags(ios_base::fixed) << setprecision(1) << (stddev - stddev * 0.1) << "\033[0m instructions" << endl;
	if (params.objective.has_value())
		cout << "Objectif = \033[94m" << (successful * 100 / done) - (successful * 100 / done) * 0.1 << "\033[0m % sous \033[94m" << (params.objective.value()) << "\033[0m (\033[91m" << (done - successful) - (done - successful) * 0.1 << "\033[0m au dessus)   " << endl;
	else
		cout << "Objectif = entrez un nombre en troisième argument" << endl;
	if (params.checker.has_value())
		cout << "Précision = \033[97m" << (ok * 100 / done) - (ok * 100 / done) * 0.1 << "\033[0m % OK (\033[91m" << (done - ok) - (done - ok) * 0.1 << "\033[0m KO)   " << endl;
	else
		cout << "Précision = entrez un testeur en quatrième argument" << endl;
	cout << "\033[32m" << (done * 100 / params.iterations) - (done * 100 / params.iterations) * 0.1 << "\033[0m % effectué" << endl;
}

void printEnd(const program_opts&, const program_params&) {
	cout << "\033[38m" << getVersion() << "\033[0m" << endl;
}
