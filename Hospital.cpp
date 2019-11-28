#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
string machine[1000][2];
class Health_Centre
{  
    int phone;
public:
    void add_doctor(int id, string name,long long int phone, string speciality);
};
class Doctor
{
public:
    int dr_id;
    string dr_name;
    long long int dr_phone;
    string dr_speciality;
    friend class Health_Centre;
};
class Surgeon : public Doctor
{
    string sg_name;
    string sg_speciality;
};
class Medical
{
    string m_name;
    string m_license_no;
    int stock_of_drugs;
public:
    void buy_drug(string drug,int number,string date);
};
class Drug : public Medical
{
    public:
    string dr_name;
    int dr_stock;
    string exp_date;
    Drug(){
        dr_stock=0;
    }
};
class Diagnosis
{
    public:
    char symptom[500];
    char diagnosis[500];
    char medicine[500];
    char addmission[30];
    char ward[15];
};
class Treatment : public Diagnosis
{
    string tr_type;
    string tr_name;
    string tr_cost;
};
class Prescription : public Diagnosis
{
    int pr_no;
    string pr_name;
    string pr_type;
public:
    void give_medicine(string drug,int num_drug);
};
class Department
{
public:
    string name;
};
class Staff
{
    string staff_name;
    string staff_speciality;
};
class Technical_Staff : public Staff
{
    string s_name;
    string post;
    public:
    void order_machinery(string str,string str2);
};
class Nurse : public Staff
{
    string nurse_name;
    int ward_number;
public:
    void set_warding(int x);
};
class Addministration_staff : public Staff
{
    string s_name;
    string post;
public:
    void doctor_info(int doc);
};
class Front_Desc_Staff : public Addministration_staff
{
    string fd_name;
    string fd_post;
};
class Patient
{
    public:
    char name[20];
    char address[100];
    char contact[10];
    char email_id[50];
    char age[5];
    char sex[8];
    char blood_gp[5];
    char disease_past[50];
    char id[15];
    void appointment();
    void admit();
    void leave();
    void under_go_operation();
};

Doctor D1[50];
Health_Centre h1;
void Health_Centre :: add_doctor(int id, string name,long long int phone, string speciality)
{
    D1[id].dr_id = id;
    D1[id].dr_name = name;
    D1[id].dr_phone = phone;
    D1[id].dr_speciality = speciality;
}
void enter_doc(){
    int id=10;
    string name;
    long long int phone;
    string speciality;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
    cout<<"\n\t\t\t\t\t"<<"\nDoctor Name: "; cin>>name;
    cout<<"\n\t\t\t\t\t"<<"\nDoctor's Phone number : "; cin>>phone;
    cout<<"\n\t\t\t\t\t"<<"\nDoctor speciality: "; cin>>speciality;
    h1.add_doctor(id,name,phone,speciality);
    cout<<"\n\t\t\t\t\t"<<"Information successfully added"<<"\n";
    cout<<"\n\n";
    id++;
	system("pause");
    system("cls");
}

void Patient :: appointment()
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    fstream pat_file;
    char fname[20];
    cout<<"\n\nEnter the patient's id to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Information about "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
            int id_Doc;
			cout<<"Book appointment................on : "<<asctime (timeinfo);pat_file<<"Appointment Time: "<<asctime (timeinfo)<<"\n";
            cout<<"\nEnter Doctor id: "; pat_file<<"Doctor name: "; cin>>id_Doc; pat_file<<D1[id_Doc].dr_name<<"\n";
            pat_file<<"\n********************************************************************\n\n";
            cout<<"\nInformation successfully Add";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
		}
    return;
}
void Patient :: admit()
{
        time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    fstream pat_file;
    char fname[20];
    cout<<"\n\nEnter the patient's id to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Information about "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
            int id_Doc;
			cout<<"Patient admit................on : "<<asctime (timeinfo);pat_file<<"Admit Time: "<<asctime (timeinfo)<<"\n";
            pat_file<<"\n********************************************************************\n\n";
            cout<<"\nInformation successfully Add";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
		}
    return;
}
void Patient :: leave()
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    fstream pat_file;
    char fname[20];
    cout<<"\n\nEnter the patient's id to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Information about "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
            int id_Doc;
			cout<<"Patient leave................on : "<<asctime (timeinfo);pat_file<<"Leave Time: "<<asctime (timeinfo)<<"\n";
            pat_file<<"\n********************************************************************\n\n";
            cout<<"\nInformation successfully Add";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
		}
    return;
}
void Patient :: under_go_operation()
{
                time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    fstream pat_file;
    char fname[20];
    cout<<"\n\nEnter the patient's id to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Information about "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
            int id_Doc;
            string op;
			cout<<"Patient operation................on : "<<asctime (timeinfo);pat_file<<"Operation Time: "<<asctime (timeinfo)<<"\n";
            cout<<"\nEnter Doctor id: "; pat_file<<"Doctor name: "; cin>>id_Doc; pat_file<<D1[id_Doc].dr_name<<"\n";
            cout<<"\nOperation Details: "; pat_file<<"Operation Details: "; cin>>op; pat_file<<op<<"\n";
            pat_file<<"\n********************************************************************\n\n";
            cout<<"\nInformation successfully Add";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
		}
    return;
}
int machine_num=0;
void Technical_Staff :: order_machinery(string str,string str2)
{
    machine[machine_num][0]=str;
    machine[machine_num][1]=str2;
    machine_num++;
}

