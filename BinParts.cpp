#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct parts
{
  string description;
  int numParts;
};

parts addParts(parts part);
parts removeParts(parts part);

int main()
{
  char answer;
  int binNumber;
  bool check = true;

  parts array[10];
  array[0] = {"Valve         ", 10};
  array[1] = {"Bearing       ", 5};
  array[2] = {"Bushing       ", 15};
  array[3] = {"Coupling      ", 21};
  array[4] = {"Flange        ", 7};
  array[5] = {"Gear          ", 5};
  array[6] = {"Gear Housing  ", 5};
  array[7] = {"Vacuum Gripper", 25};
  array[8] = {"Cable         ", 18};
  array[9] = {"Rod           ", 12};

  cout << "Part Description \t Number of Parts in the Bin\n";
  for(int i = 0; i < 10; i++)
  {
    cout << array[i].description << "\t\t\t";
    cout << array[i].numParts << endl;
  }

  do
  {
    cout << "Would you like to quit (q), add parts (a), or remove parts (r)? ";
    cin >> answer;
    if(answer == 'a')
    {
      cout << "Which bin would you like to add to (0-9)? ";
      cin >> binNumber;
      while(binNumber < 0 || binNumber > 9)
      {
        cout << "Please choose a number between 0 and 9. ";
        cin >> binNumber;
      }
      array[binNumber] = addParts(array[binNumber]);
      cout << "Part Description \t Number of Parts in the Bin\n";
      for(int i = 0; i < 10; i++)
      {
        cout << array[i].description << "\t\t\t";
        cout << array[i].numParts << endl;
      }
    }
    else if(answer == 'r')
    {
      cout << "Which bin would you like to remove from (0-9)? ";
      cin >> binNumber;
      while(binNumber < 0 || binNumber > 9)
      {
        cout << "Please choose a number between 0 and 9. ";
        cin >> binNumber;
      }
      array[binNumber] = removeParts(array[binNumber]);
      cout << "Part Description \t Number of Parts in the Bin\n";
      for(int i = 0; i < 10; i++)
      {
        cout << array[i].description << "\t\t\t";
        cout << array[i].numParts << endl;
      }
    }
    else if (answer == 'q')
    {
      check = false;
    }
    else
    {
      cout << "Please enter a q, a, or r.\n";
    }
  }
  while(check);

  return 0;
}

parts addParts(parts part)
{
  int answer;
  int value = part.numParts;

  while(value + answer > 30)
  {
    cout << "How many parts would you like to add? ";
    cin >> answer;
    if(value + answer > 30)
    {
      cout << "You are adding too many parts to this bin. Please choose a different value.\n";
    }
    else if(answer < 0)
    {
      cout << "Please enter a non-negative number.\n";
    }
    else
    {
      part.numParts += answer;
    }
  }

  return part;
}

parts removeParts(parts part)
{
  int answer;
  int value = part.numParts;

  while(value - answer < 0 || answer < 0)
  {
    cout << "How many parts would you like to remove? ";
    cin >> answer;
    if(value - answer < 0)
    {
      cout << "You are removing too many parts to this bin. Please choose a different value.\n";
    }
    else if(answer < 0)
    {
      cout << "Please enter a non-negative number.\n";
    }
    else
    {
      part.numParts -= answer;
    }
  }

  return part;
}
