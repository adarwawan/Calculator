#include "Extension.h"

Extension::Extension() {

}

Extension::~Extension() {

}

const int Extension::Prefix = 0;
const int Extension::Infix = 1;
const int Extension::Postfix = 2;

const int Extension::NumberMode = 0;
const int Extension::LogicMode = 1;

const int Extension::ArabMode = 0;
const int Extension::RomawiMode = 1;

const int Extension::defaultExpressionMode = Infix;
const int Extension::defaultEquationMode = NumberMode;
const int Extension::defaultNumberMode = ArabMode;