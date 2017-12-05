#include <stdio.h>
#include <stdlib.h>
int input_product(void);
int input_customer(void);

struct product_type{
    char product_name[30];
    int product_code;
    float price;
    int normal_stock;
    int current_stock;
} ;


  struct product_type product[10]={
    {"Yeezy",1,31000.00,20,20},
    {"Tubular radial",2,4200.00,20,20},
    {"Nmd r1 yelllow",3,5200.00,20,20},
    {"Nmd og black",4,12000.00,20,20},
    {"Stand smith",5,3200.00,20,20},
    {"Nike air jordan",6,5300.00,20,20},
    {"Nike Air max 97",7,6800.00,20,20},
    {"Vans slip on run away with me",8,2300.00,20,20},
    {"Vans old skool 90s",9,6990.00,20,20},
    {"Vans style 36",10,2100.00,20,20},
};
   typedef struct{
       char name_customer[50];
   }BillHead;
     BillHead billHead[100];

    typedef struct{
        int product_amount;
        int product_code;
    }BillDetail;
    BillDetail billDetail[100][30];

int main()
{
    char custname;
    printf("-----------------------------------------------------------------");
    printf("\n|                      EEP store                               |");
    printf("\n|             1.Yeezy                                          |");
    printf("\n|             2.Tubular radial                                 |");
    printf("\n|             3.Nmd r1 yelllow                                 |");
    printf("\n|             4.Nmd og black                                   |");
    printf("\n|             5.Stand smith                                    |");
    printf("\n|             6.Nike air jordan                                |");
    printf("\n|             7.Nike Air max 97                                |");
    printf("\n|             8.Vans slip on run away with me                  |");
    printf("\n|             9.Vans old skool 90s                             |");
    printf("\n|            10.Vans style 36                                  |");
    printf("\n|             0.End select                                     |");
    printf("\n-----------------------------------------------------------------");
    do {
        printf("\ncustomer name:");
        gets(custname);
       // input_custinfo();
        input_product();
    }while(custname!="endday");
    return 0;
}
//int input_customer()
//{

//}
int input_product()
{
    int s,q,i_cust=0,i_product=0,sum=0,i=0,pcode,pamount,subtotal,pname;
    int price;
    do{
      printf("\nSelect product:");
      scanf("%d",&s);
      if(s==0)break;
      do {
        printf("Quantity :");
        scanf("%d",&q);
        printf("%d",product[s-1].current_stock);
            if(q>product[s-1].current_stock){
           // printf("%d",pamount-product[q].current_stock);
            printf(" Product Not Enough ");
            printf("\n***** Please Insert new Quantity ****** \n");

      }
      }while(q>product[s].current_stock);
     billDetail[i][i].product_amount = q;
     billDetail[i][i].product_code = s-1;
      i_product=i_product+1;
      i++;
    }while(s!=0 && i_product<30);
    printf("\n--------------------------------------------------------------------");
    printf("\n            EEP Store               ");
    printf("\ncustomer: %s");
    printf("\n--------------------------------------------------------------------");
    printf("\n| Order             Product              Amount       Price      Subtotal    |");
    printf("\n--------------------------------------------------------------------");
    for(i=0;i<i_product;i++)
    { subtotal=0;

       pcode=billDetail[i][i].product_code;
        price = product[pcode]. price;
        pamount=billDetail[i][i].product_amount;

       subtotal=price*pamount;
        sum+=subtotal;
        pname=product[pcode].product_name;
       product[pcode].current_stock-=pamount;
       printf("\n%d",(product[pcode].current_stock));



        printf("\n|  %d  \t  %s  \t\t%d\t\t%d\t\t%d\t|",i+1,pname,pamount,price,subtotal);
    }
    printf("\n-------------------1-------------------------------------------------");
    printf("\n                                               Total: %d",sum);
}
