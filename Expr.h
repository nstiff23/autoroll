#pragma once

// defines the Expr interface and all subclasses

// interface for all expressions
// an expression is an atomic operation, number, or dice roll that can evaluate to a long
class Expr {
public:
	virtual long eval() = 0;
};

// all atomic operations are children of Expr2
class Expr2 : public Expr {
public:
	Expr *e1, *e2;
	Expr2(Expr *ex1, Expr *ex2) {
		e1 = ex1;
		e2 = ex2;
	}
};

// represents a dice roll
class Roll : public Expr {
private:
	int num; //the number of dice to roll
	int die; //the maximum of each die
	int highest; //the number of highest rolls to keep

public:
	Roll(int number, int die_val, int num_highest) {
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

	//this method returns the result of the roll
	long eval() override {
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
};

// multiplies two expressions
class Mul : public Expr2 {
public:
	long eval() override {
		long v1 = e1->eval();
		long v2 = e2->eval();
		Log::log_msg(std::to_string(v1) + "*" + std::to_string(v2) + "=" + std::to_string(v1 * v2), Log::Level::eval);
		return (v1 * v2);
	}
	Mul(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// divides two expressions
class Div : public Expr2 {
public:
	long eval() override {
		long v1 = e1->eval();
		long v2 = e2->eval();
		Log::log_msg(std::to_string(v1) + "/" + std::to_string(v2) + "=" + std::to_string(v1 / v2), Log::Level::eval);
		return (v1 / v2);
	}
	Div(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// adds two expressions
class Add : public Expr2 {
public:
	long eval() override {
		long v1 = e1->eval();
		long v2 = e2->eval();
		Log::log_msg(std::to_string(v1) + "+" + std::to_string(v2) + "=" + std::to_string(v1 + v2), Log::Level::eval);
		return (v1 + v2);
	}
	Add(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// subtracts two expressions
class Sub : public Expr2 {
public:
	long eval() override {
		long v1 = e1->eval();
		long v2 = e2->eval();
		Log::log_msg(std::to_string(v1) + "-" + std::to_string(v2) + "=" + std::to_string(v1 - v2), Log::Level::eval);
		return (v1 - v2);
	}
	Sub(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// wrapper for a single value. eval() simply returns the value.
class Num : public Expr {
public:
	long val;
	
	long eval() override {
		Log::log_msg("Passing " + std::to_string(val), Log::Level::eval);
		return val;
	}
	Num(long value) {
		val = value;
	}
};