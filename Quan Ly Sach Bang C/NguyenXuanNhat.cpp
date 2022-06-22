#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct THONG_TIN_SACH{
	char maSach[10];
	char tenSach[30];
	int namXB;
	char nhaXB[255];
	char tacGia[255];
	char tinhtrang[255];
	int soluong;
};
struct NodeAVL{
	THONG_TIN_SACH data;
	int HangNode;
	NodeAVL *left,*right;
};
typedef NodeAVL *TREEAVL;

void XoaManHinh1();
void textcolor(int x);
void resizeConsole(int width, int height);

void MENU();
int Nhap_sach(THONG_TIN_SACH &x);
void LNR(TREEAVL &t);
float Xem_Node_La(TREEAVL t);

void Init(TREEAVL &t);
NodeAVL *GetNodeAVL(THONG_TIN_SACH x);
int Insert_TREE(TREEAVL &t,THONG_TIN_SACH x);
void Create_Tree(TREEAVL &t);

NodeAVL *TimKiem(TREEAVL t,char x[]);
int Xoa(TREEAVL &t,char x[]);
int CapNhat(TREEAVL &t,char ma[]);
void Liet_Ke(TREEAVL t, TREEAVL &Tot, TREEAVL &Hong, TREEAVL &Lac, TREEAVL &ThanhLy);
int Cap_Nhat_Trang_Thai(TREEAVL &t);

int Dem_Hang(TREEAVL t);
int Cap_Nhat_Cap_Cho_Tree(TREEAVL &t);
int Sua_Thanh_AVL(TREEAVL &t);

int GhiFile(TREEAVL t,char x[]);
int DocFileChenTRee(TREEAVL &t,char x[]);
int DocFile(char x[]);
int Tong_Sach_Da_Nhap(TREEAVL t);

void File_Test_19503031_DT7(char ch[]);

void Free(TREEAVL &t);
void MENU(){
	printf("\n%-25s %-25s %-25s %-30s\n%-25s %-25s %-25s %-30s\n%-25s %-25s %-25s\n       C H O N   C O N G   V I E C: ",
	       "| 1.  Xem sach.","| 4. Cap nhat sach.","| 7. Doc file detai7.txt.","| 10. Thong ke node."
	      ,"| 2. Tao sach moi.","| 5. Xoa sach.","| 8. Liet ke sach.","| 11. Giai phong vung nho.",
	       "| 3. Tim kiem sach.","| 6. Ghi vao detai7.txt","| 9. Cap nhat tinh trang.");
}

int main(){

	TREEAVL c1;
	float so=0;
	Init(c1);
	char chon1;
	printf("\tBan co muon doc du lieu tu file tao san va them vao cay ? (Y: Dong y): ");
	scanf("%c",&chon1);
	if( chon1 == 'y' || chon1 == 'Y' ){
	File_Test_19503031_DT7("30_Sach.txt");
	DocFileChenTRee(c1,"30_Sach.txt");
	printf("\nDa doc du lieu tu 30_Sach.txt !!");
	}
	char x[12];
	int chon;
	do{
		system("pause");
		system("cls");
		printf("%60s\n","THONG TIN SACH");
		MENU();
		scanf("%d",&chon);
		Sua_Thanh_AVL(c1);
		switch(chon){
			case 1:
				printf("%60s %-45s %-50s\n","THONG TIN SACH\n"," "," ");
				printf("%-7s %-10s %-15s %-15s %-15s %-12s %-20s %-15s","Hang","Ma sach",
			"Ten sach","Nam xuat ban","Nha xuat ban","Tac gia","Tinh trang","So luong");
				LNR(c1);
				break;
			case 2:
				Create_Tree(c1);
				break;
			case 3:
				printf("Tim kiem ma: ");
				fflush(stdin);
				gets(x);
				if(TimKiem(c1,x)==NULL)
					printf("Khong tim thay !!\n");
				else
					printf("Da tim thay !!\n");
				break;
			case 4:
				printf("%-7s %-10s %-15s %-15s %-15s %-12s %-20s %-15s","Hang","Ma sach",
			"Ten sach","Nam xuat ban","Nha xuat ban","Tac gia","Tinh trang","So luong");
				LNR(c1);
				printf("\nNhap ma cap nhat: ");
				fflush(stdin);
				gets(x);
				if(CapNhat(c1,x)==0)
					printf("That bai!!\n");
				else
					printf("Thanh cong!!\n");
				break;
			case 5:
				LNR(c1);
				printf("Nhap ma can xoa: ");
				fflush(stdin);
				gets(x);
					
				if(Xoa(c1,x)==1)
					printf("Xoa thanh cong!!\n");
				else
					printf("That bai!!\n");
				break;
			case 6:
				FILE *fp;
			    fp = fopen ("Detai_7.txt", "w");
				if(fp==NULL){
					printf("Loi mo file!!");
					return 0;
				}
			    fclose(fp);  
				GhiFile(c1,"Detai_7.txt");
				printf("Da ghi vao tap tin Detai_7.txt !!\n");
				break;
			case 7:	
				printf("Doc file Detai_7.txt !!\n");
				DocFile("Detai_7.txt");
				break;
			case 8: 
				TREEAVL Tot,Hong,Lac,ThanhLy;
				Init(Tot);
				Init(Hong);
				Init(Lac);
				Init(ThanhLy);
				Liet_Ke(c1,Tot,Hong,Lac,ThanhLy);
					printf("\n%-8s %-10s %-15s %-15s %-15s %-12s %-20s %-15s","Hang","Ma sach",
			"Ten sach","Nam xuat ban","Nha xuat ban","Tac gia","Tinh trang","So luong");
				printf("\nSach tot.");				
					LNR(Tot);
				printf("\nSach hu hong.");				
					LNR(Hong);
				printf("\nSach That lac.");	
					LNR(Lac);
				printf("\nSach Thanh ly.");				
					LNR(ThanhLy);
				printf("\n%60s","Toan bo sach\n");
				LNR(c1);
				break;
			case 9:
				Cap_Nhat_Trang_Thai(c1);
				printf("Da cap nhat trang thai cho tat ca sach.\n");
				break;
			case 10:
				printf("Tong sach da nhap %d\nCac node la:\n",Tong_Sach_Da_Nhap(c1));
				Xem_Node_La(c1);
				break;
			case 11:
				Free(c1);
				break;
		}
		printf("\n\t\t\t_______________________________________________________________\n");
		
	}while(chon!=0);
}

