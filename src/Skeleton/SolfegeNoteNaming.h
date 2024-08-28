#ifndef SRC_SKELETON_SOLFEGENOTENAMING_H_
#define SRC_SKELETON_SOLFEGENOTENAMING_H_

#include <string>
#include "NoteName.h"

class SolfegeNoteNaming {
  char noteText;

 public:
  SolfegeNoteNaming() = default;
  SolfegeNoteNaming(char noteText) : noteText(noteText) {}

  NoteName operator()(const std::string& noteText) const;
};
#endif  // SRC_SKELETON_SOLFEGENOTENAMING_H_
