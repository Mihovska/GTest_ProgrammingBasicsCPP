#include "SolfegeNoteNaming.h"

NoteName SolfegeNoteNaming::operator()(const std::string& noteText) const {
  switch (noteText[0]) {
    case 'D': return NoteName('C');
    case 'R': return NoteName('D');
    case 'M': return NoteName('E');
    case 'F': return NoteName('F');
    case 'L': return NoteName('A');
    case 'S': return noteText == "Sol" ? NoteName('G') : NoteName('B');
  }
  return NoteName('?');
}