void Nurse :: set_warding(int x)
{
    ward_number = x;
}
Addministration_staff a1;
void Addministration_staff :: doctor_info(int doc)
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
    cout<<"\n\t\t\t\t\t"<<"Doctor Name: "<<D1[doc].dr_name<<"\n";
    cout<<"\n\t\t\t\t\t"<<"Doctor's Phone number: "<<D1[doc].dr_phone<<"\n";
    cout<<"\n\t\t\t\t\t"<<"Doctor speciality: "<<D1[doc].dr_speciality<<"\n";
    cout<<"\n\n";
	system("pause");
    system("cls");
}
void search_doc(){
    int id;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
    cout<<"\n\t\t\t\t\t"<<"\nDoctor id: "; cin>>id;
    a1.doctor_info(id);
    return;
}
vector < Drug > DRUG;
int DRUG_NUM=0;
void Prescription :: give_medicine(string drug,int num_drug)
{
    for(int i=0;i<DRUG.size();++i)
    {
        if(DRUG[i].dr_name==drug)
        {
            DRUG[i].dr_stock=DRUG[i].dr_stock-num_drug;
            break;
        }
    }
}

void Medical :: buy_drug(string drug,int number,string date)
{
    Drug drug1;
    drug1.dr_name=drug;
    drug1.dr_stock=drug1.dr_stock+number;
    drug1.exp_date=date;
    DRUG.push_back(drug1);
    DRUG_NUM++;
    cout<<DRUG_NUM<<" "<<drug1.dr_name<<" "<<drug1.dr_stock<<" "<<drug1.exp_date<<"\n";
}

