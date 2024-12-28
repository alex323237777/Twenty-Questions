#include "Question.h"

bool Question::displaySolution() const
{
  const int solution=getSolution();
  cout << op1 << " " << getSymbol() << " " << op2 << " = " << solution;
  const bool correct=(solution==useranswer);
  if (!correct)
    cout << " - you answered with " << useranswer;
  return correct;
}
