#include <string>
#include <regex>
#include <list>

#include "Log.h"
#include "Tok.h"

#include "tokenize.h"

std::list<Tok*>* tokenize(const std::string& input) {
	std::regex match_d("^d");
	std::regex match_h("^h");
	std::regex match_num("^[0-9]+");
	std::regex match_lparen("^\\(");
	std::regex match_rparen("^\\)");
	std::regex match_plus("^\\+");
	std::regex match_minus("^\\-");
	std::regex match_star("^\\*");
	std::regex match_slash("^/");
	
	std::list<Tok*> *toks = new std::list<Tok*>();
	std::smatch *res = new std::smatch();
	
	size_t i{ 0 };
	while (i < input.size()) {
		if (std::regex_search(input.begin() + i, input.end(), match_d)) {
			toks->push_back(new Tok(Tok::Type::dice));
			Log::log_msg("d", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), match_h)) {
			toks->push_back(new Tok(Tok::Type::high));
			Log::log_msg("h", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), match_lparen)) {
			toks->push_back(new Tok(Tok::Type::lparen));
			Log::log_msg("(", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), match_rparen)) {
			toks->push_back(new Tok(Tok::Type::rparen));
			Log::log_msg(")", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), match_plus)) {
			toks->push_back(new Tok(Tok::Type::plus));
			Log::log_msg("+", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), match_minus)) {
			toks->push_back(new Tok(Tok::Type::minus));
			Log::log_msg("-", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), match_star)) {
			toks->push_back(new Tok(Tok::Type::times));
			Log::log_msg("*", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), match_slash)) {
			toks->push_back(new Tok(Tok::Type::div));
			Log::log_msg("/", Log::Level::tokenizer);
			i++;
		}
		else if (std::regex_search(input.begin() + i, input.end(), *res, match_num)) {
			std::string num_str = res->str();
			int val = stoi(num_str);
			toks->push_back(new Tok(Tok::Type::number, val));
			Log::log_msg(num_str, Log::Level::tokenizer);
			i += num_str.size();
		}
		else {
			Log::log_msg("Unknown token at index: " + std::to_string(i), Log::Level::error);
			return NULL;
		}
	}
	
	delete(res);
	
	return toks;
}