#include "std_lib_facilities.h"
// Get this header file in K&R's book.

class Token {
public:
    enum input { ENDL, LPAREN, RPAREN, ADD, SUB, MUL, DIV, NUM, BEGIN } kind;
    double value;
};

class Token_stream {
public:
    Token_stream();        // make a Token_stream that reads from cin
    Token get();           // get a Token
    void putback(Token t); // put a Token back
private:
    bool full; // is there a Token in the buffer?
    char ch;
    double val;
    Token buffer; // here is where we keep a Token put back using putback()
};

Token_stream::Token_stream() : full(false), buffer() {}

// The putback() member function puts its argument back into the Token_stream's
// buffer:
void Token_stream::putback(Token t) {
    if (full)
        error("putback() into a full buffer");
    buffer = t;    // copy t to buffer
    full   = true; // buffer is now full
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    cin >> ch;
    switch (ch) {
    case ';':
        return Token{Token::ENDL};
    case '(':
        return Token{Token::LPAREN};
    case ')':
        return Token{Token::RPAREN};
    case '+':
        return Token{Token::ADD};
    case '-':
        return Token{Token::SUB};
    case '*':
        return Token{Token::MUL};
    case '/':
        return Token{Token::DIV};
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
        cin.putback(ch);
        cin >> val;
        return Token{Token::NUM, val};
    }
    default:
        error("Bad token");
        return Token();
    }
}

Token_stream ts; // provides get() and putback()

double expression();
double term();
double primary();

// Start here!
double expression() {
    double left = term();

    while (true) {
        Token token = ts.get();
        switch (token.kind) {
        case Token::ADD:
            left += term();
            break;
        case Token::SUB:
            left -= term();
            break;
        default:
            ts.putback(token);
            return left;
        }
    }
    return 0;
}

double term() {
    double left = primary();
    while (true) {
        Token token = ts.get();
        switch (token.kind) {
        case Token::MUL:
            left *= primary();
            break;
        case Token::DIV: {
            double v = primary();
            if (v == 0) {
                cout << "divide by zero" << endl;
                error("Divided by zero");
            }
            left /= v;
            break;
        }
        default:
            ts.putback(token);
            return left;
        }
    }
    return 0;
}

double primary() {
    Token token = ts.get();
    switch (token.kind) {
    case Token::LPAREN: {
        double d = expression();
        token    = ts.get();
        if (token.kind != Token::RPAREN)
            error("')' expected");
        return d;
    }
    case Token::NUM:
        return token.value;
    case Token::ADD:
        token = ts.get();
        if (token.kind != Token::NUM)
            error("number expected");
        return token.value;
    case Token::SUB:
        token = ts.get();
        if (token.kind != Token::NUM)
            error("number expected");
        return 0.0 - token.value;
    default:
        cout << token.kind;
        error("primary expected.");
    }
    return 0;
}

// main function
int main() {
    double val = 0;
    while (cin) {
        Token t = ts.get();
        if (t.kind == Token::ENDL) {
            cout << fixed;
            cout << setprecision(3) << val << '\n';
            break;
        } else
            ts.putback(t);
        val = expression();
    }
    return 0;
}
