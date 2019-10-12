

# INI variables definition

INI variables defined using this general pattern:

``` INI
var_name = ini variable type, cpp variable type, valid values, default value / [err]
```

## ini variable type
Can be one of:
  - **mandatory**: Mark the variable as mandatory, if the variable is not exist in the loaded INI file the load will fail.  
  - **optional**: Mark the variable as optional, loading INI file without this variable will not fail the load process.
  - **removed**: Mark the variable as obsulite that must not exist in the INI file, if the loaded INI file contains removed variables the load will fail.
  - **same-as**: 

## cpp variable type
Defines the variable type, can be:
  - Any builtin type of cpp (`int`, `unsigned`, `bool`, `char`, `double`, `float`, `int8_t`, `int64_t`, `uint8_t`, `uint64_t`, `std::string`)
  - User defined enum by setting the type to `enum class MyEnum`

## valid values
Defines the valid values of the variable, For:
  - numeric types: [`min value`, `max value`] or `[*]` to accept any value the type can handle.
  - bool: must be `[*]`, allowing just true or just false does not make logical sense.
  - std::string: [`"string_1"`, `"string_2"`, ..., `"string_n"`] or `[*]` to accept any string.
  - enum class: [`Enum_Val_1`, `Enum_Val_2`, ..., `Enum_Val_n`], `[*]` is not allowed for enums.

## default value
Relavent only for `optional` ini variable type, defines the cpp variable value in case the ini variable is missing from the loaded INI file.
The default value must be valid value.

# Examples

**mandatory int variable**:
``` INI
var_name = mandatory, int, [-20, 1900]
```

**optional uint32_t variable with default value of 100**:
``` INI
var_name = optional, uint32_t, [20, 1900], [100]
```

**optional bool variable with default value of true**:
``` INI
var_name = optional, bool, [*], [true]
```

**mandatory enum variable**:
``` INI
var_name = mandatory, enum class MyEnum, [Val_0, Val_1, Val_2, Val_3]
```

**optional enum variable with default value of Val_1**:
``` INI
var_name = optional, enum class MyEnum, [Val_0, Val_1, Val_2, Val_3], [Val_1]
```

**removed variable**:
``` INI
var_name = removed
```

**same-as variable**:
``` INI
var_name_1 = optional, uint32_t, [20, 1900], [100]
var_name_2 = same-as, var_name_1
```
