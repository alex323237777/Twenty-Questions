#pragma once
#include <iostream>

using namespace std;

class Question
{
public:
  Question(int op1, int op2);

  void readUserAnswer();
  void displayQuestion() const;
  bool displaySolution() const;
  bool isCorrect() const;
  
protected:
  int getOp1() const;
  int getOp2() const;
  virtual char getSymbol() const =0;
  virtual int getSolution() const =0;

private:
  int op1, op2, useranswer;
};

inline Question::Question(int op1, int op2) : op1(op1), op2(op2), useranswer(0x7FFFFFFF) {}
inline int Question::getOp1() const { return op1; }
inline int Question::getOp2() const { return op2; }
inline bool Question::isCorrect() const { return (useranswer==getSolution()); }

inline void Question::displayQuestion() const
{
  cout << op1 << " " << getSymbol() << " " << op2 << " = ? ";
}

inline void Question::readUserAnswer()
{
  cin >> useranswer;
}
