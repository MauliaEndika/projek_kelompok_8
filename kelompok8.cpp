#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Deklarasi kelas Reservasi
class Reservasi {
public:
    int id;
    string namaTamu;
    string tanggalCheckIn;
    string tanggalCheckOut;
    string tipeKamar;

    // Method untuk menampilkan detail reservasi
    void tampilkanReservasi() const {
        cout << "ID: " << id << endl;
        cout << "Nama Tamu: " << namaTamu << endl;
        cout << "Tanggal Check-In: " << tanggalCheckIn << endl;
        cout << "Tanggal Check-Out: " << tanggalCheckOut << endl;
        cout << "Tipe Kamar: " << tipeKamar << endl;
    }
};

// Deklarasi kelas Hotel
class Hotel {
private:
    vector<Reservasi> daftarReservasi;
    int nextId; // Untuk menghasilkan ID unik untuk setiap reservasi

public:
    Hotel() : nextId(1) {}

    // Method untuk menambah reservasi baru
    void tambahReservasi(const string& namaTamu, const string& tanggalCheckIn, const string& tanggalCheckOut, const string& tipeKamar) {
        Reservasi reservasi;
        reservasi.id = nextId++;
        reservasi.namaTamu = namaTamu;
        reservasi.tanggalCheckIn = tanggalCheckIn;
        reservasi.tanggalCheckOut = tanggalCheckOut;
        reservasi.tipeKamar = tipeKamar;
        daftarReservasi.push_back(reservasi);
        cout << "Reservasi berhasil ditambahkan!" << endl;
    }

    // Method untuk menghapus reservasi berdasarkan ID
    void hapusReservasi(int id) {
        auto it = find_if(daftarReservasi.begin(), daftarReservasi.end(), [&](const Reservasi& r) {
            return r.id == id;
        });

        if (it != daftarReservasi.end()) {
            daftarReservasi.erase(it);
            cout << "Reservasi dengan ID " << id << " berhasil dihapus!" << endl;
        } else {
            cout << "Reservasi dengan ID tersebut tidak ditemukan!" << endl;
        }
    }

    // Method untuk mencari reservasi berdasarkan ID
    void cariReservasi(int id) const {
        auto it = find_if(daftarReservasi.begin(), daftarReservasi.end(), [&](const Reservasi& r) {
            return r.id == id;
        });

        if (it != daftarReservasi.end()) {
            it->tampilkanReservasi();
        } else {
            cout << "Reservasi dengan ID tersebut tidak ditemukan!" << endl;
        }
    }

    // Method untuk mencari reservasi berdasarkan nama tamu
    void cariReservasi(const string& namaTamu) const {
        bool found = false;
        for (const auto& reservasi : daftarReservasi) {
            if (reservasi.namaTamu == namaTamu) {
                reservasi.tampilkanReservasi();
                found = true;
            }
        }
        if (!found) {
            cout << "Reservasi dengan nama tamu tersebut tidak ditemukan!" << endl;
        }
    }

    // Method untuk mengedit reservasi berdasarkan ID
    void editReservasi(int id, const string& namaTamu, const string& tanggalCheckIn, const string& tanggalCheckOut, const string& tipeKamar) {
        auto it = find_if(daftarReservasi.begin(), daftarReservasi.end(), [&](const Reservasi& r) {
            return r.id == id;
        });

        if (it != daftarReservasi.end()) {
            it->namaTamu = namaTamu;
            it->tanggalCheckIn = tanggalCheckIn;
            it->tanggalCheckOut = tanggalCheckOut;
            it->tipeKamar = tipeKamar;
            cout << "Reservasi dengan ID " << id << " berhasil diperbarui!" << endl;
        } else {
            cout << "Reservasi dengan ID tersebut tidak ditemukan!" << endl;
        }
    }

    // Method untuk menampilkan semua reservasi yang ada
    void tampilkanSemuaReservasi() const {
        if (daftarReservasi.empty()) {
            cout << "Tidak ada reservasi." << endl;
        } else {
            for (const auto& reservasi : daftarReservasi) {
                reservasi.tampilkanReservasi();
                cout << "-----------------------------" << endl;
            }
        }
    }
};

// Fungsi utama
int main() {
    Hotel hotel;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Reservasi\n";
        cout << "2. Hapus Reservasi\n";
        cout << "3. Cari Reservasi (Nama Tamu)\n";
        cout << "4. Cari Reservasi (ID)\n";
        cout << "5. Edit Reservasi\n";
        cout << "6. Tampilkan Semua Reservasi\n";
        cout << "7. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan karakter newline dari buffer input

        string namaTamu, tanggalCheckIn, tanggalCheckOut, tipeKamar;
        int id;

        switch (pilihan) {
        case 1:
            cout << "Nama Tamu: ";
            cin.ignore(); // Membersihkan karakter newline yang tersisa di buffer
            getline(cin, namaTamu);
            cout << "Tanggal Check-In (YYYY-MM-DD): ";
            getline(cin, tanggalCheckIn);
            cout << "Tanggal Check-Out (YYYY-MM-DD): ";
            getline(cin, tanggalCheckOut);
            cout << "Tipe Kamar: ";
            getline(cin, tipeKamar);
            hotel.tambahReservasi(namaTamu, tanggalCheckIn, tanggalCheckOut, tipeKamar);
            break;
        case 2:
            cout << "ID Reservasi: ";
            cin >> id;
            hotel.hapusReservasi(id);
            break;
        case 3:
            cout << "Nama Tamu: ";
            cin.ignore(); // Membersihkan karakter newline yang tersisa di buffer
            getline(cin, namaTamu);
            hotel.cariReservasi(namaTamu);
            break;
        case 4:
            cout << "ID Reservasi: ";
            cin >> id;
            hotel.cariReservasi(id);
            break;
        case 5:
            cout << "ID Reservasi: ";
            cin >> id;
            cin.ignore(); // Membersihkan karakter newline yang tersisa di buffer
            cout << "Nama Tamu: ";
            getline(cin, namaTamu);
            cout << "Tanggal Check-In (YYYY-MM-DD): ";
            getline(cin, tanggalCheckIn);
            cout << "Tanggal Check-Out (YYYY-MM-DD): ";
            getline(cin, tanggalCheckOut);
            cout << "Tipe Kamar: ";
            getline(cin, tipeKamar);
            hotel.editReservasi(id, namaTamu, tanggalCheckIn, tanggalCheckOut, tipeKamar);
            break;
        case 6:
            hotel.tampilkanSemuaReservasi();
            break;
        case 7:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 7);

    return 0;
}