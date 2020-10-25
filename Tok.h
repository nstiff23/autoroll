#pragma once

class Tok {
public:
	enum Type
	{
		null, lparen, rparen, plus, minus, times, div, dice, high, number
	};
	Type t;
	int val;

	static std::string to_str(Tok::Type st) {
		if (st == Type::null) {
			return "NULL";
		}
		else if (st == Type::lparen) {
			return "(";
		}
		else if (st == Type::rparen) {
			return ")";
		}
		else if (st == Type::plus) {
			return "+";
		}
		else if (st == Type::minus) {
			return "-";
		}
		else if (st == Type::times) {
			return "*";
		}
		else if (st == Type::div) {
			return "/";
		}
		else if (st == Type::dice) {
			return "d";
		}
		else if (st == Type::high) {
			return "h";
		}
		else if (st == Type::number) {
			return "number";
		}
		else {
			return NULL;
		}
	}
	
	Tok(Type type, int value) {
		t = type;
		val = value;
	}
	Tok(Type type) {
		t = type;
		val = 0;
	}
};