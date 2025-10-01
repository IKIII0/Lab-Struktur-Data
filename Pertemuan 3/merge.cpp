#include <iostream> // Library untuk input/output standar
#include <vector>   // Library untuk menggunakan tipe data vector
using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std:: di setiap fungsi

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
    
    int n1 = mid - left + 1;  // Panjang bagian kiri
    int n2 = right - mid;     // Panjang bagian kanan

    vector<int> L(n1), R(n2); // Membuat dua vector sementara untuk menyimpan bagian kiri dan kanan

    // Menyalin data ke vector L dan R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; // Isi bagian kiri dari arr ke L
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // Isi bagian kanan dari arr ke R

    int i = 0;     // Indeks untuk L
    int j = 0;     // Indeks untuk R
    int k = left;  // Indeks untuk arr (bagian yang akan digabung)

    // Proses penggabungan dua bagian yang sudah terurut
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {      // Jika elemen di L lebih kecil atau sama
            arr[k] = L[i];       // Masukkan elemen dari L ke arr
            i++;                 // Geser indeks L
        } else {
            arr[k] = R[j];       // Masukkan elemen dari R ke arr
            j++;                 // Geser indeks R
        }
        k++; // Geser indeks arr
    }

    // Menyalin sisa elemen dari L jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Menyalin sisa elemen dari R jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk melakukan merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    
    if (left >= right)
        return; // Basis rekursi: jika hanya satu elemen, tidak perlu diurutkan

    int mid = left + (right - left) / 2; // Menghitung indeks tengah

    mergeSort(arr, left, mid);       // Rekursi untuk bagian kiri
    mergeSort(arr, mid + 1, right);  // Rekursi untuk bagian kanan

    merge(arr, left, mid, right);    // Gabungkan dua bagian yang sudah terurut
}

// Fungsi untuk mencetak isi array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; // Cetak setiap elemen array
    }
    cout << endl; // Pindah baris setelah mencetak semua elemen
}

// Fungsi utama
int main() {
    int n;
    cout << "Masukkan jumlah elemen data: "; // Minta jumlah elemen dari pengguna
    cin >> n; // Input jumlah elemen

    vector<int> data(n); // Buat vector dengan ukuran n
    cout << "Masukkan elemen-elemen data: "; // Minta input elemen-elemen
    for (int i = 0; i < n; i++) {
        cin >> data[i]; // Input setiap elemen ke dalam vector
    }

    cout << "Array sebelum diurutkan: ";
    printArray(data); // Cetak array sebelum diurutkan

    mergeSort(data, 0, n - 1); // Panggil fungsi merge sort

    cout << "Array setelah diurutkan: ";
    printArray(data); // Cetak array setelah diurutkan

    return 0; // Selesai
}