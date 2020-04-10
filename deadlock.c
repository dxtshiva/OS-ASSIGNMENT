#include<stdio.h>
#include<conio.h>
int main()
{
	    int allocation[5][4] = { { 0, 0, 1, 2 }, // P0    
                        { 1, 0, 0, 0 }, // P1 
                        { 1, 3, 5, 4 }, // P2 
                        { 0, 6, 3, 2 }, // P3 
                        { 0, 0, 1, 4 } }; // P4 
  
       int maximum[5][4] = { { 0,0,1,2 }, // P0    
                      { 1,7,5,0 }, // P1 
                      { 2,3,5,6 }, // P2 
                      { 0,6,5,2}, // P3 
                      { 0,6,5,6 } }; // P4 
  
    int available[4] = { 1,5,2,0 }; 
  
int needed[5][4];
int fin[5],flag=1,k,c1=0;
               int dead[5];
               int n=5,r=4;
               int i,j;
               printf("Safe State Detection\n\n");
               printf("Process\t  Allocation\t  Max\t      Available\t");
               for(i=0;i<n;i++)
               {
                              printf("\nP%d\t   ",i);
                              for(j=0;j<r;j++)
                              {
                                             printf("%d ",allocation[i][j]);
                              }
                              printf("\t");
                              for(j=0;j<r;j++)
                              {
                                             printf("%d ",maximum[i][j]); 
                              }
                              printf("\t");
                              if(i==0)
                              {
                                             for(j=0;j<r;j++)
                                             printf("%d ",available[j]);
                              }
               }
               
               for(i=0;i<n;i++)
                  fin[i]=0;
                      
               for(i=0;i<n;i++)
                for(j=0;j<r;j++)
                 needed[i][j]=maximum[i][j]-allocation[i][j];
                 
               while(flag)
               {
                	flag=0;
                	for(i=0;i<n;i++)
                	{
                		int c=0;
                		for(j=0;j<r;j++)
		                {
		                if((fin[i]==0)&&(needed[i][j]<=available[j]))
			                {
			                c++;
			                if(c==r)
				                {
					                for(k=0;k<r;k++)
						                {
						                available[k]+=allocation[i][j];
						                fin[i]=1;
						                flag=1;
						                 }
					                if(fin[i]==1)
						                i=n;
						                }
                			}	}  	}
                }
                j=0;
                flag=0;
                for(i=0;i<n;i++)
	                {
		                if(fin[i]==0)
		                {
		                dead[j]=i;
		                j++;
		                flag=1;
		                }
	               }
               if(flag==1)
               {
                printf("\n\nSystem is in Deadlock and the Deadlock process are\n");
                for(i=0;i<n;i++)
                {
                printf("P%d\t",dead[i]);
                }
               }
			                  else
               {
                              printf("\n\nSystem is in safe state \n");
                              
                                            } 
               getch();
               return 0;
}
