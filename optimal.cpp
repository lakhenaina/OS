#include<stdio.h>

int main()
{
    int f,p,frames[10],pages[30],temp[10],flag1,flag2,flag3,i,j,k,pos,max,count=0;
    printf("Naina Lakhe\n");
    printf("\n ENTER THE NUMBER OF PAGES:\n");
      scanf("%d",&p);
      printf("\n ENTER THE REFERENCE STRING :\n");
      for(i=0;i<p;++i)
      scanf("%d",&pages[i]);
      printf("\n ENTER THE NUMBER OF FRAMES :");
      scanf("%d",&f);
    for(i = 0; i <f; ++i){
        frames[i] =-1;
    }

    for(i = 0; i < p; ++i){
        flag1 = flag2 = 0;

        for(j = 0; j < f; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }

        if(flag1 == 0){
            for(j = 0; j < f; ++j){
                if(frames[j] == -1){
                    count++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
        	flag3 =0;

            for(j = 0; j < f; ++j){
            	temp[j] = -1;

            	for(k = i + 1; k < p; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }

            for(j = 0; j < f; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }

            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;

            	for(j = 1; j < f; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}
            }

			frames[pos] = pages[i];
			count++;
        }

        printf("\n");

        for(j = 0; j <f; ++j){
            printf("%d\t", frames[j]);
        }
        printf("\t Page Faults = %d\n",count);
    }

    printf("\n\nTotal Page Faults = %d",count);

    return 0;
}
