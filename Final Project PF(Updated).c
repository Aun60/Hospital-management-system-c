#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//////FUNCTION DECLARATION/////
void WelcomeScreen(void);
void title(void);
void LoginScreen(void);
void MainMenu(void);
void ex_it(void);
void search_recod_by_id(void);
void admitPatient();
void patientList();
void dischargePatient();
void addDoctor();
void RemoveDoctor();
void doctorList();

struct patient{
    int id;
    char patientName[50];
    int age;
    char gender[10];
    char contact[12];
    char patientAddress[50];
    char disease[50];
    char date[12];
}p;

struct doctor{
    int id;
    char name[50];
    int age;
    char gender[10];
    char contact[12];
    char address[50];
    char specialize[50];
    char date[12];
}d;

///Welcome Sceen////
void WelcomeScreen(void)
{
	printf("\n\t\t\t#####################################################################");
	printf("\n\t\t\t#\t\t            Welcome To\t\t\t  \t    #");
	printf("\n\t\t\t#\t              FAST MEDICAL HOSPITAL       \t \t    #");
	printf("\n\t\t\t#####################################################################");
	printf("\n\n\n\n\n Press any key to continue..........\n");
	getch();
	system("cls");
}
//// Welcome screen end////

////Title/////
void title(void)
{
	printf("\n\t------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t \t        Fast Medical Hospital             ");
	printf("\n\t------------------------------------------------------------------------------------------------------");
}

/////Title end/////


////exit///
void ex_it(void)
{
	system("cls");
	title();
	printf("\n\n\n\t\t\t\t\t\tThank You :)");
	exit(0);
}
//exit end///

/// Main Menu////
void MainMenu(void)
{
int ch;

    while(1){
        system("cls");
        title();
//        printf("\n\t\t\t<== ------------- Fast Medical Hospital------------ ==>\n");
        printf("\n\t\t\t\t1.Admit Patient\n");
        printf("\t\t\t\t2.Patient List\n");
        printf("\t\t\t\t3.Discharge Patient\n");
        printf("\t\t\t\t4.Add Doctor\n");
        printf("\t\t\t\t5.Doctors List\n");
        printf("\t\t\t\t6.Search Recod of Patient by ID\n");
        printf("\t\t\t\t7.Remove Doctor Record by ID\n");
        printf("\t\t\t\t0.exit\n\n");
        printf("\n\n\n\t\t\t\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            ex_it();

        case 1:
            admitPatient();
            break;

        case 2:
            patientList();
            break;

        case 3:
            dischargePatient();
            break;

        case 4:
            addDoctor();
            break;

        case 5:
            doctorList();
            break;
        
		case 6:
            search_recod_by_id();
            break;
		
		case 7:
            RemoveDoctor();
            break;	 

        default:
            printf("Invalid Choice...\n\n");

        }
        printf("\nPress Any Key To Continue...");
        getch();
    }
}
//////Menu End///// 
FILE *fp;

void main()
{
	WelcomeScreen();
	title();
	LoginScreen();
}


//Search by ID//////
void search_recod_by_id(void)
{
	int id, f=0;
	char s,name[20];
    system("cls");
    title();
    printf("\n\t\t\t\t\t\t<== Find Patient Recod by ID ==>\n\n");
    printf("Enter Patient id to get record: \n");
	scanf("%d", &id);

    FILE *ft;
    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.id){
            f=1;
            break;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }
	
if(f==1)
{
    system("cls");
    title();
    printf("\n\t\t\t\t\t\t<== Patient List ==>\n\n");
    printf("%-10s %-20s %-10s %-7s %-13s %-20s %-22s %s\n", "Id", "Patient Name","Age","Gender","Contact", "Address", "Disease", "Date");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-10d %-20s %-10d %-7s %-13s %-20s %-22s %s\n", p.id, p.patientName,p.age,p.gender,p.contact, p.patientAddress, p.disease, p.date);
    getch();
}else{
    printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

}
   /// Main Login screen////	
	void LoginScreen(void)
	{
		int trials=0;
		char username[15];
		char password[15];
		char ori_username[15]={"Fast"};
		char ori_password[15]={"123"};
		do
		{
			printf("\n\n\t\t\t\t\tEnter Your Username and Password :");
			printf("\n\n\n\t\t\t\t\t\tUSERNAME:");
			scanf("%s",username);
			printf("\nt\t\t\t\t\t\tPASSWORD:");
			scanf("%s",password);
			if(strcmp(username,ori_username)==0 && strcmp(password,ori_password)==0)
			{
				printf("\n\n\n\t\t\t\t........Login Successfull......");
				getch();
				MainMenu();
				break;
			}
			else
			{
				printf("\n\n\t\t\tEither Password Or User Name Is Incorrect: ( Try Again: )");
				trials++;
				getch();
			}
		}
		while(trials<=2);
		if(trials>2)
		{
			printf("......You Cannot Login Know.......\n");
			printf("<<<<<<<password attempts limit has beeb crossed>>>>>>>>");
			getch();
			ex_it();	
		}
	}

    


