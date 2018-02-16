#include <iostream>
#include <future>
#include <vector>


int fibonacci(int input) {
  if(input == 0 || input == 1) {
    return input;
  }

  int beforePrevious = 0;
  int previous = 0;
  int result = 1;


  for(int i = 1; i < input; ++i) {
    beforePrevious = previous;
    previous = result;
    result = beforePrevious + previous;
  }
  return result;
}

int getGreatestCommonDivisor(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int getLeastCommonMultiple(int a, int b) {
  return a*b / getGreatestCommonDivisor(a, b);
}

int main() {
  int x;
  int y;
  std::cout << "Give 2 numbers:" << std::endl;
  std::cin >> x >> y;

  //auto = std::future<int>
  auto fibonacciFromX = std::async(fibonacci, x);
  auto fibonacciFromY = std::async(fibonacci, x);
  auto leastCommonMultipleFromXY = std::async(getLeastCommonMultiple, x, y);
  std::cout << "Sum:" << fibonacciFromX.get() + fibonacciFromY.get() + leastCommonMultipleFromXY.get();

  return 0;
}
