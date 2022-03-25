#include <iostream>       // input output stream
#include <thread>         // std::thread berisi fungsi seputar thread, std::this_thread::sleep_for untuk memerintahkan program sleep/pause selama beberapa waktu
#include <chrono>         // std::chrono::milliseconds untuk memberi return waktu 

using namespace std;    //std library

void pause_thread(int n)//fungis untuk melakukan pause pada thread
{
   this_thread::sleep_for(chrono::milliseconds(n));//memanggil fungsi sleep pada library thread menggunakan bantuan parameter chrono untuk melakukan paused
   
   //Percabangan untuk memberikan informasi pause pada setiap thread 
   if (n > 1000) {//Informasi pause untuk thread yang mengimplementasi fungsi EvenNumber
       cout << "\t\t\t\t\t!!!!Pause of 2.5 seconds ended!!!!!\n";
   }
   else {//Informasi pause untuk yang mengimplementasi fungsi OddNumber
       cout << "!!!!!Pause of 1 seconds ended!!!!!\n";
   }
}

void OddNumber() { //fungsi untuk thread pertama
    for (int i = 1; i <= 20; i++)//Perulangan untuk membatasi jumlah jumlah sembako.
    {
        if (i % 2 != 0)//Jika iterator dibagi dua memiliki sisa, maka iterator ganjil dan lakukan aksi di bawah ini
        {
            cout << "Sembako " << i << " (Odd number)" << endl;
            cout << "Start Pausing....\n";//memberi informasi bahwa thread akan dipause
            pause_thread(1000);//pemanggilan fungsi pause thread dengan parameter 1000 millisecond/ 1 second
        }
        cout << endl;
    }

}

void EvenNumber() {//fungsi untuk thread kedua
    for (int i = 1; i <= 20; i++)//Perulangan untuk membatasi jumlah jumlah sembako.
    {
        if (i%2==0)//Jika iterator dibagi dua tidak memiliki sisa, maka iterator genap dan lakukan aksi di bawah ini
        {
            cout << "\t\t\t\t\tSembako " << i << " (even number)" << endl;
            cout << "\t\t\t\t\tStart Pausing....\n";//memberi informasi bahwa thread akan dipause
            pause_thread(2500);//pemanggilan fungsi pause thread dengan parameter 2500 millisecond/ 2.5 second
        }
        cout << endl;
    }
    
}



int main()
{
    thread first(OddNumber);                      // spawn new thread that calls OddNumber
    thread second(EvenNumber);                    // spawn new thread that calls EvenNumber

    // synchronize threads:
    first.join();                                // pauses until first finishes
    second.join();                               // pauses until second finishes

    cout << "\n\n\t\t\t************************Bagi-bagi sembako telah selesai*******************************\n";

    return 0;//exit code(code telah selesai dieksekusi)
}