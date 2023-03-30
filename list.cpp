/* 
Nama 		: Devina Lusiana
NIM 		: 211511011
Tanggal 	: 08 Maret 2022
Mata Kuliah : Struktur Data & Algoritma
*/ 

#include <cstdio>
#include <iostream>
#include "list.h"
using namespace std;

void menu(){
    cout<<"================ MENU ================"<<endl;
    cout<<"1. Input Data List (Awal) "<<endl;
    cout<<"2. Input Data List (Akhir) "<<endl;
    cout<<"3. Mencari Elemen List "<<endl;
    cout<<"4. Delete Data List (Awal)"<<endl;
    cout<<"5. Delete Data List (Akhir)"<<endl;
    cout<<"6. Delete Data List (Elemen X)"<<endl;
    cout<<"7. Nilai MAX "<<endl;
    cout<<"8. Nilai MIN "<<endl;
    cout<<"9. Jumlah elemen"<<endl;
    cout<<"10. Nilai AVERAGE"<<endl;
    cout<<"11. Reverse List"<<endl;
    cout<<"0. EXIT"<<endl;
}

bool ListEmpty (List L)
{
    bool status;
    if (L.First = Nil){
        status = true;
    }
    else{
        status = false;
    }
    return status;
}

void CreateList (List * L)
{
    L->First = Nil;
}

address Alokasi (infotype X)
{
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        // cout<<"Masukkan angka : ";
        // cin >> X;
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else{
        cout<< "Memory anda penuh";
        return Nil;
    }
}

void Dealokasi(address *P)
{   /* I.S  : P terdefinisi      				*/
	/* F.S  : P dikembalikan ke  sistem 			*/
	/*   	    Melakukan dealokasi, pengembalian address P */
	Next(*P) = Nil;
	free(*P);
	*P = Nil;
}

address Search (List L, infotype X)
{
    address Posisi, P;
    P = First(L);
    while (P != Nil){
        if (Info(P) == X){
            return P;
        }
        else{
            P = Next(P);
        }
    }
    return P;
}


bool FSearch (List L, address P)
{
    address Cek;
    bool Ketemu;
    Cek = First(L);
    Ketemu = false;
    while ((Cek != Nil) && (!Ketemu)){
        if (Cek == P){
            Ketemu = true;
        }
        else{
            Cek = Cek->next;
        }
    }
    return Ketemu;
}

address SearchPrec (List L, infotype X) {
    //sumber : rivasyafri
    /* Kamus Lokal */
    address P;
    bool Found;

    /* Algoritma */
    P = First(L);
    Found = false;
    if (P == Nil) {
      return Nil;
    } else {
      while ((Next(P) != Nil) && (!Found)) {
        if (X == Info(Next(P))) {
          Found = true;
        } else {
          P = Next(P);
       }
      }
    }
    if (Next(P) == Nil) {
      return Nil;
    } else {
      return P;
    }
}



void InsertFirst (List * L, address P)
{
    Next(P) = L->First;
    L->First = P;
}

void InsVFirst (List *L, infotype X) {
    address P;
    
    P = Alokasi(X);
    if (P != Nil) {
      InsertFirst(L,P);
    }
}

void PrintInfo (List L) {
    address P;
    P = First(L);
    if (P == Nil) {
      cout<<"List kosong"<<endl;
    } else {
      while (Next(P) != Nil) {
        cout<<Info(P)<<", ";
        P = Next(P);
      }
      cout<<Info(P);
    }
}

void InsVLast(List *L, infotype X)
{   /* I.S  : L mungkin kosong          */
	/* F.S  : Melakukan alokasi sebuah elemen dan                */
	/*        menambahkan elemen list di akhir; elemen terakhir  */
	/*        yang baru bernilai X jika alokasi berhasil,        */
	/*	    Jika alokasi gagal: I.S = F.S		       */

	address P = Alokasi(X);
	if (P != Nil)
	{
		InsertLast(&(*L), P);
	}
}


/* *** Penghapusan Elemen  ***  */

