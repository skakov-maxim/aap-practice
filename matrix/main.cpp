#include <iostream>

int** create_matrix(size_t rows, size_t cols)
{
  int ** m = new int * [rows];
  for (int i = 0; i < rows; i++) {
    m[i] = new int[cols];
  }
  return m;
}

void input_matrix(int** matrix, size_t rows, size_t cols)
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cin >> matrix[i][j];
    }
  }
}

void free_matrix(int ** m, size_t rows)
{
  for (int i = 0; i < rows; i++) {
    delete[] m[i];
  }
  delete[] m;
}

int** transpose_matrix(int **matrix, size_t rows, size_t cols)
{
  int ** t = create_matrix(cols, rows);
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      t[i][j] = matrix[j][i];
    }
  }
  return t;
}

void print_matrix(int** matrix, size_t rows, size_t cols)
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main()
{
  size_t rows = 0, cols = 0;
  std::cin >> rows >> cols;
  int** matrix = nullptr;
  int** transposed = nullptr;
  matrix = create_matrix(rows, cols);
  input_matrix(matrix, rows, cols);
  transposed = transpose_matrix(matrix, rows, cols);
  print_matrix(transposed, cols, rows);
  free_matrix(matrix, rows);
  free_matrix(transposed, cols);
  return 0;
}