void Init(TREEAVL &t){
	t = NULL;
}

NodeAVL *GetNodeAVL(THONG_TIN_SACH x){
	NodeAVL *p = new NodeAVL;
	if(p==NULL){
		printf("Loi bo nho!!");
		return NULL;
	}
	p->data = x;
	p->left = p->right = NULL;
	return p;
}

int Insert_TREE(TREEAVL &t,THONG_TIN_SACH x){
	NodeAVL *p = GetNodeAVL(x);
	int n = atoi(p->data.maSach);
	int m = atoi(t->data.maSach);
	if(t==NULL){
		t = p;
		return 1;
	}
	if(n<m)
		return Insert_TREE(t->left,x);
	else if(n>m)
		return Insert_TREE(t->right,x);
	else
		return 0;
}
void Create_Tree(TREEAVL &t){
	THONG_TIN_SACH x;
	int k;
	do{
		k = Nhap_sach(x);
		if(k!=0)
			Insert_TREE(t,x);
		Sua_Thanh_AVL(t);	
	}while(k!=0);
	system("cls");
}
void LNR(TREEAVL &t){
	if(t!=NULL){
		LNR(t->left);
		printf("\n%-9d",t->HangNode);
		if(strcmp(t->data.tinhtrang,"1")==0)
			strcpy(t->data.tinhtrang,"Tot");
		else if(strcmp(t->data.tinhtrang,"2")==0)
			strcpy(t->data.tinhtrang,"HuHong");
		else if(strcmp(t->data.tinhtrang,"3")==0)
			strcpy(t->data.tinhtrang,"ThatLac");
		else if(strcmp(t->data.tinhtrang,"4")==0)
			strcpy(t->data.tinhtrang,"DenHanThanhLy");	
		printf("%-10s %-15s %-15d %-15s %-12s %-20s %-15d",t->data.maSach
			,t->data.tenSach,t->data.namXB,t->data.nhaXB,t->data.tacGia,t->data.tinhtrang,t->data.soluong);
		LNR(t->right);
	}
}
int Tong_Sach_Da_Nhap(TREEAVL t){
	if(t!=NULL){
		return Tong_Sach_Da_Nhap(t->left) + Tong_Sach_Da_Nhap(t->right) + 1;
	}
}
int Dem_Hang(TREEAVL t){
	int a=0, b=0;
	if(t!=NULL){
	a = Dem_Hang(t->left) + 1;
	b = Dem_Hang(t->right) + 1;
	}
	if(a>b)
		return a;
	else
		return b;
}

