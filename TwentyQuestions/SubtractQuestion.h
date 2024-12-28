#pragma once
#include "Question.h"

class SubtractQuestion : public Question
{
public:
  SubtractQuestion(int op1, int op2);

  virtual char getSymbol() const;
  virtual int getSolution() const;
};

inline SubtractQuestion::SubtractQuestion(int op1, int op2) : Question(op1, op2) {}  
inline char SubtractQuestion::getSymbol() const { return '-'; }
inline int SubtractQuestion::getSolution() const { return (getOp1()-getOp2()); }