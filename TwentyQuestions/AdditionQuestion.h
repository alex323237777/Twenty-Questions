#pragma once
#include "Question.h"

class AdditionQuestion : public Question
{
public:
  AdditionQuestion(int op1, int op2);

  virtual char getSymbol() const;
  virtual int getSolution() const;
};

inline AdditionQuestion::AdditionQuestion(int op1, int op2) : Question(op1, op2) {} 
inline char AdditionQuestion::getSymbol() const { return '+'; }
inline int AdditionQuestion::getSolution() const { return (getOp1()+getOp2()); }

