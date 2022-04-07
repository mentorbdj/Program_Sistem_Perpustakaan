#include <bits/stdc++.h>
using namespace std;

void loading(){
	for(int i=0; i<=100; i++){
		cout<<"loading "<<i<<"%";
		system("cls");
	}
}

void header(){
    system("cls");
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"-----------------------PERPUSTAKAAN SAIBRO-----------------------"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< "\n\n\n";
}

void menu(){
    header();
    cout << "P - Peminjaman Buku\n";
    cout << "K - Pengembalian Buku\n";
    cout << "D - Daftar Buku\n";
    cout << "E - Exit\n\n";
    cout << "Masukkan Pilihan Anda  : ";
}

void cetakBio(char name[50], int age, char address[100]){
    cout<<"Nama     : "<<name <<endl;
    cout<<"Umur     : "<<age <<endl;
    cout<<"Alamat   : "<<address <<endl;
    
}

string peminjaman(int jml, int kod){
	string jb;
    jb = "";
    for(int i = 0; i < jml; i++)
    {
        if(kod==1){
            jb = "Buku Novel";
        } 
        else if(kod==2){
            jb = "Buku Pelajaran";
        }
        else if(kod==3){
            jb = "Buku Komik";
        }
        else{
        	jb = "Kode Buku ("+to_string(kod)+") Tidak Terdaftar";
		}
    }
    return jb;
}

string pengembalian(int jml, int kod){
	string jb;
    jb = "";
    for(int i = 0; i < jml; i++)
    {
        if(kod==1){
            jb = "Buku Novel";
        } 
        else if(kod==2){
            jb = "Buku Pelajaran";
        }
        else if(kod==3){
            jb = "Buku Komik";
        }
        else{
        	jb = "Kode Buku ("+to_string(kod)+") Tidak Terdaftar";
		}
    }
    return jb;
}

void katalog(){
    cout<<" =======Daftar Buku========\n";
    cout<<" --------------------------\n";
    cout<<" | KODE BUKU | JENIS BUKU |\n";
    cout<<" |-----------|------------|\n";
    cout<<" |     1     |    Novel   |\n";
    cout<<" |     2     |  Pelajaran |\n";
    cout<<" |     3     |    Komik   |\n";
    cout<<" --------------------------\n";
}

void exit(){
	cout << "Terimakasih Sudah Mengunjungi Perpustakaan Saibro\n";
	exit(0);
}

void inputSalah(){
	cout << "Input Yang Anda Masukkan Salah\n\n";
}

string waktu(){
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}

void cetakStruk(string jenisAktivitas, string jenisBuku, int jumlahBuku){
    system("cls");
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"--------------------STRUK PERPUSTAKAAN SAIBRO--------------------"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Tanggal          : " << waktu();
    cout<<"Jenis Aktivitas  : " << jenisAktivitas << endl;
    cout<<"Jenis Buku       : " << jenisBuku << endl;
    cout<<"Jumlah Buku      : " << jumlahBuku << endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
        
int main(){
    loading();
    header();
    char nama[50], alamat[100], pilihan, kembali;
    int umur;
    
    cout<<"Selamat Datang, Silahkan Lakukan Login Terlebih dahulu!!!\n\n";
    cout << "Nama   : ";
    cin.getline(nama, 50, '\n');
    cout << "Umur   : ";
    cin >> umur;
    cout << "Alamat : ";
    cin.ignore();
    cin.getline(alamat, 100, '\n');
    cout << "\n";
 
    do{
        string jenisBuku;
        int jml, kod, verify;
        jenisBuku = "";
        verify = 0;
        menu();
        cin >> pilihan;
        if(pilihan == 'P' || pilihan == 'p'){
            header();
            cetakBio(nama, umur, alamat);
    		cout<<"\nJumlah Buku yang ingin dipinjam          : ";
    		cin>>jml;
    		cout<<"Masukkan Kode Buku                       : ";
    		for(int i = 0; i < jml; i++){
    			cin>>kod;
    			if(i == 0){
    				jenisBuku = jenisBuku + peminjaman(jml, kod);	
				}
    			else{
    				jenisBuku = jenisBuku + "\n\t\t   " + peminjaman(jml, kod);
				}
				if(kod == 1 || kod ==2 || kod ==3){
					verify++;
				}
			}
            cetakStruk("Pengembalian",jenisBuku,verify);
            cout << "\n\n<-- Kembali\n\n";
            kembali = 'B';
            system("pause");
        }
        else if(pilihan == 'K' || pilihan == 'k'){
            header();
            cetakBio(nama, umur, alamat);
    		cout<<"\nJumlah Buku yang ingin dikembalikan      : ";
    		cin>>jml;
    		cout<<"Masukkan Kode Buku                       : ";
    		for(int i = 0; i < jml; i++){
    			cin>>kod;
    			if(i == 0){
    				jenisBuku = jenisBuku + pengembalian(jml, kod);	
				}
    			else{
    				jenisBuku = jenisBuku + "\n\t\t   " + pengembalian(jml, kod);
				}
				if(kod == 1 || kod ==2 || kod ==3){
					verify++;
				}
			}
            cetakStruk("Pengembalian",jenisBuku,verify);
            cout << "\n\n<-- Kembali\n\n";
            kembali = 'B';
            system("pause");
        }
        else if(pilihan == 'D' || pilihan == 'd'){
            header();
            katalog();
            cout << "\n\n<-- Kembali\n\n";
            kembali = 'B';
            system("pause");
        }
        else if(pilihan == 'E' || pilihan == 'e'){
            header();
            exit();
        }
        else{
            header();
            inputSalah();
            cout << "\n\n<-- Kembali\n\n";
            kembali = 'B';
            system("pause");
        }
    }
    while(kembali == 'B');

    return 0;
}
