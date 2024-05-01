#include <corecrt_wstdio.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>


int main(int argc, char** argv) {

  std::ifstream infile("curSalary.txt");
  std::ofstream outfile("newSalary.txt");

  // Verify files opened correctly
  if (infile.fail() || outfile.fail()) {

    std::cout << "Failed to open files\n";
    return 1;
  }

  // Declare variables used in loop
  double salary, raise;
  char output[250], firstname[64], lastname[64];
  int count = 0;

  while (infile >> lastname >> firstname >> salary >> raise) {
    salary *= (1 + raise / 100);
    snprintf(output, 250, "%s %s %.2f\n", lastname, firstname, salary);
    //std::cout << output << std::endl;
    outfile << output;
    count++;
  }

  // Report records processed
  if (count)
    std::cout << count << " records processed and saved in \"newSalary.txt\"." << std::endl;
  else
    std::cout << "Warning: empty input file. Output file created but is empty." << std::endl;

  // Close files and return
  infile.close();
  outfile.close();
  return 0;
}