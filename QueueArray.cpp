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
    enqueueArray("Real Steel");
    viewArray();

    enqueueArray("Harry Potter");
    enqueueArray("Avenger");
    enqueueArray("Spiderman");
    enqueueArray("Antman");
    viewArray();

    enqueueArray("Ironman");
    viewArray();

    dequeueArray();
    viewArray();

    enqueueArray("Fast and Furious");
    enqueueArray("Batman");
    enqueueArray("Superman");
    enqueueArray("One Punch Man");
    viewArray();

    destroyArray();
    viewArray();

    cout << countArray() << endl;

    return 0;
}
