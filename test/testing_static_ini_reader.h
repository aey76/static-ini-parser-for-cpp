// #############################################################################
// File Name: testing_static_ini_reader.h
// #############################################################################

// /////////////////////////////////////////////////////////////////////////////
// general types / code
// /////////////////////////////////////////////////////////////////////////////

enum class IniVarType
{
  Mandatory,
  Optional,
  Removed
};

enum class IniVarState
{
  Empty,
  Default_Value,
  Loaded
};

template<typename T>
class IniVar
{
public:
  IniVar() = delete;
  IniVar(IniVarType iniVarType, T minVal, T maxVal):
    m_iniVarState(iniVarType),
    m_minValue(minVal),
    m_maxValue(maxVal),
    m_iniVarState(IniVarState::Empty)
  { }
  
  IniVar(IniVarType iniVarType, T minVal, T maxVal, T defaultVal):
    m_iniVarState(iniVarType),
    m_minValue(minVal),
    m_maxValue(maxVal),
    m_value(defaultVal),
    m_iniVarState(IniVarState::Default_Value)
  { }
  
  IniVarState load(T newValue)
  {
    if ((m_minVal >= newValue) && (newValue <= m_maxValue))
    {
      m_value = newValue;
      m_iniVarState = IniVarState::Loaded;
    }
    
    return (m_iniVarState);
  }
  
  IniVarState state() const { return (m_iniVarState); }
  T value() const           { return (m_value); }
  
private:
  IniVarState m_iniVarState;
  T m_minValue;
  T m_maxValue;
  T m_value;
};


// /////////////////////////////////////////////////////////////////////////////
// generated class based on testing_static_ini_reader.schema.ini
// /////////////////////////////////////////////////////////////////////////////
class testing_static_ini_reader
{
public:
  bool isReady() const;
  bool loadFile(const char* iniFileToLoad);
  
  IniVar<int> v1_int{IniVarType::Mandatory, };
  IniVar<int> v2_int;
  
private:
  
  bool m_isReady = false;
};


// --- END OF FILE ---
