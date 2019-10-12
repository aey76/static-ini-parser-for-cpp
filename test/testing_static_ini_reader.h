// #############################################################################
// File Name: testing_static_ini_reader.h
// #############################################################################


class testing_static_ini_reader
{
public:
  bool isReady() const;
  bool loadFile(const char* iniFileToLoad);
  
  IniVar<int> var_1;
};


// --- END OF FILE ---
