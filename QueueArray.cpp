#include <iostream>
using namespace std;

// array Antrian
int maksimalAntrianArrayFilm = 8, front = 0, back = 0;
// ruang antrian array
string antrianFilm[8];

// isFull / cek data antrian penuh atau tidak
bool isFullArray()
{
    return back == maksimalAntrianArrayFilm;
}

// isEmpty
bool isEmptyArray()
{
    return back == 0;
}

// enqueue / penambahan data antrian
void enqueueArray(string data)
{
    if (isFullArray())
    {
        cout << "Antrian penuh!!" << endl;
    }
    else
    {
        antrianFilm[back] = data;
        back++;
    }
}

// dequeue / penghapusan data depan
void dequeueArray()
{
    if (isEmptyArray())
    {
        cout << "Antrian kosong!!" << endl;
    }
    else
    {
        for (int i = 0; i < back - 1; i++)
        {
            antrianFilm[i] = antrianFilm[i + 1];
        }
        antrianFilm[back - 1] = "";
        back--;
    }
}

// countArray / menghitung banyak data yg ngantri
int countArray()
{
    return back;
}

// destroy / clear
void destroyArray()
{
    if (isEmptyArray())
    {
        cout << "Antrian kosong!!" << endl;
    }
    else
    {
        for (int i = 0; i < maksimalAntrianArrayFilm; i++)
        {
            antrianFilm[i] = "";
        }
        back = 0;
        front = 0;
    }
}

// Display / View
void viewArray()
{
    cout << "Jumlah data Film yang ngantri : " << countArray() << " data." << endl;
    cout << "Data Antrian Film : " << endl;
    if (isEmptyArray())
    {
        cout << "Antrian kosong!!" << endl;
    }
    else
    {
        for (int i = 0; i < maksimalAntrianArrayFilm; i++)
        {
            // cek apakah ruang kosong atau tidak
            if (antrianFilm[i] != "")
            {
                // kalau ruang tidak kosong
                cout << i + 1 << ". " << antrianFilm[i] << endl;
            }
            else
            {
                // kalo kosong
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }
    cout << "\n"
         << endl;
}

int main()
{
    enqueueArray("Real Steel, 120 menit, Rp.40.000");
    viewArray();

    enqueueArray("Harry Potter, 140 menit, Rp.45.000");
    enqueueArray("Avenger, 100 menit, Rp. 60.000");
    enqueueArray("Spiderman, 110 menit, Rp.60.000");
    enqueueArray("Antman, 115 menit, Rp.45.000");
    viewArray();

    enqueueArray("Ironman, 90 menit, Rp.50.000");
    viewArray();

    dequeueArray();
    viewArray();

    enqueueArray("Fast and Furious, 110 menit, Rp.55.000");
    enqueueArray("Batman, 100 menit, Rp.40.000");
    enqueueArray("Superman, 100 menit, Rp.40.000");
    enqueueArray("One Punch Man, 100 menit, Rp.40.000");
    viewArray();

    destroyArray();
    viewArray();

    cout << countArray() << endl;

    return 0;
}
