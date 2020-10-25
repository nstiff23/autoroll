#pragma once

Expr *parse_roll(std::list<Tok*>::iterator *begin, std::list<Tok*>::iterator *end);
Expr *parse_add_sub(std::list<Tok*>::iterator *begin, std::list<Tok*>::iterator *end);
Expr *parse_mul_div(std::list<Tok*>::iterator *begin, std::list<Tok*>::iterator *end);