#include <iostream>
using namespace std;

int main() {
    double liter, total = 0;

    for (int i = 1; i <= 15; i++) {
        cout << "Masukkan liter ke-" << i << ": ";
        cin >> liter;
        total += liter;

        if (liter > 50) {
            cout << "Penjualan tinggi" << endl;
        } else {
                 cout << "Penjualan normal" << endl;
        }
    }

    cout << "Total liter terjual dalam 1 jam = " << total << endl;

    return 0;
}

   