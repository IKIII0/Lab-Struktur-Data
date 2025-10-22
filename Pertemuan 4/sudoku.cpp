/*
Nama: Rifki Al Sauqy 
NIM: 241401007
*/
#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) { // mengecek apakah ada angka yang sama sejajar secara vertikal dan horizontal
            return false; // jika ada maka return false
        }
    }

    // Periksa sub-kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) { // mengecek sub-kota 3x3 apakah ada angka yang sama secara vertikal dan horizontal
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false; // jika ada angka yang sama maka return false
            }
        }
    }

    return true; // return true jika semua pengecekan tidak ada angka yang sama secara vertikal dan horizontal
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) { // Iterasi seluruh sel papan
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) { // Jika sel kosong (berisi 0)
                for (int num = 1; num <= 9; num++) { // Coba masukkan angka dari 1 sampai 9
                    if (isValid(board, row, col, num)) { // Periksa apakah angka valid di posisi ini
                        board[row][col] = num; // Masukkan angka ke sel

                        if (solveSudoku(board)) { // Rekursi: lanjutkan ke sel berikutnya
                            return true; // Jika berhasil, kembalikan true
                        }
                        board[row][col] = 0; // Jika gagal, kosongkan kembali sel (backtrack)
                    }
                }
                return false; // Jika tidak ada angka yang valid, kembalikan false (backtrack)
            }
        }
    }
    return true; // Jika tidak ada lagi sel kosong, berarti solusi ditemukan
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}