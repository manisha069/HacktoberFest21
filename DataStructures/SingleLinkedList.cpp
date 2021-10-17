#include <bits/stdc++.h>
using namespace std;
typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
    infotype info;
    address next;
}ElmtList;

struct List{
    address first;
};
void CreateEmpty(List *L){
    (*L).first=NULL;
}
bool isEmpty(List L){
    return ((L).first==NULL);
}
address Allocation(infotype x){
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
    NewElmt->info=x;
    NewElmt->next=NULL;
    return NewElmt;
}
void Deallocation(address hapus){
    free(hapus);
}

void InsertFirst(List *L, infotype x){
    address NewElmt;
    NewElmt = Allocation(x);
    if(NewElmt!=NULL){
        NewElmt->next=(*L).first;
        (*L).first=NewElmt;
    }
}
void InsertAfter(address *PredElmt, infotype x){
    address NewElmt;
    NewElmt = Allocation(x);
    if(NewElmt!=NULL){
        NewElmt->next=(*PredElmt)->next;
        (*PredElmt)->next=NewElmt;
    }
}
void InsertLast(List *L, infotype x){
    if(isEmpty((*L))){
        InsertFirst(&(*L),x);
    }
    else{
        address temp;
        temp = (*L).first;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        InsertAfter(&temp,x);
    }
}
void DeleteFirst(List *L){
    if(!isEmpty(*L)){
        address temp;
        temp = (*L).first;
        (*L).first=(*L).first->next;
        temp->next=NULL;
        Deallocation(temp);
    }
}
void DeleteAfter(address pred){
    if(pred->next!=NULL){
        address temp;
        temp=pred->next;
        pred->next=temp->next;
        temp->next=NULL;
        Deallocation(temp);
    }
}
void DeleteLast(List *L){
    if(!isEmpty(*L)){
        address temp, predTemp;
        predTemp = NULL;
        temp = (*L).first;
        while(temp->next!=NULL){
            predTemp=temp;
            temp=temp->next;
        }
        if(temp==(*L).first){
            DeleteFirst(&(*L));
        }else{
            DeleteAfter(predTemp);
        }
    }
}
void printInfo (List L){
	/*	I.S. List mungkin kosong
		F.S. Jika list tidak kosong,
		Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
		Jika list kosong, hanya menuliskan "[]"
	*/
	cout<<"[";
	if(!isEmpty(L)){
		address P = L.first;
		while(P->next!=NULL){
			cout<<P->info<<", ";
			P = P->next;
		}
		cout<<P->info;
	}
	cout<<"]"<<endl;
}
int main(){
	List L;
	CreateEmpty(&L);

	//Soal A
	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;
		InsertLast(&(L),x);
	}
	printInfo(L);
}
