

INI variables definition general pattern:

``` INI
var_name = mandatory or optional, variable type, valid values, default value / [err]
```

**mandatory** - Mark the variable as mandatory, if the variable is not exist in the loaded INI file the load will fail.  
**optional** - Mark the variable as optional, loading INI file without this variable will not fail the load process.

**variable type** - define the variable type, can be any build in type of cpp (`int`, `unsigned`, `bool`, `char`, `int8_t`, `int64_t`, `uint8_t`, `uint64_t`, `std::string`) or user defined enum by setting the type to `enum class MyEnum`.