int Cap_Nhat_Cap_Cho_Tree(TREEAVL &t){
	if(t!=NULL){
		Cap_Nhat_Cap_Cho_Tree(t->left);
		Cap_Nhat_Cap_Cho_Tree(t->right);
		NodeAVL *p = t->left, *q = t->right;
		t->HangNode = Dem_Hang(p) - Dem_Hang(q);
	}
}

int Sua_Thanh_AVL(TREEAVL &t){
	if(t!=NULL){
		Sua_Thanh_AVL(t->left);
		Sua_Thanh_AVL(t->right);
		Cap_Nhat_Cap_Cho_Tree(t);
		if(t->HangNode < -1){
			NodeAVL *p = t;
			NodeAVL *q = p->right;
			if(q->HangNode<=-1){
				p->right = q->left;
				q->left = p;
				t = q;		
			} else if(q->HangNode>=1){	
				NodeAVL *k = q->left;
				q->left = k->right;
				k->right = q;
				p->right = k;
				p->right = k->left;
				k->left = p;
				t = k;
			}
		}else if (t->HangNode > 1){
			NodeAVL *p = t;
			NodeAVL *q = p->left;
			if(q->HangNode>=1){
				p->left = q->right;
				q->right = p;
				t = q;	
			} else if(q->HangNode>=-1){
				NodeAVL *k = q->right;
				q->right = k->left;
				k->left = q;
				p->left = k;
				p->left = k->right;
				k->right = p;
				t = k;
			}
		}				
	}
}
NodeAVL *TimKiem(TREEAVL t,char x[]){
	int a = atoi(t->data.maSach);
	int b = atoi(x);
	if(t==NULL)
		return NULL;
	else{
		if(b<a)
			TimKiem(t->left,x);
		else if(b>a)
			TimKiem(t->right,x);
		else 
			return t;
	}
}
int CapNhat(TREEAVL &t,char ma[]){
	int a = atoi(t->data.maSach);
	int b = atoi(ma);
	if(t==NULL)
		return 0;
	else{
		if(b<a)
			CapNhat(t->left,ma);
		else if(b>a)
			CapNhat(t->right,ma);
		else{
			int chon;
			THONG_TIN_SACH x;
				strcpy(x.maSach,ma);
				printf("Ten sach: ");	fflush(stdin);	gets(x.tenSach);
				printf("Nam xuat ban: ");	scanf("%d",&x.namXB);
				printf("Nha xuat ban: ");	fflush(stdin);	gets(x.nhaXB);
				printf("Tac gia: ");	fflush(stdin);	gets(x.tacGia);
				printf("Tinh trang ( 1 : Tot, 2: Hu hong, 3: That lac, 4. Den Han Thanh Ly ): ");	fflush(stdin);	gets(x.tinhtrang);
				if(strcmp(x.tinhtrang,"1")!=0 && strcmp(x.tinhtrang,"2")!=0 && strcmp(x.tinhtrang,"3")!=0 && strcmp(x.tinhtrang,"4")!=0)
					return 0;
				if(strcmp(x.tinhtrang,"1")==0)
					strcpy(x.tinhtrang,"Tot");
				else if(strcmp(x.tinhtrang,"2")==0)
					strcpy(x.tinhtrang,"HuHong");
				else if(strcmp(x.tinhtrang,"3")==0)
					strcpy(x.tinhtrang,"ThatLac");
				else 
					strcpy(x.tinhtrang,"DenHanThanhLy");		
				printf("So luong: ");	scanf("%d",&x.soluong);
				if(x.soluong==0){
					Xoa(t,ma);
					return 1;
				}
				t->data = x;
			return 1;
		}
	}
}

int Xoa(TREEAVL &t,char x[]){
	if(t==NULL)
		return 0;
	else{
		int a = atoi(t->data.maSach);
		int b = atoi(x);
		if(b<a)
			return Xoa(t->left,x);
		else if(b>a)
			return Xoa(t->right,x);
		else{
			if(t->left == t->right)
				t = NULL;
			else if(t->left==NULL)  
				t = t->right;
			else if(t->right==NULL)
				t = t->left;
			else{
				int kt =0;
				NodeAVL *p = t;
				NodeAVL *s=p,*q=p->left;
				while(q->right!=NULL){
					s = q;
					q=q->right;
				}
					t->data = q->data;
					if( q == s->left){
						p->left = q->left;
						delete(q);
					}
					else{
						s->right = q->left;
						delete(q);
					}
			}
			return 1;
		}
	}
}

