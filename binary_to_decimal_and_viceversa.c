#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int utility(char binary[]);
int main()
{
    char binary[100],temp[2];
    int dec,i,mask,mode,ch1,ch2;
    while(1)
    {
        printf("1.Binary to decimal\n2.Decimal to binary\n3.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
                printf("\n1.Unsigned integer\n2.Signed Integer\n");
                printf("Enter your choice: ");
                scanf("%d",&ch2);
                switch(ch2)
                {
                    case 1:
                        printf("Enter a binary number: ");
                        scanf("%*c%[^\n]",binary);
                        dec=utility(binary);
                        printf("\nDecimal: %d\n\n",dec);
                        break;
                    case 2:
                        printf("Enter a binary number: ");
                        scanf("%*c%[^\n]",binary);
                        if(binary[0]=='1')
                        {
                            mode=0;
                            for(i=strlen(binary)-1;i>=0;i--)
                            {
                                if(binary[i]=='1' && mode==0)
                                {
                                    mode=1;
                                    continue;
                                }
                                else if(mode==1)
                                    binary[i]=(binary[i]=='0')?'1':'0';
                            }
                        }
                        dec=utility(binary);
                        if(mode==1)
                            dec=-dec;
                        printf("\nDecimal: %d\n\n",dec);
                        break;
                    default:
                        printf("\nInvalid choice\n");
                        break;
                }
                break;
            case 2:
                printf("Enter a decimal integer: ");
                scanf("%d",&dec);
                printf("Binary: ");
                for(i=31;i>=0;i--)
                {
                    mask=1<<i;
                    if((dec&mask)!=0)
                        printf("1");
                    else
                        printf("0");
                }
                printf("\n\n");
                break;
            case 3:
                printf("\n----------End of the Program----------\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}
int utility(char binary[])
{
    int x=0,sum,i,y;
    char temp[2]={0};
    sum=0;
    for(i=strlen(binary)-1;i>=0;i--)
    {
        temp[0]=binary[i];
        y=atoi(temp);
        sum+=y*(1<<x);
        x++;
    }
    return sum;
}
