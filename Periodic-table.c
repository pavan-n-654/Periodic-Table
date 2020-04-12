#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct table st;
struct table{
char str[300][30];
}arr[37];
int total;

void Main(int x,int ref,st *ar);
void menu(int ref,st *ar);
void choice(st *ar);
void option(st *ar,int opt);

void Des_criptor(char name[],st *ar)
{
	int ele,ref=0;
	for(int i=1;ar[0].str[i][0]!='\0';i++)
	{
	    if ((strcasecmp(name,(*(ar+1)).str[i]))==0 || (strcasecmp(name,(*(ar+2)).str[i]))==0 || (strcasecmp(name,(*(ar+0)).str[i]))==0)
        {
            ele=i;
        }
	}
	for(int i=0;i<25;i++)
    {
         printf("%-30s:%s\n",(*(ar+i)).str[0],(*(ar+i)).str[ele]);
        
    }
    menu(ref,ar);	
}

void element_finder(char efind[],int finde[],st *ar)
{
	int ref=2;
	char low_range[6][30],up_range[6][30];
    for (int j =0;j<6;j++)
	{
	    switch(efind[j])
	    {
		case 'n': continue;
        	break;
		case 'y':
		{
		    printf("Enter the lower range to find: ");
		    scanf(" %[^\n]",&low_range[j]);
		    printf("Enter the upper range or enter the same value to find: ");
		    scanf(" %[^\n]",&up_range[j]);
            
        }
	    }
    }
    printf("  ");
    for (int j=0;j<163;j++) printf("_");
	printf("\n");
	printf("||%-15s|%-15s|%-8s|%-18s|%-23s|%-18s|%-18s|%-20s|%-20s||\n", (*ar).str[0],(*(ar+1)).str[0],(*(ar+2)).str[0],(*(ar+3)).str[0],(*(ar+10)).str[0],(*(ar+5)).str[0],(*(ar+6)).str[0],ar[17].str[0],ar[18].str[0]);
	printf("||_______________|_______________|________|__________________|_______________________|__________________|__________________|____________________|____________________||\n");

	for(int k=1;(*(ar+0)).str[k][0]!='\0';k++)
	{
        int cond[6]={0,0,0,0,0,0};
        for(int j=0;j<6;j++)
        {
            if(j==3)
            {
                switch(efind[j])
                {
                    case 'n':cond[j]=1;
                    case 'y':
                    {
                        if(strcasecmp((*(ar+10)).str[k],low_range[3])==0 || strcasecmp((*(ar+10)).str[k],up_range[3])==0)
                            cond[j]=1;
                    }
                }
            }
            else if(j==4 || j==5)
            {
                switch(efind[j])
                {
                    case 'n':cond[j]=1;
                    case 'y':
                    {
                        if(strtof((*(ar+finde[j])).str[k],NULL)>=strtof(low_range[j],NULL) && strtof((*(ar+finde[j])).str[k],NULL)<=strtof(up_range[j],NULL))
                            cond[j]=1;
                    }
                }
            }
            else
            {            
                switch(efind[j])
                {
                    case 'n':cond[j]=1;
                    case 'y':
                    {
                        if(strtoimax((*(ar+finde[j])).str[k],NULL,10)>=strtoimax(low_range[j],NULL,10) && strtoimax((*(ar+finde[j])).str[k],NULL,10)<=strtoimax(up_range[j],NULL,10))
                            cond[j]=1;
                    }
                }
            }
        }
	    if(cond[0]==1 && cond[1]==1 && cond[2]==1 && cond[3]==1 && cond[4]==1 && cond[5]==1)
            printf("||%-15s|%-15s|%-8s|%-18s|%-23s|%-18s|%-18s|%-20s|%-20s||\n",(*(ar+0)).str[k],(*(ar+1)).str[k],(*(ar+2)).str[k],(*(ar+3)).str[k],(*(ar+10)).str[k],(*(ar+5)).str[k],(*(ar+6)).str[k],ar[17].str[k],ar[18].str[k]);
	}
    
    printf("||_______________|_______________|________|__________________|_______________________|__________________|__________________|____________________|____________________||\n");
	
    menu(ref,ar);
}

void reffer_table(st *ar, int t1, int t2, int t3, int t4)
{
    int ref=1;
    printf("  ");
	for (int j=0;j<156;j++) printf("_");
	printf("\n");
	printf("||%-15s|%-15s|%-8s|%-28s|%-28s|%-28s|%-28s||\n", (*ar).str[0],(*(ar+1)).str[0],(*(ar+2)).str[0],(*(ar+t1+2)).str[0],(*(ar+t2+2)).str[0],(*(ar+t3+2)).str[0],(*(ar+t4+2)).str[0]);
	printf("||_______________|_______________|________|____________________________|____________________________|____________________________|____________________________||\n");
	for (int i=1;(*(ar+0)).str[i][0]!='\0';i++)
	{
	    printf("||%-15s|%-15s|%-8s|%-28s|%-28s|%-28s|%-28s||\n",(*(ar+0)).str[i],(*(ar+1)).str[i],(*(ar+2)).str[i],(*(ar+t1+2)).str[i],(*(ar+t2+2)).str[i],(*(ar+t3+2)).str[i],(*(ar+t4+2)).str[i]);
	}
    printf("||_______________|_______________|________|____________________________|____________________________|____________________________|____________________________||\n");
    menu(ref,ar);
}


void choice(st *ar)
{

    printf("\n1.Description: Complete details of a particular element\n2.Refference table: Details of certain properties of all elements \n3.Element Finder: Finds the elements based on given properties\n4.Newbie: adding new elements\n");
    printf("enter the number of the function to be performed: ");
    int opt;
    scanf("%d", &opt);
    option(ar,opt);
}


