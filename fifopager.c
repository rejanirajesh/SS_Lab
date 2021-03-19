#include<stdio.h>
void main()
{
    int i,j,n,ref[50],frm[10],nof,k,flag,pf=0;
    printf("\n....ENTER THE NUMBER OF FRAMES.... ");
    scanf("%d",&nof);
    printf("\n....ENTER THE NUMBER OF PAGES.... ");
    scanf("%d",&n);
    printf("\n....ENTER EACH PAGE NUMBER.... :\n");
    for(i=1;i<=n;i++)
    scanf("%d",&ref[i]);
   //printf("\nENTER THE NUMBER OF FRAMES : ");
    //scanf("%d",&nof);
    for(i=0;i<nof;i++)
        frm[i]= -1;

    j=0;
    printf("Reference String\t \tPage Frames\n");
    for(i=1;i<=n;i++)
        {
            printf("%d\t  \t",ref[i]);
            flag=0;
            for(k=0;k<nof;k++)
                if(frm[k]==ref[i])
                    flag=1;
            if (flag==0)
                {
                    frm[j]=ref[i];
                    j=(j+1)%nof;
                    pf++;
                    for(k=0;k<nof;k++)
                        printf("%d\t\t",frm[k]);
                }
            printf("\n");
        }
    printf("\nPage Fault : %d",pf);

}
