#!/usr/bin/env bash
set -e
for task in Task01 Task02 Task03 Task04 Task05 Task06; do
  echo "===== $task ====="
  g++ -std=c++17 -Wall -Wextra -pedantic "$task/main.cpp" -o "$task/program"
  "./$task/program"
done
g++ -std=c++17 -Wall -Wextra -pedantic Task03/complete_code.cpp -o Task03/complete
./Task03/complete
g++ -std=c++17 -Wall -Wextra -pedantic Task05/complete_code.cpp -o Task05/complete
./Task05/complete
g++ -std=c++17 -Wall -Wextra -pedantic Task04/predict.cpp -o Task04/predict
./Task04/predict
