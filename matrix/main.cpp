#include <iostream>
#include <stdexcept>
#include <new>

void free_matrix(int ** m, size_t rows)
{
  for (size_t i = 0; i < rows; ++i) {
    delete[] m[i];
  }
  delete[] m;
}

int** create_matrix(size_t rows, size_t cols)
{
  int ** m = new int * [rows]();
  try {
    for (size_t i = 0; i < rows; ++i) {
      m[i] = new int[cols];
    }
  } catch (...) {
    free_matrix(m, rows);
    throw;
  }
  return m;
}

void input_matrix(int** matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (!(std::cin >> matrix[i][j])) {
        throw std::invalid_argument("bad input");
      }
    }
  }
}

int** transpose_matrix(int **matrix, size_t rows, size_t cols)
{
  int ** t = create_matrix(cols, rows);
  for (size_t i = 0; i < cols; ++i) {
    for (size_t j = 0; j < rows; ++j) {
      t[i][j] = matrix[j][i];
    }
  }
  return t;
}

void print_matrix(int** matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main()
{
  size_t rows = 0, cols = 0;
  if (!(std::cin >> rows >> cols)) {
    return 1;
  }
  int** matrix = nullptr;
  int** transposed = nullptr;
  try {
  matrix = create_matrix(rows, cols);
  input_matrix(matrix, rows, cols);
  transposed = transpose_matrix(matrix, rows, cols);
  print_matrix(transposed, cols, rows);
  } catch (const std::invalid_argument &) {
    return 1;
  } catch (const std::bad_alloc &) {
    return 2;
  }
  free_matrix(matrix, rows);
  free_matrix(transposed, cols);
  return 0;
}