void DelVFirst(List *L, infotype *X)
{ /* I.S    : List tidak kosong  		                 */
	/* F.S    : Elemen pertama List dihapus, nilai info disimpan   */
	/*	      pada X dan alamat elemen pertama  di-dealokasi 	 */
	/* Kamus */
	address P;

	DelFirst(&(*L), P); /* Hapus elemem pertama, blm didealokasi */
	*X = Info(P);		 /* info dari First disimpan di X       */
	Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{ /* I.S    : List tidak kosong  		                 */
	/* F.S    : Elemen terakhir list dihapus, nilai info disimpan */
	/*	      pada X dan alamat elemen terakhir di-dealokasi 	 */
	address P;
	DelLast(&(*L), &P);
	/* Hapus Elemen Terakhir, addressnya disimpan di P, */
	/* Belum diDealokasi, masih bisa dibaca isinya      */
	*X = Info(P); /* Info dari address P, ditampung  */
	Dealokasi(&P);
}

/* *******  PRIMITIF BERDASARKAN ALAMAT ********	*/
/* Penambahan Elemen Berdasarkan Alamat 		*/


void InsertAfter(List *L, address P, address Prec)
{   /* I.S   : Prec pastilah elemen  dan bukan elemen terakhir  */
	/*         P sudah dialokasi 					  */
	/* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P) {
    /* Kamus Lokal */
    address Last;
    
    /* Algoritma */
    Last = First(*L);
    if (First(*L) == Nil) {
      InsertFirst(L,P);
    } else {
      while (Next(Last) != Nil) {
        Last = Next(Last);
      }
      InsertAfter(L,P,Last);
    }
}

/* ****** PENGHAPUSAN SEBUAH ELEMEN	*********   */
void DelFirst (List *L, address P) {
    /* Kamus Lokal */

    /* Algoritma */
    P = First(*L);
    First(*L) = Next(First(*L));
}


// void DelP(List *L, infotype X)
// {   /* I.S   : Sembarang  */
// 	/* F.S   : Jika ada elemen  list beraddress P,dengan info (P)=X    */
// 	/*         Maka P dihapus dari List dan di-dealokasi		     */
// 	/*	     Jika tidak ada elemen List dengan info(P)=X, maka list  */
// 	/*         tetap. List mungkin menjadi kosomg karena penghapusan   */
// 	address P = First(*L);

// 	while ((Next(P) != Nil) && (Info(P) != X))
// 	{
// 		P = Next(P);
// 	} /*Next(P)=Nil or Info(P)= X */

// 	if (Info(P) == X)
// 	{
// 		Dealokasi(&P);
// 	}
// }

void DelP (List *L, infotype X) {
  /* Kamus Lokal */
  address P, Prec;

  /* Algoritma*/
  P = Search(*L,X);
  if (P == First(*L)) {
    DelFirst(L,P);
  } else {
    Prec = SearchPrec(*L,X);
    DelAfter(L,P,Prec);
  }
}


void DelLast(List *L, address *P)
{ /* I.S   : List tidak kosong  */
	/* F.S   : P adalah alamat elemen terakhir list sebelum penghapusan */
	/*	     Elemen list berkurang 1 (mungkin menjadi kosong)	      */
	/*         Last elemen baru adalah predessesor elemen pertama yang  */
	/*         lama, jika  ada					      */

	/* Kamus */
	address Last, PrecLast;

	Last = First(*L);
	/* dari catatan di kelas */
	if (Next(Last) == Nil)
	{ /* hanya 1 elemen */
		DelFirst(&(*L), (Last));
	}
	else
	{ /* Lebih dr 1 elemen */
		PrecLast = Nil;
		while (Next(Last) != Nil)
		{ /* Maju sampai elemen terakhir */
			PrecLast = Last;
			Last = Next(Last);
		} /* Next(Last)=Nil */
		*P = Last;
		Next(PrecLast) = Nil;
	}
}

void DelAfter (List *L, address Pdel, address Prec) {
    /* Kamus Lokal */

    /* Algoritma */
    Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(Pdel) = Nil;
}

/* *************PROSES SEMUA ELEMEN ****************   */

int NbElmt(List L)
{ /* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */
	address P;
	int NbEl = 0;
	if (ListEmpty(L))
	{
		return 0;
	}
	else
	{ /* Tidak kosong */
		P = First(L);
		do
		{
			NbEl++;
			P = Next(P);
		} while (P != Nil);
	}
	return NbEl;
}

infotype Max(List L)
{ /* Mengirimkan nilai info(P) yang maksimum */

	address P;
	infotype MMax;
	if (!ListEmpty(L))
	{
		P = First(L);
		MMax = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (Info(P) > MMax)
			{
				MMax = Info(P);
			}
		} /* Next(P)==Nil */
	}
	return MMax;
}

