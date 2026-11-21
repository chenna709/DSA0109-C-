@echo off
setlocal
for %%T in (Task01 Task02 Task03 Task04 Task05 Task06) do (
  echo ===== %%T =====
  g++ -std=c++17 -Wall -Wextra -pedantic %%T\main.cpp -o %%T\program.exe
  if errorlevel 1 exit /b 1
  %%T\program.exe
)
g++ -std=c++17 -Wall -Wextra -pedantic Task03\complete_code.cpp -o Task03\complete.exe
Task03\complete.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task05\complete_code.cpp -o Task05\complete.exe
Task05\complete.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task04\predict.cpp -o Task04\predict.cpp
Task04\predict.exe
