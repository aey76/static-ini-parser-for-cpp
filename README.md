# Project under construction !!!


# Roadmap
  - [ ] First version with that support built-in types - WIP
  - [ ] Add support for user defined types
  - [ ] Performance


# static-ini-reader-for-cpp
Define INI schema to generate INI file and cpp code to load and validate INI files in static way.
The idea is to make INI schema file, run the python script on it to produce cpp class that has:
1. publich load function that load and validate your INI file. if validation pass the function populate all the public variables.
2. public variable for every variable in the INI file.

## INI Schema File
The INI schema file is INI file. It defines the variables and additional rules for every variable.

Simple INI schema just to get the idea:

``` INI
################################################################################
# File Name: sample.schema.ini
################################################################################

# define variable named var_1 that will be translated to int variable in the cpp
# code, his value must be ((var_1 >= -10) && (var_1 <= 200))
var_1 = mandatory, int, [-10, 200]

# define variable named var_2 that will be translated to std::string variable in
# the cpp code, his valid values can be "hello_world_1", "hello_world_2" or
# "hello_world_3" and if it is not exist in the INI file the variable will get
# default value of "hello_world_1".
var_2 = optional, std::string, ["hello_world_1", "hello_world_2", "hello_world_3"], ["hello_world_1"]
```

after running the script on the above INI schema file you will get two files: sample.ini and sample.hpp.

``` INI
# File Name: sample.ini

# var_1: mandatory, int, [-10, 200]
var_1 = 

# var_2: optional, std::string, ["hello_world_1", "hello_world_2", "hello_world_3"]
var_2 = "hello_world_1"
```

``` cpp
// #############################################################################
// File Name: sample.hpp
// #############################################################################

enum class IniVarState
{
  Empty,
  Has_Default_Value,
  Has_Valid_Value
};

template<typename T>
class IniVar
{
public:
  IniVarState state() const { return (m_varState); }
  T value() const           { return (m_value); }
  
private:
  bool  m_varState = IniVarState::Empty;
  T     m_value;
};

class Sample
{
public:
  bool isReady();
  bool loadFile(const char* iniFileToLoad);
  
  IniVar<int>         var_1;
  IniVar<std::string> var_2;
};
```

Then, in your code you simply do:

``` cpp
// #############################################################################
// File Name: some_cpp_file.cpp
// #############################################################################

#include "sample.hpp"

int main()
{
  Sample ini;
  
  ini.loadFile("my_sample.ini");
  
  if (ini.isReady())
  {
    std::cout << "var_1 = " << ini.var_1.value() << "\n";
    std::cout << "var_2 = " << ini.var_2.value() << "\n";
  }
  
  return 0;
}
```

Check ini_schema_rules.md for complete rules definition.
