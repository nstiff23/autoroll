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
	Expr2(Expr *ex1, Expr *ex2);
};

// represents a dice roll
class Roll : public Expr {
private:
	int num; //the number of dice to roll
	int die; //the maximum of each die
	int highest; //the number of highest rolls to keep

public:
	Roll(int number, int die_val, int num_highest);

	//this method returns the result of the roll
	long eval() override;
};

// multiplies two expressions
class Mul : public Expr2 {
public:
	long eval() override;
	Mul(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// divides two expressions
class Div : public Expr2 {
public:
	long eval() override;
	Div(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// adds two expressions
class Add : public Expr2 {
public:
	long eval() override;
	Add(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// subtracts two expressions
class Sub : public Expr2 {
public:
	long eval() override;
	Sub(Expr *e1, Expr *e2) :Expr2(e1, e2) {}
};

// wrapper for a single value. eval() simply returns the value.
class Num : public Expr {
public:
	long val;
	
	long eval() override;
	Num(long value) {
		val = value;
	}
};