void admitPatient(){
	system("cls");
	title();
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(p.date, myDate);

    fp = fopen("patient.txt", "ab");

    printf("\n\nEnter Patient id: ");
    scanf("%d", &p.id);

    printf("Enter Patient name: ");
    fflush(stdin);
    gets(p.patientName);
    
    printf("Enter Patient age: "); ////
    scanf("%d", &p.age);
    
    printf("Enter Patient gender: "); /////
    fflush(stdin);
    gets(p.gender);
    
    printf("Enter Patient contact no: "); ///////
    fflush(stdin);
    gets(p.contact);

    printf("Enter Patient Address: ");
    fflush(stdin);
    gets(p.patientAddress);
 
    printf("Enter Patient Disease: ");
    fflush(stdin);
    gets(p.disease);

    printf("\nPatient Added Successfully");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void patientList(){

    system("cls");
    title();
    printf("\n\t\t\t\t\t\t<== Patient List ==>\n\n");
    printf("%-10s %-20s %-10s %-7s %-13s %-20s %-22s %s\n", "Id", "Patient Name","Age","Gender","Contact", "Address", "Disease", "Date");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("patient.txt", "rb");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-10d %-20s %-10d %-7s %-13s %-20s %-22s %s\n", p.id, p.patientName,p.age,p.gender,p.contact, p.patientAddress, p.disease, p.date);
    }

    fclose(fp);
}


void dischargePatient(){
	

    int id, f=0;
    system("cls");
    title();
    printf("\n\t\t\t\t\t\t<== Discharge Patient ==>\n\n");
    printf("Enter Patient id discharge: \n");
    scanf("%d",&id);

    FILE *ft;
    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.id){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }
 
	
if(f==1){
        printf("\n\nPatient Discharged Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");
	

}

void addDoctor(){
    
    
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(d.date, myDate);

    int f=0;

    system("cls");
    title();
    printf("\n\t\t\t\t\t\t<== Add Doctor ==>\n\n");

    fp = fopen("doctor.txt", "ab");

    printf("Enter Doctor id: ");
    scanf("%d", &d.id);

    printf("Enter Doctor Name: ");
    fflush(stdin);
    gets(d.name);
    
    printf("Enter Doctor age: "); ////
    scanf("%d", &d.age);
    
    printf("Enter Doctor gender: "); /////
    fflush(stdin);
    gets(d.gender);
    
    printf("Enter Doctor contact no: "); ///////
    fflush(stdin);
    gets(d.contact);

    printf("Enter Doctor Address: ");
    fflush(stdin);
    gets(d.address);

    printf("Doctor Specialize in: ");
    fflush(stdin);
    gets(d.specialize);

    printf("Doctor Added Successfully\n\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}



void doctorList(){
    system("cls");
    title();
    printf("\n\t\t\t\t\t\t<== Doctor List ==>\n\n");

    printf("%-10s %-20s %-10s %-7s %-13s %-20s %-22s %s\n", "id", "Name","Age","Gender","Contact", "Address", "Specialize","Date");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("doctor.txt", "rb");
    while(fread(&d, sizeof(d), 1, fp) == 1){
        printf("%-10d %-20s %-10d %-7s %-13s %-20s %-22s %s\n", d.id, d.name,d.age,d.gender,d.contact, d.address, d.specialize, d.date);
    }

    fclose(fp);
}

void RemoveDoctor()
{
int id, f=0;
    system("cls");
    title();
    printf("\n\t\t\t\t\t\t<== Remove Doctor ==>\n\n");
    printf("Enter Doctor id to remove: \n");
    scanf("%d",&id);

    FILE *ft;
    fp = fopen("doctor.txt", "rb");
    ft = fopen("tempd.txt", "wb");

    while(fread(&d, sizeof(d), 1, fp) == 1){

        if(id == d.id){
            f=1;
        }else{
            fwrite(&d, sizeof(p), 1, ft);
        }
    }
 
	
if(f==1){
        printf("\n\nDoctor record has been removed successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("doctor.txt");
    rename("tempd.txt", "doctor.txt");
		
}
