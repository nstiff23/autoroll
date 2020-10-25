#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <list>
#include <vector>
#include <chrono>

#include <time.h>
#include <stdlib.h>

// class includes
#include "Log.h"
#include "Tok.h"
#include "Expr.h"

// function includes
#include "tokenize.h"
#include "parse.h"

// initializes log variables
Log::Level Log::log_level = Log::Level::all;
int Log::indentation = 0;

// runs the parsing pipeline on an input
void process_input(std::string input) {
	std::list<Tok*> *tokens = tokenize(input);
	if (tokens) {
		tokens->reverse();
		std::list<Tok*>::iterator begin = tokens->begin();
		std::list<Tok*>::iterator end = tokens->end();
		Expr *top_expr = parse_add_sub(&begin, &end);
		if (top_expr) {
			long result = top_expr->eval();
			delete(tokens);
			delete(top_expr);
			
			std::cout << result << '\n';
		}
	}
}

int main(int argc, char** argv) {
	Log::set_level(Log::Level::error);
	
	std::string input{ "" };
	
	if (argc > 3) {
		Log::log_msg("Too many arguments!", Log::Level::error);
		return 1;
	}
	
	if (argc == 3) {
		srand(atoi(argv[1]));
		input = argv[2];
		process_input(input);
		return 0;
	}
	else {
		using namespace std::chrono;
		milliseconds ms = duration_cast<std::chrono::milliseconds>(steady_clock::now().time_since_epoch());
		srand(ms.count());
	}
	
	if (argc == 2) {
		input = argv[1];
		process_input(input);
		return 0;
	}
	
	while (true) {
		std::cout << "> ";
		std::cin >> input;
		if (input == "exit") {
			return 0;
		}
		else {
			process_input(input);
		}
	}
}