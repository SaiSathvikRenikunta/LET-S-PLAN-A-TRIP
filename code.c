#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct{
    int p,q,w;
    char fname[30];
    char lname[30],uname[30];
    char email[30],pass[20];
}detail;
void heading()
{
    system("clear");
    printf("\t\t************************************************************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t*--LET'S PLAN A TRIP--*\n");
    printf("\t\t\t\t\t\t\t\t\t            --We shall make this trip memorable together ;-p\n");
    printf("\t\t************************************************************************************************************************************\n");
}
int signup(){
    FILE *fpt;
    detail user;
    int i;
    char c,passcode[30],f[30],l[30];
    heading();
    fpt=fopen("signup.txt","r");
    fseek(fpt,-2,2);
    fscanf(fpt,"%d",&user.p);
    fclose(fpt);
    i=user.p + 1;
    printf("%d\n",i);
    printf("\t---A warm welcome to our user, to enroll to our family fillup these details---\n\n");
    getchar();
    printf("\n\t\tFirst name (Without spaces) : ");
    gets(f);
    strcpy(user.fname,f);
    printf("\n\t\tsecond name (Without spaces) : ");
    gets(l);
    strcpy(user.lname,l);
    printf("\n\t\tEnter your email ID : ");
    gets(user.email);
    printf("\n\t\tUsername: ");
    gets(user.uname);
    strncpy(passcode, getpass("\n\t\tCreate a password: "), 99);
    strcpy(user.pass,passcode);
    fpt=fopen("signup.txt","a+");
    fprintf(fpt,"Name : %s %s",user.fname,user.lname);
    fprintf(fpt,"\tpassword : %s\tEmail : %s\tUsername : %s\nP = %d ",user.pass,user.email,user.uname,i);
    fclose(fpt);
    return i;
}
int signin(){
    FILE *fpt;
    detail user;
    int n=0,result,result1,i=0;
    char username[20],password[20],ch,c;
    heading();
    fpt=fopen("signup.txt","r");
    fseek(fpt,0l,2);
    n=ftell(fpt);
    fclose(fpt);
me: printf("\n\n\t\tUsername : ");
    getchar();
    gets(username);
    strncpy(password, getpass("\n\t\tPassword: "), 99);
    fpt=fopen("signup.txt","r");
    fseek(fpt,0l,0);
    while(i<n)
    {
        fscanf(fpt,"P = %d Name : %s %s\tpassword : %s\tEmail : %s\tUsername : %s",&user.p,user.fname,user.lname,user.pass,user.email,user.uname);
        result=strcmp(password,user.pass);
        result1=strcmp(username,user.uname);
        for(;(c=getc(fpt))!='\n';i++);
        if(!(result && result1))
            return user.p;
    }
    printf("\n\t\tPlease signup first \n\n\t\t\t Enter 'A' to retry \n\n\t\t\t Enter 'B' to continue to signup\n\n\t\t");
sa: scanf(" %c",&ch);
    if(ch=='B')
        signup();
    else if(ch=='A')
        goto me;
    else{
        printf("Enter a valid option ");
        goto sa;
    }
}
void places(){
    char cha;
mai:heading();
    printf("\n\n\t\tWe can now make a efficient plan and enjoy it. We would like to recommend you to some most visisted places in INDIA\n\n");
    printf("\t\tA.HYEDERABAD\t\t\t\tB.KANYAKUMARI\n\n\t\tC.GOA\t\t\t\t\tD.KERLA\n\n\t\tE.AGRA");
    printf("\n\n\t\tEnter option mentioed across your choice place (If none of them intrests you enter 'N') : ");
    scanf(" %c",&cha);
    switch(cha){
        case 'A':printf("\n\t\tHyderabad is the capital of southern India's Telangana state.\n\t\t A major center for the technology industry, it's home to many upscale restaurants and shops.\n\t\t Its historic sites include Golconda Fort, a former diamond-trading center that was once the Qutb Shahi dynastic capital.\n\t\t The Charminar, a 16th-century mosque whose 4 arches support towering minarets, is an old city landmark near the long-standing Laad Bazaar.");
                 printf("\n\t\tPlaces to visit :\n\t\tA.GOLCONDA\n\t\tB.CHARMINAR\n\t\tC.SALAR JUNG MUSEUM\n\t\tD.RAMOJI FILM CITY");
                 break;
        case 'B':printf("\n\t\tKanyakumari is a coastal town in the state of Tamil Nadu on India's southern tip.\n\t\t Jutting into the Laccadive Sea, the town was known as Cape Comorin during British rule \n\t\tand is popular for watching sunrise and sunset over the ocean.");
                 printf("\n\t\tPlaces to visit :\n\t\tA.Thirparappu Falls\n\t\tB.kanyakumar Beach\n\t\tC.Vivekananda Rock\n\t\tD.Thanumalayan Temple");
                 break;
        case 'C':printf("\n\t\tGoa is a state in western India with coastlines stretching along the Arabian Sea.\n\t\t Its long history as a Portuguese colony prior to 1961 is evident in its preserved\n\t\t 17th-century churches and the area’s tropical spice plantations.");
                 printf("\n\t\tPlaces to visit :\n\t\tA.Baga Beach\n\t\tB.Dona Paula\n\t\tC.Dudhsagar Waterfalls");
                 break;
        case 'D':printf("\n\t\tThe state has the highest media exposure in India with newspapers publishing in nine languages,\n\t\t mainly English and Malayalam. Kerala is one of the prominent tourist destinations of India,\n\t\t with backwaters, hill stations, beaches, Ayurvedic tourism and tropical greenery as its major attractions.");
                 printf("\n\t\tPlaces to visit :\n\t\tA.Munnar\n\t\tB.Alappuzha\n\t\tC.Kochhi");
                 break;
        case 'E':printf("\n\t\tAgra is a city on the banks of the Yamuna river in the Agra district of the Indian state of Uttar Pradesh.\n\t\t It is 206 kilometres south of the national capital New Delhi.");
                 printf("\n\t\tPlaces to visit :\n\t\tA.Taj mahal\n\t\tB.Hotel Oberio( most expensive hotel in INDIA)\n\t\tC.Agra fort\n\t\tD.Akbar's tomb");
                 break;
        case 'N':break;
        default :printf("\n\t\tEnter a valid option");
                 goto mai;
                 break;
    }
    if(cha!='N'){
re:     printf("\n\t\tDo you want to check our any different places Y/N : ");
        scanf(" %c",&cha);
        if(cha=='Y')
            goto mai;
        else if(cha=='N');
        else{
            printf("\n\t\tEnter a valid option\n");
            goto re;
        }
    }
}
int main()
{
    char cho,city[20],rcho,bname[20],scity[20],c;
    int res,people,d1,d2,m1,m2,y1,y2,n=1,t,a,nam,ch;
    int i=0,k;
    detail user;
    FILE *fpt;
    heading();
    printf("\tWe welcome you, our user to our program. We help you to plan a TRIP to your destinated location, we make the best we could to make your journey wonderful.\n");
    printf("\n\t\tSIGNIN OR SINGUP");
    printf("\n\n\t\tFor SIGNIN enter A");
    printf("\n\n\t\tFor SIGNUP enter B\n\n\t\t");
go: scanf(" %c",&cho);
    if(cho=='A')
        res=signin();
    else if(cho=='B')
        res=signup();
    else{
        printf("\n\t\tEnter a valid option\n\n\t\t");
        goto go;
    }
    fpt=fopen("signup.txt","r");
    fseek(fpt,0l,2);
    n=ftell(fpt);
    fclose(fpt);
    fpt=fopen("signup.txt","r");
    fseek(fpt,0l,0);
    while(i<n)
    {
        fscanf(fpt,"P = %d Name : %s %s\tpassword : %s\tEmail : %s\tUsername : %s",&user.p,user.fname,user.lname,user.pass,user.email,user.uname);
        for(;(c=getc(fpt))!='\n';i++);
        if(res==user.p)
            break;
    }
ni: heading();
    printf("\n\t\tUSERNAME : %s",user.uname);
    printf("\n\n\t\t1.A new Journey\n\n\t\t2.Review booked Journey\n\n\t\tEnter your choice : ");
    scanf("%d",&nam);
    if(nam==2){
        fpt=fopen("travel.txt","r");
        fseek(fpt,0l,2);
        k=ftell(fpt);
        fclose(fpt);
        fpt=fopen("travel.txt","r");
        fseek(fpt,0l,0);
        for(;i<k;)
        {
            printf("%d,%d",i,k);
            fscanf(fpt,"\tP = %d\tbill name : %s\t",&a,bname);
            fscanf(fpt,"Journey : %s to %s\tDate : %d/%d/%d to %d/%d/%d\t",scity,city,&d1,&m1,&y1,&d2,&m2,&y2);
            fscanf(fpt,"People : %d\tMode : %c,%c\nn = %d ",&people,&cho,&rcho,&n);
            for(;(c=getc(fpt))!='\n';i++);
            if(a==res)
                printf("\n\t\tBill name :  %s\n\n\t\t\tFrom %d/%d/%d to %d/%d/%d \n\t\t\tJourney from %s to %s\n\t\t\tEpenditure : RS.xxxxxxx",bname,d1,m1,y1,d2,m2,y2,scity,city);
        }
        fclose(fpt);
        heading();
        printf("\n\n\t\tUSERNAME : %s",user.uname);
min:    printf("\n\n\t\tWould you like to exit (Y/N) : ");
        scanf(" %c",&cho);
        if(cho=='Y')
            return 0;
        else if(cho=='N')
            goto ni;
        else{ 
            printf("\n\t\tEnter a valid option\n\t\t ");
            goto min;
        }
    }
    else if(nam==1)
    {
        places();
        heading();
        printf("\n\t\tUSERNAME : %s",user.uname);
        printf("\n\n\t\tEnter the state or city name you wish to visit : ");
        getchar();
        gets(city);
n:      printf("\n\t\tNumber of people on trip : ");
        scanf("%d",&people);
        if(people>25){
            printf("\n\n\t\tAre you sure of the number (Y/N) : ");
            scanf(" %c",&cho);
            if(cho!='Y'){
                if(cho!='N')
                    printf("Enter a valid option");
                goto n;
            }
        }
        printf("\n\t\tOn which days you wish to plan your trip \n\n\t\tEnter dates from(dd/mm/yyyy) to(dd,mm,yyyy):");
        printf("\n\n\t\t");
        scanf("%d/%d/%d",&d1,&m1,&y1);
        printf("\n\t\t");
        scanf("%d/%d/%d",&d2,&m2,&y2);
        printf("\n\t\tWhich mode of transport you would choose\n\n\t\tA.Aeroplane (If accessible)\n\n\t\tB.Train (If accessible)\n\n\t\tC.Bus\t\t\tD.Car\n\n\t\tEnter a option mentioned across them : ");
        scanf(" %c",&cho);
        printf("\n\t\tWhich mode of transport you would choose while returning : ");
        scanf(" %c",&rcho);
        heading();
        printf("\n\t\tUSERNAME : %s",user.uname);
        printf("\n\n\t\tEnter the name of the person on whome you would like to get the bill (withoout any spaces) : ");
        getchar();
        gets(bname);
        printf("\n\t\tEnter the location where you would like to start your journey : ");
        gets(scity);
        heading();
na:     printf("\n\t\tYOUR JOURNEY DETAILS : \n\t\tBill name :  %s\n\n\t\t\tFrom %d/%d/%d to %d/%d/%d \n\t\t\tJourney from %s to %s\n\t\t\t",bname,d1,m1,y1,d2,m2,y2,scity,city);
        printf("And the expected expenditure is : RS.xxxxxx\n\t\tWould you like to continue (Y/N) : \t\t");
        scanf(" %c",&c);
        if(c=='Y'){
            fpt=fopen("travel.txt","r");
            fseek(fpt,-2,2);
            fscanf(fpt,"%d",&n);
            fclose(fpt);
            fpt=fopen("travel.txt","a");
            fprintf(fpt,"\tP = %d\tbill name : %s\t",res,bname);
            fprintf(fpt,"Journey : %s to %s\tDate : %d/%d/%d to %d/%d/%d\t",scity,city,d1,m1,y1,d2,m2,y2);
            fprintf(fpt,"People : %d\tMode : %c,%c\nn = %d ",people,cho,rcho,(n+1));
            fclose(fpt);
        }
        else if(c=='N')
            goto ni;
        else{
            printf("\n\t\tEnter a valid option");
            goto na;
        }
        heading();
mine:   printf("\n\t\tWould you like to exit (Y/N) : ");
        scanf(" %c",&cho);
        if(cho=='Y')
            return 0;
        else if(cho=='N')
            goto ni;
        else{ 
            printf("\n\t\tEnter a valid option \n\t\t");
            goto mine;
        }
    }  
    else{
        printf("\n\t\tEnter a valid option\n\t\t");
        goto ni;
    }
    return 0;
}
