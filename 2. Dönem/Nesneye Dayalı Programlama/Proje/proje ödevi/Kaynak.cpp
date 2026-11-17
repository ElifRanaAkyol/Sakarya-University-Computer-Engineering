#include <iostream>
#include<fstream>
#include <iomanip> //setw için kütüphane.
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish"); //türkçe karakterleri kullanmamýzý saðlar.
	string takimNo = " ";
	string takimAdi = " ";
	string adresi = " ";
	string telefon = " ";
	string	oyuncuSayisi = " ";
	string yoneticiIsmi = " ";
	int secim = 0;
	char cevap = 'e';


	string futbolcuAdi, soyadi, lisansNo, oyundakiKonumu, ucreti, dogumTarihi, tcNo;


	do {
		cout << "Takým oluþtur (1) \n";
		cout << "Takým sil (2)\n";
		cout << "Takýma futbolcu ekle (3) \n";
		cout << "Takýmdan futbolcu sil (4) \n";
		cout << "Takýmdaki futbolcularý listele (5)\n";
		cout << "Takýmdan bir futbolcuyu güncelle (6)\n";
		cin >> secim;



		switch (secim) {
		case 1:
		{


			do {
				ofstream dosyaYaz;
				dosyaYaz.open("Takim.txt", ios::app);
				cout << "\nOluþturmak istediðiniz takýmýn bilgilerini giriniz.";
				cout << "\nTakým No      :"; cin >> takimNo;
				cout << "\nTakým Adý     :"; cin >> takimAdi;
				cout << "\nAdresi        :"; cin >> adresi;
				cout << "\nTelefon       :"; cin >> telefon;
				cout << "\nOyuncu Sayýsý :"; cin >> oyuncuSayisi;
				cout << "\nYönetici Ýsmi :"; cin >> yoneticiIsmi;
				dosyaYaz << takimNo << " " << takimAdi << " " << adresi << " " << telefon << " " << oyuncuSayisi << " " << yoneticiIsmi << "\n";
				dosyaYaz.close();
				cout << "Baþka kayýt yapmak ister misiniz? (e/h)\n";cin >> cevap;
			} while (cevap != 'h');

			cout << "\nTakým/Takýmlar oluþturulmuþtur. \n";
			break;

		}
		case 2:
		{
			string girilenTakimNo;
			cout << "\nSilmek istediðiniz takýmýn numarasýný giriniz: ";
			cin >> girilenTakimNo;
			ifstream dosyaOku("Takim.txt", ios::in);
			ofstream geciciYaz("Gecici.txt", ios::app);
			while (!dosyaOku.eof())
			{
				dosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;

				if (girilenTakimNo == takimNo)
				{
					cout << "\n***Takým Bilgileri***\n";
					cout << "\nTakým No      : " << takimNo;
					cout << "\nTakým Adý     : " << takimAdi;
					cout << "\nAdresi        : " << adresi;
					cout << "\nTelefon       : " << telefon;
					cout << "\nOyuncu Sayýsý : " << oyuncuSayisi;
					cout << "\nYönetici Ýsmi : " << yoneticiIsmi;
					cout << "\nBu takýmý silmek istediðinizden emin misiniz? (e/h) ";
					cin >> cevap;
					if (cevap == 'e')
					{
						cout << "Takým silindi.";
					}
					else
					{
						geciciYaz << takimNo << " " << takimAdi << " " << adresi << " " << telefon << " " << oyuncuSayisi << " " << yoneticiIsmi << "\n";
					}
				}
				
			}
			geciciYaz.close();
			dosyaOku.close();
			remove("Takim.txt");
			rename("Gecici.txt", "Takim.txt");
			break;
		}


		case 3:
		{
			string girilenTakimNo;
			cout << "\nFutbolcu eklemek istediðiniz takýmýn numarasýný giriniz: ";
			cin >> girilenTakimNo;
			ifstream dosyaOku("Takim.txt", ios::in);
			//dosyaOku >> noskipws;
			while (!dosyaOku.eof())
			{
				dosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;

				if (girilenTakimNo == takimNo)
				{
					cout << "\n***Takým Bilgileri***\n";
					cout << "\nTakým No      : " << takimNo;
					cout << "\nTakým Adý     : " << takimAdi;
					cout << "\nAdresi        : " << adresi;
					cout << "\nTelefon       : " << telefon;
					cout << "\nOyuncu Sayýsý : " << oyuncuSayisi;
					cout << "\nYönetici Ýsmi : " << yoneticiIsmi;
					cout << "\nFutbolcu eklemek ister misiniz? (e/h) ";
					cin >> cevap;
					takimNo = girilenTakimNo;								//dosyayý aþaðýda kapatýcaðýmýz için takimNo deðiþkenini kalýcý olarak eþitledik.
					if (cevap != 'h')
					{
						dosyaOku.close();
						ofstream dosyaYaz("Futbolcu.txt", ios::app);
						cout << "\nFutbolcu bilgilerini giriniz.";
						cout << "\nT.C. Numarasý: "; cin >> tcNo;
						cout << "\nAdý: ";cin >> futbolcuAdi;
						cout << "\nSoyadý :";cin >> soyadi;
						cout << "\nLisans Numarasý: ";cin >> lisansNo;
						cout << "\nOyundaki Konumu: ";cin >> oyundakiKonumu;
						cout << "\nÜcreti: ";cin >> ucreti;
						cout << "\nDoðum Tarihi:";cin >> dogumTarihi;
						dosyaYaz << " " << takimNo << " " << tcNo << " " << futbolcuAdi << " " << soyadi << " " << lisansNo << " " << oyundakiKonumu << " " << ucreti << " " << dogumTarihi << "\n";
						dosyaYaz.close();
						break;
					}
				}
			}
			break;
		}
		case 4:
		{
			string girilenTakimNo;
			cout << "\nFutbolcu silmek istediðiniz takýmýn numarasýný giriniz: ";
			cin >> girilenTakimNo;
			ifstream dosyaOku("Takim.txt", ios::in);
			ofstream geciciYaz("Gecici.txt",ios::app);
			//dosyaOku >> noskipws;
			while (!dosyaOku.eof())
			{
				dosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;

				if (girilenTakimNo == takimNo)
				{
					string girilenTcNo;
					cout << "\n***Takým Bilgileri***\n";
					cout << "\nTakým No      : " << takimNo;
					cout << "\nTakým Adý     : " << takimAdi;
					cout << "\nAdresi        : " << adresi;
					cout << "\nTelefon       : " << telefon;
					cout << "\nOyuncu Sayýsý : " << oyuncuSayisi;
					cout << "\nYönetici Ýsmi : " << yoneticiIsmi;
					cout << "\nSilmek istediðiniz futbolcunun T.C numarasýný giriniz? ";
					cin >> girilenTcNo;
					takimNo = girilenTakimNo;								//dosyayý aþaðýda kapatýcaðýmýz için takimNo deðiþkenini kalýcý olarak eþitledik.

					dosyaOku.close();
					ifstream dosyaOku("Futbolcu.txt");

					while (!dosyaOku.eof())
					{
						dosyaOku >> takimNo >> tcNo >> futbolcuAdi >> soyadi >> lisansNo >> oyundakiKonumu >> ucreti >> dogumTarihi;
						if (girilenTcNo == tcNo)
						{
							cout << "Futbolcu silindi.";
						}
						else
						{
							geciciYaz << " " << takimNo << " " << tcNo << " " << futbolcuAdi << " " << soyadi << " " << lisansNo << " " << oyundakiKonumu << " " << ucreti << " " << dogumTarihi << "\n";
						}
					}

				}
			}
			dosyaOku.close();
			geciciYaz.close();
			remove("Futbolcu.txt");
			rename("Gecici.txt", "Futbolcu.txt");
			break;
		}
		case 5:
		{

			string girilenTakimNo;
			cout << "\nListelemek istediðiniz takýmýn numarasýný giriniz: "; cin >> girilenTakimNo;
			ifstream dosyaOku("Takim.txt", ios::in);
			while (!dosyaOku.eof())
			{
				dosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;

				if (girilenTakimNo == takimNo)
				{
					cout << "\n***Takým Bilgileri***\n";
					cout << "\nTakým No      : " << takimNo;
					cout << "\nTakým Adý     : " << takimAdi;
					cout << "\nAdresi        : " << adresi;
					cout << "\nTelefon       : " << telefon;
					cout << "\nOyuncu Sayýsý : " << oyuncuSayisi;
					cout << "\nYönetici Ýsmi : " << yoneticiIsmi;
					cout << "\nFutbolcu listelemek ister misiniz?" << endl;
					cin >> cevap;
					takimNo = girilenTakimNo;
					if (cevap != 'h')
					{
						dosyaOku.close();
						ifstream dosyaOku;
						dosyaOku.open("Futbolcu.txt");
						cout << "\n***Futbolcu bilgileri***\n";
						cout << setw(11) << "Takým No" << setw(10) << "T.C. Numarasý" << setw(10) << "Adý" << setw(12) << "Soyadý" << setw(10) << "Lisans No" << setw(10) << "Konumu" << setw(10) << "Ücreti" << setw(10) << "Doðum Tarihi\n";
						while (!dosyaOku.eof())
						{
							dosyaOku >> takimNo >> tcNo >> futbolcuAdi >> soyadi >> lisansNo >> oyundakiKonumu >> ucreti >> dogumTarihi;

							if (girilenTakimNo == takimNo)
							{
								cout << setw(11) << takimNo << setw(10) << tcNo << setw(10) << futbolcuAdi << setw(12) << soyadi << setw(10) << lisansNo << setw(10) << oyundakiKonumu << setw(10) << ucreti << setw(10) << dogumTarihi << endl;
							}
						}


					}

				}
			}
			break;
		}
			
		case 6:
		{
			string girilenTakimNo;
			string girilenTcNo;
			cout << "\nFutbolcu güncellemek istediðiniz takýmýn numarasýný giriniz: ";
			cin >> girilenTakimNo;
			ifstream dosyaOku("Takim.txt", ios::in);
			ofstream geciciYaz("Gecici.txt", ios::app);
			
			while (!dosyaOku.eof())
			{
				dosyaOku >> takimNo >> takimAdi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;

				if (girilenTakimNo == takimNo)
				{
					cout << "\n***Takým Bilgileri***\n";
					cout << "\nTakým No      : " << takimNo;
					cout << "\nTakým Adý     : " << takimAdi;
					cout << "\nAdresi        : " << adresi;
					cout << "\nTelefon       : " << telefon;
					cout << "\nOyuncu Sayýsý : " << oyuncuSayisi;
					cout << "\nYönetici Ýsmi : " << yoneticiIsmi;
					cout << "\nFutbolcu güncellemek ister misiniz? (e/h) ";
					cin >> cevap;
					takimNo = girilenTakimNo;


					if (cevap != 'h')
					{
						cout << "\nLütfen güncellemek istediðiniz futbolcunun T.C. numarasýný giriniz: ";cin >> girilenTcNo;
						while (!dosyaOku.eof())
						{
							dosyaOku >> takimNo >> tcNo >> futbolcuAdi >> soyadi >> lisansNo >> oyundakiKonumu >> ucreti >> dogumTarihi;


							if (girilenTcNo == tcNo)
							{
								dosyaOku.close();
								ifstream dosyaOku("Futbolcu.txt", ios::in);
								dosyaOku.open("Futbolcu.txt", ios::app);
								cout << "\nBilgilerini güncelleyiniz.";
								cout << "\nT.C. Numarasý: "; cin >> tcNo;
								cout << "\nAdý: ";cin >> futbolcuAdi;
								cout << "\nSoyadý :";cin >> soyadi;
								cout << "\nLisans Numarasý: ";cin >> lisansNo;
								cout << "\nOyundaki Konumu: ";cin >> oyundakiKonumu;
								cout << "\nÜcreti: ";cin >> ucreti;
								cout << "\nDoðum Tarihi:";cin >> dogumTarihi;
								geciciYaz << " " << takimNo << " " << tcNo << " " << futbolcuAdi << " " << soyadi << " " << lisansNo << " " << oyundakiKonumu << " " << ucreti << " " << dogumTarihi << "\n";
							}
							else
							{
								geciciYaz << " " << takimNo << " " << tcNo << " " << futbolcuAdi << " " << soyadi << " " << lisansNo << " " << oyundakiKonumu << " " << ucreti << " " << dogumTarihi << "\n";
							}


							cout << "\Futbolcu bilgileri güncellenmiþtir.\n";
						}
					}

				}
			}
			geciciYaz.close();
			dosyaOku.close();
			remove("Futbolcu.txt");
			rename("Gecici.txt", "Futbolcu.txt");
			break;
		}

		}

	} while (secim == 1 || secim == 2 || secim == 3 || secim == 4 || secim == 5 || secim == 6);
	return 0;
}