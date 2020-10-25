#pragma once

class Log {
public:
	enum Level {
		error, eval, parser, tokenizer, all
	};
private:
	static Level log_level;
	static int indentation;
public:
	static void set_level(Level lvl) {
		log_level = lvl;
	}
	static void indent() {
		indentation++;
	}
	static void unindent() {
		if (indentation > 0)
			indentation--;
	}
	
	static void log_msg(std::string msg, Level lvl) {
		if (log_level >= lvl) {
			std::string indent = "";
			for (int i = 0; i < indentation; i++) {
				indent += "    ";
			}
			
			std::string prefix;
			if (lvl == Level::error)
				prefix = "[ERROR] ";
			if (lvl == Level::tokenizer)
				prefix = "[TOKENIZER] ";
			if (lvl == Level::parser)
				prefix = "[PARSER] ";
			if (lvl == eval)
				prefix = "[EVALUATION] ";
			
			std::cout << prefix << indent << msg << '\n';
		}
	}
};