void Liet_Ke(TREEAVL t, TREEAVL &Tot, TREEAVL &Hong, TREEAVL &Lac, TREEAVL &ThanhLy){
	if(t!=NULL){
		Liet_Ke(t->left,Tot,Hong,Lac,ThanhLy);
		if(strcmp(t->data.tinhtrang,"Tot")==0||strcmp(t->data.tinhtrang,"1")==0)
			Insert_TREE(Tot,t->data);
		else if(strcmp(t->data.tinhtrang,"HuHong")==0||strcmp(t->data.tinhtrang,"2")==0)
			Insert_TREE(Hong,t->data);
		else if(strcmp(t->data.tinhtrang,"ThatLac")==0||strcmp(t->data.tinhtrang,"3")==0)
			Insert_TREE(Lac,t->data);
		else if(strcmp(t->data.tinhtrang,"DenHanThanhLy")==0||strcmp(t->data.tinhtrang,"4")==0)
			Insert_TREE(ThanhLy,t->data);
		Liet_Ke(t->right,Tot,Hong,Lac,ThanhLy);
	}
}

float Xem_Node_La(TREEAVL t){
	if (t!= NULL) {
		if(t->left == NULL && t->right == NULL) {
			printf("%2s\t",t->data.maSach);
		}
			Xem_Node_La(t->left);
			Xem_Node_La(t->right);
	}
}

int Cap_Nhat_Trang_Thai(TREEAVL &t){
	if(t!=NULL){
		Cap_Nhat_Trang_Thai(t->left);
		if(strcmp(t->data.tinhtrang,"DenHanThanhLy")==0)
			strcpy(t->data.tinhtrang,"ThanhLy");
		else if(strcmp(t->data.tinhtrang,"Tot")==0)
			strcpy(t->data.tinhtrang,"HuHong");
		else if(strcmp(t->data.tinhtrang,"HuHong")==0)
			strcpy(t->data.tinhtrang,"DenHanThanhLy");	
		Cap_Nhat_Trang_Thai(t->right);
	}
}

void Free(TREEAVL &t){
	if(t==NULL)
		return;
	if(t->left)
		Free(t->left);
	else if(t->right)
		Free(t->right);
	delete(t);
	t=NULL;
}

