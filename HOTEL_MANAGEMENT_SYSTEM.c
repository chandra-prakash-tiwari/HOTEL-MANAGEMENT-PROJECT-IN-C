#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

struct CustomerDetails
{
	char roomnumber[5];
	char name[20];
	char address[25];
	char phonenumber[15];
	char email[20];
	char period[10];
	char month[4];
	char date[4];
	char year[7];
	char advance[3];
}s;

void MENU();
void AVAIL();
void ADD();
void EDIT();
void LIST();
void DELETE1();
void SEARCH();
void BILLGEN();
void main();

void footer(){
	int i;
	time_t t;
	time(&t);
	gotoxy(1,22);
	for(i=0;i<80;i++)
	printf("_");
	printf("Current date and time : %s",ctime(&t));
	gotoxy(1,24);
	for(i=0;i<80;i++)
	printf("_");
}

void header(){
	int i;
	gotoxy(1,1);
	for(i=0;i<82;i++)
	printf("*");
	gotoxy(79,2);
	for(i=0;i<82;i++)
	printf("*");
}

		/////////////////////////////////////////////
		/*                 L O G I N               */
		/////////////////////////////////////////////

void login()
{

	int a=0,i=0;
	char uname[10],c=' ';
	char pword[10],code[10];
	char user1[10]="user";
	char pass1[10]="pass";
	do
	{
		system("cls");
		gotoxy(15,10);
		cprintf("*******************");
		gotoxy(45,10);
		cprintf(" *********************");
		gotoxy(35,10);
		printf("LOGIN PAGE");
		gotoxy(15,11);
		printf("**\t     ENTER USERNAME:- _________    \t**");
		gotoxy(15,12);
		printf("**\t     ENTER PASSWORD:- _________\t\t**");
		gotoxy(15,13);
		cprintf("****************************************************");
		footer();
		gotoxy(47,11);
		scanf("%s", &uname);
		i=0;
		gotoxy(47,12) ;
		while(i<10)
		{
			pword[i]=getch();
			c=pword[i];
			if(c==13) break;
			else printf("*");
			i++;
		}
		pword[i]='\0';
		i=0;
		gotoxy(33,15);
		cprintf("checking .");
		delay(1000);
		cprintf(" . .");
		delay(1000);
		if(strcmp(uname,user1)==0 && strcmp(pword,pass1)==0)
		{
			MENU();
			break;
		}
		else
		{
			gotoxy(25,15);
			printf("SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;
			getch();
		}
	}
	while(a<=2);
	if (a>2)
	{
		gotoxy(5,15);
		printf("Sorry you have entered the wrong username and password for three times!!!");
		getch();
		main();
	}
}

		/////////////////////////////////////////////
		/*              M E N U  P A G E           */
		/////////////////////////////////////////////

void MENU(){
	int i;
	char choice;
	system("cls");
	while (1)
	{
		system("cls");
		header();
		gotoxy(35,2);
		printf("Main Menu");
		gotoxy(16,5);
		printf(" Please enter your choice for menu");
		printf("\n\n \n    1. Room Availabilty");
		printf(" \n    2. Book a room");
		printf(" \n    3. View Customer Record");
		printf(" \n    4. Search Customer Record");
		printf(" \n    5. Edit Record");
		printf(" \n    6. Bill Generate");
		printf(" \n    7. Logout");
		printf(" \n    8. Exit");
		footer();
		choice=getche();
		switch(choice)
		{
			case '1':
				AVAIL();
				break;
			case '2':
				ADD();
				break;
			case '3':
				LIST();
				break;
			case '4':
				SEARCH();
				break;
			case '5':
				EDIT();
				break;
			case '6':
				BILLGEN();
				break;
			case '7':
				login();
				break;
			case '8':
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}

		/////////////////////////////////////////////
		/*      R O O M   A V A I L A B I T Y      */
		/////////////////////////////////////////////

void AVAIL(){
	int i,count,line,p,q;
	char j[4];
	FILE *f;
	f=fopen("FILE.txt","rb+");
	system("cls");
	header();
	gotoxy(30,2);
	printf("ROOM AVAILABLE ");
	gotoxy(1,5);
	printf("S I N G L E   B E D   R O O M :");
	printf("\n\n     100    101    102    103    104    105    106    107    108    109    110\n\n");
	printf("     200    201    202    203    204    205    206    207    208    209    210\n\n");
	printf("D O U B L E   B E D   R O O M :");
	printf("\n\n     300    301    302    303    304    305    306    307    308    309    310\n\n");
	printf("S P E C I A L   R O O M :");
	printf("\n\n     400    401    402    403    404    405    406    407    408    409    410\n\n");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		count=1;
		line=6;
		for(i=100;i<=110;i++)
		{
			itoa(i,j,10);
			if(strcmp(s.roomnumber,j)==0)
			{
				count=0;
				q=7;
				p=line;
				goto w;
			}
			else
			line=line+7;
		}
		line=6;
		for(i=200;i<=210;i++)
		{
			itoa(i,j,10);
			if(strcmp(s.roomnumber,j)==0)
			{
				count=0;
				q=9;
				p=line;
				goto w;
			}
			else
			line=line+7;
		}
		line=6;
		for(i=300;i<=310;i++)
		{
			itoa(i,j,10);
			if(strcmp(s.roomnumber,j)==0)
			{
				count=0;
				q=13;
				p=line;
				goto w;
			}
			else
			line=line+7;
		}
		line=6;
		for(i=400;i<=410;i++)
		{
			itoa(i,j,10);
			if(strcmp(s.roomnumber,j)==0)
			{
				count=0;
				q=17;
				p=line;
				goto w;
			}
			else
			line=line+7;
		}
		w:
		if(count==0){
			gotoxy(p,q);
			printf("---");}
	}
	fclose(f);
	getch();
}

		/////////////////////////////////////////////
		/*        R O O M   B O O K I N G          */
		/////////////////////////////////////////////


void ADD()
{
	FILE *f;
	int i,room,no,a=1,per,m,d,y,adv,mo,em,temp,salery,flag,mon[12];
	char test,room1[5],test1,day;
	time_t T=time(NULL);
	struct tm tm=*localtime(&T);
	f=fopen("FILE.txt","ab+");
	if(f==0)
	{
		f=fopen("FILE.txt","wb+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(a)
	{
		system("cls");
		header();
		gotoxy(30,2);
		printf("Enter Customer Details");
		gotoxy(1,5);
		printf("Enter Room number      :\n");
		fflush(stdin);
		printf("\nEnter Name             :\n");
		printf("\nEnter Address          :\n");
		printf("\nEnter Phone Number     :\n");
		printf("\nEnter Email            :\n");
		printf("\nEnter Period('x'days)  :\n");
		printf("\nEnter Arrival          : \n");
		gotoxy(26,5);
		scanf("%d",&room);
		if(room>=100&&room<=110||room>=200&&room<=210||room>=300&&room<=310||room>=400&&room<=410){
		itoa(room,room1,10);
		f=fopen("FILE.txt","rb+");
		while(fread(&s,sizeof(s),1,f)==1)
		{
			if(strcmp(s.roomnumber,room1)==0){
				system("cls");
				gotoxy(20,10);
				cprintf("Sorry Room has been already Booked!!!");
				fclose(f);
				getch();
				MENU();
			}
		}
		itoa(room,s.roomnumber,10);
		nn:
		flag=0;
		fflush(stdin);
		gotoxy(26,7);
		scanf("%s",s.name);
		no=strlen(s.name);
		for(i=0;i<no;i++)
		{
			if(isalpha(s.name[i])!=0)
			flag++;
		}
		if(flag!=no)
		{
			gotoxy(2,22);
			printf("Please Enter Correct Name");
			delay(1000);
			gotoxy(2,22);
			printf("                                ");
			gotoxy(26,7);
			printf("                                      ");
			goto nn;
		}
		strupr(s.name);
		gotoxy(26,9);
		scanf("%s",s.address);
		strupr(s.address);
		m:
		mo=0;
		gotoxy(26,11);
		scanf("%s",s.phonenumber);
		if(strlen(s.phonenumber)==10)
		{
			if(s.phonenumber[0]>='6'&&s.phonenumber[0]<='9')
			mo++;
			for(i=1;i<10;i++)
			{
				if(s.phonenumber[i]>='0'||s.phonenumber[i]<='9')
				mo++;
			}
		}
		if(mo!=10)
		{
			gotoxy(2,22);
			printf("Enter Correct Mobile Number");
			delay(1000);
			gotoxy(2,22);
			printf("           	                    ");
			gotoxy(26,11);
			printf("                             ");
			goto m;
		}
		ema:
		temp=0;
		gotoxy(26,13);
		scanf(" %s",s.email);
		em=strlen(s.email);
		strlwr(s.email);
		for(i=0;i<em-5;i++)
		{
			if(s.email[i+1]=='@')
			temp++;
		}
		if(s.email[em-1]=='m'&&s.email[em-2]=='o'&&s.email[em-3]=='c'&&s.email[em-4]=='.')
		temp++;
		if(temp!=2)
		{
			gotoxy(2,22);
			printf("Enter Correct E-Mail Address");
			delay(1000);
			gotoxy(2,22);
			printf("                               ");
			gotoxy(26,13);
			printf("                                       ");
			goto ema;
		}
		q1:
		gotoxy(26,15);
		scanf("%d",&per);
		if(isalnum(per)!=0)
		{
			gotoxy(26,22);
			printf("Enter Correct Value");
			delay(1000);
			gotoxy(26,22);
			printf("                         ");
			gotoxy(26,15);
			printf("           ");
			goto q1;
		}
		itoa(per,s.period,10);
		gotoxy(1,22);
		printf("Press Enter for Current Date, for Advance Booking press Any Key:");
		day=getch();
		gotoxy(1,22);
		printf("                                                                           ");
		if(day==13)
		{
			d=tm.tm_mday;
			m=tm.tm_mon+1;
			y=tm.tm_year+1900 ;
			gotoxy(26,17);
			printf("%d/%d/%d",d,m,y);
		}
		else
		{
			gotoxy(17,17);
			printf("Year   :");
			gotoxy(17,19);
			printf("Month  :");
			gotoxy(17,21);
			printf("Date   :");
                        mon[0]=mon[3]=mon[5]=mon[7]=mon[8]=mon[10]=mon[12]=31;
                        mon[4]=mon[6]=mon[9]=mon[11]=30;
                        mon[2]=28;
			a:
			gotoxy(26,17);
			printf("      ");
			gotoxy(26,17);
			scanf("%d",&y);
                        if((y%4==0&&y%100!=0)||y%400==0)
                        mon[2]=29;
			if(y==tm.tm_year+1900)
			{
				b:
				gotoxy(26,19);
				printf("     ");
				gotoxy(26,19);
				scanf("%d",&m);
				if(m>=1&&m<=12&&m==tm.tm_mon+1)
				{
					e:
					gotoxy(26,21);
					printf("   ");
					gotoxy(26,21);
					scanf("%d",&d);
					if(d<=mon[m])
                                        goto d;
                                        else
					{
						gotoxy(26,22);
						printf("Wrong Date input");
						delay(1000);
						gotoxy(26,22);
						printf("                ");
						goto b;
					}
				}
				else
				{
					gotoxy(26,22);
					printf("Wrong Month input");
					delay(1000);
					gotoxy(26,22);
					printf("                ");
					goto b;
				}

			}
			else if(y>=tm.tm_year+1900)
			{
				f:
				gotoxy(26,19);
				printf("     ");
				gotoxy(26,19);
				scanf("%d",&m);
				if(m>=1&&m<=12)
				{
					g:
					gotoxy(26,21);
					printf("   ");
					gotoxy(26,21);
					scanf("%d",&d);
					if(d<=mon[m])
                                        goto d;
                                        else
					{
						gotoxy(26,22);
						printf("Wrong Date input");
						delay(1000);
						gotoxy(26,22);
						printf("                ");
						goto g;
					}
				}
				else
				{
					gotoxy(26,22);
					printf("Wrong Month input");
					delay(1000);
					gotoxy(26,22);
					printf("                ");
					goto f;
				}
			}
			else
			{
				gotoxy(26,22);
				printf("Wrong Year input");
				delay(1000);
				gotoxy(26,22);
				printf("                    ");
				goto a;
			}
		}
		d:
		itoa(m,s.month,10);
		itoa(d,s.date,10);
		itoa(y,s.year,10);
		gotoxy(26,17);
		printf("%d/%d/%d",m,d,y);
		s1:
		gotoxy(1,19);
		for(i=0;i<240;i++)
		printf(" ");
		gotoxy(1,19);
		printf("Advance Money          : ");
		scanf("%d",&salery);
		if(salery<200)
		{
			gotoxy(2,22);
			printf("Please Pay More than Minimum Amt..%d",salery);
			delay(1000);
			gotoxy(2,22);
			printf("                                     ");
			gotoxy(26,19);
			printf("                  ");
			goto s1;
		}
		else
		{
			itoa(salery,s.advance,10);
		}

		gotoxy(2,23);
		printf("If Entered Detail is incorrect Press N/n");
		test=getch();
		if(test=='n'||test=='N'){
			fclose(f);
			ADD();
		}
		gotoxy(2,23);
		printf("                                                ");
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		gotoxy(2,23);
		printf(" Room is successfully booked!!");
		printf("\n Press esc key to add another entry,  any other key to exit:");
		test=getche();
		if(test!=27)
			a=0;

	}
	else
	{       system("cls");
		gotoxy(35,8);
		printf("This room doesn't exist");
		getch();
		MENU() ;
		fclose(f);
	}
	}
	fclose(f);
}

		////////////////////////////////////////////////////////
		/* A L L  C U R R E N T  C U S T O M E R  R E C O R D */
		////////////////////////////////////////////////////////

void LIST()
{
	FILE *f;
	int i,line;
	if((f=fopen("FILE.txt","rb"))==NULL)
	exit(0);
	system("cls");
	rv:
	header();
	gotoxy(33,2);
	printf("CUSTOMER DETAIL");
	gotoxy(1,5);
	printf("ROOM   NAME          ADDRESS    MO.NO      EMAIL                PER  ARRIVALDATE");
	gotoxy(65,6);
	printf("-IOD");
	gotoxy(1,7);
	for(i=0;i<80;i++)
	printf("_");
	line=9;
	while(fread(&s,sizeof(s),1,f)==1)
	{
		gotoxy(1,line);
		printf("%s",s.roomnumber);
		gotoxy(5,line);
		printf("%s",s.name);
		gotoxy(21,line);
		printf("%s",s.address);
		gotoxy(32,line);
		printf("%s",s.phonenumber);
		gotoxy(43,line);
		printf("%s",s.email);
		gotoxy(65,line);
		printf("%s",s.period);
		gotoxy(70,line);
		printf("%s",s.month);
		printf("/%s",s.date);
		printf("/%s",s.year);
		line++;
		if(line%24==0)
		{
			printf("\nPress any key to continue:");
			getch();
			goto rv;
		}

	}
	printf("\n");
	for(i=0;i<80;i++)
	printf("_");
	fclose(f);
	getch();
}

		////////////////////////////////////////////////////
		/*             D E L E T E   R E C O R D          */
		////////////////////////////////////////////////////


void DELETE1(char a[5])
{
	FILE *f,*t,*r;
	char roomnumber[5];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("FILE.txt","rb"))==NULL)
	exit(0);
	if((r=fopen("RECORD.txt","ab+"))==NULL)
	exit(0);
	fflush(stdin);
	strcpy(roomnumber,a);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
			fwrite(&s,sizeof(s),1,r);
		else
			fwrite(&s,sizeof(s),1,t);
	}
	fclose(r);
	fclose(t);
	fclose(r);
	remove("FILE.txt");
	rename("temp.txt","FILE.txt");
	fclose(t);
	fclose(f);
}

		///////////////////////////////////////////////
		/*          S E A R C H   R E C O R D        */
		///////////////////////////////////////////////

void SEARCH()
{
	FILE *f;
	char roomnumber[5];
	int flag=1;
	f=fopen("FILE.txt","rb+");
	system("cls");
	if(f==0)
	exit(0);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			flag=0;
			printf("\n   Record Found\n ");
			printf("\n    Room Number     : %s\n",s.roomnumber);
			printf("\n    Name            : %s\n",s.name);
			printf("\n    Address         : %s\n",s.address);
			printf("\n    Phone number    : %s\n",s.phonenumber);
			printf("\n    Email           : %s\n",s.email);
			printf("\n    Period          : %s\n",s.period);
			printf("\n    Arrival date    : %s",s.month);
			printf("/%s",s.date);
			printf("/%s\n",s.year);
			printf("\n    Advance         : %s",s.advance);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

		/////////////////////////////////////////////
		/*          E D I T   R E C O R D          */
		/////////////////////////////////////////////

void EDIT()
{
	FILE *f,*t;
	int i,m,d,y,per,mo,temp,em;
	int k=1;
	char roomnumber[5];
	if((f=fopen("FILE.txt","rb+"))==NULL)
	exit(0);
	system("cls");
	header();
	gotoxy(33,2);
	printf("EDIT CUSTOMER DETAIL");
	gotoxy(1,5);
	printf(" Enter Room number of the customer to edit:\n\n");
	scanf("%s",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
			if((t=fopen("temp.txt","wb+"))==NULL)
			exit(0);
			system("cls");
			header();
			gotoxy(30,2);
			printf("Edit Customer Details");
			gotoxy(1,5);
			printf("Enter Room number      :\n");
			fflush(stdin);
			printf("\nEnter Name             :\n");
			printf("\nEnter Address          :\n");
			printf("\nEnter Phone Number     :\n");
			printf("\nEnter Email            :\n");
			printf("\nEnter Period('x'days)  :\n");
			printf("\nEnter Arrival   Date   : \n");
			gotoxy(26,5);
			printf("%s",s.roomnumber);
			gotoxy(26,7);
			scanf("%s",s.name);
			gotoxy(26,9);
			scanf("%s",s.address);
			m1:
			mo=0;
			gotoxy(26,11);
			scanf("%s",s.phonenumber);
			if(strlen(s.phonenumber)==10)
			{
				if(s.phonenumber[0]>='6'&&s.phonenumber[0]<='9')
				mo++;
				for(i=1;i<10;i++)
				{
					if(s.phonenumber[i]>='0'||s.phonenumber[i]<='9')
					mo++;
				}
			}
			if(mo!=10)
			{
				gotoxy(2,22);
				printf("Enter Correct Mobile Number");
				delay(2000);
				gotoxy(2,22);
				printf("                               ");
				gotoxy(26,11);
				printf("                             ");
				goto m1;
			}
			ema1:
			temp=0;
			gotoxy(26,13);
			scanf(" %s",s.email);
			em=strlen(s.email);
			strlwr(s.email);
			for(i=0;i<em-5;i++)
			{
				if(s.email[i+1]=='@')
				temp++;
			}
			if(s.email[em-1]=='m'&&s.email[em-2]=='o'&&s.email[em-3]=='c'&&s.email[em-4]=='.')
			temp++;
			if(temp!=1)
			{
				gotoxy(2,22);
				printf("Enter Correct E-Mail Address");
				delay(2000);
				gotoxy(2,22);
				printf("                               ");
				gotoxy(26,13);
				printf("                                       ");
				goto ema1;
			}
			gotoxy(26,15);
			scanf("%d",&per);
			itoa(per,s.period,10);
			fflush(stdin);
			gotoxy(26,17);
			printf("%s/%s/%s",s.month,s.date,s.year)  ;
			fwrite(&s,sizeof(s),1,t);
		}
		else{
			fwrite(&s,sizeof(s),1,t);
		}
	}
	if(k==1)
	{
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}
	else
	{
		fclose(t);
		fclose(f);
		remove("FILE.txt");
		rename("temp.txt","FILE.txt");
		printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
		getch();
	}
}

		/////////////////////////////////////////////
		/*         B I L L   G E N E R A T E       */
		/////////////////////////////////////////////

void BILLGEN()
{
	int i,flag=1;
	FILE *f,*q,*t,*r;
	float qty,tax,rate,total[5],subtotal;
	int line,room,count,no=1,htotal,rtotal,adv=0,d1,m1,y1,v,d2,m2,y2,d,m,y,billno;
	char roomnumber[5],desc,ch,itm[20];
	time_t T=time(NULL);
	struct tm tm=*localtime(&T);
	d1=tm.tm_mday;
	m1=tm.tm_mon+1;
	y1=tm.tm_year+1900;
	if((f=fopen("FILE.txt","rb"))==NULL)
	exit(0);
	q=fopen("hotel.txt","ab+");
	system("cls");
	fflush(stdin);
	printf("Enter Room number of the customer to print bill : \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			system("cls");
			flag=0;
			for(i=0;i<80;i++)
			printf("_");
			gotoxy(32,2);
			printf("ABC Hotel services");
			gotoxy(30,3);
			printf("XYZ, main road ,PQRS 823033");
			gotoxy(30,4);
			printf("GST NO: 35AABCS1429B1ZX	");
			gotoxy(1,5);
			for(i=0;i<80;i++)
			printf("_");
			d2=atoi(s.date);
			m2=atoi(s.month);
			y2=atoi(s.year);
			if(y1>=y2)
			{
				y=y1-y2;
				m=m1-m2;
				d=d1-d2;
				if(d<0)
				{
					d=30+d;
					m--;
				}
				if(m<0)
				{
					m=12+m;
					y--;
				}
				qty=(y*365)+(m*30)+d+1;
			}
			gotoxy(1,7);
			printf("Bill No     : %s",billno);
			gotoxy(45,7);
			printf("Date        : %d/%d/%d",d1,m1,y1);
			gotoxy(1,8);
			printf("Room Number : %s",s.roomnumber);
			room=atoi(s.roomnumber);
			gotoxy(45,8);
			printf("Email Id    : %s",s.email);
			gotoxy(1,9);
			printf("Name        : %s",s.name);
			gotoxy(45,9);
			printf("Address     : %s",s.address);
			gotoxy(1,10);
			printf("Phone number: %s",s.phonenumber);
			gotoxy(45,10);
			printf("Arrival date: %s/%s/%s",s.month,s.date,s.year);
			gotoxy(1,11);
			for(i=0;i<80;i++)
			printf("_");
			gotoxy(2,12);
			printf("S.no ");
			gotoxy(8,12);
			printf("Type");
			gotoxy(23,12);
			printf("Item Name");
			gotoxy(40,12);
			printf("Duration");
			gotoxy(50,12);
			printf("Qty ");
			gotoxy(55,12);
			printf("Rate/Price");
			gotoxy(70,12);
			printf("Total ");
			gotoxy(1,13);
			for(i=0;i<80;i++)
			printf("_");
			gotoxy(1,18);
			for(i=0;i<80;i++)
			printf("_");
			printf("Thanks visit again !!!");
			gotoxy(59,23);
			printf("SubTotal %c___________%c",179,179);
			gotoxy(59,22);
			printf("Advance  %c___________%c",179,179);
			gotoxy(59,21);
			printf("CGST(06) %c___________%c",179,179);
			gotoxy(59,20);
			printf("SGST(06) %c___________%c",179,179);
			gotoxy(59,19);
			printf("Total    %c___________%c",179,179);
			v=0;
			rtotal=0;
			line=14;
			count=0;
			for(i=0;i>=0;i++)
			{
				zz:
				gotoxy(1,24);
				printf("In description press R/r for Room Services and F/f for Restaurant Services");
				gotoxy(2,line);
				printf("%d",i+1);
				desc=getch();
				gotoxy(1,24);
				printf("                                                                          ");
				if(desc=='r'||desc=='R'){
				if(count==0){
					if((room>=100&&room<=110)||(room>=200&&room<=210))
						rate=500;
					else if(room>=300&&room<=310)
						rate=800;
					else
						rate=1100;
				gotoxy(8,line);
				printf("Room");
				gotoxy(43,line);
				if(qty<=0)
				qty=0;
				printf("%2.0f",qty);
				gotoxy(55,line);
				printf("%0.2f",rate);
				count=1;
				v=atoi(s.advance);
				rtotal=rate*qty;
				if(qty<=0)
				{
					qty=0;
					line++;
					gotoxy(8,line);
					printf("Non refundable");
					gotoxy(70,line);
					adv=200;
					printf("%d",adv);
					rtotal=200;
				}
				DELETE1(roomnumber);
				}
				    else
				    {
					gotoxy(2,24);
					printf("Room Price has been Already Paid");
					getch();
					gotoxy(2,24);
					printf("                                ");
					goto zz;
				    }
				}
				else if (desc=='F'||desc=='f')
				{
					gotoxy(8,line);
					printf("Restaurant");
					gotoxy(23,line);
					scanf("%s",itm);
					gotoxy(1,24);
					gotoxy(50,line);
					scanf("%f",&qty);
					gotoxy(55,line);
					scanf("%f",&rate);
				}
				else{
					goto zz;
				}
				gotoxy(70,line);
				total[i]=rate*qty;
				printf("%0.2f",total[i]);
				subtotal=subtotal+total[i];
				gotoxy(2,24);
				printf("Press Y for Stop");
				ch=getch();
				if(ch=='Y'||ch=='y')
				break;
				else
				{
					line++;
					gotoxy(2,24);
					printf("                ");
				}

			}
			tax=subtotal*0.06;
			if(subtotal<0)
			tax=0;
			gotoxy(69,19);
			printf(" %0.2f",subtotal);
			gotoxy(69,20);
			printf(" %0.2f",tax);
			gotoxy(69,21);
			printf(" %0.2f",tax);
			gotoxy(69,22);
			printf(" %d.00",v);
			gotoxy(69,23);
			printf(" %0.2f",subtotal+2*tax-v+adv);
			rtotal=subtotal-rtotal;
			subtotal=subtotal+2*tax;
		}
	}

	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	fclose(f);
		fclose(t);
		fclose(r);
	fclose(q);

	getch();
}

		/////////////////////////////////////////////
		/*       M A I N   F U N C T I O N         */
		/////////////////////////////////////////////

void main(){
system("cls");
login();
}