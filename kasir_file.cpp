#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

// CLASS BARANG
class barang {
    public:
        string nama;
        int jumlah;
        double harga;

        barang(string n, int j, double h) {
            nama = n;
            jumlah = j;
            harga = h;
        }

        double total() const {
            return jumlah * harga;
        }
};

//class kasir
class kasir {
    private:
        vector<barang> daftar_barang;
        double totalBelanja = 0;

    public:
    //tambahkan fungsi
    void tambahBarang() {
        string nama;
        int jumlah;
        double harga;
        char lagi;

        do {
            //input barang, harga, dan jumlah
            cout << "\nMasukan Nama Barang: ";
            cin >> ws;
            getline(cin, nama);
            cout << "Masukan Harga Barang: ";
            cin >> harga;
            cout << "Masukan Jumlah Barang: ";
            cin >> jumlah;

            //daftarkan ke daftar barang
            barang b(nama, jumlah, harga);
            daftar_barang.push_back(b);

            //kode konfirm
            cout << "Tambah barang lagi? (y/n)";
            cin >> lagi;

            //agar dapat menggunakan huruf kapital/nonkapital
            lagi = toupper(lagi);
            cout << endl;
        } while (lagi == 'Y');
    }

    void hitungTotal() {
        totalBelanja = 0;
        for (auto &b : daftar_barang) {
            totalBelanja += b.total();
        }
    }

    void cetakStruk() {
        ofstream file("struk.txt"); //file untuk di isi oleh struk
        double bayar, kembalian;

        hitungTotal();

        cout << fixed << setprecision(2);
        cout << "\n====================\n";
        cout << "   STRUK PEMBAYARAN    \n";
        cout << "\n====================\n";
        cout << left << setw(15) << "Nama Barang" << setw(10) << "Jumlah" << setw(10) << "Harga" << setw(10) << "Total" << endl;
        //masuk/tersimpan ke file
        file << "\n====================\n";
        file << "   STRUK PEMBAYARAN    \n";
        file << "\n====================\n";
        file << left << setw(15) << "Nama Barang" << setw(10) << "Jumlah" << setw(10) << "Harga" << setw(10) << "Total" << endl;

        for (auto &b : daftar_barang) {
            cout << left << setw(15) << b.nama << setw(10) << b.jumlah << setw(10) << b.harga << setw(10) << b.total() << endl;
        }

        cout << "\n====================\n";
        cout << "Total Belanja : Rp " << totalBelanja << endl;
        cout << "Masukan Uang Bayar : Rp ";
        cin >> bayar;
        
        if (kembalian == ' ') {
            cout << 0 << endl;
        } else {
            kembalian = bayar - totalBelanja;
        }

        cout << "Kembalian Anda : Rp " << kembalian;
        cout << "\n====================\n";
        cout << "Terimakasih telah berbelanja!"<< endl;
        cout << "\n====================\n";

        
        //simpan ke file
        file << "====================\n";
        file << "Total Belanja : Rp " << totalBelanja << endl;
        file << "Uang Bayar : Rp " << bayar << endl;
        file << "Kembalian : Rp " << kembalian << endl;
        file << "====================\n";
        file << "Terimakasih telah berbelanja!" << endl;
    }
};

// fungsi utama
int main() {
    kasir k;
    cout << "=== PROGRAM KASIR SEDERHANA (OOP + FILE) ===\n";
    k.tambahBarang();
    k.cetakStruk();

    return 0;
}