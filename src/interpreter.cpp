#include <iostream>
#include <string>

using namespace std;

class Expression {
public:

    virtual bool interpret(string context) = 0;
    virtual ~Expression() {}
};


class TerminalExpression: public Expression {
public:
    TerminalExpression(string data) {
        _data = data;
    }

    bool interpret(string context) {
        if (context.find(_data) != string::npos) {
            return true;
        }
        return false;
    }
private:
    string _data;
};

class AndExpression: public Expression {
public:
    AndExpression(Expression* exp1, Expression* exp2) {
        _exp1 = exp1;
        _exp2 = exp2;
    }
    bool interpret(string context) override {
        return _exp1->interpret(context) && _exp2->interpret(context);
    }

    ~AndExpression() {
        delete _exp1;
        delete _exp2;
        _exp1 = nullptr;
        _exp2 = nullptr;
    }
private:
    Expression* _exp1;
    Expression* _exp2;
};

class OrExpression: public Expression {
public:
    OrExpression(Expression* exp1, Expression* exp2) {
        _exp1 = exp1;
        _exp2 = exp2;
    }
    bool interpret(string context) {
        return _exp1->interpret(context) || _exp2->interpret(context);
    }

    ~OrExpression() {
        delete _exp1;
        delete _exp2;
        _exp1 = nullptr;
        _exp2 = nullptr;
    }
private:
    Expression* _exp1;
    Expression* _exp2;

};


static Expression* getMaleExpression() {
    Expression* robert = new TerminalExpression("Robert");
    Expression* john = new TerminalExpression("John");
    return new OrExpression(robert, john);
}

static Expression* getMarriedWomanExpression() {
    Expression* julie = new TerminalExpression("Julie");
    Expression* married = new TerminalExpression("Married");

    return new AndExpression(julie, married);
}

int main() {
    Expression* isMale = getMaleExpression();
    Expression* isMarriedWoman = getMarriedWomanExpression();

    cout << "John is male? " << isMale->interpret("John") << endl;
    cout << "Julie is a married woman? " << isMarriedWoman->interpret("Married Julie") << endl;
    
    delete isMale;
    delete isMarriedWoman;
    isMale = nullptr;
    isMarriedWoman = nullptr;

    system("pause");
    return 0;
}