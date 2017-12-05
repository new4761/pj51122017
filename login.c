#include<conio.h>
#include<stdio.h>
#include<string.h>
static int i=0;
struct web
{
char name[30],pass[30];
}w[99];
int n;
void login(void);
void reg(void);
int main()
{
system("cls");
printf("\n\t\t==================================================\n");
    for(i=1;i<3;i++)
    {
        printf("\t\t||\t\t\t\t\t\t||\n");
    }
    printf("\t\t||\t       WELCOME TO EEP STORE \t\t||\n");
    for(i=1;i<3;i++)
    {
        printf("\t\t||\t\t\t\t\t\t||\n");
    }
    printf("\t\t==================================================\n");

printf("\n\n\n\t\t        1. LOGIN\t\t 2. REGISTER");
printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
for(i=1;i<1000;i++)
{
    scanf("%d",&n);
switch(n)
  {
    case 1: system("cls");
        login();
        break;
    case 2: system("cls");
        reg();
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice\n\t\t\t\t\t\t\t");
        break;
  }

  }
  return 0;
}
void reg()
  {
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("Web_reg.txt","wb+");
    system("cls");
    printf("\n\t\t\t==========================================\n");
    for(i=1;i<3;i++)
    {
        printf("\t\t\t||\t\t\t\t\t||\n");
    }
    printf("\t\t\t||\t\t REGISTER    \t\t||\n");
    for(i=1;i<3;i++)
    {
        printf("\t\t\t||\t\t\t\t\t||\n");
    }
    printf("\t\t\t==========================================\n");
    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
            system("cls");
            reg();
            }
          else
          {
            strcpy(w[i].name,checker);
            break;
          }
        }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&w[i],sizeof(w[i]),1,fp);
      fclose(fp);
      printf("\n\n\t\t\t\t> Press 1 to Re-REGISTER");
      printf("\n\n\t\t\t\t> Press 2 to Continue\n\n\t\t\t\t\t\t\t");

      for(i=0;i<1000;i++)
      {
          scanf("%d",&n);
            switch(n)
          {
              case 1: system("cls");
                    reg();
                    break;
              case 2: system("cls");
                    system("cls");
        printf("\n\n\t\t* You are successfully registered *");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        for(i=1;i<1000;i++)
        {
            scanf("%d",&n);
         switch(n)
          {
              case 1: system("cls");
                    login();
                    break;
              case 2: system("cls");
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    getch();
                    main();
                    break;
               default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice\n\t\t\t\t\t\t\t");
                    break;
          }
         }
               default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice\n\t\t\t\t\t\t\t");
                    break;
          }
        }
        break;
       }
       getch();
  }

  void login()
    {
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      system("cls");
      fp=fopen("Web_reg.txt","rb");
      printf("\n\t\t\t==========================================\n");
    for(i=1;i<3;i++)
    {
        printf("\t\t\t||\t\t\t\t\t||\n");
    }
    printf("\t\t\t||\t\t  Log-in   \t\t||\n");
    for(i=1;i<3;i++)
    {
        printf("\t\t\t||\t\t\t\t\t||\n");
    }
    printf("\t\t\t==========================================\n");
      for(i=0;i<1000;i++)
      {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&w[i],sizeof(w[i]),1,fp);
          checku=strcmp(name,w[i].name);
          checkp=strcmp(pass,w[i].pass);
          if(checku==0&&checkp==0)
          {
            system("cls");
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
            break;
          }
        else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            printf("\n\n\n\t\t\tYou are not a Registered User\n");
            printf("\n\t\t\t> PRESS 1 TRY TO LOG-IN");
            printf("\n\n\t\t\t> PRESS 2 TO REGISTER YOURSELF\n\n\t\t\t\t\t\t\t");
            for(i=1;i<100;i++)
            {
               scanf("%d",&n);
        switch(n)
          {
              case 1: system("cls");
                    login();
                    break;
              case 2: system("cls");
                    reg();
                    break;
              default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice\n\t\t\t\t\t\t\t");
                    break;
          }
            }

          }
        }
        break;
      }
      getch();
    }
