#include <iostream>
#include <string>


struct timeholder {
  int hours, minutes;
  std::string ap;
};

// prints the data from the struct
int display_results(timeholder *to_print, std::string directionality) {
  std::cout << "The time is: " << to_print->hours <<":" << to_print->minutes;
  if (directionality == "2")
  {
    std::cout << to_print->ap << std::endl;
  }
  else {
    std::cout << std::endl;
  }
  return 0;
}

// converts the data from 12 to 24 hour format.
int convert_time(timeholder *input_time, std::string directionality) 
{
  if (directionality == "2")
  {
    if (input_time->hours >= 12)
    {
      input_time->hours -= 12;
      input_time->ap = "p.m.";
    }
    else 
    {
      input_time->ap = "a.m.";
    }
  }
  else 
  {
    if (input_time->ap == "p")
    {
      input_time->hours += 12;
      input_time->ap = "p.m.";
    }
  }
  return 0;
}

// get input from the user about the time to be converted
timeholder get_input(std::string direction) {
  timeholder th;

  std::cout << "Enter hours: ";
  std::cin >> th.hours;

  std::cout << "Enter minutes: ";
  std::cin >> th.minutes;
  if (direction == "1")
  {
    std::cout << "Enter AM/PM (A or P): ";
    std::cin >> th.ap;

  }
  return th;
}

// display the option menu for choosing between 12 and 24 hour formats
std::string display_menu() {
  std::string option;
  std::cout << "Options --\n1: To convert time from 12-hour notation to 24-hour notation.\n2: To convert time from 24-hour notation to 12-hour notation.\n0: To quit the program\nChoose:" << std::endl;
  std::cin >> option;
  return option;
}

int main()
{
    std::string command;

    command = display_menu();
    while ("0" != command) {
      timeholder input_time = get_input(command);
      convert_time(&input_time,command);
      display_results(&input_time,command);
      command = display_menu();
    };
}