void File_Test_19503031_DT7(char ch[]){
	FILE *f;
	f = fopen(ch,"w");
	fputs("50   TraHoaNu        2017     aa              aa          1      1 \n",f);
	fputs("71   KiepSau         2003     aa              Aa          1     11 \n",f);
	fputs("70   ToanA2          1996     aa              aa          2     11 \n",f);
	fputs("80   TheOneThing     1999     bb              bb          2      2 \n",f);
	fputs("90   XayDung         1864     BB              BB          3     22 \n",f);
	fputs("100  CodeC           2003     dd              dd          3      3 \n",f);
	fputs("40   C++             2003     ee              ee          4     33 \n",f);
	fputs("30   C#              2003     zz              zz          4      4 \n",f);
	fputs("20   Java            2003     xx              xx          1     44 \n",f);
	fputs("10   PYTHON          2003     vv              ww          1      5 \n",f);	
	fputs("5    Html            2003     qq              qq          2     55 \n",f);
	fputs("95   English12       2006     GD              10          2      6 \n",f);
	fputs("15   TiengViet5      2000     GD              10          3     66 \n",f);
	fputs("85   Toan12          2000     GD              10          3      7 \n",f);
	fputs("25   VatLy12         2000     GD              10          4     77 \n",f);
	fputs("75   HoaHoc12        2000     GD              10          4      8 \n",f);
	fputs("35   NguVan12        2000     GD              10          1     88 \n",f);
	fputs("04   LichSu12        2000     GD              10          1      9 \n",f);
	fputs("45   DiaLy12         2000     GD              2           1     99 \n",f);
	fputs("55   HocDeLamGiau    2008     10              2           2     12 \n",f);	
	fputs("12   DacNhanTam      2004     Simon&Schuster  10          3     23 \n",f);
	fputs("98   TuDuyTichCuc    1999     10              10          3     34 \n",f);
	fputs("23   MatBiec         2002     NXBTre          10          4     45 \n",f);
	fputs("87   QuangCaoNoiLao  2009     10              10          4     56 \n",f);
	fputs("9    HerryPoter      2008     10              10          1     67 \n",f);
	fputs("76   KhoiNghiep4.0   2018     10              10          1     17 \n",f);
	fputs("45   BiMatDotCom     2019     10              10          2      1 \n",f);
	fputs("65   NAPOLEON_HILL   2005     10              10          2     11 \n",f);
	fputs("56   SonGoKu         2007     10              10          3      1 \n",f);
	fputs("18   SinhHoc         2000     10              10          3     10 \n",f);
	fputs("33   EinStein        1812     10              10          4     10 \n",f);
	fputs("44   GDCD12          2000     10              10          4     11 \n",f);
	fputs("66   Naruto          2007     10              10          1     10 \n",f);
	fputs("77   OnePiece        2009     10              10          1      1 \n",f);
	fputs("88   HACKER          2014     10              10          2     10 \n",f);
	fputs("1    DaoLyLamNguoi   2018     DanTri          LanPhuong   2      1 \n",f);
	fclose(f);	
}
int DocFileChenTRee(TREEAVL &t,char x[]) {   
    THONG_TIN_SACH p;
    FILE *fp;
    fp = fopen (x, "a+");
	if(fp==NULL){
		printf("Loi mo file!!");
		return 0;
	}
    while(fscanf(fp,"%s %s %d %s %s %s %d",&p.maSach,&p.tenSach,&p.namXB,&p.nhaXB,&p.tacGia,&p.tinhtrang,&p.soluong)!=EOF){
    	Insert_TREE(t,p);
    	Sua_Thanh_AVL(t);
	}
    fclose (fp);
    return 1;
}
int DocFile(char x[]) {
    FILE *fp;
    THONG_TIN_SACH p;
    fp = fopen (x, "r");
	if(fp==NULL){
		printf("Loi mo file!!");
		return 0;
	}
	if(fscanf(fp,"%s %s %d %s %s %s %d",&p.maSach,&p.tenSach,&p.namXB,&p.nhaXB,&p.tacGia,&p.tinhtrang,&p.soluong)==EOF)
		printf("[ File rong !! ]");
	else
		printf("%-15s %-15s %-15d %-15s %-15s %-20s %-15d\n",p.maSach,p.tenSach,p.namXB,p.nhaXB,p.tacGia,p.tinhtrang,p.soluong); 
    while(fscanf(fp,"%s %s %d %s %s %s %d",&p.maSach,&p.tenSach,&p.namXB,&p.nhaXB,&p.tacGia,&p.tinhtrang,&p.soluong)!=EOF){
		printf("%-15s %-15s %-15d %-15s %-15s %-20s %-15d\n",p.maSach,p.tenSach,p.namXB,p.nhaXB,p.tacGia,p.tinhtrang,p.soluong);    	
	}
    fclose (fp);
    return 1;
}
int GhiFile(TREEAVL t,char x[]){
	
	FILE *f;
	f = fopen(x,"a+");
	if(f==NULL){
		printf("Khong du bo nho\n");
		return 0;
	}
	f==NULL;
	if(t!=NULL){
		GhiFile(t->left,x);
		if(strcmp(t->data.tinhtrang,"1")==0)
				strcpy(t->data.tinhtrang,"Tot");
			else if(strcmp(t->data.tinhtrang,"2")==0)
				strcpy(t->data.tinhtrang,"HuHong");
			else if(strcmp(t->data.tinhtrang,"3")==0)
				strcpy(t->data.tinhtrang,"ThatLac");
			else if(strcmp(t->data.tinhtrang,"4")==0)
				strcpy(t->data.tinhtrang,"DenHanThanhLy");
		fprintf(f,"%-15s %-15s %-15d %-15s %-15s %-20s %-15d\n",t->data.maSach, t->data.tenSach,
		t->data.namXB,t->data.nhaXB,t->data.tacGia,t->data.tinhtrang,t->data.soluong);
		GhiFile(t->right,x);
	}
	fclose(f);
	return 1;
}
int Nhap_sach(THONG_TIN_SACH &x){
	printf("\n========= NHAP 0 DUNG ===========");
	printf("\nMa sach: ");
	fflush(stdin);
	gets(x.maSach);
	if(strcmp(x.maSach,"0")==0){
	 printf("Dung !!\n");
		return 0;
	}
	printf("Ten sach: ");
	fflush(stdin);
	gets(x.tenSach);
	printf("Nam xuat ban: ");
	scanf("%d",&x.namXB);
	printf("Nha xuat ban: ");
	fflush(stdin);
	gets(x.nhaXB);
	printf("Tac gia: ");
	fflush(stdin);
	gets(x.tacGia);
	printf("Tinh trang ( 1 : Tot, 2: Hu Hong, 3: That Lac, 4. Den Han Thanh Ly ): ");
	fflush(stdin);
	gets(x.tinhtrang);
	if(strcmp(x.tinhtrang,"1")!=0 && strcmp(x.tinhtrang,"2")!=0 
	&& strcmp(x.tinhtrang,"3")!=0 && strcmp(x.tinhtrang,"4")!=0){
		printf("Nhap Sai !! \n");
		return 0;
	}
	printf("So luong: ");
	scanf("%d",&x.soluong);
	return 1;
}