int main(void)
{
    char ch;
    int i=0;
    FILE *fp=fopen("Periodic-table-elements.csv","a+");
    if (fp == NULL){
        perror("Error while reading the file.\n");
        exit(EXIT_FAILURE);
    }
    
    int travel=0, po=0;
    while ((ch=fgetc(fp)) != EOF){
        
        if (ch!='\n'){
            char c[20];    
            if (ch!=','){
                arr[po].str[travel][i]=ch;
                i++;
            }
            else  arr[po].str[travel][i]='\0',po+=1,i=0;
        }
        else travel+=1, po=0,i=0;
        
    }
    total = travel;
    
    fclose(fp);
	struct table *ar=arr;
	choice(ar);
}

void menu(int ref,st *ar)
{
    int me_nu;
    printf("\t 1.Main Menu \t 2.Back \t 3.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&me_nu);
    Main(me_nu-1,ref,ar);
}

void Main(int x,int ref,st *ar )
{
    enum Menu{Main_menu,back,Ex_it};
    if(x>=0 && x<3)
    {
        int op;
        enum Menu opt=x;
        if (opt==Main_menu) choice(ar);
        else if (opt==back) 
        {
            if(ref==0) option(ar,op=1);   
            else if (ref==1) option(ar,op=2);
            else if (ref==2) option(ar,opt=3);
        }
        else if (opt==Ex_it)
        {
            printf("\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	        printf("\t\t\t\t\t\t\t\t@@   ___                         _       @@\n");
	        printf("\t\t\t\t\t\t\t\t@@    |  |_|  /\\  |\\ | |/   \\ / | | | |  @@\n");
	        printf("\t\t\t\t\t\t\t\t@@    |  | | /  \\ | \\| |\\    /  |_| |_|  @@\n");
	        printf("\t\t\t\t\t\t\t\t@@                                       @@\n");
	        printf("\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

            exit(EXIT_FAILURE);
        }
    }
    else menu(ref,arr);
}

void option(st *ar,int opt)
{
enum choose {
    description,
    refference_table,
    element_find,
    newbie };

    enum choose opted = opt - 1;
    if (opt >= 1 && opt <= 4)
    {
        if (opted == description)
        {
            char name[20];
            printf("Enter the Atomic Number, Element name or Element symbol: ");
	        scanf("%s",&name);
            Des_criptor(name,ar);
        }
        else if (opted == refference_table)
        {
            printf("\nAtomic Number (default)  \tElement Name (default)    \tElement symbol (default)\n1.Atomic-weight\t\t\b\t\t2.CPK-color-hex-format\n3.Period\t\t\t\t\b\b\t4.Group \n5.Phase\t\t\t\t\b\t6.bonding-type\n7.Most-Stable-Crystal \t\t8.Type\n9.Ionic-Radius\t\t\t10.Atomic-Radius\n11.EA-kJ/mol \t\t  \t12.Electronegativity\n13.First-Ionization-kJ/mol    \t14.Density\n15.Melting-Point-(K)  \t\t16.Boiling-Point-(K)\n17.Isotopes \t\t\t18.Discoverer\n19.oxidation-states\t   \t20.Year_Discovery\n21.Specific-Heat-Capacity     \t22.Electron-Configuration\n");
	        printf("\nEnter numbers of any 4 of the above properties: ");  
            int tab_opt1,tab_opt2,tab_opt3,tab_opt4;
            scanf("%d%d%d%d", &tab_opt1,&tab_opt2,&tab_opt3,&tab_opt4);
	    
	        reffer_table(ar, tab_opt1, tab_opt2, tab_opt3, tab_opt4);
	    }
	    else if (opted==element_find)
	    {
		    printf("###Note: Type has the following characteristics\n1. Metal  2. Nonmetal  3. Halogen  4. Alkali Metal\n5. Alkaline Earth Metal  \n");
		    printf("6. Metalloid  7. Nobel gas  8. Transition Metal  9.Lanthanide  10. Actinide  11. Transactinide  12. No-info.\n");
	        printf("\nEnter y(yes) or n(no) for the parameters to find the elements\n");
	        char efind[6];
	        int finde[6]={0,5,6,10,17,18};
    	    printf("1.Atomic Number: ");
	        scanf(" %c",&efind[0]);
	        printf("2.Period: ");
    	    scanf(" %c",&efind[1]);
	        printf("3.Group: ");
	        scanf(" %c",&efind[2]);
    	    printf("4.Type(eg.Metal/Non-metal): ");
	        scanf(" %c",&efind[3]);
	        printf("5.Melting-point: ");
    	    scanf(" %c",&efind[4]);
	        printf("6.Boiling-point: ");
	        scanf(" %c",&efind[5]);
	        element_finder(efind,finde,ar);
	    }
        else if(opted==newbie)
        {
            FILE *f=fopen("Periodic-table-elements.csv","a");
            if(f==NULL) printf("NOT GOOD\n");
            char data[50];
            printf("Enter the details otherwise enter \"No-info\" next to the properties:\n");
            printf("Atomic-Number: \n");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Element: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Symbol: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Atomic-Weight: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data); 
            printf("CPK-color-hex-format: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Period: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Group: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Phase: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("bonding-type: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Most-Stable-Crystal: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Type: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Ionic-Radius: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Atomic-Radius: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("EA-kJ/mol: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Electronegativity: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("First-Ionization-kJ/mol: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Density: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Melting-Point-(K): ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Boiling-Point-(K): ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Isotopes: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Discoverer: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("oxidation-states: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Year-Discovery: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Specific-Heat-Capacity: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s,",data);
            printf("Electron-Configuration: ");
            scanf(" %[^\n]",&data);
            fprintf(f,"%s\n",data);
            fclose(f);
            main();
        }
	}
    else choice(ar);
}