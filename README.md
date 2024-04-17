C++ study repository using SFML

# Bug
**warning appear when run hello_world.cpp with c/c++ extension.**
warning do not appear when run with code runner (g++) or compile in terminal with clang++. problem seem to be associated with debugger but launch setting already set to appopriate debugger (codelldb). could be related to c/c++ extension setting.

```zsh
Warning: Debuggee TargetArchitecture not detected, assuming x86_64.
=thread-selected,id="1"
=library-unloaded,id="/Users/eugenekang/Documents/GitHub/cpp_study/hello_world",target-name="/Users/eugenekang/Documents/GitHub/cpp_study/hello_world",host-name="/Users/eugenekang/Documents/GitHub/cpp_study/hello_world"
Loaded '/usr/lib/dyld'. Symbols loaded.
Loaded '/Users/eugenekang/Documents/GitHub/cpp_study/hello_world'. Symbols loaded.
=library-unloaded,id="/Users/eugenekang/Documents/GitHub/cpp_study/hello_world",target-name="/Users/eugenekang/Documents/GitHub/cpp_study/hello_world",host-name="/Users/eugenekang/Documents/GitHub/cpp_study/hello_world"
```

# Set Up
- env: macos 14.4
- compiler: clang++

## External Libraries
### SFML
> install with homebrew
> location: /opt/homebrew/Cellar/sfml/2.6.1/include

# Commands
> commands for files that use sfml library
> shortcut in Makefile

## Build
create .o file
```zsh
clang++ -c <file_name.cpp> -I"/opt/homebrew/Cellar/sfml/2.6.1/include"
```

create binary file
```zsh
clang++ <file_name.o> -o <file_name> -L"/opt/homebrew/Cellar/sfml/2.6.1/lib" -lsfml-graphics -lsfml-window -lsfml-system
```

## Run
execute binary file
```zsh
./<file_name>
```