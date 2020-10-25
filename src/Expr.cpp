// defines functions for all Expr subclasses

#include <string>
#include <vector>
#include <algorithm>

#include "Expr.h"
#include "Log.h"

Expr2::Expr2(Expr *ex1, Expr *ex2) {
	e1 = ex1;
	e2 = ex2;
}

Roll::Roll(int number, int die_val, int num_highest) {
	if (number <= 0) {
		Log::log_msg("Can't roll fewer than 1 dice!", Log::Level::error);
	}
	if (num_highest >= number) {
		Log::log_msg("Can't keep the highest " + std::to_string(highest) + " rolls when only " + std::to_string(num) + " dice are rolled!", Log::Level::error);
	}
	num = number;
	die = die_val;
	highest = num_highest;
}

long Roll::eval() {
	if (die <= 0) {
		return num;
	}
	std::vector<int> rolls(num);
	for (int i = 0; i < num; i++) {
		rolls[i] = rand() % die + 1;
	}

	if (highest > 0) {
		int drop = num - highest;
		std::partial_sort(rolls.begin(), rolls.end() - highest, rolls.end());
		for (int i = 0; i < drop; i++) {
			rolls[i] = 0;
		}
	}

	long sum{ 0 };
	for (int i = 0; i < num; i++) {
		sum += rolls[i];
	}

	Log::log_msg("Rolling " + std::to_string(num) + "d" + std::to_string(die) + "h" + std::to_string(highest) + ": " + std::to_string(sum), Log::Level::eval);
	return sum;
}

long Mul::eval() {
	long v1 = e1->eval();
	long v2 = e2->eval();
	Log::log_msg(std::to_string(v1) + "*" + std::to_string(v2) + "=" + std::to_string(v1 * v2), Log::Level::eval);
	return (v1 * v2);
}

long Div::eval() {
	long v1 = e1->eval();
	long v2 = e2->eval();
	Log::log_msg(std::to_string(v1) + "/" + std::to_string(v2) + "=" + std::to_string(v1 / v2), Log::Level::eval);
	return (v1 / v2);
}

long Add::eval() {
	long v1 = e1->eval();
	long v2 = e2->eval();
	Log::log_msg(std::to_string(v1) + "+" + std::to_string(v2) + "=" + std::to_string(v1 + v2), Log::Level::eval);
	return (v1 + v2);
}

long Sub::eval() {
	long v1 = e1->eval();
	long v2 = e2->eval();
	Log::log_msg(std::to_string(v1) + "-" + std::to_string(v2) + "=" + std::to_string(v1 - v2), Log::Level::eval);
	return (v1 - v2);
}

long Num::eval() {
	Log::log_msg("Passing " + std::to_string(val), Log::Level::eval);
	return val;
}