address AdrMax(List L)
{ /* mengirimkan address P, dengan info (P) yang maksimum */

	address PMax, P;
	infotype Max;
	if (!ListEmpty(L))
	{
		P = First(L);
		Max = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (Info(P) > Max)
			{
				Max = Info(P);
				PMax = P;
			}
		} /* Next(P)==Nil */
	}
	return PMax;
}

infotype Min(List L)
{ /* mengirimkan nilai info(P), yang minimum    */

	address P;
	infotype MMin;
	if (!ListEmpty(L))
	{
		P = First(L);
		MMin = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (Info(P) < MMin)
			{
				MMin = Info(P);
			}
		} /* Next(P)==Nil */
	}
	return MMin;
}

address AdrMin(List L)
{ /* mengirimkan address P, dengan info(P) yang minimum */

	address PMin, P;
	infotype Min;
	if (!ListEmpty(L))
	{
		P = First(L);
		Min = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (Info(P) < Min)
			{
				Min = Info(P);
				PMin = P;
			}
		}
	}
	return PMin;
}

float Average(List L)
{ /* mengirimkan nilai rata-rata info(P)	*/
	address P;
	infotype NbEl, Count;
	float avg;

	if (!ListEmpty(L))
	{ /* Tidak kosong */
		P = First(L);
		Count = Info(P);
		NbEl = 1;
		while (Next(P) != Nil)
		{
			P = Next(P);
			Count = Count + Info(P);
			NbEl++;
		} /*Next(P) == Nil */
		avg = (float)Count / (float)NbEl;
	}
	return avg;
}

/******************************************************/
/***   		PROSES TERHADAP LIST		    ***/
/******************************************************/
void DelAll(List *L)
{ /* Delete semua elemen list, dan alamat elemen di-dealokasi */
	infotype X;
	while (!ListEmpty(*L))
	{
		DelVFirst(&(*L), &X);
	} /* kosong */
}

void InversList(List *L)
{   /* I.S   : sembarang  			*/
	/* F.S   : elemen list  dibalik		*/
	/*	   elemen terakhir menjadi elemen pertama, dst    */
	/*	   Membalik elemen list, tanpa alokasi/dealokasi  */

	/* Kamus */
	List LTemp;
	address P;

	/* Algoritma */
	CreateList(&LTemp);
	while (First(*L) != Nil)
	{
		DelFirst(&(*L), P);
		Next(P) = Nil;
		InsertFirst(&LTemp, P);
	}
	First(*L) = First(LTemp);
}

List FInversList(List L)
{   /* mengirimkan list baru (LB), hasil invers dari L 	*/
	/* dengan Alokasi 					*/

	/* List L tidak kosong ; min 1 elemen				*/

	/* Kamus */
	List LB;
	address P, PB;
	infotype X;

	/* Algoritma */
	P = First(L);
	CreateList(&LB);
	do
	{
		X = Info(P);
		PB = Alokasi(X);
		if (PB != Nil)
		{ /* berhasil alokasi */
			InsertLast(&LB, PB);
			P = Next(P);
		}
		else
		{ /* alokasi gagal */
			DelAll(&LB);
			First(LB) = Nil;
		}
	} while (P != Nil);
	return LB;
}