void main_macine(){
    string str;
    int i=0;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
    cout<<"\n\t\t\t\t\t"<<"Search Macine Name: "; cin>>str; cout<<"\n";
    for(i=0;i<machine_num;i++){
        if(machine[i][0]==str)
        break;
    }
    cout<<"\n\t\t\t\t\t"<<"Macine information: "<<machine[i][1]<<"\n";
    cout<<"\n\n";
	system("pause");
    system("cls");
}
Technical_Staff t1;
Medical m1;
void add_machine(){
    string str,str2;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
    cout<<"\n\t\t\t\t\t"<<"\nMachine Name: "; cin>>str;
    cout<<"\n\t\t\t\t\t"<<"\nMachine Information: "; cin>>str2;
    t1.order_machinery(str,str2);
    cout<<"\n\t\t\t\t\t"<<"Information successfully added"<<"\n";
    cout<<"\n\n";
	system("pause");
    system("cls");
}
void update_drug(){
    fstream pat_file;
    pat_file.open("drug.txt");
        if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
        else{
            for(int i=0;i<DRUG_NUM;i++){
                pat_file<<"0"<<" "<<DRUG[i].dr_name<<" "<<DRUG[i].dr_stock<<" "<<DRUG[i].exp_date<<"\n";
            }
            pat_file<<"1";
        }
        cout<<"DONE"<<"\n";
    pat_file.close();
}
void read_drug(){
    ifstream pat_file;
    int r;
    string s1,s2;
    int dr_s;
    Drug drug1;
    pat_file.open("drug.txt");
    if(!pat_file){
	cout<<"\nError while opening the file\n";
	}
    else{
        for(int i=0;true;i++){
            pat_file>>r;
                if(r==0){
                pat_file>>s1>>dr_s>>s2;
                drug1.dr_name=s1;
                drug1.dr_stock=drug1.dr_stock+dr_s;
                drug1.exp_date=s2;
                DRUG.push_back(drug1);
                cout<<"0"<<" "<<DRUG[i].dr_name<<" "<<DRUG[i].dr_stock<<" "<<DRUG[i].exp_date<<"\n";
                DRUG_NUM++;
                }
                if(r==1)
                {
                    break;
                }
            }
        }
    cout<<"OKKA"<<"\n";
    pat_file.close();
}
void add_drug(){
    string str,str2;
    int stock;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
    cout<<"\n\t\t\t\t\t"<<"Drug Name: "; cin>>str;
    cout<<"\n\t\t\t\t\t"<<"Stock: "; cin>>stock;
    cout<<"\n\t\t\t\t\t"<<"Exp date: "; cin>>str2;
    m1.buy_drug(str,stock,str2);
    cout<<"\n\t\t\t\t\t"<<"Information successfully added"<<"\n";
    cout<<"\n\n";
    update_drug();
	system("pause");
    system("cls");
}
void drug_search(){
    string str;
    int i;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
    cout<<"\n\t\t\t\t\t"<<"Drug Name: "; cin>>str;
    for(i=0;i<DRUG_NUM;i++){
        if(DRUG[i].dr_name==str)
        break;
    }
    cout<<"\n\t\t\t\t\t"<<"Stock: "<<DRUG[i].dr_stock<<"\n";
    cout<<"\n\t\t\t\t\t"<<"Exp date: "<<DRUG[i].exp_date<<"\n";

    cout<<"\n\n";
	system("pause");
    system("cls");
}
void add_patient(){
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

  ofstream pat_file;
  char fname[20];
  cout<<"\n\n\n\nEnter the patient's id : ";
  cin.ignore();
  gets(fname);
  pat_file.open(fname);
  		if(!fname)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
            Patient ak;
            cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";//fn1353 st
            cout<<"\nName : ";pat_file<<"Name : ";gets(ak.name);pat_file<<ak.name<<"\n";
            cout<<"\nAddress : ";pat_file<<"Address : ";gets(ak.address);pat_file<<ak.address<<"\n";
            cout<<"\nContact Number : ";pat_file<<"Contact Number : ";gets(ak.contact);pat_file<<ak.contact<<"\n";
            cout<<"\nE mail : ";pat_file<<"E mail : ";gets(ak.email_id);pat_file<<ak.email_id<<"\n";
            cout<<"\nAge : ";pat_file<<"Age : ";gets(ak.age);pat_file<<ak.age<<"\n";
            cout<<"\nSex : ";pat_file<<"Sex : ";gets(ak.sex);pat_file<<ak.sex<<"\n";
            cout<<"\nBlood Group : ";pat_file<<"Blood Group : ";gets(ak.blood_gp);pat_file<<ak.blood_gp<<"\n";
            cout<<"\nAny Major disease suffered earlier : ";pat_file<<"Any Major disease suffered earlier : ";gets(ak.disease_past);pat_file<<ak.disease_past<<"\n";
            cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";
            cout<<"\nInformation Saved Successfully\n";
            }
  system("pause");
  system("cls");
  return;
}

