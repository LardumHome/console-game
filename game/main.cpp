#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <algorithm> 

#include <string>
#include <vector>
#include <cstring>

std::string title {
"   +--------------------------------------------------------------------+ \n"
"   |   _____                      _         _____                       |\n"
"   |  / ____|                    | |       / ____|                      |\n"
"   | | |     ___  _ __  ___  ___ | | ___  | |  __  __ _ _ __ ___   ___  |\n"
"   | | |    / _ \\| '_ \\/ __|/ _ \\| |/ _ \\ | | |_ |/ _` | '_ ` _ \\ / _ \\ |\n"
"   | | |___| (_) | | | \\__ \\ (_) | |  __/ | |__| | (_| | | | | | |  __/ |\n"
"   |  \\_____\\___/|_| |_|___/\\___/|_|\\___|  \\_____|\\__,_|_| |_| |_|\\___| |\n"
"   |                        Developed by Lardum                         |\n"
"   +--------------------------------------------------------------------+\n"
"                             1: Start a game\n"
"                             *: Close out of game\n"
">"                                      
};

/*
  Create modded maps here
*/
std::string level{
  "+-------------------+\n"
  "|                   |\n"
  "|                   |\n"
  "|                   |\n"
  "|                   |\n"
  "|                   |\n"
  "|                   |\n"
  "|                   |\n"
  "|o                  |\n"
  "+-------------------+\n"
};


void canMove(std::string direction)
{
  std::string newPos = "";
  
  const std::string& str = level;
  int arrSize {0};
    
  std::vector<std::string> substrings;
 
  for (size_t i = 0; i < str.size(); i++) {
      substrings.push_back(str.substr(i, 1));
      arrSize += 1;
  }
    
  bool oVis = false;
    
  for (auto &token : substrings)
  {
    if (token == "o")
    {
      oVis = true;
    }
  }
  
  if (direction == "W")
  {
    for (int i = 0; i < arrSize; i++)
    {
      if (substrings[i] == "o" && oVis == true)
      {
        if (substrings[i - 22] == " ")
        {
          substrings[i - 22] = "o";
          substrings[i] = " ";
        }
      }
    }
  } 
  if (direction == "S")
  {
    for (int i = 0; i < arrSize; i++)
    {
      if (substrings[i] == "o" && oVis == true)
      {
        if (substrings[i + 22] == " ")
        {
          substrings[i + 22] = "o";
          substrings[i] = " ";
          break;
        }
      }
    }
  }
  if (direction == "D")
  {
    for (int i = 0; i < arrSize; i++)
    {
      if (substrings[i] == "o" && oVis == true)
      {
        if (substrings[i + 1] == " ")
        {
          std::cout << i << " : " << substrings[i] << std::endl;
          substrings[i + 1] = "o";
          substrings[i] = " ";
          break;
        }
      }
    }
  }
  if (direction == "A")
  {
    for (int i = 0; i < arrSize; i++)
    {
      if (substrings[i] == "o" && oVis == true)
      {
        if (substrings[i - 1] == " ")
        {
          std::cout << i << " : " << substrings[i] << std::endl;
          substrings[i - 1] = "o";
          substrings[i] = " ";
          break;
        }
      }
    }
  }
  
  for (int i = 0; i < arrSize; i++)
  { 
    newPos = newPos + substrings[i];
  }
  
  level = newPos;
}

void clear()
{
  #if defined _WIN32
    system("cls");
  #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
  #elif defined (__APPLE__)
    system("clear");
  #endif
}

void move(std::string direction)
{
  std::transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c){return std::toupper(c);});
  
  if (direction == "W" || direction == "A" || direction == "S" || direction == "D")
  {
    canMove(direction);
  } else {
    clear();
    std::cout << "Invalid Key" << std::endl;
    sleep(2);
  }
}

int main()
{
    while (1)
    {
      clear();
      std::cout << title;
      char c = getch();

      if (c == '1') {
        break;
      }
      if (c == '*')
      {
            clear();
            std::cout << "+--------------------+\n" 
                      << "| The game has ended |\n" 
                      << "+--------------------+\n" << std::endl;
            sleep(2);
            std::abort();
      }
    }
    

    while (1)
    {
        clear();
        std::cout << level << std::endl;
      
        std::cout << "Select Movement(W,A,S,D): ";
        char c = getch();
        std::string s = "";

        s += std::string(1, c);

        if (s == "*")
        {
            clear();
            std::cout << "+--------------------+\n" 
                      << "| The game has ended |\n" 
                      << "+--------------------+\n" << std::endl;
            sleep(2);
            break;
        }
        move(s);
    }
}
