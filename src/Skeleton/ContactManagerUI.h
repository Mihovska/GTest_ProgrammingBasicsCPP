#ifndef CONTACT_MANAGER_UI_H
#define CONTACT_MANAGER_UI_H

#include <algorithm>
#include <sstream>
#include <vector>

#include "Echo.h"
#include "EmailContact.h"

class ContactManagerUI {
  std::vector<EmailContact>& contacts;
  bool running;
  bool hintsOn;

 public:
  ContactManagerUI(std::vector<EmailContact>& contacts, bool hintsOn);

  void start();

  void stop();

 private:
  void handleInput(char choice);

  void printMenu();

  std::vector<EmailContact>::iterator queryContact();
};

#endif  // !CONTACT_MANAGER_UI_H