void add_diagnosi(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    fstream pat_file;
    char fname[20];
    cout<<"\n\nEnter the patient's id to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Information about "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
			cout<<"Adding more information in patient's file................on : "<<asctime (timeinfo);pat_file<<"Description of "<<asctime (timeinfo)<<"\n";
            Diagnosis add;
            cout<<"\nSymptoms : "; pat_file<<"Symptoms : ";gets(add.symptom); pat_file<<add.symptom<<"\n";
            cout<<"\nDiagnosis : "; pat_file<<"Diagnosis : ";gets(add.diagnosis); pat_file<<add.diagnosis<<"\n";
            cout<<"\nAddmission Required? : "; pat_file<<"Addmission Required? : ";gets(add.addmission); pat_file<<add.addmission<<"\n";
            cout<<"\nType of ward : "; pat_file<<"Type of ward : ";gets(add.ward); pat_file<<add.ward<<"\n";pat_file<<"\n********************************************************************\n";
            cout<<"\n\n"<<add.ward<<" ward is alloted Successfully\n";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
		}
    return;
}
void patient_info(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);
    char fname[20];
    fstream pat_file;
    cout<<"\n\nEnter the patient's id to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Full Medical History of "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
        }
    system("pause");
    system("cls");
    return;
}
void information(){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                         IIT HEALTH CENTRE MANAGEMENT SYSTEM                           |@@\n";
    cout<<"\t\t\t\t\t@@|                                Phone number: 842484662                                |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|        A Primary Health Centre (PHC) has been stared at the IIT Jodhpur in 2017.       |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
}
int login(int i){
   string pass ="";
   char ch;
   string id;
   string user[3];
   user[0]="Nirmal";
   user[1]="Manan";
   user[2]="Parshv";
   string password[3];
   password[0]="Nirmal";
   password[1]="Manan";
   password[2]="Parshv";
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";
   cout<<"\t\t\t\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t\t\t\t     LOGIN \n";	
   cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n";
   cout << "\t\t\t\t\t\t\t\tEnter ID: ";
   cin>>id;
   if(id==user[i-1]){
   cout << "\t\t\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == password[i-1]){
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login(i);
   }
   }
   else{
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login(i);
   }
   return 0;
}

