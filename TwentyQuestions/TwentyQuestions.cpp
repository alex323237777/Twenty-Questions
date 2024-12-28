#include <iostream>
#include <time.h>
#include "AdditionQuestion.h"
#include "SubtractQuestion.h"

using namespace std;

int main()
{
#ifdef _DEBUG
  _onexit(_CrtDumpMemoryLeaks);
#endif

  const int NOOFQUESTIONS=20;
  const int MIN_OPERAND_VALUE=1;
  const int MAX_OPERAND_VALUE=20;
  Question* questions[NOOFQUESTIONS];

  time_t start=time(NULL);
  srand((unsigned) start);

  cout << "Welcome to Twenty Questions\n===========================\n";
  cout << "Twenty random addition or subtraction questions with operands between 1 and 20.  How many can you get right?\n";
  cout << "(just enter integer values as your input isn't validated - provide sensible inputs... please)\n\n";

  for (int i=0; i<NOOFQUESTIONS; i++)
  {
    
 
    int op1=MIN_OPERAND_VALUE+(rand()%(MAX_OPERAND_VALUE-MIN_OPERAND_VALUE+1));
    int op2=MIN_OPERAND_VALUE+(rand()%(MAX_OPERAND_VALUE-MIN_OPERAND_VALUE+1));
    if (rand()<(RAND_MAX/2))
      questions[i]=new AdditionQuestion(op1, op2);
    else
      questions[i]=new SubtractQuestion(op1, op2);

    cout << "Question " << (i+1) << ":\t";
    questions[i]->displayQuestion();
    questions[i]->readUserAnswer();
  }

  time_t end=time(NULL);

  int correct=0;
  cout << "\n\nCorrect Answers\n";
  cout << "===============\n";
  for (int i=0; i<NOOFQUESTIONS; i++)
  {
    if (questions[i]->isCorrect())
    {
      questions[i]->displaySolution();
      cout << "\n";
      ++correct;
    }
  }

  if (correct==NOOFQUESTIONS)
    cout << "\n\nAnd none wrong - nice job, well done : ";
  else
  {
    if (correct==0)
      cout << "  None correct... well that was a poor effort\n";

    cout << "\nAnd the wrong answers\n";
    cout << "=====================\n";
    for (int i=0; i<NOOFQUESTIONS; i++)
    {
      if (!questions[i]->isCorrect())
      {
        questions[i]->displaySolution();
        cout << "\n";
      }
    }

    cout << "\n\n" << correct << " out of " << NOOFQUESTIONS << " : ";
  }
  cout << "Completed in " << (end-start) << " seconds" << "\n\n";

  for (int i=0; i<NOOFQUESTIONS; i++)
    delete questions[i];

  system("pause");
  return 0;
}
