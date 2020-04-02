
Setelah selesai mengimplementasikan soal sebelumnya, buatlah driver pada **Main.java** dengan spesifikasi yang dijelaskan pada bagian Format Input dan Format Output.

## Format Input

Baris pertama program akan menerima sebuah string **S** yang merepresentasikan jenis fuel dari mobil yang akan dilakukan interaksi. Setelah itu, program akan menerima **input** operasi yang akan dilakukan terus menerus sampai dimasukan operasi untuk berhenti. Operasi yang dapat dilakukan adalah sebagai berikut.

1. 'Fill <Fuel> <Amount>',   mengisi bensin mobil dengan bensin berjenis <Fuel> sebanyak <Amount>.
2. 'ChangeGear <Gear>',   mengganti gigi mobil menjadi <Gear>.
3. 'ChangeAcPower <AcPower>',   mengganti power ac mobil menjadi <AcPower>.
4. 'Start',   menyalakan mobil.
5. 'Service <Fuel> <Amount> <Gear> <AcPower>', melakukan pergantian pengecekan seluruh fitur mobil.
6. 'End', mengakhiri program.
7. Selain operasi di atas, program akan melempar Exception dengan message "Masukan tidak valid".

**Program tidak langsung berhenti jika menemukan Exception berupa FuelException, InvalidInputCarException, atau TheCarIsOnException.** Artinya, program akan tetap menjalankan interaksi berikutnya meskipun program menemukan Exception untuk interaksi sebelumnya. **Namun, program akan langsung berhenti jika menemukan Exception selain yang di atas.**

## Format Output

Untuk setiap interaksi, keluarkan output dari method yang dijalankan sesuai dengan spesifikasi yang diberikan. Jika method melempar Exception, cetaklah dengan format

`[{nama_exception}] {message_exception}]`

Pada akhir eksekusi program cetak "Program selesai" (termasuk jika ditemui unhandled Exception). Cetak juga "Tidak ada unhandled exception", jika program berakhir tanpa adanya unhandled exception.

## Contoh Interaksi
| Input | Output |
|-------|--------|
| PERTAMAX <br> <br> Fill SOLAR 2<br> Service PERTAMAX 3 2 0<br> Start<br> ChangeGear 1<br> ChangeAcPower 5<br> End | [FuelException] Bensin jenis SOLAR tidak sesuai <br> Berhasil melakukan starter mobil <br> Berhasil isi bensin sebanyak 3 liter <br> Berhasil mengubah gigi menjadi gigi 2 <br> Berhasil mengubah power ac menjadi 0 <br> [TheCarIsOnException] Mobil sudah menyala <br> Berhasil mengubah gigi menjadi gigi 1 <br> [InvalidInputCarException] Input 5 diluar range <br> Program selesai <br> Tidak ada unhandled exception |
| PERTAMAX <br> Fill PERTAMAX 5 <br> Selesai | Berhasil isi bensin sebanyak 5 liter <br> Program selesai |


**Catatan:** Tambahkan **throws Exception** pada method **main.**

Kumpulkan hanya **Main.java** nya saja.