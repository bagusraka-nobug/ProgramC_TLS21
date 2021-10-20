#include <iostream>
#include <windows.h>

using namespace std;

void countdown(int jam, int menit, int detik)
{
    string waktu;
    while (true)
    {
        if(detik == 0 && menit == 0 && jam == 0)
        {
            break;
        }
        if(detik == 0 && menit == 0)
        {
            menit = 60;
            jam--;
        }
        if(detik == 0)
        {
            detik = 60;
            menit--;
        }
        cout<<string(waktu.length(), '\b');
        waktu = to_string(jam) + " : " + to_string(menit) + " : " + to_string(detik--) + " ";
        cout<<waktu;
        Sleep(1000);
    }
}

int main()
{
    program:
    int pilihan, tugas, count = 0, yt;

    cout<<"Selamat datang di Program Penjadwalan Pengerjaan Tugas";
    cout<<"\nSemoga lebih produktif :)";
    cout<<"\n\nProgram ini menawarkan dua cara untuk penjadwalan";
    cout<<"\nSilahkan pilih!";
    cout<<"\n 1. Metode Pomodoro";
    cout<<"\n 2. Mengatur sendiri tugas dan waktu pengerjaan";
    cout<<"\n 3. Keluar dari program";
    cout<<"\nPilihan: "; cin>>pilihan;

    if (pilihan == 1)
    {
        pomodoro:
        cout<<"\nMetode Pomodoro";
        cout<<"\nMasukkan jumlah tugas yang ingin Anda kerjakan (isi dengan angka): "; cin>>tugas;
        string stugas [tugas];
        cin.ignore();
        for (int i = 0; i < tugas; i++)
        {
            cout<<"Masukkan tugas ke-"<<i+1<<": "; getline(cin, stugas[i]);
        }
        cout<<"\nTerimakasih sudah mengisi tugas-tugas Anda!";
        gas:
        cout<<"\nAnda akan mengerjakan tugas berikut";
        cout<<"\nTugas"<<"\t\tWaktu Mengerjakan\n";
        cout<<"---------------------------------\n";
        for (int i = 0; i < tugas; i++)
        {
            cout<<stugas[i]<<"\t\t25 Menit";
            if(count < 3)
            {
                cout<<"\nIstirahat\t5 Menit\n";
                count++;
            }
            else
            {
                cout<<"\nIstirahat\t15 Menit\n";
                count = 0;
            }
        }
        count = 0;
        cout<<"\nSiap mengerjakan? \n1 = Ya \n2 = Tidak \n3 = Reset Tugas \nPilihan: "; cin>>yt;
        if (yt == 1)
        {
            for (int i = 0; i < tugas; i++)
            {           
                cout<<"\n\nSelamat mengerjakan tugas '"<<stugas[i]<<"' selama 25 menit";
                cout<<"\nFokus mengerjakan ya!\nNanti setelah 25 menit akan ada bunyi dan perintah selanjutnya\n";
                countdown(0,25,0);
                Beep(500, 5000);
                cout<<"\n\nSelamat kamu sudah mengerjakan tugas '"<<stugas[i]<<"' selama 25 menit!";
                if (count < 3)
                {
                    cout<<"\nSekarang saatnya beristirahat selama 5 menit!\n";
                    countdown(0,5,0);
                    Beep(500, 5000);
                    count++;
                }
                else
                {
                    cout<<"\n\nSelamat beristirahat panjang selama 15 menit!";
                    cout<<"\nTerimakasih!\n";
                    countdown(0,15,0);
                    Beep(500, 5000);
                    count = 0;
                }
                if (i == tugas-1)
                {
                    cout<<"\nSelamat kamu sudah menyelesaikan semua tugasmu!\n";
                    goto program;
                }
            }
        }
        else if(yt == 2)
        {
            cout<<"\nOke kami tunggu sampai Anda siap";
            goto gas;
        }
        else if(yt == 3)
        {
            goto pomodoro;
        }
        else
        {
            cout<<"Angka yang anda masukkan salah";
            cout<<"\nSilahkan masukan angka 1 untuk Ya atau 0 untuk Tidak";
            goto gas;
        }
    }
    else if (pilihan == 2)
    {
        pengguna:
        cout<<"\nMengatur Tugas dan Waktu Sendiri";
        cout<<"\nMasukkan jumlah tugas yang ingin Anda kerjakan (isi dengan angka): "; cin>>tugas;
        string stugas [tugas];
        int jam [tugas];
        int menit  [tugas];
        int detik [tugas];
        int jamI [tugas];
        int menitI [tugas];
        int detikI [tugas];
        for (int i = 0; i < tugas; i++)
        {
            cout<<"\nMasukkan tugas ke-"<<i+1<<": "; cin.ignore(); getline(cin, stugas[i]);
            cout<<"\nMasukkan waktu untuk tugas ke-"<<i+1;
            cout<<"\nBerapa jam?: "; cin>>jam[i];
            cout<<"Berapa menit?: "; cin>>menit[i];
            cout<<"Berapa detik?: "; cin>>detik[i];
            cout<<"\nMasukkan waktu istirahat setelah tugas ke-"<<i+1;
            cout<<"\nBerapa jam?: "; cin>>jamI[i];
            cout<<"Berapa menit?: "; cin>>menitI[i];
            cout<<"Berapa detik?: "; cin>>detikI[i];
        }
        cout<<"\nTerimakasih sudah mengatur tugas dan waktunya!";
        gas1:
        cout<<"\nAnda akan mengerjakan tugas berikut";
        cout<<"\nTugas"<<"\t\tWaktu Mengerjakan\n";
        cout<<"---------------------------------\n";
        for (int i = 0; i < tugas; i++)
        {
            cout<<stugas[i]<<"\t\t"<<jam[i]<<":"<<menit[i]<<":"<<detik[i];
            cout<<"\nIstirahat\t"<<jamI[i]<<":"<<menitI[i]<<":"<<detikI[i]<<"\n";
        }
        count = 0;
        cout<<"\nSiap mengerjakan? \n1 = Ya \n2 = Tidak \n3 = Reset Tugas \nPilihan: "; cin>>yt;
        if (yt == 1)
        {
            for (int i = 0; i < tugas; i++)
            {           
                cout<<"\n\nSelamat mengerjakan tugas '"<<stugas[i]<<"' selama "<<jam[i]<<" jam "<<menit[i]<<" menit "<<detik[i]<<" detik";
                cout<<"\nFokus mengerjakan ya!\nNanti setelah "<<jam[i]<<" jam "<<menit[i]<<" menit "<<detik[i]<<" detik akan ada bunyi dan perintah selanjutnya\n";
                countdown(jam[i],menit[i],detik[i]);
                Beep(500, 5000);
                cout<<"\n\nSelamat kamu sudah mengerjakan tugas '"<<stugas[i]<<"' selama "<<jam[i]<<" jam "<<menit[i]<<" menit "<<detik[i]<<" detik";
                cout<<"\nSekarang saatnya beristirahat selama "<<jamI[i]<<" jam "<<menitI[i]<<" menit "<<detikI[i]<<" detik\n";
                countdown(jamI[i],menitI[i],detikI[i]);
                Beep(500, 5000);
                if (i == tugas-1)
                {
                    cout<<"\nSelamat kamu sudah menyelesaikan semua tugasmu!\n";
                    goto program;
                }
            }
        }
        else if(yt == 2)
        {
            cout<<"\nOke kami tunggu sampai Anda siap";
            goto gas1;
        }
        else if(yt == 3)
        {
            goto pengguna;
        }
        else
        {
            cout<<"Angka yang anda masukkan salah";
            cout<<"\nSilahkan masukan angka 1 untuk Ya atau 0 untuk Tidak";
            goto gas1;
        }
    }
    else if(pilihan == 3)
    {
        return 0;
    }
    else
    {
        cout<<"Anda salah memasukkan pilihan, silahkan mencoba lagi :)\n";
        pilihan = 0;
        goto program;
    }
}