Prescription p1;
void add_pre(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    fstream pat_file;
    char fname[20];
    cout<<"\n\nEnter the patient's id to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Information about "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
            int n,i,num;
            string str;
			cout<<"Adding more information in patient's file................on : "<<asctime (timeinfo);pat_file<<"Description of "<<asctime (timeinfo)<<"\n";
            cout<<"How many Medicine ? :"; cin>>n;
            pat_file<<"\n Prescription:";
            int j;
            for(i=0;i<n;i++){
                cout<<"\n\t\t\t\t\t"<<"Drug Name: "; cin>>str;
                    for(j=0;j<DRUG_NUM;j++){
                    if(DRUG[j].dr_name==str)
                    break;
                    }
                cout<<"\n\t\t\t\t\t"<<"Numbers of Drugs: "; cin>>num;
                p1.give_medicine(str,num);
                pat_file<<"\n\tDrug Name\t\t\t\t\tNumberof Drugs";
                pat_file<<"\n\t"<<str<<"\t\t\t\t\t"<<num;
            }
            pat_file<<"\n********************************************************************\n";
            cout<<"Information Successfully added\n";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
		}
        update_drug();
    return;
}
void temp_data()
{
    h1.add_doctor(0,"Dr. Ram Singh",9831545122,"ENT Specialist");
    h1.add_doctor(1,"Dr.Mukesh Chaudhary",8622136573,"Pediatrician");
    h1.add_doctor(2,"Dr. Mukhopadhyay",8460226646,"Psychiatrist");
    h1.add_doctor(3,"Dr. Rajesh Koothrapalli",9645235972,"Surgeon");
    h1.add_doctor(4,"Dr. Suhaag Patel",8756432894,"Physician");
    h1.add_doctor(5,"Dr. Chetan Shah",7835926613,"Child Specialist");
    h1.add_doctor(6,"Dr. Prakash Singhi",6355981245,"Neurologist.");
    h1.add_doctor(7,"Dr. Nilay Desai",6852958214,"Orthopedist");
    h1.add_doctor(8,"Dr. Girish Pokharna",7996012553,"Ophthalmologist");
    h1.add_doctor(9,"Dr. Manisha Jhawar",9556021022,"Surgeon");

    t1.order_machinery("Defibrillators","Working well");
    t1.order_machinery("Anesthesia Machines","Under maintenance");
    t1.order_machinery("Sterilizers","Working well");
    t1.order_machinery("ECG Machines","Not working properly");
    t1.order_machinery("Electrosurgical Units","Under maintenance");
    t1.order_machinery("Breast pump","Working well");
    t1.order_machinery("Nebulizers","One is working, one is not working");

    read_drug();
}
int main(){
    int i;
    char fname[20];
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    //printing the welcome note
    re:
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                         IIT HEALTH CENTRE MANAGEMENT SYSTEM                           |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                 -Manan Chhajer(B18CSE029)             |@@\n";
    cout<<"\t\t\t\t\t@@|                                                 -Nirmal Katariya(B18CSE022)           |@@\n";
    cout<<"\t\t\t\t\t@@|                                                 -Shah Parshv(B18CSE051)               |@@\n";
    cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
    int j;
    temp_data();
    start:
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";	
    cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
    cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
    cout<<"\t\t\t\t\t\t|                                    	                          |\n";
    cout<<"\t\t\t\t\t\t|             1  >> Technical staff                               |\n";
    cout<<"\t\t\t\t\t\t|             2  >> Front desc staff                              |\n";
    cout<<"\t\t\t\t\t\t|             3  >> Medical                                       |\n";
    cout<<"\t\t\t\t\t\t|             4  >> Exit                                          |\n";
    cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
    b:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>j;
    if(j>4||j<1){cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto b;} //if inputed choice is other than given choice
    if(j==4) exit(1);
    system("cls");
    login(j);
    if(j==2){
        pat:
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";	
        cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
        cout<<"\t\t\t\t\t\t|             2  >> Add Diagnosis Information                     |\n";
        cout<<"\t\t\t\t\t\t|             3  >> Full History of the Patient                   |\n";
        cout<<"\t\t\t\t\t\t|             4  >> Information About the Hospital                |\n";
        cout<<"\t\t\t\t\t\t|             5  >> Add Doctor                                    |\n";
        cout<<"\t\t\t\t\t\t|             6  >> Add Appointment                               |\n";
        cout<<"\t\t\t\t\t\t|             7  >> Admit Patient                                 |\n";
        cout<<"\t\t\t\t\t\t|             8  >> Discharge Patient                             |\n";
        cout<<"\t\t\t\t\t\t|             9  >> Undergo Operation                             |\n";
        cout<<"\t\t\t\t\t\t|             10 >> Add Prescription                              |\n";
        cout<<"\t\t\t\t\t\t|             11 >> About Doctor                                  |\n";
        cout<<"\t\t\t\t\t\t|             12 >> Exit the Program                              |\n";
        cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>i;
        if(i>12||i<1){cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto a;}//if inputed choice is other than given choice
        if(i==12) { system("cls"); goto start; }
        if(i==1) { system("cls"); add_patient(); goto pat;}
        if(i==2) { system("cls"); add_diagnosi(); goto pat;}
        if(i==3) { system("cls"); patient_info(); goto pat;}
        if(i==4) { system("cls"); information(); goto pat;}
        Patient p2;
        if(i==5) { system("cls"); enter_doc(); goto pat;}
        if(i==6) { system("cls"); p2.appointment(); goto pat;}
        if(i==7) { system("cls"); p2.admit(); goto pat;}
        if(i==8) { system("cls"); p2.leave(); goto pat;}
        if(i==9) { system("cls"); p2.under_go_operation(); goto pat;}
        if(i==10) { system("cls"); add_pre(); goto pat;}
        if(i==11) { system("cls"); search_doc(); goto pat;}
    }
    if(j==1){
        tech:
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";	
        cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t|             1  >> Add New Machine                               |\n";
        cout<<"\t\t\t\t\t\t|             2  >> Maintain Machine                              |\n";
        cout<<"\t\t\t\t\t\t|             3  >> Exit the Program                              |\n";
        cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        c:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>i;
        if(i>3||i<1){cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto c;} //if inputed choice is other than given choice
        if(i==3) { system("cls"); goto start; }
        if(i==1) { system("cls"); add_machine(); goto tech; }
        if(i==2) { system("cls"); main_macine(); goto tech; }
    }
    if(j==3){
        medi:
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  IIT HEALTH CENTRE MANAGEMENT SYSTEM \n\n";	
        cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t|             1  >> Add New Drug                                  |\n";
        cout<<"\t\t\t\t\t\t|             2  >> Search Drug                                   |\n";
        cout<<"\t\t\t\t\t\t|             3  >> Exit the Program                              |\n";
        cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        d:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>i;
        if(i>3||i<1){cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto d;} //if inputed choice is other than given choice
        if(i==3) { system("cls"); goto start; }
        if(i==1) { system("cls"); add_drug(); goto medi; }
        if(i==2) { system("cls"); drug_search(); goto medi; }
    }
}
