#include<stdio.h>
#include<conio.h>
int main()
{
	    int alloc[5][4] = { { 0, 0, 1, 2 }, // P0    
                        { 1, 0, 0, 0 }, // P1 
                        { 1, 3, 5, 4 }, // P2 
                        { 0, 6, 3, 2 }, // P3 
                        { 0, 0, 1, 4 } }; // P4 
  
       int max[5][4] = { { 0,0,1,2 }, // P0    
                      { 1,7,5,0 }, // P1 
                      { 2,3,5,6 }, // P2 
                      { 0,6,5,2}, // P3 
                      { 0,6,5,6 } }; // P4 
  
    int avail[4] = { 1,5,2,0 }; 
  
int need[5][4];
int finish[5],temp,flag=1,k,c1=0;
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
                                             printf("%d ",alloc[i][j]);
                              }
                              printf("\t");
                              for(j=0;j<r;j++)
                              {
                                             printf("%d ",max[i][j]); 
                              }
                              printf("\t");
                              if(i==0)
                              {
                                             for(j=0;j<r;j++)
                                             printf("%d ",avail[j]);
                              }
               }
               
               for(i=0;i<n;i++)
               {
                              finish[i]=0;
               }
               //find need matrix
               for(i=0;i<n;i++)
                for(j=0;j<r;j++)
                 need[i][j]=max[i][j]-alloc[i][j];
                 
               while(flag)
               {
                	flag=0;
                	for(i=0;i<n;i++)
                	{
                		int c=0;
                		for(j=0;j<r;j++)
		                {
		                if((finish[i]==0)&&(need[i][j]<=avail[j]))
			                {
			                c++;
			                if(c==r)
				                {
					                for(k=0;k<r;k++)
						                {
						                avail[k]+=alloc[i][j];
						                finish[i]=1;
						                flag=1;
						                 }
					                if(finish[i]==1)
						                {
						                	i=n;
						                
						                }
				                }
                			}		
                		}
                	}
                }
                j=0;
                flag=0;
                for(i=0;i<n;i++)
	                {
		                if(finish[i]==0)
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

